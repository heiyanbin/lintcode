/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/singleton
@Language: Java
@Datetime: 15-04-18 04:14
*/

class Solution {
    /**
     * @return: The same instance of this class every time
     */
    public static Solution getInstance() {
        return Holder.instance;
    }
    
    private Solution () {}
    
    private static class Holder {
        private static Solution instance = new Solution();
    }
};
