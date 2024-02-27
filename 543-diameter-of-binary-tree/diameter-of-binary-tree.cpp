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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int diameter = 0;
        calculateDiameter(root, diameter);
        
        return diameter;
    }
    
    int calculateDiameter(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int left = calculateDiameter(node->left, diameter);
        int right = calculateDiameter(node->right, diameter);
        
        diameter = std::max(diameter, left + right);
        
        return 1 + std::max(left, right);
    }
};
