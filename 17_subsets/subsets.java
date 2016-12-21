/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/subsets
@Language: Java
@Datetime: 14-10-18 16:25
*/

class Solution {
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> S) {
        // write your code here
        Collections.sort(S);
        DFS(x,S,0);
        return output;

    }
    private void DFS(ArrayList<Integer> x, ArrayList<Integer> S, int start)
    {
        output.add((ArrayList<Integer>)x.clone());
        for(int i=start;i<S.size();i++)
        {
            x.add(S.get(i));
            DFS(x,S,i+1);
            x.remove(x.size()-1);
        }
    }
    private ArrayList<ArrayList<Integer>> output = new ArrayList<ArrayList<Integer>>();
    private ArrayList<Integer> x = new ArrayList<Integer>();
}
