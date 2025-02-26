class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0){
            return {-1,-1};
        }
        vector<int> pos{-1,-1};
        int left = 0; 
        int right = len - 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                left = mid; 
                right = mid;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(left != right || nums[left] != target){
            return {-1,-1};
        }
        while(right < len && nums[right] == target){
            right++;
        }
        right--;
        while(left >= 0 && nums[left] == target){
            left--;
        }
        left++;
        return {left,right};
    }
};