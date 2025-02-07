class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int bits_count[32] = {0};
    int result = 0;
    int n = nums.size() - 1;
    for (int bit = 0; bit<32; bit++){
        int mask = 1<<bit;
            for(int i = 1; i <= n; i++){
                if(i&mask)
                    bits_count[bit]--;
            }
            for(int num: nums){
                if(num&mask)
                    bits_count[bit]++;
            }
            if (bits_count[bit] > 0)
                result |= mask;
    }
    return result;
    }
};