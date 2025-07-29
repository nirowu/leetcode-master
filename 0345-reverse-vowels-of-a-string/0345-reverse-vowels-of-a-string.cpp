class Solution {
public:
    string reverseVowels(string s) {
        string tmp = "";
        for (auto c: s) {
            char lower_c = tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || \
            lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                tmp+= c;
            }
        }
        int idx = tmp.size()-1;
        for (auto &c: s) {
            char lower_c = tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || \
            lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                c = tmp[idx--];
            }
        }
        return s;
    }
};