class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* 
            Moore's Voting Algorithm
            We consider count of votes to be 0.
            (The first number will automatically get a vote)
            When we encounter the same number as the majority we increment the count.
            Otherwise we decrement it. 
            When the count becomes 0, we place the next number as the majority and continue.
            This works only becasue the majority is always more than half the lenght of the array.

        */
        int majority, count = 0;
        for(int num : nums){
            if (count == 0){
                majority = num;
                count++;
            }
            else{
                if (num == majority){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return majority;
    }
};