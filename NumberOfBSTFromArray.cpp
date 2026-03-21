class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();

        // Precompute Catalan numbers up to n
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        if (n >= 1) catalan[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        vector<int> result;

        for (int i = 0; i < n; i++) {
            int root = arr[i];
            int L = 0, R = 0;

            for (int j = 0; j < n; j++) {
                if (arr[j] < root) L++;
                else if (arr[j] > root) R++;
            }

            result.push_back(catalan[L] * catalan[R]);
        }

        return result;
    }
};
