class Solution {
public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<long long> prefix(n);
        vector<int> result;

        // Build prefix sum
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        // Process queries
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum;
            if(l == 0) sum = prefix[r];
            else sum = prefix[r] - prefix[l - 1];

            int len = r - l + 1;
            result.push_back(sum / len); // floor automatically
        }

        return result;
    }
};
