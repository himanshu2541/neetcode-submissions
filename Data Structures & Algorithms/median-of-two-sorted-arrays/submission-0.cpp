class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // A is always smaller array
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int lo = 0;
        int hi = m;

        while(lo <= hi){
            int i = lo + (hi - lo) / 2;
            int j = (m + n + 1)/2 - i;

            // boundary els of both partitions
            int leftA = (i==0) ? INT_MIN : nums1[i - 1];
            int rightA = (i==m) ? INT_MAX : nums1[i];

            int leftB = (j==0) ? INT_MIN : nums2[j - 1];
            int rightB = (j==n) ? INT_MAX : nums2[j];

            // correct partition found
            if(leftA <= rightB && leftB <= rightA){
                int leftMax = max(leftA, leftB);

                // odd total length
                if((m+n) % 2 == 1){
                    return leftMax;
                }

                int rightMin = min(rightA, rightB);

                return ((double)leftMax + rightMin) / 2.0;
            }

            // if leftA > rightB -> too many elements
            else if(leftA > rightB) hi = i - 1;

            // if leftB > rightA -> placed few elements
            else lo = i + 1;
        }

        return 0.0; // unreachable 
    }
};
