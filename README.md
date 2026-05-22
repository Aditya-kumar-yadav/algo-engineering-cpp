# 🚀 Automated Algorithm Engineering Repository

[![CI Pipeline](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions/actions/workflows/ci.yml/badge.svg)](https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions/actions)
[![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![Build System](https://img.shields.io/badge/Build-CMake-orange.svg)](https://cmake.org/)
[![Testing](https://img.shields.io/badge/Testing-GoogleTest-green.svg)](https://github.com/google/googletest)

A scalable and automated repository for solving algorithmic problems using modern software engineering practices.

This project goes beyond storing LeetCode solutions by integrating:

* Automated testing
* CI/CD pipelines
* Metadata-driven documentation generation
* Dynamic build configuration
* Repository automation tooling

The goal is to treat algorithmic problem solving with the same engineering discipline used in production software systems.

---

# ✨ Features

* Modern **C++17** solutions
* Automated **Google Test** validation
* Dynamic **CMake** build system
* Continuous Integration using **GitHub Actions**
* Auto-generated Markdown documentation
* Metadata-based problem tracking
* Python automation scripts for repository maintenance
* Structured repository architecture for scalability

---

# 🏗️ Repository Structure

```text
📦 Leetcode-Company-wise-Questions
 ┣ 📂 .github/workflows   # CI/CD pipelines
 ┣ 📂 hubs                # Company-wise and topic-wise indexes
 ┣ 📂 metadata            # JSON database and analytics
 ┣ 📂 scripts             # Automation utilities
 ┣ 📂 src                 # C++ solution implementations
 ┣ 📂 tests               # Google Test unit tests
 ┣ 📜 CMakeLists.txt      # Build configuration
 ┗ 📜 README.md
```

---

# ⚙️ Engineering Workflow

```text
Problem Solved
      ↓
Unit Tests Written
      ↓
GitHub Push
      ↓
GitHub Actions Triggered
      ↓
CMake Build + Test Execution
      ↓
Metadata Parsing
      ↓
Documentation Regeneration
```

---

# 🔧 Automation Tools

The `/scripts` directory contains custom tooling designed to automate repository maintenance.

### `start.py`

Generates:

* Solution boilerplate
* Matching Google Test file
* Standardized naming structure

### `auto_discover.py`

Automatically:

* Scans solution directories
* Extracts metadata
* Updates the central JSON database

### `generate_docs.py`

Builds:

* Markdown indexes
* Problem tables
* Organized documentation hubs

---

# 🛠️ Local Setup

## Prerequisites

* CMake
* Python 3.x
* C++17 compatible compiler

---

## Clone Repository

```bash
git clone https://github.com/Aditya-kumar-yadav/Leetcode-Company-wise-Questions.git

cd Leetcode-Company-wise-Questions
```

---

## Configure Build

```bash
cmake -B build -S .
```

---

## Compile Project

```bash
cmake --build build
```

---

## Run Test Suite

```bash
cd build
ctest --output-on-failure
```

---

# 📊 Repository Goals

This repository focuses on:

* Clean and optimized implementations
* Scalable repository organization
* Automated engineering workflows
* Consistent testing practices
* Continuous improvement in problem-solving and software engineering

---

# 📈 Problem Database

The repository maintains an auto-generated index containing:

* Solved problems
* Difficulty tracking
* Company-wise mapping
* Topic categorization
* Solution metadata

## 📄 Solution Index

[View Complete Database](./SOLUTIONS.md)

---

# 🤝 Contributions

Contributions, improvements, and discussions are welcome.

If you find improvements related to:

* optimization
* testing
* automation
* documentation
* architecture

feel free to open an issue or pull request.

---

# 📫 Connect

If you're interested in:

* software engineering
* backend systems
* competitive programming
* automation tooling
* scalable developer workflows

feel free to explore the repository and connect.
