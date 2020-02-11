package com.myj.simple;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * 该文件仅仅作为调试和测试的文件，每次完成后的代码保留在doc文件夹中，该文件包含的算法随意
 */

public class Solution {

    public static void main(String[] args) {
        int n=lengthOfLongestSubstring(" ");
        System.out.println(n);
    }

    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int i = 0, j = 0, maxWidth = 0;//分别表示窗口的下界，上界和最大的窗口宽度
        while(i<n&&j<n){
            if(set.contains(s.charAt(j))){
                set.remove(s.charAt(i++));
            }
            else{
                set.add(s.charAt(j++));
                maxWidth=Math.max(maxWidth,j-i);//每次添加新元素就要更新最大窗口，因为如果是每次检测出重复再更新，那么一个值无法测出最大窗口
            }
        }
        return maxWidth;
    }

}
