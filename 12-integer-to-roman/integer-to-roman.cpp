class Solution {
public:
    string intToRoman(int num) {
        string ri[4][10] ={
                    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
                    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                    {"", "M", "MM", "MMM"}
        };
        return (ri[3][num/1000] + ri[2][(num%1000)/100] + ri[1][(num%100)/10] + ri[0][(num%10)]);
    }
};