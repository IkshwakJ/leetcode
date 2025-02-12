class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0; 
        int len = nums.size();

        for(int next = 0; next < len; next++){
            if(nums[next] != 0){
                swap(nums[next],nums[curr]);
                curr++; // as long as the number is non-zero the pointer to curr will increase
                // if a zero number is encountered 
                // all the indexes to till the next nonzero has to be swapped with the ones after the first nonzero.
            }
        }
    }
};