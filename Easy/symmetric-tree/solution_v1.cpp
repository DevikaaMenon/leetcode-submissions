/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //create a helper function
    bool ismirror(TreeNode* l,TreeNode* r){
        if(!l && !r) return true;
        else if(!l || !r || l->val!=r->val) return false;
        else return ismirror(r->left,l->right) && ismirror(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return ismirror(root->left,root->right);
    }
};