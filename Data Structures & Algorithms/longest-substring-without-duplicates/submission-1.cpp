class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int max_len = 0;
        int i = 0, j = 0;

        unordered_set<char> seen;

        while(j < n){
            if(seen.count(s[j])){
                seen.erase(s[i]);
                i++;
            } else{
                seen.insert(s[j]);
                j++;
            }
            max_len = max(max_len, j - i);
        }

        return max_len;
    }
};
