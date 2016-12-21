/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: Java
@Datetime: 16-06-20 04:42
*/

public class Solution {
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        // Write your code here
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        for(int i = 0, j = 0; i < nums1.length && j < nums2.length; ) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                list.add(nums1[i]);
                for (++i; i < nums1.length && nums1[i] == nums1[i - 1]; ++i);
                for (++j; j < nums2.length && nums2[j] == nums2[j - 1]; ++j);
            }
        }
        
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            ans[i] = list.get(i);
        }
        
        return ans;
    }
}