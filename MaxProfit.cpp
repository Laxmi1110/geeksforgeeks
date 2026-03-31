class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        
        int buy = -arr[0];  // holding stock
        int sell = 0;       // not holding
        
        for(int i = 1; i < n; i++) {
            int prevBuy = buy;
            
            buy = max(buy, sell - arr[i]);
            sell = max(sell, prevBuy + arr[i] - k);
        }
        
        return sell;
    }
};
