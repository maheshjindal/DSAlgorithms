// Construct Binary tree from inorder and preorder
#include<iostream>
using namespace std;

class Solution {
public:
    TreeNode* solve(int prestart, int instart, int inend, vector<int>& preorder, vector<int>& inorder) {
        if(prestart > preorder.size()-1 || instart > inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int index = 0;
        for(int i = instart; i <= inend; i++)
            if(root->val == inorder[i]) index = i;
            
        root->left = solve(prestart+1, instart, index-1, preorder, inorder);
        root->right = solve(prestart+index-instart+1, index+1, inend, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return solve(0, 0, inorder.size()-1, preorder, inorder);
    }
};