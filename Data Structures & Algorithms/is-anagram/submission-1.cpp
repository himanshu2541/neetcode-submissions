class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sCharC, tCharC;

        for(auto &cs: s){
            sCharC[cs]++;
        }
        for(auto &ct: t){
            tCharC[ct]++;
        }

        return sCharC == tCharC;
    }
};
