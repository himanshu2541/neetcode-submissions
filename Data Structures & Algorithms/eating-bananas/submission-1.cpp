class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        int k = piles[hi];

        while(lo < hi){
            long long hours = 0;
            int mid = lo + (hi - lo) / 2;
            
            for(auto pile: piles){
                hours += (pile + (long long)mid - 1)/mid;
            }

            if(hours <= h){
                // this hour work try smaller
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
