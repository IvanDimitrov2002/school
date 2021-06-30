package org.elsys.ip.springboot.controller;

import org.elsys.ip.springboot.DbService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RestController
@RequestMapping("db")
public class DbController {
    private final DbService dbService;

    @Autowired
    public DbController(DbService dbService) {
        this.dbService = dbService;
    }

    @GetMapping
    public Map<String, String> getDb() {
        return dbService.getDb();
    }

    @PostMapping
    public void addEntry(@RequestBody Entry entry) {
        dbService.addEntry(entry.key, entry.value);
    }

    @DeleteMapping
    public void deleteEntry(String key) {
        dbService.deleteEntry(key);
    }

    static class Entry {
        private final String key;
        private final String value;

        public Entry(String key, String value) {
            this.key = key;
            this.value = value;
        }

        public String getKey() {
            return key;
        }

        public String getValue() {
            return value;
        }
    }
}
