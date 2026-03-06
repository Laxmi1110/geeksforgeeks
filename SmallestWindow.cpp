#include <stdio.h>
#include <string.h>
#include <limits.h>

char* smallestWindow(char *s, char *p) {

    int lenS = strlen(s);
    int lenP = strlen(p);

    if(lenP > lenS)
        return "";

    int hash_pat[256] = {0};
    int hash_str[256] = {0};

    for(int i = 0; i < lenP; i++)
        hash_pat[p[i]]++;

    int start = 0, start_index = -1;
    int min_len = INT_MAX;
    int count = 0;

    for(int j = 0; j < lenS; j++) {

        hash_str[s[j]]++;

        if(hash_pat[s[j]] != 0 && hash_str[s[j]] <= hash_pat[s[j]])
            count++;

        if(count == lenP) {

            while(hash_str[s[start]] > hash_pat[s[start]] || hash_pat[s[start]] == 0) {

                if(hash_str[s[start]] > hash_pat[s[start]])
                    hash_str[s[start]]--;

                start++;
            }

            int window_len = j - start + 1;

            if(window_len < min_len) {
                min_len = window_len;
                start_index = start;
            }
        }
    }

    if(start_index == -1)
        return "";

    static char ans[100000];
    strncpy(ans, s + start_index, min_len);
    ans[min_len] = '\0';

    return ans;
}
