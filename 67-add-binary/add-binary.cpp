class Solution {
public:
    string addBinary(string a, string b) {

        int len_a = a.size() - 1, len_b = b.size() - 1, i = len_a, j = len_b;
        int transfer = 0;
        string c = "";
        char x;
        while (i >= 0 || j >=0 || transfer == 1){
            if(i >= 0){
                transfer += a[i] - '0'; // The ascii value of a[i] - the ascii value of '0'
                                        // 0 if a[i] is 0 otherwise 1 
                i--;          
            }
            if(j >= 0){
                transfer += b[j] - '0'; // The ascii value of a[i] - the ascii value of '0'
                                        // 0 if a[i] is 0 otherwise 1 
                j--;          
            }
            // At this point transfer can have the values of 0, 1, or 2
            x = transfer%2 + '0';
            c =  x + c;
            transfer /= 2;
        }
        return c;
    }
};