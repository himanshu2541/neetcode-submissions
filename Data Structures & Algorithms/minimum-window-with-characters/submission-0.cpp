class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> need, window;

        for(auto &c: t) need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        for(int right = 0; right < s.size(); right++){
            char c = s[right];

            // Add current char to window
            window[c]++;

            // check if character's required freq is satisfied
            if(need.count(c) && window[c] == need[c]) formed++;

            while(formed == required){

                // update minimum window
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // remove left character to shrink the window
                char leftChar = s[left];
                window[leftChar]--;

                // removing it make window invalid
                if(need.count(leftChar) && window[leftChar] < need[leftChar]) formed--;

                left++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(startIndex, minLen);
    }
};
