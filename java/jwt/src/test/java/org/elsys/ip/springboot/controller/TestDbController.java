package org.elsys.ip.springboot.controller;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;

import java.util.Map;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.delete;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
@AutoConfigureMockMvc
class TestDbController {

    @Autowired
    private MockMvc mvc;

    @Test
    void testCrud() throws Exception {
        mvc.perform(get("/")).
                andExpect(status().isOk()).
                andExpect(content().contentType(MediaType.APPLICATION_JSON)).
                andDo(result -> {
                    String response = result.getResponse().getContentAsString();
                    ObjectMapper mapper = new ObjectMapper();

                    Map map = mapper.readValue(response, Map.class);

                    assert map.size() == 2;
                    assert map.get("First").equals("Value");
                });

        mvc.perform(post("/").content("{\n" +
                "  \"key\": \"From Test\",\n" +
                "  \"value\": \"Yet another value\"\n" +
                "}").contentType(MediaType.APPLICATION_JSON)).
                andExpect(status().isOk());

        mvc.perform(get("/")).
                andExpect(status().isOk()).
                andExpect(content().contentType(MediaType.APPLICATION_JSON)).
                andDo(result -> {
                    String response = result.getResponse().getContentAsString();
                    ObjectMapper mapper = new ObjectMapper();

                    Map map = mapper.readValue(response, Map.class);

                    assert map.size() == 3;
                    assert map.get("From Test").equals("Yet another value");
                });

        mvc.perform(delete("/?key=First")).
                andExpect(status().isOk());

        mvc.perform(get("/")).
                andExpect(status().isOk()).
                andExpect(content().contentType(MediaType.APPLICATION_JSON)).
                andDo(result -> {
                    String response = result.getResponse().getContentAsString();
                    ObjectMapper mapper = new ObjectMapper();

                    Map map = mapper.readValue(response, Map.class);

                    assert map.size() == 2;
                    assert !map.containsKey("First");
                });
    }

}
