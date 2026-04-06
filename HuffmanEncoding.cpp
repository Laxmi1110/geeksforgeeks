

class Solution {
public:
    struct Node {
        int freq;
        char ch;
        Node *left, *right;

        Node(int f, char c) {
            freq = f;
            ch = c;
            left = right = NULL;
        }
    };

    struct cmp {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

    void preorder(Node* root, string code, vector<string>& ans) {
        if (!root) return;

        if (!root->left && !root->right) {
            ans.push_back(code);
        }

        preorder(root->left, code + "0", ans);
        preorder(root->right, code + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f) {
        priority_queue<Node*, vector<Node*>, cmp> pq;

        int N = S.size(); // FIX: calculate N here

        for (int i = 0; i < N; i++) {
            pq.push(new Node(f[i], S[i]));
        }

        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* newNode = new Node(left->freq + right->freq, '$');
            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        Node* root = pq.top();

        vector<string> ans;
        preorder(root, "", ans);

        return ans;
    }
};
