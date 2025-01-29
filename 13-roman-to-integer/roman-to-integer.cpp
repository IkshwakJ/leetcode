enum roman_num{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000,
};

class Solution {
public:
    int romanToInt(string s) {
        input = s;
        len = s.size();
        int sum = 0;
        int temp = 0;
        for (int i = 0; i < len; i++){
            switch(sub_string_link (s[i], i)){
                case 0:
                    temp = temp + getRomanValue(s[i]);
                    break;
                case 1:
                    sum = sum + temp + getRomanValue(s[i]);
                    temp = 0;
                    break;
                case -1:
                    sum = sum - temp - getRomanValue(s[i]);
                    temp = 0;
                    break;
            }
        }
        return sum;
    }
private:
    string input;
    int len;
    int getRomanValue(char c) {
        switch (c) {
            case 'I': return I;
            case 'V': return V;
            case 'X': return X;
            case 'L': return L;
            case 'C': return C;
            case 'D': return D;
            case 'M': return M;
            default: return -1; 
        }
    }
    int sub_string_link (char c, int pos)
    {
        int curr_val = getRomanValue(c);
        int next_val = -1;
    
        if(pos != len-1){
                next_val = getRomanValue(input[pos+1]);
        }
        if (curr_val > next_val)
            return 1; // 1 stands for add to the rest. Empy the temp value in the same manner.
        else if (curr_val ==  next_val)
            return 0; // 0 stands for add to temp value 
        else
            return -1;  // -1 stands for subtract from the next value. Empy the temp value in the same manner.

    }
};
