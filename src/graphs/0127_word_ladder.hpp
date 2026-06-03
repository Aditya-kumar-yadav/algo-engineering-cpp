/* * ID: 127
 * Title: Word Ladder
 * Difficulty: Hard
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <utility> // Required for strict CI runners using std::pair

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        
        // If the target word isn't in the dictionary, early exit
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        
        // Remove beginWord from dictionary to prevent any weird cycle edge cases
        dict.erase(beginWord);

        while (!q.empty()) {
            // Unpacking pair explicitly to avoid C++17 structured binding CI quirks
            std::string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) {
                return steps;
            }

            for (std::size_t i = 0; i < word.length(); ++i) {
                char originalChar = word[i];

                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;

                    word[i] = c;

                    if (dict.find(word) != dict.end()) {
                        q.push({word, steps + 1});
                        dict.erase(word); // Erase immediately to prevent memory queue bloat
                    }
                }
                
                word[i] = originalChar; // Backtrack
            }
        }

        return 0;
    }
};