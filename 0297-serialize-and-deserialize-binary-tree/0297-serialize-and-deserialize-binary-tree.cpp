/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false) {
            TreeNode* src = q.front();
            q.pop();

            if (src == NULL) {
                s += "#,";
            } else {
                s += to_string(src->val) + ",";
                q.push(src->left);
                q.push(src->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        queue<TreeNode*> q;

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while (q.empty() == false) {
            TreeNode* src = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#") {
                src->left = new TreeNode(stoi(str));
                q.push(src->left);
            } else {
                src->left = NULL;
            }
            getline(s, str, ',');
            if (str != "#") {
                src->right =  new TreeNode(stoi(str));
                q.push(src->right);
            } else {
                src->right = NULL;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));