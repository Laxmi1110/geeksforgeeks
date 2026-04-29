class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: count total 1s
        int k = 0;
        for (int x : arr) {
            if (x == 1) k++;
        }
        
        // Step 2: if no 1s
        if (k == 0) return -1;
        
        // Step 3: count 0s in first window
        int zeroCount = 0;
        for (int i = 0; i < k; i++) {
            if (arr[i] == 0) zeroCount++;
        }
        
        int minSwaps = zeroCount;
        
        // Step 4: sliding window
        for (int i = k; i < n; i++) {
            // remove left element
            if (arr[i - k] == 0) zeroCount--;
            
            // add right element
            if (arr[i] == 0) zeroCount++;
            
            minSwaps = min(minSwaps, zeroCount);
        }
        
        return minSwaps;
    }
};
