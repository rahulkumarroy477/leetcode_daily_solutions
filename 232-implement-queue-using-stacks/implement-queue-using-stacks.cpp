class MyQueue {
public:
    vector<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        int n = st.size();
        st.push_back(x);
        for(int i = n-1;i>=0;i--){
            st[i+1] = st[i];
        }
        st[0] = x;
    }
    
    int pop() {
        int val = st.back();
        st.pop_back();
        return val;
    }
    
    int peek() {
        return st.back();
    }
    
    bool empty() {
        return st.empty();
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