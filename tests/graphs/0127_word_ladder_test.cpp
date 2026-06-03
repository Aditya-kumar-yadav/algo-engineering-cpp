#include <gtest/gtest.h>
#include "graphs/0127_word_ladder.hpp"

// Test 1: Standard LeetCode Example 1
TEST(WordLadderTest, StandardValidPath) {
    Solution sol;
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 5);
}

// Test 2: Standard LeetCode Example 2
TEST(WordLadderTest, TargetMissingFromDictionary) {
    Solution sol;
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 0);
}

// Test 3: Immediate Neighbor
TEST(WordLadderTest, DirectOneStepTransformation) {
    Solution sol;
    std::string beginWord = "hit";
    std::string endWord = "hot";
    std::vector<std::string> wordList = {"hot"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 2);
}

// Test 4: Dead End (No single-letter bridge connects them)
TEST(WordLadderTest, DeadEndNoValidPath) {
    Solution sol;
    std::string beginWord = "talk";
    std::string endWord = "moon";
    std::vector<std::string> wordList = {"tall", "tank", "moon"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 0);
}

// Test 5: Graph Cycles
TEST(WordLadderTest, HandlesGraphCycles) {
    Solution sol;
    std::string beginWord = "cat";
    std::string endWord = "dog";
    std::vector<std::string> wordList = {"bat", "car", "bit", "bot", "dot", "dog"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 6);
}

// Test 6: Multiple Paths (Must pick shortest)
TEST(WordLadderTest, ChoosesShortestPath) {
    Solution sol;
    std::string beginWord = "dig";
    std::string endWord = "dog";
    std::vector<std::string> wordList = {"big", "bog", "dog"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 2);
}