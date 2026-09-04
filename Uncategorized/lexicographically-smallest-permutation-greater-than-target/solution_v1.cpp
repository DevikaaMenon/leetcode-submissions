class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        // Keep matching target as long as possible
        for (int i = 0; i < n; i++) {

            // Try making the answer GREATER at this position
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string candidate = target.substr(0, i);

                    candidate += char('a' + c);

                    freq[c]--;

                    // Put all remaining characters
                    // in smallest possible order
                    for (int x = 0; x < 26; x++) {
                        candidate += string(freq[x], 'a' + x);
                    }

                    freq[c]++;

                    // Since we're going further to the right,
                    // this candidate is smaller than previous ones
                    ans = candidate;
                    break;
                }
            }

            // Now try to keep the prefix equal to target
            int same = target[i] - 'a';

            if (freq[same] == 0) {
                break;
            }

            freq[same]--;
        }

        return ans;
    }
};