/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) dp[i][i] = true;

        int max = 0, start = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    if(j - i<= 1) dp[i][j] = true;
                    else if(dp[i+1][j-1]) dp[i][j] = true;
                    if (dp[i][j] && j - i + 1 > max) 
                        { max = j - i + 1; start = i; }
                }
            }
        }
        string res = s.substr(start,max);
        return res;
    }
};
// @lc code=end

