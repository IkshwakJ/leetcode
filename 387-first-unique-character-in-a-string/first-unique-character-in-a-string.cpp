class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] {0};
        queue<char> alph;
        queue<int> index;
        for(int i = 0; i<s.size(); i++){
            alph.push(s[i]);
            index.push(i);
            freq[s[i] - 'a']++;
        }
        while(!alph.empty() && freq[alph.front() - 'a'] > 1){
            alph.pop();
            index.pop();
        }
        if(!alph.empty()){
            return index.front();
        }
        return -1;
    }
};