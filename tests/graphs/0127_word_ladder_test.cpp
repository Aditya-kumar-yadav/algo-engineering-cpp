#include <gtest/gtest.h>
#include "graphs/0127_word_ladder.hpp"

TEST(WordLadderTest, LeetCodeExample1) {
    Solution sol;
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 5);
}

TEST(WordLadderTest, LeetCodeExample2) {
    Solution sol;
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 0);
}

TEST(WordLadderTest, DirectPath) {
    Solution sol;
    std::string beginWord = "hit";
    std::string endWord = "hot";
    std::vector<std::string> wordList = {"hot"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 2);
}

TEST(WordLadderTest, DisconnectedGraph) {
    Solution sol;
    std::string beginWord = "talk";
    std::string endWord = "moon";
    std::vector<std::string> wordList = {"tall", "tank", "moon"};
    
    EXPECT_EQ(sol.ladderLength(beginWord, endWord, wordList), 0);
}