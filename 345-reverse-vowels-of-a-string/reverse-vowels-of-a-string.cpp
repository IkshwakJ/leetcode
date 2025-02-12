class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int j = len - 1;
        int i  = 0;
        unordered_map<char,int> vowels {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
        while(i<j){
            while(i<len && vowels[s[i]] != 1 && i<j){
                i++;
            }
            while(j>=0 && vowels[s[j]] != 1 && i<j){
                j--;
            }
            swap(s[i],s[j]);
            i++; 
            j--;
        }    
        return s;
    }
};