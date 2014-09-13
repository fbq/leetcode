// vim: sw=4:sts=4:et:ts=4:sta:si
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
        /* 
         * @id: the current symmetic center of a palindrome substring with the most left tail.
         * @mx: the tail of id
         * for each i in the loop, if i < mx, then p[i] is at least min(p[id - (i - id)], mx - i)
         */
        int id = 0;
        int mx = 0;
 
        for (int i = 0; i < len; i++) {
            int j;
            if (i < mx) {
                j = min(p[id - (i - id)], mx - i);
            }
            else
                j = 1;
            while (i - j >= 0 && i + j < len) {
                if (str[i-j] == str[i+j]) {
                    j++;
                }
                else
                    break;
            }
            p[i] = j-1;
            if (i + p[i] > mx) {
                id = i;
                mx = i + p[i];
            }
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
