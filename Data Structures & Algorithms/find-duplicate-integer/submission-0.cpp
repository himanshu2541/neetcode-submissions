class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(auto &num: nums){
            if(seen.find(num) != seen.end()){ // we already had this element
                return num;
            }
            seen.insert(num);
        }

        return 0;
    }
};
