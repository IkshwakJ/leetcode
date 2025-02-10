class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Kadane
        
        int len = prices.size();
        if(len == 0){
            return 0;
        }
        vector<int> diffs(len,0);      
        diffs[0] = 0;
        for(int i = 1; i < len; i++){
            diffs[i] = prices[i] - prices[i-1];
        }
        int sum = 0; 
        int max = 0;
        for( int i = 0; i < len; i++){
            sum += diffs[i];
            if (sum<0){
                sum = 0;
            }
            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
};