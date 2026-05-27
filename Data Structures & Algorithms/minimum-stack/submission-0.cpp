class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val<=minSt.top()) minSt.push(val);
    }
    
    void pop() {
        if(!st.empty() && !minSt.empty() && st.top()==minSt.top()){
            minSt.pop();
        }
        if(!st.empty()) st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        else return st.top();
    }
    
    int getMin() {
        if(minSt.empty()) return -1;
        int min=minSt.top();
        return min;
    }
};
