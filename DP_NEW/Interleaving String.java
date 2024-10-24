class Solution {
    int n, m, N;
    Boolean[][] memo;

    private boolean solve(String s1, String s2, String s3, int i, int j, int k) {
        // Base Case
        if (i == n && j == m && k == N) {
            return true;
        }

        // Return if we exceed the length of s3
        if (k >= N) {
            return false;
        }

        // Check the memo table
        if (memo[i][j] != null) {
            return memo[i][j];
        }

        boolean res = false;

        // Choose a character from s1 if it matches with s3
        if (i < n && s1.charAt(i) == s3.charAt(k)) {
            res = solve(s1, s2, s3, i + 1, j, k + 1);
        }

        // Choose a character from s2 if it matches with s3
        if (j < m && s2.charAt(j) == s3.charAt(k)) {
            res = res || solve(s1, s2, s3, i, j + 1, k + 1);
        }

        // Store result in memo table and return it
        return memo[i][j] = res;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        n = s1.length();
        m = s2.length();
        N = s3.length();

        // Early return if lengths don't match
        if (n + m != N) {
            return false;
        }

        // Initialize memoization table
        memo = new Boolean[n + 1][m + 1];

        return solve(s1, s2, s3, 0, 0, 0);
    }
}
