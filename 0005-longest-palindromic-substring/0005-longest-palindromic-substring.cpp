class Solution {
public:
    string longestPalindrome(string s) {
        int ml = 0;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {

                int left = i, right = j;
                bool ok = true;

                while (left < right) {
                    if (s[left] != s[right]) {
                        ok = false;
                        break;
                    }
                    left++;
                    right--;
                }

                if (ok && (j - i + 1 > ml)) {
                    ml = j - i + 1;
                    ans = s.substr(i, ml);
                }
            }
        }

        return ans;
    }
};