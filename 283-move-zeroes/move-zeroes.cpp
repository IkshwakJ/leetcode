class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0; 
        int next = 1;
        int len = nums.size();
        while(next < len && curr < len){
            if(nums[curr] == 0 && nums[next] != 0){
                nums[curr] = nums[next];
                nums[next] = 0;
            }
            while(next < len && nums[next] == 0){
                next++;
            }
            while(curr < len && nums[curr] != 0){
                next = 1 + ++curr;
            }
        }
    }
};