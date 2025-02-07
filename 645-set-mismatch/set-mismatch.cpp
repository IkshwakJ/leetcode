class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int miss_and_rep = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            miss_and_rep ^= nums[i - 1] ^ i;
        }
        // At this point miss_and_rep is the XOR of the missing and the repeated
        // number
        int rightbit = (miss_and_rep & (miss_and_rep - 1)) ^ miss_and_rep;
        int miss = 0;
        int in_input = 1;
        for (int i = 1; i <= n; i++) {
            if (i&rightbit){
                miss ^= i;
                in_input--;
            }
            if (nums[i-1]&rightbit){
                miss ^= nums[i-1];
                in_input++;
            }
        }
        if(in_input){
            // This is the case where the missing value was considered as the repeated one.
            miss =  miss_and_rep^miss;
        }
        int rep = miss_and_rep^miss;
        return {rep, miss};
    }
};