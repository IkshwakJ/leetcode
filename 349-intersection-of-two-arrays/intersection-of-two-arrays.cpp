class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> result_set;
        if(nums1.size() > nums2.size()){
            for(int num1 : nums1){
                for(int num2 : nums2){
                    if(num1 == num2){
                        result_set.insert(num1);
                    }
                }
            }
        }
        else{
            for(int num2: nums2){
                for(int num1 : nums1){
                    if(num1 == num2){
                        result_set.insert(num1);
                    }
                }
            }
        }
        vector<int> result;
        for(int num: result_set){
            result.push_back(num);
        }
        return result;
    }
};