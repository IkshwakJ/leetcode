class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        for(int start = 0; start < len; start += 2*k){
            int left = start; 
            int right = start + k - 1;
            if(right >= len){
                right = len - 1; 
            }
            while(left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            } 
        }
        return s;
    }
};