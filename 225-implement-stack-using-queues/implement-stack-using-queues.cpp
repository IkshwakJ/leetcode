class MyStack {
public:
    MyStack() {

    }
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while (!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q = temp;
    }
    
    int pop() {
        if(q.empty()){
            return {};
        }
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        if(q.empty()){
            return {};
        }
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
private:
    queue<int> q;
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */