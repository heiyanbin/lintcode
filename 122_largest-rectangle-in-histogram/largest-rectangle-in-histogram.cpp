/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/largest-rectangle-in-histogram
@Language: C++
@Datetime: 15-11-04 04:25
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
    	stack<int> s;
    	int maxArea = 0;
    	height.push_back(0);
    	for(int i = 0; i < height.size(); ++i) {		
    		while (!s.empty() && height[i] < height[s.top()]){
    			int h = height[s.top()]; s.pop();
    			int left = s.empty() ? -1 : s.top();
    			maxArea = max(maxArea, h * (i - left - 1));
    		}
    		s.push(i);
    	}
    	return maxArea;
    }
};

