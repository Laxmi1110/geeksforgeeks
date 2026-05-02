class Solution {
  public:
    int findPosition(int n) {
        // Step 1: Check if n is zero
        if (n == 0) return -1;
        
        // Step 2: Check if more than one set bit
        if ((n & (n - 1)) != 0) return -1;
        
        // Step 3: Find position
        int pos = 1;
        while (n > 1) {
            n = n >> 1;
            pos++;
        }
        
        return pos;
    }
};
