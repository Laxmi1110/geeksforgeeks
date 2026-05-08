class Solution {
public:
    
    void solve(string s, int idx, int parts, string curr, vector<string>& ans) {
        
        // If 4 parts are formed and all digits are used
        if(parts == 4 && idx == s.size()) {
            curr.pop_back(); // remove last '.'
            ans.push_back(curr);
            return;
        }
        
        // Invalid cases
        if(parts > 4) return;
        
        for(int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            
            string part = s.substr(idx, len);
            
            // Leading zero check
            if(part.size() > 1 && part[0] == '0')
                continue;
            
            int num = stoi(part);
            
            // Valid IP segment
            if(num >= 0 && num <= 255) {
                solve(s, idx + len, parts + 1,
                      curr + part + ".", ans);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        
        solve(s, 0, 0, "", ans);
        
        return ans;
    }
};
