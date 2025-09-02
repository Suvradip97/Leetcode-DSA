

// DP on Trees

// At every node i maintain a value of pick and not pick and 
// return the maximum of it.
// pair<int, int> denotes {pick, not pick} of that node

/*
337. House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


*/


// Memoization

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> helper(TreeNode* node) {
        if (!node)
            return {0, 0};
        pair<int, int> leftSide = helper(node->left);
        pair<int, int> rightSide = helper(node->right);
        int pick = node->val + leftSide.second + rightSide.second;
        int notPick = max(leftSide.first, leftSide.second) +
                      max(rightSide.first, rightSide.second);
        return {pick, notPick};
    }

    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if (root and !root->left and !root->right)
            return root->val;
        pair<int, int> ans = helper(root);
        int result = max(ans.first, ans.second);
        return result;
    }
};