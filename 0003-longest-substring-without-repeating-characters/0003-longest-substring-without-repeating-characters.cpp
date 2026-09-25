
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            // If duplicate exists, remove from the left
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

