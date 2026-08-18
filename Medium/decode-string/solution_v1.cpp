class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;

        string curr = "";
        int num = 0;

        for (char c : s) {

            // Build multi-digit number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Start of a new nested string
            else if (c == '[') {
                st.push({curr, num});
                curr = "";
                num = 0;
            }

            // End of current nested string
            else if (c == ']') {
                auto [prev, repeat] = st.top();
                st.pop();

                string temp = prev;

                while (repeat--) {
                    temp += curr;
                }

                curr = temp;
            }

            // Normal character
            else {
                curr += c;
            }
        }

        return curr;
    }
};