/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/assignment-operator-overloading-c-only
@Language: C++
@Datetime: 15-05-18 03:57
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (&object == this) return *this;
        
        if (m_pData) delete [] m_pData;
        if (object.m_pData == NULL) {
            m_pData = NULL;
            return *this;
        }
        int n = strlen(object.m_pData) + 1;
        m_pData = new char[n];
        for (int i = 0; i < n; i++) {
            m_pData[i] = object.m_pData[i];
        }
        return *this;
    }
};
