class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int left = 0;
        int right = 0;
        int word_end;
        while(left<len){
            while(right<len && s[right] != ' '){
                right++;
            }
            word_end = right - 1;
            while(left < word_end){
                swap(s[left],s[word_end]);
                left++;
                word_end--;
            }
            right++;
            left = right;
        }
        return s;
    }
};