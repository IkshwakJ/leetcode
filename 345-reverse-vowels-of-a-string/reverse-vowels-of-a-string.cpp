class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int j = len - 1;
        int i  = 0;
        while(i<j){
            while(i<len && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'){
                i++;
                cout<<i<<", ";
            }
            while(j>=0 && s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U'){
                j--;
                cout<<j<<", ";
            }
            if(i < j){
                swap(s[i],s[j]);
            }
            i++; 
            j--;
        }    
        return s;
    }
};