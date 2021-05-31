/**
*
*Given the root of a binary tree, flatten the tree into a "linked list":
*
*The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
*The "linked list" should be in the same order as a pre-order traversal of the binary tree.
**/

#include<iostream>
#include<vector>
#include "../Utils/IOUtils.cpp"

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FlattenTreeHelper{
public:
	void flatten(TreeNode * root) {
      if (root == NULL || 
          (root -> left == NULL && root -> right == NULL))
        return;
      
      if (root -> left != NULL) {
        // flatten the left subtree
        flatten(root -> left);
        // store the right node subtree
        TreeNode * tempRightNode = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
        
        // Go to the end of right path
        TreeNode * newRightNode = root -> right;
        while (newRightNode -> right != NULL)
          newRightNode = newRightNode -> right;
        // add the temp right node at the end
        newRightNode -> right = tempRightNode;
      }
      // flatten the right path
      flatten(root -> right);
    }
};

int main(){

	// ioutils::enableFastIO();

	TreeNode* treeNode = new TreeNode(1);
	FlattenTreeHelper* flattenTreeHelper = new FlattenTreeHelper();
	flattenTreeHelper -> flatten(treeNode);
	return 0;
}