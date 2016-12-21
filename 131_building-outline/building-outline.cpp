/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/building-outline
@Language: C++
@Datetime: 15-05-26 03:59
*/

#include <set>
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
		// write your code here
		if (buildings.empty()) return vector<vector<int>>();
		vector<vector<int>> sides;
		for (auto &b : buildings) {
			sides.push_back({ b[0], 0, b[2] });
			sides.push_back({ b[1], 1, b[2] });
		}
		sort(sides.begin(), sides.end());
		int x = 0;
		vector<vector<int>> res;
		multiset<int> q;
		for (auto &side : sides) {
			if (q.empty()) x = side[0];
			else {
			    auto maxH = *q.rbegin();
				if (side[0] > x && (side[2] > maxH ||
					side[2] == maxH && side[1] == 1 && q.count(side[2]) == 1))
				{
					res.push_back({ x, side[0], maxH });
					x = side[0];
				}
			}
			if (side[1] == 0) q.insert(side[2]);
			else q.erase(q.find(side[2]));
		}
		return res;
	}
};
