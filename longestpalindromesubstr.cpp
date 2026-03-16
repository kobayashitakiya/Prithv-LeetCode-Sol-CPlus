#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        int n = s.size();

        // Helper function to expand from center and return palindrome length
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length is (right - 1) - (left + 1) + 1
            return right - left - 1;
        };

        for (int i = 0; i < n; ++i) {
            // Case 1: Odd length (e.g., "aba", center is 'b')
            int len1 = expand(i, i);
            // Case 2: Even length (e.g., "abba", center is between 'b' and 'b')
            int len2 = expand(i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                // Calculate starting index based on length and current center i
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};
