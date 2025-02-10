class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Brute Force
        int len = nums.size();
        map<int,int> mp;
        for(int num:nums){
            if(++mp[num] > len/2){
                return num;
            }
        }
        return -1;
    }
};