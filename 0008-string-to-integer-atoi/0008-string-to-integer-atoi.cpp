
class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Step 1: Ignore leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Step 3: Convert digits
        long long num = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Check overflow
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > INT_MAX % 10)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};

