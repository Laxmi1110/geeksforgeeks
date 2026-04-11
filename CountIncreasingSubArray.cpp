class Solution {
public:
    int countIncreasing(vector<int>& arr) {  
        int n = arr.size();
        int count = 0;
        int len = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                len++;
                count += (len - 1);
            } else {
                len = 1;
            }
        }
        
        return count;
    }
};
