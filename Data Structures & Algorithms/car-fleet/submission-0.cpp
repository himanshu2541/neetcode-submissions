class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,int>> car;

    int n = position.size();

    for(int i = 0; i < n; i++) {
        car.push_back({position[i], speed[i]});
    }

    sort(car.begin(), car.end(), greater<pair<int,int>>());

    stack<double> st;

    for(auto &[p, s] : car) {
        double time = (double)(target - p) / s;

        if(st.empty() || time > st.top()) {
            st.push(time);
        }
    }

    return st.size();
}
};
