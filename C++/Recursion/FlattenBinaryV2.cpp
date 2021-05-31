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
    void flatten(TreeNode* root) {

    	int* preorderData = new int[2000];
    	int k = 0;
    	preOrder(root,preorderData,k);
    	nullifyTree(root);
        root = new TreeNode(preorderData[0]);
    	populateTree(root, preorderData, 1, k);
    }
    void populateTree(TreeNode* root,int* preOrder ,int index, int maxIndex){
    	if(index == maxIndex)
    		return;
        root->left = NULL;
        root->right = new TreeNode(preOrder[index]);
    	populateTree(root->right, preOrder, index+1, maxIndex);
    }

    void nullifyTree(TreeNode* root){
    	if(root == NULL)
    		return;

    	nullifyTree(root->left);

    	if(root->left)
    		root->left = NULL;
    		delete root->left;

    	nullifyTree(root->right);

    	if(root->right)
    		root->right = NULL;
    		delete root->right;
    }
    void preOrder(TreeNode* root, int* preorder, int& k){
    	if(root == NULL){
    		return;
    	}
    	preorder[k++] = root->val;
    	preOrder(root->left,preorder,k);
    	preOrder(root->right,preorder,k);
    }


    public void flatten(TreeNode* root){
    	if(root == NULL || (root->left == NULL && root->right == NULL)){
    		return;
    	}
    	if(root->left != NULL){
    		flatten(root->left);
    		TreeNode* tempRightNode = root->right;
    		root->right = root->left;
    		root->left = NULL:
    		TreeNode* newRightNode = root->right;
    		while(newRightNode->right != NULL)
    			newRightNode = newRightNode->right;

    		newRightNode->right = tempRightNode;
    	}
    	flatten(root->right);
    }
};

int main(){

	// ioutils::enableFastIO();

	TreeNode* treeNode = new TreeNode(1);
	FlattenTreeHelper* flattenTreeHelper = new FlattenTreeHelper();
	flattenTreeHelper -> flatten(treeNode);
	return 0;
}