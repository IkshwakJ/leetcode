class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Kadane
        
        int len = prices.size();
        if(len == 0){
            return 0;
        }
        int sum = 0; 
        int max = 0;
        for( int i = 1; i < len; i++){
            sum += prices[i]- prices[i-1];
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