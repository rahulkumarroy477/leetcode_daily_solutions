class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty()){
            if(val<st.top().second){
                st.push({val,val});
            }
            else{
                st.push({val,st.top().second});
            }
        }
        else{
            st.push({val,val});
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first;
        }
        return -1;
    }
    
    int getMin() {
        if(!st.empty()){
            return st.top().second;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */