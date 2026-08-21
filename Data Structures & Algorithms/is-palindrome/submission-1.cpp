class Solution {
public:
    bool isPalindrome(string s) {
        string sanitized_s;

        for(auto &c: s){
            if(isalnum(c)){
                sanitized_s += tolower(c);
            }
        }

        int left = 0;
        int right = sanitized_s.length() - 1;

        while(left < right){
            if(sanitized_s[left] != sanitized_s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
