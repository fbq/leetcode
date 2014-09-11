/*
 * Longest Palindromic Substring
 *
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int p[2001];
        char str[2001];
        char out[1001];
        int len = s.length();
        for (int i = 0; i < len; i++) {
            p[2*i] = 0;
            p[2*i+1] = 0;
            str[2 * i] = 0;
            str[2 * i + 1] = s[i];
        }
        str[2*len] = 0;
        p[2*len] = 0;
        len = 2 * len + 1;
    
        int center = longestPalindromeCenter(str, p, len);
        int radix = p[center];

        return s.substr(center/2 - radix/2, radix);

        
    }
    
    int longestPalindromeCenter(char* str, int* p, int len) {
        int i = 0;
        while (i < len) {
            int j = p[i] + 1;
            while (i - j >= 0 && i + j < len) {
                if (str[i-j] == str[i+j]) {
                    j++;
                }
                else
                    break;
            }
            p[i] = j-1;
            for (int k = 1; k < j; k++) {
                int Min = min(p[i-k], j-k-1);
                p[i+k] = max(p[i+k], Min);
            }
            i++;
        }
        int maxR = 0;
        int index = 0;
        for (int i = 0 ; i < len; i++) {
            if (p[i] > maxR) {
                index = i;
                maxR = p[i];
            }
            
        }
        return index;
        
    }
    
};
