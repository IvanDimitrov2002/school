package test.com.elsys.picturesort;

import main.com.elsys.picturesort.Data;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class DataTest {
    Data data;

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        data = new Data(List.of(0,0,0,255,1,2,3,255));
    }

    @org.junit.jupiter.api.Test
    void getImagePixels() {
        assertArrayEquals(new Integer[]{ 0,0,0,255 }, data.getImagePixels().get(0).toArray());
        assertArrayEquals(new Integer[]{ 1,2,3,255 }, data.getImagePixels().get(1).toArray());
    }

    @org.junit.jupiter.api.Test
    void getMask() {
        assertArrayEquals(new Integer[]{ 0,-1,0 }, data.getMask().get(0).toArray());
        assertArrayEquals(new Integer[]{ -1,4,-1 }, data.getMask().get(1).toArray());
        assertArrayEquals(new Integer[]{ 0,-1,0 }, data.getMask().get(2).toArray());
    }
}