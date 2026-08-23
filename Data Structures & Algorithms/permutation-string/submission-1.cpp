class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // freq of s1
        for(auto &c: s1){
            count1[c - 'a']++;
        }


        int left = 0;

        for(int right = 0; right < s2.size(); right++){
            // add current char
            count2[s2[right] - 'a']++;

            // Maintain a window of size s1
            if(right - left + 1 > s1.size()){
                count2[s2[left]-'a']--; // exclude the left element
                left++;
            }

            // check if freq matches
            if(right - left + 1 == s1.size() && count1 == count2) return true;
        }

        return false;
    }
};
