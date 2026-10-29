class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(auto &task: tasks){
            freq[task]++;
        }

        priority_queue<int> maxHeap;

        for(auto &[task, count]: freq){
            maxHeap.push(count);
        }

        queue<pair<int, int>> cooldown; // {remaining freq, available time}

        int time = 0;
        while(!maxHeap.empty() || !cooldown.empty()){
            time++;

            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();

                count--;

                if(count > 0){
                    cooldown.push({count, time + n});
                }
            }

            if(!cooldown.empty() && cooldown.front().second == time){
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
