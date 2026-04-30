class Solution {
public:
    bool isMaxHeap(vector<int>& arr) {
        int n = arr.size();

        // Only need to check non-leaf nodes
        for (int i = 0; i <= (n - 2) / 2; i++) {
            
            // left child
            if (arr[i] < arr[2*i + 1])
                return false;
            
            // right child (check exists)
            if (2*i + 2 < n && arr[i] < arr[2*i + 2])
                return false;
        }

        return true;
    }
};
