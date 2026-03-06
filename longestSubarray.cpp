#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int totalElements(vector<int> &arr) {
        
        unordered_map<int,int> freq;
        int start = 0;
        int maxLen = 0;

        for(int end = 0; end < arr.size(); end++) {

            freq[arr[end]]++;

            while(freq.size() > 2) {

                freq[arr[start]]--;

                if(freq[arr[start]] == 0)
                    freq.erase(arr[start]);

                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
