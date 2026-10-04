class MinStack {
    private:
        vector<int> arr;
        vector<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        arr.push_back(val);

        if(minStack.empty()){
            minStack.push_back(val);
        } else{
            minStack.push_back(min(val, minStack.back()));
        }
    }
    
    void pop() {
        arr.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
