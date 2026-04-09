class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> result;

        while (i < a.size() && j < b.size()) {
            
            // Skip duplicates in a
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            
            // Skip duplicates in b
            if (j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }

            if (a[i] == b[j]) {
                result.push_back(a[i]);
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return result;
    }
};
