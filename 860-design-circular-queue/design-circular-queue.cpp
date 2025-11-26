class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k;
        Queue.assign(k, -1);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(head == -1)
            head++;
        tail++;
        if(tail >= size)
            tail = 0;
        Queue[tail] = value;
        return true; 
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(head == tail)
        {
            head = -1;
            tail = -1;
        }
        else{
            head += 1;
            if(head >= size)
                head = 0;
        }
        return true;
    }
    
    int Front() {
        if(head == -1)
            return -1;
        return Queue[head];
    }
    
    int Rear() {
        if(head == -1)
            return -1;
        return Queue[tail];
    }
    
    bool isEmpty() {
        if(head == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((tail + 1)%size == head)
            return true;
        return false;
    }

private: 
    vector<int> Queue; 
    int head = -1; 
    int tail = -1;
    int size = -1;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */