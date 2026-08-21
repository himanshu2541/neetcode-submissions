class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;

        int lMax = 0, rMax = 0;

        int water = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] >= lMax){
                    lMax = height[l];
                } else{
                    water += lMax - height[l];
                }
                l++;
            } else{
                if(height[r] >= rMax){
                    rMax = height[r];
                } else{
                    water += rMax - height[r];
                }
                r--;
            }
        }

        return water;
    }
};
