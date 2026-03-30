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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>>qu;
        qu.push({p,q});
        while(!qu.empty())
        {
            auto[n1,n2] = qu.front();
            qu.pop();
            if(!n1&&!n2)
            {
                continue;
            }
            if(!n1||!n2)
            {
                return false;
            }
            if(n1->val != n2->val)
            {
                return false;
            }
            qu.push({n1->left,  n2->left});
            qu.push({n1->right, n2->right});
        }
        return true;
        
    }
};
