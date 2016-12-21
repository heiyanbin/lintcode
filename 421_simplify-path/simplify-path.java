/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/simplify-path
@Language: Java
@Datetime: 15-06-01 07:48
*/

public class Solution {
    /**
     * @param path the original path
     * @return the simplified path
     */
    public static String simplifyPath(String path) {
        // Write your code here
        String[] tokens = path.split("/+");
        if (tokens.length == 0) return "/";
        List<String> s = new ArrayList<String>();
        for (String t : tokens) {
        	if (t.equals("..")) {
        		if (s.size() > 1)
        			s.remove(s.size() - 1);
        	}
        	else if (!t.equals(".")) s.add(t);	
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.size(); ++i) {
        	sb.append(s.get(i));
        	if (i == 0 || i < s.size() - 1) sb.append("/");
        }
        return sb.toString();
    }
}
