class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] {0};
        queue<pair<char,int>> alph;
        queue<int> index;
        for(int i = 0; i<s.size(); i++){
            alph.push({s[i],i});
            freq[s[i] - 'a']++;
        }
        while(!alph.empty() && freq[alph.front().first - 'a'] > 1){
            alph.pop();
        }
        return alph.empty() ? -1 : alph.front().second;
    }
};