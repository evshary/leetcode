class MyQueue {
private:
    vector<int> input, output;
    void update_output() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push_back(input.back());
                input.pop_back();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push_back(x);
    }
    
    int pop() {
        update_output();
        int ret_val = output.back();
        output.pop_back();
        return ret_val;
    }
    
    int peek() {
        update_output();
        return output.back();
    }
    
    bool empty() {
        if (input.empty() && output.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */