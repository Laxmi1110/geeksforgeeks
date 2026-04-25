class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;

        for (int x : arr) {
            bool alive = true;

            while (!st.empty() && (st.back() > 0 && x < 0)) {
                int top = st.back();

                if (abs(top) == abs(x)) {
                    st.pop_back();
                    alive = false;
                    break;
                }
                else if (abs(top) > abs(x)) {
                    alive = false;
                    break;
                }
                else {
                    st.pop_back();
                }
            }

            if (alive) {
                st.push_back(x);
            }
        }

        return st;
    }
};
