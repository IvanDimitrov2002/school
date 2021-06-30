package com.example.demo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ClientService {
    private final Map<String, String> properties;
    private final ArrayList<Map<String, Object>> queue = new ArrayList<>();

    public ClientService(){
        this.properties = new HashMap<String, String>();
    }

    public ClientService(Map<String, String> properties) {
        this.properties = properties;
    }

    public Map<String, String> getProperties() {
        return properties;
    }

    public ArrayList<Map<String, Object>> getQueue() {
        return queue;
    }
}
