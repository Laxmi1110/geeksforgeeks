class Solution {
public:
    int countStrings(int n) {
        if (n == 1) return 2;
        
        int a = 1, b = 1;  // a = ending with 0, b = ending with 1
        
        for (int i = 2; i <= n; i++) {
            int newA = a + b;
            int newB = a;
            
            a = newA;
            b = newB;
        }
        
        return a + b;
    }
};
