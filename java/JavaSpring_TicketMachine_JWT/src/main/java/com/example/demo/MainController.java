package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.util.List;
import java.util.UUID;
import java.util.stream.Collectors;

@RestController
public class MainController {

    @Autowired
    private MainService service;

    @GetMapping("/services")
    public List<ServiceType> getServiceTypes() throws IOException {
        return service.getAllServiceTypes();
    }

    @PreAuthorize("hasAuthority('ENROLL')")
    @PostMapping("/enroll")
    @ResponseStatus(HttpStatus.CREATED)
    public Enrollment enroll(@RequestBody String serviceId) {
        return service.enroll(UUID.fromString(serviceId));
    }

    @PreAuthorize("hasAuthority('DESK')")
    @PutMapping("/desk/{deskNumber}")
    public Call call(@RequestBody List<String> serviceIds, @PathVariable int deskNumber) {
        return service.call(serviceIds.stream().map(s -> UUID.fromString(s)).collect(Collectors.toList()), deskNumber);
    }

    @GetMapping("/board")
    public List<Info> info(@RequestParam int top) {
        return service.info(top);
    }

}
