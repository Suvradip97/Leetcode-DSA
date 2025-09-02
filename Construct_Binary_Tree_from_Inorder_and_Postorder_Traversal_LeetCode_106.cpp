

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// LeetCode Medium




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

    TreeNode* func(vector<int>& postorder, int postStart, int postEnd, 
vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
        if(inStart > inEnd || postEnd < postStart) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int elem = inMap[postorder[postEnd]];
        int nElem = elem - inStart;
        root->left = func(postorder, postStart, postStart + nElem - 1, inorder, inStart, elem - 1, inMap);
        root->right = func(postorder, postStart + nElem, postEnd-1, inorder, elem + 1, inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        int postStart = 0, postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = func(postorder, postStart, postEnd, inorder, inStart, inEnd, inMap);
        return root;
    }
};