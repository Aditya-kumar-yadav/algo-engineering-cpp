# 🚀 Enterprise LeetCode Architecture

[![CI/CD Pipeline](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions/actions/workflows/ci.yml/badge.svg)](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions/actions)
[![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![Testing: GTest](https://img.shields.io/badge/Testing-Google_Test-green.svg)](https://github.com/google/googletest)
[![Build: CMake](https://img.shields.io/badge/Build-CMake-orange.svg)](https://cmake.org/)

**A fully automated, production-grade algorithmic engineering repository.** This project demonstrates software engineering maturity by treating algorithm solutions as production code. It features a custom CI/CD pipeline, Test-Driven Development (TDD), and automated documentation generation.

---

## ⏱️ The 5-Second Overview
* **Language:** Modern C++17 (Focus on memory safety and optimized time/space complexity).
* **Testing:** 100% test coverage using **Google Test (GTest)** for edge-case verification.
* **CI/CD:** Automated **GitHub Actions** pipeline compiles code and runs tests on every push.
* **Build System:** Dynamic **CMake** configuration that automatically links new algorithmic modules.
* **DevOps:** Custom Python scripts auto-discover new C++ files and regenerate the database architecture.

---

## 🏗️ System Architecture

1. **Code:** Solutions are written in C++ with standardized boilerplate.
2. **Test:** Every solution is strictly paired with a `_test.cpp` file.
3. **Push:** Code is pushed to the repository.
4. **Pipeline:** A cloud Ubuntu runner provisions CMake, builds the binaries, and executes the GTest suite.
5. **Automation:** If tests pass, a Python script parses the C++ metadata and updates the solution database.

---

## 📊 Algorithmic Problem Database

The comprehensive database of solved algorithmic problems, their corresponding test suites, and corporate applicability mapping (FAANG) is maintained in a dedicated, auto-generated index.

👉 **[Click here to view the complete Problem Database (SOLUTIONS.md)](./SOLUTIONS.md)**

---

## 🛠️ Local Development & Testing

The dynamic CMake build system automatically discovers new test files. 

**Prerequisites:** `cmake` and a C++ compiler (`g++` or `clang`).

```bash
# Clone the repository
git clone [https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions.git](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions.git)
cd Leetcode-Company-wise-Questions

# Configure the build system (Downloads GTest automatically)
cmake -B build -S .

# Compile the entire C++ codebase
cmake --build build

# Run the Google Test suite
cd build
ctest --output-on-failure
```

---

## 🤝 Contributing

We utilize a Python automator to handle all folder creation, C++ boilerplate generation, and CMake linking. Please read our [CONTRIBUTING.md](./CONTRIBUTING.md) guide before submitting a Pull Request to ensure your code complies with our automated pipeline.

---
<p align="center">
  <i>Engineered by <a href="https://github.com/Aditya-kumar-yadav">Aditya Kumar Yadav</a> • Maintained by automated CI/CD pipelines 🤖</i>
</p>