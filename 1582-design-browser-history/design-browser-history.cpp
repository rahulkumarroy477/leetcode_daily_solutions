class BrowserHistory {
public:
    stack<string> backSt, forwardSt;
    BrowserHistory(string homepage) {
        backSt.push(homepage);
    }
    
    void visit(string url) {
        backSt.push(url);
        while(!forwardSt.empty()){
            forwardSt.pop();
        }
    }
    
    string back(int steps) {
        while(backSt.size()>1 && steps>0){
            string top = backSt.top();
            backSt.pop();
            forwardSt.push(top);
            steps--;
        }
        return backSt.top();
    }
    
    string forward(int steps) {
        while(!forwardSt.empty() && steps>0){
            string top = forwardSt.top();
            forwardSt.pop();
            backSt.push(top);
            steps--;
        }
        return backSt.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */