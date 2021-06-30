package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.Map;
import java.util.stream.Collectors;

@RestController
public class ServicesController {
    private final ServicesService servicesService;

    @Autowired
    public ServicesController(ServicesService servicesService) {
        this.servicesService = servicesService;
    }

    @GetMapping("/services")
    public ArrayList<Map<String, String>> getServices() {
        return this.servicesService.getServices().stream().map(ClientService::getProperties).collect(Collectors.toCollection(ArrayList::new));
    }

    @PostMapping("/enroll")
    public ResponseEntity<Map<String, Object>> addCustomer(@RequestBody String serviceId) {
        Map<String, Object> newCustomer = this.servicesService.addCustomer(serviceId);
        if(newCustomer == null){
            return new ResponseEntity<>(null, HttpStatus.NOT_FOUND);
        }
        return new ResponseEntity<>(newCustomer, HttpStatus.CREATED);
    }

    @PutMapping("/desk/{number}")
    public ResponseEntity<Map<String, Object>> callCustomer(@PathVariable("number") Integer deskNumber, @RequestBody ArrayList<String> serviceIds) {
        if(serviceIds == null){
            return new ResponseEntity<>(null, HttpStatus.BAD_REQUEST);
        }
        Map<String, Object> calledCustomer = this.servicesService.callCustomer(deskNumber, serviceIds);
        if(calledCustomer == null){
            return new ResponseEntity<>(null, HttpStatus.NOT_FOUND);
        }
        return new ResponseEntity<>(calledCustomer, HttpStatus.OK);
    }

    @GetMapping("/board")
    public ArrayList<Map<String, Object>> showBoard(@RequestParam(name = "top") Integer results) {
        return this.servicesService.showBoard(results);
    }
}

