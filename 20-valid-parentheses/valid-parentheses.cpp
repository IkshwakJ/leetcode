class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len%2 != 0)
            return false;
        vector<char> brackets; 
        for(int i = 0; i < len; i++){
            switch (s[i]){
                case '(':
                    brackets.push_back('(');
                    break;
                case '{':
                    brackets.push_back('{');
                    break;
                case '[':
                    brackets.push_back('[');
                    break;
                case ')':
                    if(brackets.size() == 0 || brackets.back() != '(')
                        return false;
                    else
                        brackets.pop_back();
                    break;
                case '}':
                    if(brackets.size() == 0 || brackets.back() != '{')
                        return false;
                    else
                        brackets.pop_back();
                    break;
                case ']':
                    if(brackets.size() == 0 || brackets.back() != '[')
                        return false;
                    else
                        brackets.pop_back();
                    break;
                
            }
        }

        return (brackets.size()==0)?true:false;
    }
};