class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_1(nums1.begin(), nums1.end());
        vector<int>result;
        for(int num: nums2){
            if(set_1.count(num)>0){
                result.push_back(num);
                set_1.erase(num);
            }
        }
        return result;
    }
};