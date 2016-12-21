/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/number-of-islands-ii
@Language: C++
@Datetime: 15-06-29 01:44
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
   vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        UF uf;
        vector<vector<int>> grid(n, vector<int>(m));
        vector<int> ans;
        const pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        map<pair<int, int>, int> t;
        for (auto &p : operators) {
            if (grid[p.x][p.y] > 0) ans.push_back(ans.back());
            else {
                grid[p.x][p.y] = 1;
                int index = uf.add();
                t[make_pair(p.x, p.y)] = index;
                for (auto &d : dirs) {
                    int i = p.x + d.first, j = p.y + d.second;
                    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) continue;
                    uf.connect(index, t[make_pair(i, j)]);
                }
                ans.push_back(uf.ccNum());
            }
        }
        return ans;
    }
private:
    class UF {
    public:
        UF():cc(0){}
        int add() {
            id.push_back((int)id.size());
            sz.push_back(1);
            ++cc;
            return (int)id.size() - 1;
        }
        int ccNum() { return cc;}
        bool connected(int p, int q) {
            return root(p) == root(q);
        }
        void connect(int p, int q) {
            int i = root(p), j = root(q);
            if (i == j) return;
            if (sz[i] < sz[j]) {
                id[i] = j;
                sz[j] += sz[i];
            }
            else {
                id[j] = i;
                sz[i] += sz[j];
            }
            --cc;
        }
    private:
        int root(int i) {
            while(id[i] != i) {
                id[i] = id[id[i]];
                i = id[i];
            }
            return i;
        }
        vector<int> id;
        vector<int> sz;
        int cc;
    };
};
