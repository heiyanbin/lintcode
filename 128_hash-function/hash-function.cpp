/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 14-12-11 04:59
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long long hash =0;
        for(int i=0;i<key.size();i++)
            hash= (hash *(33 % HASH_SIZE) % HASH_SIZE + key[i]%HASH_SIZE) %HASH_SIZE;
        return hash;
    }
};
