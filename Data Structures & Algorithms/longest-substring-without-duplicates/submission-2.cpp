class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);

        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++){
            if(last[s[right]] >= left){
                left = last[s[right]] + 1;
            }
            
            last[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
