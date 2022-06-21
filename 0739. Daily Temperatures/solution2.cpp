class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());  // save the next larger index
        stack<int> st;  // we only save index
        for (int i = 0; i < temperatures.size(); i++) {
            // Compare the top of stack and current value
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                result[st.top()] = i - st.top();  // record the diff
                st.pop();
            }
            st.push(i);
        }
        // Remember to clear the stack
        while (!st.empty()) {
            // Do anything you want here. Here we keep the result 0;
            result[st.top()] = 0;
            st.pop();
        }
        return result;
    }
};