/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/simplify-path
@Language: C++
@Datetime: 15-06-01 07:15
*/

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string &path) {
		int i = 0, n = path.size();
		for (int j = 0; j < n; ) {
			if (path[j] != '.' || j + 1 < n && path[j + 1] != '/'  && path[j + 1] != '.'||
			 j + 2 < n && path[j + 1] != '/' && path[j + 2] != '/' && path[j + 2] != '.') {
				if (path[j] != '/' || i == 0 || path[i - 1] != '/' && j < n - 1)
					path[i++] = path[j++];
				else
					j++;
			}
			else {
				if (j + 1 < n && path[j + 1] == '.') {
					if (j + 2 < n && path[j + 2] == '.') { //handle ...
						for (int k = 0; k < 3; path[i++] = path[j++], k++);
					}
					else {//handle ..
						if (i > 1) { //only pop when current path is not root 
							for (--i; i > 1 && path[i - 1] != '/'; --i);
							if (i > 1) --i;
						}
						j += 2;
					}
				}
				else 
					j++;
			}
		}
		return path.substr(0, i);
	}	
};
