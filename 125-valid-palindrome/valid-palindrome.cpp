class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0;
        int j = len - 1;
        while(i < len && j >= 0 && i < j){
            while(i< len && !isalnum(s[i])){
                // while s[i] is not an alphabet
                i++;
            }
            while(j >= 0 && !isalnum(s[j])){
                // while s[j] is not an alphabet
                j--;
            }
            if(i<len && j >= 0 && tolower(s[i]) != tolower(s[j])){
                cout<<i<<"\t"<<j;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};