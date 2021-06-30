package com.example.demo;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.stereotype.Service;
import org.springframework.util.ResourceUtils;

import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

@Service
public class ServicesService {
    private Integer currCustomerId = 1;
    private final ArrayList<ClientService> clientServices;
    private final ArrayList<Map<String, Object>> waitingCustomers = new ArrayList<>();

    public ServicesService() throws IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        File servicesFromJSON = ResourceUtils.getFile("classpath:services.json");
        ArrayList<Map<String, String>> clientServices = objectMapper.readValue(servicesFromJSON, ArrayList.class);
        clientServices.forEach(service -> service.put("id", UUID.randomUUID().toString()));
        this.clientServices = clientServices.stream().map(ClientService::new).collect(Collectors.toCollection(ArrayList::new));
    }

    public ArrayList<ClientService> getServices() {
        return clientServices;
    }

    public Map<String,Object> addCustomer(String serviceId) {
        ClientService clientService = clientServices.stream().filter(service -> serviceId.equals(service.getProperties().get("id"))).findFirst().orElse(null);
        if(clientService != null){
            Map<String, Object> newCustomer = new HashMap(){{
                put("customerId", currCustomerId++);
                put("serviceId", serviceId);
                put("queueCount", clientService.getQueue().size() + 1);
            }};
            clientService.getQueue().add(newCustomer);
            return newCustomer;
        }
        return null;
    }

    private Map<String, Object> findLongestWaiting(ArrayList<String> serviceIds){
        ArrayList<Map<String, Object>> customers = new ArrayList<>();
        for(String serviceId : serviceIds){
            ClientService clientService = clientServices.stream().filter(service -> serviceId.equals(service.getProperties().get("id"))).findFirst().orElse(null);
            if(clientService != null){
                if(clientService.getQueue().size() != 0){
                    customers.add(clientService.getQueue().get(0));
                }
            }
        }
        if(customers.size() == 0){
            return null;
        }
        return Collections.min(customers, Comparator.comparing(c -> (Integer) c.get("customerId")));
    }

    public Map<String, Object> callCustomer(Integer deskNumber, ArrayList<String> serviceIds){
        Map<String, Object> calledCustomer = findLongestWaiting(serviceIds);
        if(calledCustomer == null){
            return null;
        }
        ClientService clientService = clientServices.stream().filter(service -> calledCustomer.get("serviceId").equals(service.getProperties().get("id"))).findFirst().orElse(null);
        if(clientService == null){
            return null;
        }
        clientService.getQueue().remove(calledCustomer);
        waitingCustomers.add(0, new HashMap<String, Object>() {{
            put("deskNumber", deskNumber);
            put("customerId", calledCustomer.get("customerId"));
        }});
        calledCustomer.remove("queueCount");
        return calledCustomer;
    }

    public ArrayList<Map<String, Object>> showBoard(Integer results){
        return waitingCustomers.stream().limit(results).collect(Collectors.toCollection(ArrayList::new));
    }
}
