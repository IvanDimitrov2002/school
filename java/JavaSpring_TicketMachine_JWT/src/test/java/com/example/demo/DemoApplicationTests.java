package com.example.demo;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.annotation.DirtiesContext;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.ResultActions;
import org.springframework.util.Assert;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.UUID;

import static com.example.demo.AssignmentResultHandler.assignTo;
import static org.hamcrest.Matchers.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@ExtendWith(SpringExtension.class)
@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.MOCK, classes = DemoApplication.class)
@AutoConfigureMockMvc
@DirtiesContext(classMode = DirtiesContext.ClassMode.AFTER_EACH_TEST_METHOD)
class DemoApplicationTests {

    @Autowired
    private MockMvc mvc;

    @Test
    void testGetServiceTypes() throws Exception {
        String[] services = readServices();
        String[] services2 = readServices();
        Assert.isTrue(Arrays.equals(services, services2));
    }

    @Test
    void testAuthentication() throws Exception {
        assertAuth("user", "wrongpass", false);
        assertAuth("user1", "passwrong", false);
        assertAuth("desk", "321", false);
        assertAuth("desk1", "12asdasdasd", false);
        assertAuth("admin", "root", false);
        assertAuth("user", "password", true);
        assertAuth("user1", "password1", true);
        assertAuth("desk", "123", true);
        assertAuth("desk1", "парола", true);
        assertAuth("admin", "admin", true);
    }

    @Test
    void testEnroll() throws Exception {
        String[] services = readServices();

        Assert.isTrue(assertEnroll("user", "password", services[0], 1, true) == 1);
        Assert.isTrue(assertEnroll("user", "password", services[1], 1, true) == 2);
        Assert.isTrue(assertEnroll("user", "password", services[0], 2, true) == 3);
        assertEnroll("user", "password", UUID.randomUUID().toString(), -1, false);
        Assert.isTrue(assertEnroll("user1", "password1", services[0], 3, true) == 4);
        Assert.isTrue(assertEnroll("user1", "password1", services[2], 1, true) == 5);
        Assert.isTrue(assertEnroll("user1", "password1", services[1], 2, true) == 6);
    }

    @Test
    void testCall() throws Exception {
        String[] services = readServices();

        assertEnroll("user", "password", services[0], 1, true); // 1
        assertEnroll("user", "password", services[1], 1, true); // 2
        assertEnroll("user", "password", services[0], 2, true); // 3
        assertEnroll("user", "password", services[0], 3, true); // 4
        assertEnroll("user", "password", services[2], 1, true); // 5
        assertEnroll("user", "password", services[1], 2, true); // 6

        String[] onlyTwo = new String[] { services[0], services[2] };

        assertCall("desk", "123", onlyTwo, 2, services[0], 1, true);
        assertCall("desk", "123", new String[0], 2, null, -1, false);
        assertCall("desk", "123", new String[] { UUID.randomUUID().toString() }, 2, null, -1, false);
        assertCall("desk1", "парола", new String[] { services[1] }, 3, services[1], 2, true);
        assertEnroll("user", "password", services[1], 2, true); // 7
        assertCall("desk1", "парола", new String[] { services[1], services[2] }, 4, services[2], 5, true);
    }

    @Test
    void testBoard() throws Exception {
        String[] services = readServices();

        assertEnroll("user", "password", services[0], 1, true); // 1
        assertEnroll("user", "password", services[1], 1, true); // 2
        assertEnroll("user", "password", services[0], 2, true); // 3
        assertEnroll("user", "password", services[0], 3, true); // 4
        assertEnroll("user", "password", services[2], 1, true); // 5
        assertEnroll("user", "password", services[1], 2, true); // 6

        String[] onlyTwo = new String[] { services[0], services[2] };

        assertCall("desk", "123", onlyTwo, 2, services[0], 1, true);
        assertCall("desk", "123", new String[] { services[1] }, 3, services[1], 2, true);
        assertCall("desk", "123", new String[] { services[1], services[2] }, 4, services[2], 5, true);
        assertCall("desk", "123", onlyTwo, 2, services[0], 3, true);

        List<DeskCustomer> deskCustomerList = new ArrayList<>();
        deskCustomerList.add(new DeskCustomer(2, 3));
        deskCustomerList.add(new DeskCustomer(4, 5));
        deskCustomerList.add(new DeskCustomer(3, 2));

        assertBoard("admin", "admin", 3, deskCustomerList);
    }

    private String[] readServices() throws Exception {
        AssignmentResult[] services = new AssignmentResult[3];
        services[0] = new AssignmentResult();
        services[1] = new AssignmentResult();
        services[2] = new AssignmentResult();

        mvc.perform(get("/services").contentType(MediaType.APPLICATION_JSON)).andExpect(status().isOk())
                .andExpect(content().contentTypeCompatibleWith(MediaType.APPLICATION_JSON))
                .andExpect(jsonPath("$[*]", hasSize(3))).andExpect(jsonPath("$[0].name", is("Плащане на такси")))
                .andExpect(jsonPath("$[0].description", is("Ще можете да си платите таксите към държавата.")))
                .andExpect(jsonPath("$[0].id", hasLength(36)))
                .andExpect(jsonPath("$[1].name", is("Подаване на декларация")))
                .andExpect(jsonPath("$[1].description", is("Подаване на различни декларации.")))
                .andExpect(jsonPath("$[1].id", hasLength(36)))
                .andExpect(jsonPath("$[2].name", is("Получаване на АКТ 16")))
                .andExpect(jsonPath("$[2].description", is("Трябва да носите вносната бележка със себе си.")))
                .andExpect(jsonPath("$[2].id", hasLength(36))).andDo(assignTo("$[0].id", services[0]))
                .andDo(assignTo("$[1].id", services[1])).andDo(assignTo("$[2].id", services[2]));

        String value1 = (String) services[0].getValue();
        String value2 = (String) services[1].getValue();
        String value3 = (String) services[2].getValue();

        return new String[] { value1, value2, value3 };
    }

