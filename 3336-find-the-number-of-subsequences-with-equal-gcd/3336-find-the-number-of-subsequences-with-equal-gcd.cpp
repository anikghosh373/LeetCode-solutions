class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1000000007;
        int m = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<int>> newDp(m + 1, vector<int>(m + 1, 0));

            for (int g1 = 0; g1 <= m; g1++) {
                int nextGcd1 = gcd(g1, num);

                for (int g2 = 0; g2 <= m; g2++) {
                    int ways = dp[g1][g2];

                    if (ways == 0) {
                        continue;
                    }

                    int nextGcd2 = gcd(g2, num);

                    newDp[g1][g2] = (newDp[g1][g2] + ways) % MOD;
                    newDp[nextGcd1][g2] = (newDp[nextGcd1][g2] + ways) % MOD;
                    newDp[g1][nextGcd2] = (newDp[g1][nextGcd2] + ways) % MOD;
                }
            }

            dp = move(newDp);
        }

        int ans = 0;

        for (int g = 1; g <= m; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};