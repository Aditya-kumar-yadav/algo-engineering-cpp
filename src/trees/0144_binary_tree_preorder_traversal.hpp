/* * ID: 144
 * Title: Binary Tree Preorder Traversal
 * Difficulty: Easy
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void dfs(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) return;
        
        result.push_back(node->val);  // Root
        dfs(node->left, result);      // Left
        dfs(node->right, result);     // Right
    }

public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        dfs(root, result);
        return result;
    }
};