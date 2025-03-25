class RecentCounter {
public:
    RecentCounter() {
        count = 0;
    }
    
    int ping(int t) {
        que.push(t);
        count++;
        while (!que.empty() && que.front() < t - 3000) {
            que.pop();
            count--;
        }
        return count;
    }
private:
    int count;
    queue<int> que;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */