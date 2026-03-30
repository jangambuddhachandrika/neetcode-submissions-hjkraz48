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
    int maxPathSum(TreeNode* root) {
         if(!root) return 0;

        int maxSum = INT_MIN;

        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> gain; // stores max gain from node
        TreeNode* lastVisited = nullptr;
        TreeNode* curr = root;

        while(curr || !st.empty())
        {
            // Go left
            while(curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* node = st.top();

            // If right not processed, go right
            if(node->right && lastVisited != node->right)
            {
                curr = node->right;
            }
            else
            {
                // Process node (postorder point)

                int leftGain  = max(0, gain[node->left]);
                int rightGain = max(0, gain[node->right]);

                int throughPath = leftGain + node->val + rightGain;

                maxSum = max(maxSum, throughPath);

                // Store extendable gain
                gain[node] = node->val + max(leftGain, rightGain);

                lastVisited = node;
                st.pop();
            }
        }

        return maxSum;
    }

    
};
