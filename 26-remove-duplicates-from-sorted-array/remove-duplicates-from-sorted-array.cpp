class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        int j = 0;  
        for(i = 1, j = 0; i<len; i++, j++){
            while(i<len && nums[i] == nums[j]){
                i++;
            }
            if(i<len && i != j){
                nums[j+1] = nums[i];
            }
        }
        return len + j - i + 1;
    }
};