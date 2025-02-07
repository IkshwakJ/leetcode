class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0; 
        int fast = 0;
        // This loop will result in finding the index at which we have a loop in the input numbers.
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};