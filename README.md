# 🚀 Enterprise LeetCode Architecture

[![Build Status](https://img.shields.io/github/actions/workflow/status/YOUR-USERNAME/Leetcode-Company-wise-Questions/ci.yml?branch=main&label=CI%2FCD%20Pipeline&style=flat-square)](https://github.com/YOUR-USERNAME/Leetcode-Company-wise-Questions/actions)
[![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat-square&logo=c%2B%2B)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-Build_System-success?style=flat-square&logo=cmake)](https://cmake.org/)
[![Google Test](https://img.shields.io/badge/Testing-Google_Test-yellow?style=flat-square)](https://github.com/google/googletest)

> **A scalable, production-ready repository mapping Data Structures & Algorithms to top-tier tech companies.**

This repository is more than just a collection of solved coding problems. It is architected to mirror **enterprise-grade software engineering standards**. By decoupling algorithmic logic from test execution and utilizing an automated Continuous Integration pipeline, this project demonstrates a commitment to clean code, maintainability, and rigorous testing.

---

## 🏗️ System Architecture

Unlike traditional competitive programming repositories that duplicate code across multiple folders, this codebase follows the **DRY (Don't Repeat Yourself)** principle. 

* **Algorithmic Core:** Solutions are isolated in the `src/` directory, categorized by DSA pattern (Arrays, Strings, Trees, etc.).
* **Isolated Testing:** Unit tests are strictly separated into the `tests/` directory and powered by the industry-standard **Google Test (GTest)** framework.
* **Data-Driven Mapping:** The relationship between a LeetCode problem and the companies that ask it (e.g., Microsoft, Amazon, Adobe) is managed via a central `metadata/database.json` file.
* **Automated Indexing:** Python scripts dynamically generate documentation and tracking tables based on the JSON database.

```text
📦 Repository Structure
├── .github/workflows/    # Automated CI/CD pipeline configurations
├── metadata/
│   └── database.json     # Central source of truth mapping problems to companies
├── scripts/
│   └── generate_docs.py  # Automation scripts for repo maintenance
├── src/                  # Pure C++ Algorithm Implementations
│   ├── arrays/
│   └── strings/
├── tests/                # Google Test suites for every algorithm
│   ├── arrays/
│   └── strings/
└── CMakeLists.txt        # Master build configuration

# My Custom Enterprise LeetCode Repo
Welcome to my repository! This is where I put my custom description that the bot will never delete.

## Problem Database
## Another Section
This section is also completely safe from the bot!