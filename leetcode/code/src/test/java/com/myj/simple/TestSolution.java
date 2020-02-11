package com.myj.simple;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestSolution {

    Solution solution = new Solution();

    @Test
    void testTwoSum() {
        int[] numArray= {2, 7, 11, 15};
        int[] result = {0, 1};
        assertArrayEquals(result, solution.twoSum(numArray, 9));
    }

    @Test
    void testReverse() {
        int a=solution.reverse(2147483647);
        System.out.println(a);
    }
}
