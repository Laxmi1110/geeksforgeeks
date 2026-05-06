class Solution {
public:
    int getSize(Node* root) {
        if (!root) return 0;

        queue<Node*> q;
        q.push(root);
        int count = 0;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            count++;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return count;
    }
};
