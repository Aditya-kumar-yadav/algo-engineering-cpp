#include <gtest/gtest.h>
#include "trees/0104_maximum_depth_of_binary_tree.hpp" // Strictly pathed and lowercased

TEST(MaximumDepthofBinaryTreeTest, Example1_StandardTree) {
    Solution sol;
    
    // Construct tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Assert the maximum depth is 3
    EXPECT_EQ(sol.maxDepth(root), 3);

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
}

TEST(MaximumDepthofBinaryTreeTest, Example2_UnbalancedTree) {
    Solution sol;
    
    // Construct tree: [1,null,2]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);

    // Assert the maximum depth is 2
    EXPECT_EQ(sol.maxDepth(root), 2);

    // Clean up memory
    delete root->right;
    delete root;
}

TEST(MaximumDepthofBinaryTreeTest, EmptyTree) {
    Solution sol;
    
    // Tree: []
    TreeNode* root = nullptr;

    // Assert depth of an empty tree is 0
    EXPECT_EQ(sol.maxDepth(root), 0);
}

TEST(MaximumDepthofBinaryTreeTest, SingleNode) {
    Solution sol;
    
    // Construct tree: [0]
    TreeNode* root = new TreeNode(0);

    // Assert depth of a single root node is 1
    EXPECT_EQ(sol.maxDepth(root), 1);

    // Clean up memory
    delete root;
}