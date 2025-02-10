class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int index = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (mp[nums[i]] != 0) {
                if (i + 1 - mp[nums[i]] <= k) {
                    return true;
                } 
                else {
                    mp[nums[i]] = i + 1;
                }
            } else {
                mp[nums[i]] = i + 1;
            }
        }
        return false;
    }
};