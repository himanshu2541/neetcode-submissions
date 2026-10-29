class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;  // {distance, index}

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            double dist = sqrt((double)x * x + (double)y * y);

            pq.push({dist, i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto [dist, i] = pq.top();
            pq.pop();

            ans.push_back(points[i]);
        }

        return ans;
    }
};
