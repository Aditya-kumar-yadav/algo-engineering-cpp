# 🚀 Enterprise LeetCode Solutions

This repository contains highly optimized, production-ready C++ solutions to LeetCode problems.

## 📊 Problem Database

<<<<<<< HEAD
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

# 🚀 Enterprise LeetCode Solutions

Welcome to my professional repository. This project contains highly optimized, production-ready C++ solutions to algorithmic problems. 

The entire repository is managed by a custom-built CI/CD pipeline that automatically compiles the code, runs Google Tests, and generates this problem database.

## 📊 Problem Database
*(The Python bot will inject the table here automatically when you push to GitHub!)*
---
*Maintained by an automated GitHub Actions architecture.*
=======
| ID | Problem Title | Difficulty | Category | Frequently Asked By |
| :--- | :--- | :---: | :--- | :--- |
>>>>>>> d2642e56be01825a750e9291c8919b68c52a930e
