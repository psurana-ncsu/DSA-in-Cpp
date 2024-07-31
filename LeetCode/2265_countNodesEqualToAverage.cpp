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
    int ans=0;
    pair<int, int> recurse(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            ans++;
            return {node->val, 1};
        }
        pair<int, int> left(0,0);
        pair<int, int> right(0,0);
        if(node->left){
            left=recurse(node->left);
        }
        if(node->right){
            right=recurse(node->right);
        }
        int sm = node->val+left.first+right.first;
        int ct=1+left.second+right.second;
        int avg =sm/(ct);
        if(avg==node->val){
            ans++;
        }
        return {sm, ct};

    }
    int averageOfSubtree(TreeNode* root) {
        recurse(root);
        return ans;
    }
};
