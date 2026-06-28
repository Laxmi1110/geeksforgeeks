class Solution:
    def countStrings(self, n: int, k: int) -> int:
        MOD = 10**9 + 7

        # If k >= n, impossible to have that many adjacent 1s
        if k >= n:
            return 0

        # dp[i][j][0/1] = strings of len i, j adjacent 1s, ending with 0/1
        dp = [[[0, 0] for _ in range(k + 1)] for _ in range(n + 1)]

        # Base case: length 1
        dp[1][0][0] = 1 # "0"
        dp[1][0][1] = 1 # "1"

        for i in range(2, n + 1):
            for j in range(k + 1):
                # Append 0: no new adjacent 1s
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD

                # Append 1
                dp[i][j][1] = dp[i-1][j][0] # prev was 0, no new pair
                if j > 0: # prev was 1, create new pair
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][1]) % MOD

        return (dp[n][k][0] + dp[n][k][1]) % MOD
