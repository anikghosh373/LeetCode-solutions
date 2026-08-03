class Solution {
public:
    int n;
    vector<int> t;

    int solve(int n, int i, vector<int>& nums) {

        if (i >= n)
            return 0;

        if (t[i] != -1)
            return t[i];

        int result = nums[i] - solve(n, i + 1, nums);

        if (i + 1 < n) {
            result = max(result,
                         nums[i] + nums[i + 1] - solve(n, i + 2, nums));
        }

        if (i + 2 < n) {
            result = max(result,
                         nums[i] + nums[i + 1] + nums[i + 2] -
                         solve(n, i + 3, nums));
        }

        return t[i] = result;
    }

    string stoneGameIII(vector<int>& nums) {

        n = nums.size();
        t.assign(n + 1, -1);

        int ans = solve(n, 0, nums);

        if (ans > 0)
            return "Alice";
        else if (ans == 0)
            return "Tie";
        else
            return "Bob";
    }
};