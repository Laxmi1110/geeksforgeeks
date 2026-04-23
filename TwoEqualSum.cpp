class Solution {
public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        
        // Step 1: total sum
        for(int num : arr) {
            total += num;
        }
        
        // Step 2: check even
        if(total % 2 != 0) return false;
        
        long long prefix = 0;
        
        // Step 3: find prefix = total/2
        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            
            if(prefix == total / 2) {
                return true;
            }
        }
        
        return false;
    }
};
