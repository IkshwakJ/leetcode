class Solution {
public:
    bool hasAlternatingBits(int N) {
        long n = N;
        n = (n^(n<<2));
        n = n>>2;
        n = (n&(n-1));
        if (n == 0){
            return true;
        }
        return false;  
    }
};