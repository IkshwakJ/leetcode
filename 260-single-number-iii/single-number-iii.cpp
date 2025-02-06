class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();    
        long both = 0, rightmost;
        for(int i = 0; i<len; i++){
            both ^= nums[i]; // at the end of the loop it will be equal to the XOR of the unrepeated numbers. 
        }
        vector<int> set (2,0);
        rightmost = (both&(both-1))^(both);// This gives the rightmost set bit.
        for(int i = 0; i<len; i++){
            if(nums[i]&rightmost)
                set[0] ^= nums[i]; // at the end of the loop it will have just the lower unrepeated number. 
        }
        set[1] = both^set[0];
        return set;
    }
};