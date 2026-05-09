class Solution {
  public:
    
    // Function to calculate determinant
    long long determinant(vector<vector<double>> mat, int n) {
        double det = 1;

        for (int i = 0; i < n; i++) {

            int pivot = i;

            // Find pivot row
            for (int j = i; j < n; j++) {
                if (abs(mat[j][i]) > abs(mat[pivot][i])) {
                    pivot = j;
                }
            }

            // If pivot is 0
            if (abs(mat[pivot][i]) < 1e-9)
                return 0;

            // Swap rows
            if (i != pivot) {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            det *= mat[i][i];

            // Elimination
            for (int j = i + 1; j < n; j++) {

                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {

        if (n == 1)
            return 1;

        // Laplacian Matrix
        vector<vector<double>> lap(n, vector<double>(n, 0));

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        // Create cofactor matrix
        vector<vector<double>> cofactor(n - 1,
                                        vector<double>(n - 1));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                cofactor[i - 1][j - 1] = lap[i][j];
            }
        }

        // Determinant gives spanning trees count
        return determinant(cofactor, n - 1);
    }
};
