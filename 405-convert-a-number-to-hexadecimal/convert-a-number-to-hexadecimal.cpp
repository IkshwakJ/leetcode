class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        string result = "";
        map<int, char> hex_vals {{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'},{10,'a'},{11,'b'},{12,'c'},{13,'d'},{14,'e'},{15,'f'}};
        result += hex_vals[(num&0xf0000000)>>28];
        result += hex_vals[(num&0x0f000000)>>24];
        result += hex_vals[(num&0x00f00000)>>20];
        result += hex_vals[(num&0x000f0000)>>16];
        result += hex_vals[(num&0x0000f000)>>12];
        result += hex_vals[(num&0x00000f00)>>8];
        result += hex_vals[(num&0x000000f0)>>4];
        result += hex_vals[(num&0x0000000f)];
        while(result[0] == '0'){
           result.erase(0,1); 
        }
        return result;
    }
};