    private void assertAuth(String username, String password, boolean isSuccess)
            throws Exception {
        ObjectMapper om = new ObjectMapper();

        if (!isSuccess) {
            mvc.perform(post("/authenticate").content(om.writeValueAsBytes(new User(username, password)))
                    .contentType(MediaType.APPLICATION_JSON))
                    .andExpect(status().isUnauthorized());
        } else {
            mvc.perform(post("/authenticate").content(om.writeValueAsBytes(new User(username, password)))
                            .contentType(MediaType.APPLICATION_JSON))
                    .andExpect(status().isOk());
        }
    }

    private int assertEnroll(String username, String password, String serviceId, int queueCount, boolean isSuccess)
            throws Exception {
        ObjectMapper om = new ObjectMapper();

        String jsonAsString = mvc
                .perform(post("/authenticate").content(om.writeValueAsBytes(new User(username, password)))
                        .contentType(MediaType.APPLICATION_JSON))
                .andReturn().getResponse().getContentAsString();

        String token = om.readTree(jsonAsString).get("token").textValue();

        if (!isSuccess) {
            mvc.perform(post("/enroll").content(serviceId).header("Authorization", "Bearer " + token)
                    .contentType(MediaType.TEXT_PLAIN)).andExpect(status().isNotFound());
            return -1;
        } else {
            AssignmentResult result = new AssignmentResult();
            mvc.perform(post("/enroll").content(serviceId).header("Authorization", "Bearer " + token)
                    .contentType(MediaType.TEXT_PLAIN)).andExpect(status().isCreated())
                    .andExpect(content().contentTypeCompatibleWith(MediaType.APPLICATION_JSON))
                    .andExpect(jsonPath("$.serviceId", is(serviceId)))
                    .andExpect(jsonPath("$.queueCount", is(queueCount))).andDo(assignTo("$.customerId", result));
            return (int) result.getValue();
        }
    }

    private void assertCall(String username, String password, String[] serviceIds, int deskNumber, String serviceId,
            int customerId, boolean isSuccess) throws Exception {
        ObjectMapper om = new ObjectMapper();

        String jsonAsString = mvc
                .perform(post("/authenticate").content(om.writeValueAsBytes(new User(username, password))).contentType(MediaType.APPLICATION_JSON))
                .andReturn().getResponse().getContentAsString();

        String token = om.readTree(jsonAsString).get("token").textValue();

        if (!isSuccess) {
            mvc.perform(put("/desk/" + deskNumber).content(om.writeValueAsBytes(serviceIds))
                    .header("Authorization", "Bearer " + token).contentType(MediaType.APPLICATION_JSON))
                    .andExpect(status().is4xxClientError());
        } else {
            mvc.perform(put("/desk/" + deskNumber).content(om.writeValueAsBytes(serviceIds))
                    .header("Authorization", "Bearer " + token).contentType(MediaType.APPLICATION_JSON))
                    .andExpect(status().isOk())
                    .andExpect(content().contentTypeCompatibleWith(MediaType.APPLICATION_JSON))
                    .andExpect(jsonPath("$.serviceId", is(serviceId)))
                    .andExpect(jsonPath("$.customerId", is(customerId)));
        }
    }

    private void assertBoard(String username, String password, int top, List<DeskCustomer> deskCustomerList)
            throws Exception {
        ObjectMapper om = new ObjectMapper();

        String jsonAsString = mvc
                .perform(post("/authenticate").content(om.writeValueAsBytes(new User(username, password))).contentType(MediaType.APPLICATION_JSON))
                .andReturn().getResponse().getContentAsString();

        String token = om.readTree(jsonAsString).get("token").textValue();

        ResultActions resultActions = mvc.perform(get("/board?top=" + top).header("Authorization", "Bearer " + token))
                .andExpect(status().isOk()).andExpect(content().contentTypeCompatibleWith(MediaType.APPLICATION_JSON))
                .andExpect(jsonPath("$[*]", hasSize(top)));

        int counter = 0;
        for (DeskCustomer deskCustomer : deskCustomerList) {
            resultActions = resultActions.andExpect(jsonPath("$[" + counter + "].deskNumber", is(deskCustomer.desk)))
                    .andExpect(jsonPath("$[" + counter + "].customerId", is(deskCustomer.customer)));
            counter += 1;
        }
    }

    private static class DeskCustomer {
        public int desk;
        public int customer;

        public DeskCustomer(int desk, int customer) {
            this.desk = desk;
            this.customer = customer;
        }
    }

}
