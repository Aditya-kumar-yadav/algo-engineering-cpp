/* * ID: 733
 * Title: Flood Fill
 * Difficulty: Easy
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void dfs(std::vector<std::vector<int>>& image, std::size_t r, std::size_t c, int original_color, int new_color) {
        std::size_t m = image.size();
        std::size_t n = image[0].size();

        // If color mismatch, do nothing
        if (image[r][c] != original_color) return;

        // Update color
        image[r][c] = new_color;

        // 4-directional traversal exploiting std::size_t underflow for upper/left boundaries
        // (e.g., if r is 0, r - 1 wraps to SIZE_MAX, cleanly failing the '< m' check)
        if (r - 1 < m) dfs(image, r - 1, c, original_color, new_color);
        if (r + 1 < m) dfs(image, r + 1, c, original_color, new_color);
        if (c - 1 < n) dfs(image, r, c - 1, original_color, new_color);
        if (c + 1 < n) dfs(image, r, c + 1, original_color, new_color);
    }

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
        if (image.empty()) return image;

        std::size_t start_r = static_cast<std::size_t>(sr);
        std::size_t start_c = static_cast<std::size_t>(sc);
        int original_color = image[start_r][start_c];
        
        // Base case: If target color matches original, return immediately to avoid infinite recursion
        if (original_color == color) return image;

        dfs(image, start_r, start_c, original_color, color);
        
        return image;
    }
    
    // ⚠️ STRICT COMPILER REMINDERS (-Wall -Werror):
    // 1. Use std::size_t for looping through container.size()
    // 2. Ensure all code paths return a value
};