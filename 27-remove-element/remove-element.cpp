class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;
        int j = 0;  
        for(i = 0, j = 0; i<len; i++, j++){
            while(i<len && nums[i] == val){
                i++;
            }
            if(i<len && i != j){
                nums[j] = nums[i];
            }
        }
        return len + j - i;
    }
};