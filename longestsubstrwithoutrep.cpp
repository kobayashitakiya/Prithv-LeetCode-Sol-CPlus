#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[128] = {0}; 
        int ans = 0, left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right]]++;
            while (count[s[right]] > 1) {
                count[s[left]]--;
                left++;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
