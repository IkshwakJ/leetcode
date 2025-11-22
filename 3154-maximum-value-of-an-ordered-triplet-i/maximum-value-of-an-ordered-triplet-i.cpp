class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int len = nums.size();
        if(len <3){
            return 0; 
        }
        long long sum = 0;
        for(int k = 2; k < len; k++){
            for(int j = 1; j < k; j++){
                for(int i = 0; i < j; i++){
                    if(sum < (((long long)nums[i] - (long long)nums[j])*(long long)nums[k])){
                        sum = ((long long)nums[i] - (long long)nums[j])*(long long)nums[k];
                    }
                }
            }
        }
        return sum;
    }
};