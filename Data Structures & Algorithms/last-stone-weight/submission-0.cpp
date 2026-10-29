class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];

        priority_queue<int, vector<int>> pq;

        for(auto &stone: stones){
            pq.push(stone);
        }

        while(pq.size() > 1){
            int heavy1 = pq.top();
            pq.pop();
            int heavy2 = pq.top();
            pq.pop();

            pq.push(heavy1 - heavy2);
        }

        return pq.top();
    }
};
