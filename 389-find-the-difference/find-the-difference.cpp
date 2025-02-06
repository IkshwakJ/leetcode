class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.size();
        char result = 0;
        for(int i=0; i<len; i++){
            result ^= s[i]^t[i];
        }
        return result^t[len];
    }
};