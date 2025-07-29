class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            char c1 = tolower(s[left]);
            char c2 = tolower(s[right]);

            if (c1 != 'a' && c1 != 'e' && c1 != 'i' && c1 != 'o' && c1 != 'u') {
                left++;
                continue;
            }

            if (c2 != 'a' && c2 != 'e' && c2 != 'i' && c2 != 'o' && c2 != 'u') {
                right--;
                continue;
            }

            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};
