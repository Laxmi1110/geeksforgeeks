#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();

        // square all elements
        for(int i = 0; i < n; i++){
            arr[i] = arr[i] * arr[i];
        }

        // sort the array
        sort(arr.begin(), arr.end());

        // fix c and find a,b
        for(int i = n-1; i >= 2; i--){
            int left = 0;
            int right = i - 1;

            while(left < right){
                if(arr[left] + arr[right] == arr[i]){
                    return true;
                }
                else if(arr[left] + arr[right] < arr[i]){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return false;
    }
};
