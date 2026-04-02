class Solution {
public:
    int countWays(int n, int k) {
        if (n == 1) return k;
        
        int same = 0;
        int diff = k;   // for first post
        
        for (int i = 2; i <= n; i++) {
            int new_same = diff;
            int new_diff = (same + diff) * (k - 1);
            
            same = new_same;
            diff = new_diff;
        }
        
        return same + diff;
    }
};
