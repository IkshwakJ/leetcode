class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int ans = 0;
        vector<int> :: iterator child;
        for(child = g.begin(); child != g.end(); ++child){
            while(j<s.size() && s[j] < *child){
                j++;
            }
            if(j<s.size() && s[j] >= *child){
                ans++;
                j++;
            }
        }
        return ans;
    }
};