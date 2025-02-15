class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        if (len < 10) {
            return {};
        }
        
        unordered_map<string, int> count_map; 
        set<string> repeated; 
        
        for (int i = 0; i <= len - 10; i++) { 
            string sub = s.substr(i, 10);
            count_map[sub]++;
            if (count_map[sub] >= 2) { 
                repeated.insert(sub);
            }
        } 
        return vector<string>(repeated.begin(), repeated.end());
    }
};