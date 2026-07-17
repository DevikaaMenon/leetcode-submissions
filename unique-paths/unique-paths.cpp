class Solution {
public:
    int uniquePaths(int m, int n) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long ans = 1;
        int totalMoves = m + n - 2;
        int r = min(m - 1, n - 1); 
        
        // Calculate Combination (nCr) in O(min(m, n)) time and O(1) space
        for (int i = 1; i <= r; i++) {
            ans = ans * (totalMoves - r + i) / i;
        }
        
        return (int)ans;
    }
};