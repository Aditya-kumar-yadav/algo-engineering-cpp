# 🚀 Enterprise-Grade Algorithmic Architecture

[![CI/CD Pipeline](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions/actions/workflows/ci.yml/badge.svg)](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions/actions)
[![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![Testing: GTest](https://img.shields.io/badge/Testing-Google_Test-green.svg)](https://github.com/google/googletest)
[![Build: CMake](https://img.shields.io/badge/Build-CMake-orange.svg)](https://cmake.org/)

**A fully automated, production-grade algorithmic engineering repository.** This project demonstrates software engineering maturity by treating algorithm solutions as production code. It features a custom Continuous Integration/Continuous Deployment (CI/CD) pipeline, Test-Driven Development (TDD), and automated documentation generation.

---

## ✨ Technical Specifications

* **Primary Language:** Modern C++17 (Focus on memory safety and optimized time/space complexity).
* **Test Infrastructure:** 100% test coverage using **Google Test (GTest)** for rigorous edge-case verification.
* **CI/CD Pipeline:** Automated **GitHub Actions** workflows compile code and execute test suites on every commit.
* **Build System:** Dynamic **CMake** configuration that automatically discovers and links new algorithmic modules.
* **Automation:** Custom Python scripts auto-discover new C++ files, parse metadata, and regenerate the database architecture.

---

## 🏗️ Repository Architecture

```text
📦 LeetCode-Solutions
 ┣ 📂 .github/workflows   # CI/CD pipelines (Automated Build & Test via ci.yml)
 ┣ 📂 hubs                # Curated lists (Company-wise & Topic-wise Markdown Hubs)
 ┣ 📂 metadata            # Local JSON database tracking problem states & analytics
 ┣ 📂 scripts             # Python automation tools (Doc Gen, Boilerplate, Discovery)
 ┣ 📂 src                 # Core C++ source files containing optimal solutions (.hpp)
 ┣ 📂 tests               # GTest unit tests validating every C++ solution (.cpp)
 ┣ 📜 CMakeLists.txt      # Build system configuration
 ┗ 📜 README.md           # Repository overview (You are here)
```

---

## ⚙️ System Architecture Lifecycle

1. **Code:** Solutions are implemented in C++ utilizing standardized boilerplate templates.
2. **Test:** Every algorithmic solution is strictly paired with a corresponding `_test.cpp` file.
3. **Version Control:** Code is pushed to the main repository.
4. **Pipeline Execution:** A cloud-based Ubuntu runner provisions CMake, builds the binaries, and executes the GTest suite.
5. **Documentation Automation:** Upon successful test execution, a Python script parses the C++ metadata and updates the solution database autonomously.

---

## ⚡ DevOps & Automation Scripts

To maintain clean code and eliminate manual data entry, I developed three core CLI tools located in the `/scripts` directory:

* **`start.py` (Boilerplate Generator):** Instantly scaffolds the `.hpp` solution file and the corresponding `.cpp` GTest file with the correct ID, naming conventions, and exact file paths.
* **`auto_discover.py` (Database Sync):** Scans the `src/` directory, extracts problem metadata from the C++ headers, and updates the central `metadata/database.json`.
* **`generate_docs.py` (Markdown Builder):** Reads the JSON database and dynamically injects beautifully formatted, professional tables directly into the respective Markdown files.

---

## 🛠️ Local Development & Testing

The dynamic CMake build system automatically discovers new test files. 

**Prerequisites:** `cmake`, Python 3.x, and a C++ compiler (`g++`, `clang`, or MSVC).

```bash
# Clone the repository
git clone https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions.git
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

## 📈 Algorithmic Problem Database

The comprehensive database of solved algorithmic problems, their corresponding test suites, and corporate applicability mapping (FAANG) is maintained in a dedicated, auto-generated index.

**[View the Complete Problem Database (SOLUTIONS.md)](./SOLUTIONS.md)**

---

### 📫 Let's Connect

*If you are a recruiter, hiring manager, or an engineer looking to collaborate, feel free to explore the codebase. I am actively seeking software engineering opportunities where I can bring this level of engineering rigor, testing discipline, and automation to a professional team.*