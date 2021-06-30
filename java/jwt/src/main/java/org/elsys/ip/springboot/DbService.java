package org.elsys.ip.springboot;

import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Map;

public class DbService {
    private Map<String, String> db = new HashMap<>();

    public DbService() {
        db.put("First", "Value");
        db.put("Second", "Another Value");
    }

    public Map<String, String> getDb() {
        return db;
    }

    public void addEntry(String key, String value) {
        db.put(key, value);
    }

    public void deleteEntry(String key) {
        db.remove(key);
    }
}
