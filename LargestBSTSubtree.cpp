class Solution {
public:
    struct NodeInfo {
        int size;
        int minVal;
        int maxVal;
        bool isBST;
    };
    
    int maxSize = 0;
    
    NodeInfo solve(Node* root) {
        // Base case
        if (!root) {
            return {0, INT_MAX, INT_MIN, true};
        }
        
        // Left and Right
        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);
        
        NodeInfo curr;
        
        // Check BST condition
        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {
            
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            curr.isBST = true;
            
            maxSize = max(maxSize, curr.size);
        } else {
            curr.isBST = false;
            curr.size = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        solve(root);
        return maxSize;
    }
};
