class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int s = -1, e = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                s = mid;
                break;          // stop once found
            }
            else if (target > nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (s == -1)
            return {-1, -1};

        // Find first occurrence
        while (s > 0 && nums[s - 1] == target)
            s--;

        // Find last occurrence
        e = s;
        while (e + 1 < nums.size() && nums[e + 1] == target)
            e++;

        return {s, e};
    }
};