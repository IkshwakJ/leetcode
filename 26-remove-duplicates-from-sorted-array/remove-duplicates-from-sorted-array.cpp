class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int cnt = 0; 
        for(int i = 1; i<(len-cnt); i++){
            while(nums[i] == nums[i-1]){
                cnt++;
                nums.erase(nums.begin() + i);
                if(i >=(len-cnt)){
                    return len-cnt;
                }           
            }
        } 
        return len - cnt;   
    }
};