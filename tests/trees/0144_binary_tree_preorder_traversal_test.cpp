#include <gtest/gtest.h>
#include <cstddef> // Required for std::size_t
#include "trees/0144_binary_tree_preorder_traversal.hpp" 

// Anonymous namespace for test helper functions to prevent linker conflicts
namespace {
    
    // 1. Strict verification helper to avoid copy-pasting the size_t loop
    void verifyPreorder(TreeNode* root, const std::vector<int>& expected) {
        Solution sol;
        std::vector<int> actual = sol.preorderTraversal(root);
        
        ASSERT_EQ(actual.size(), expected.size()) << "Vectors are of unequal length";
        
        for (std::size_t i = 0; i < actual.size(); ++i) {
            EXPECT_EQ(actual[i], expected[i]) << "Vectors differ at index " << i;
        }
    }

    // 2. Memory management helper to prevent CI memory leaks
    void deleteTree(TreeNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// --- LeetCode Official Examples ---

TEST(BinaryTreePreorderTraversalTest, Example1_StandardTree) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    verifyPreorder(root, {1, 2, 3});
    deleteTree(root);
}

TEST(BinaryTreePreorderTraversalTest, Example2_EmptyTree) {
    TreeNode* root = nullptr;
    verifyPreorder(root, {});
}

TEST(BinaryTreePreorderTraversalTest, Example3_SingleNode) {
    TreeNode* root = new TreeNode(1);
    verifyPreorder(root, {1});
    deleteTree(root);
}

// --- Additional Edge Cases ---

TEST(BinaryTreePreorderTraversalTest, LeftSkewedTree) {
    // Tree: 1 -> 2 -> 3 (all left children)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    verifyPreorder(root, {1, 2, 3});
    deleteTree(root);
}

TEST(BinaryTreePreorderTraversalTest, RightSkewedTree) {
    // Tree: 1 -> 2 -> 3 (all right children)
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    
    verifyPreorder(root, {1, 2, 3});
    deleteTree(root);
}

TEST(BinaryTreePreorderTraversalTest, PerfectBinaryTree) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    verifyPreorder(root, {1, 2, 4, 5, 3, 6, 7});
    deleteTree(root);
}