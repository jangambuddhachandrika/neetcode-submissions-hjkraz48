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
    int goodNodes(TreeNode* root) {
        int count = 0;
        if(!root)
        {
            return 0;
        }
        stack<pair<TreeNode*,int>>st;
        st.push({root,root->val});
        while(!st.empty())
        {
            auto[n,maxi]=st.top();
            st.pop();
            if(n->val>=maxi)
            {
                count++;
            }
            maxi = max(n->val,maxi);
            if(n->left)st.push({n->left,maxi});
            if(n->right)st.push({n->right,maxi});
        }
        return count;
        
    }
};
