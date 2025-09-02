


// 2385. Amount of Time for Binary Tree to Be Infected
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
private:
    TreeNode* findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp, int start){
        queue<TreeNode*> q;
        TreeNode* target;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) target = node;
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return target;
    }

    int infectionTime(TreeNode* target, unordered_map<TreeNode*, TreeNode*> &mpp){
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        vis[target] = true;
        q.push(target);
        cout << target->val << endl;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            cout << size << endl;
            bool flag = false;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(mpp[node] and !vis[mpp[node]]){
                    flag = true;
                    q.push(mpp[node]);
                    vis[mpp[node]] = true;
                }
                if(node->left and !vis[node->left]){
                    flag = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right and !vis[node->right]){
                    flag = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }
            }
            if(flag == true) time++;
        }
        return time;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = findParent(root, mpp, start);
        return infectionTime(target, mpp);
    }
};