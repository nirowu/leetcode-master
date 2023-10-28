class Solution {
public:
    int next[10005] ;
    void getNext(string src){
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < src.size(); i++) {
            while (j > 0 && src[i] != src[j]) {
                j = next[j-1];
            }
            if (src[i] == src[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0 ) {
            return 0;
        }
        getNext(needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            if (haystack[i] == needle[j]){
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1 );
            }
            
        }
        return -1;
    }
};