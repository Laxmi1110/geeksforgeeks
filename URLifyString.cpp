class Solution {
public:
    string URLify(string str) {
        string result = "";
        
        for(char c : str) {
            if(c == ' ')
                result += "%20";
            else
                result += c;
        }
        
        return result;
    }
};
