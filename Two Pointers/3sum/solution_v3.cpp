class Solution {
public:
    vector<vector<int>> res;

    void twosum(vector<int>& nums, int t, int i, int j) {
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == t) {
                res.push_back({-t, nums[i], nums[j]});
                int li = nums[i], rj = nums[j];
                i++; j--;
                while (i < j && nums[i] == li) i++;
                while (i < j && nums[j] == rj) j--;
            } else if (sum > t) {
                j--;
            } else {
                i++;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // fix 1
            int t = -nums[i];
            twosum(nums, t, i + 1, n - 1);                   // fix 2: no pre-dedup
        }
        return res;
    }
};