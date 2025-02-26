class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0){
            return {-1,-1};
        }
        int left = findFirst(nums, target, len);
        if(left == -1){
            return {-1,-1};
        }
        return {left, findLast(nums, target, len)};

    }
private: 
    int findFirst(vector<int>& nums, int target, int len){
        int left = 0;
        int right = len - 1; 
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(left < len && nums[left] == target){
            return left;
        }
        return -1;
    }
    int findLast(vector<int>& nums, int target, int len){
        int left = 0;
        int right = len - 1; 
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(right >= 0 && nums[right] == target){
            return right;
        }
        return -1;
    }
};