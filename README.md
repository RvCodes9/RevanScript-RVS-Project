# RevanScript (RVS) Programming Language Project

An efficient, lightweight, and direct-execution interpreter model built from scratch.

<p align="center">
  <img src="RevanScript-RVS-Logo.png" width="200" alt="RevanScript Logo"/>
</p>

## 📖 Introduction

**RevanScript (RVS)** is a programming language built on a simple, command-based foundation. It features a minimal and easy-to-understand syntax. One of the main advantages of RevanScript (RVS) is its lightweight and fast built-in interpreter.

Unlike languages such as Python, Java, and JavaScript, RVS focuses on a simple execution engine while preserving built-in automation capabilities.

The project is developed entirely from scratch using the **C programming language**, following the C99 standard (ISO/IEC 9899:1999). The project supports the following compilers: GCC, Clang, and MinGW-GCC.

RevanScript is designed to support the following platforms:

- Linux
- Windows

Several tools can be used to build the project:

1. **SimpleMake (Tool)**
2. **Python (CPython 3) Scripts**
3. **Terminal (Console Shells)**

## 💎 Data Types

The language supports the management of various data types. The following primitive types are currently fully functional:

- **String** — Text data type
- **Integer** — Whole number data type
- **Float** — Floating-point number data type
- **Boolean** — Logical data type
- **Null** — Null value type

## ⚙️ Structure Types

More complex data types are required to store and manage collections of data. RevanScript provides the following structure types:

- **Box** — List data type
- **Map** — Key-value mapping data type
- **Set** — Unique collection data type

## 📂 Project Layers & Architecture

The RevanScript project follows a modular architecture, organized and managed through the following C source and header files:

1. **Memory Management:** `src/rvsmem.c` | `include/rvsmem.h`
2. **Buffer Memory Management:** `src/rvsbuf.c` | `include/rvsbuf.h`
3. **Expression Memory Management:** `src/rvsexp.c` | `include/rvsexp.h`
4. **I/O Handling:** `src/rvsio.c` | `include/rvsio.h`
5. **Interpreter Flags:** `src/rvsflg.c` | `include/rvsflg.h`
6. **Control & Checking:** `src/rvsctl.c` | `include/rvsctl.h`
7. **Math Engine:** `src/rvsmth.c` | `include/rvsmth.h`

## 💻 RevanScript Code Examples

The following example demonstrates some of the basic commands and syntax of the RevanScript (RVS) programming language:

```custom
... RevanScript (RVS) Comment
var text = "Hello, World!\n"
out text
set text = "\t\c4RevanScript (RVS) Programming Language\n"
out text
inp text
out text
cst text
del text
```

## 🎮 Games Mode

The RevanScript interpreter includes a dedicated **Games Mode**, designed for entertainment purposes.

The following games are currently planned:

1. **Guess the Number (Console)**
2. **Tic Tac Toe (Console)**
3. **Minesweeper (Console)**
4. **Sudoku (Console)**
5. **Chess (Console)**
6. **Sea Battle (Console)**
7. **Flappy Bird (Graphics)**
8. **Tetris (Graphics)**

## 🌐 Community & Official Links

Follow the development of RevanScript (RVS) and support the project through its official resources:

- **📺 YouTube Tutorials:** [RvCodes9 YouTube Channel](https://youtube.com/@RvCodes9) | [RevanScript (RVS) YouTube Channel](https://youtube.com/@RVS-Lang) — Practical examples and video tutorials.
- **📄 Official Documentation:** [RevanScript Documentation Website](https://rvcodes9.github.io/RevanScript-RVS-Documentation-Site/) — Detailed information and tutorials.
- **💬 Reddit Community:** [r/RevanScript](https://www.reddit.com/r/RevanScript/) — Share ideas, participate in discussions, and ask questions in the official subreddit.

## 💡 Creator & Developer

The RevanScript (RVS) programming language was created by **Rəvan Babayev in 2026** and is currently under active development.

The theoretical exploration and initial design of the language's capabilities date back to **2024–2025**.