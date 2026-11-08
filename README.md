# RevanScript (RVS) Programming Language Project

An efficient, lightweight, and direct-execution interpreter model built from scratch.

<p align="center">
  <img src="RevanScript-RVS-Logo.png" width="200" alt="RevanScript Logo"/>
</p>

## 📖 Introduction
**RevanScript (RVS)** sadə, command-based (əmr əsaslı) təmələ sahib bir proqramlaşdırma dilidir. Olduqca minimal və anlaşılan bir sintaksisə malikdir. RevanScript (RVS) dilinin əsas üstünlüyü onun sürətli və yüngül işləyən daxili tərcüməçi (interpreter) proqramına sahib olmasıdır. 

Layihə tamamilə **C proqramlaşdırma dili** ilə sıfırdan hazırlanmışdır. C dilinin 1999 cu ildə tərtib olunmuş C99 Standardını istifadə edilir. Lahiyədə (GCC, Clang, MinGW-GCC) kompilatorlarından istifadə olunur. Lahiyənin platforma dəstəyi (Linux, Windows) üçün dəstəklənir.

## 💎 Data Types

The language supports the management of various data types. The following primitive types are currently fully functional:

- **String** — Text data type
- **Integer** — Whole number data type
- **Float** — Floating-point number data type
- **Boolean** — Logical data type
- **Null** — Null value type

## ⚙️ Structure Types
Dildə müxtəlif məlumatları toplu şəkildə saxlamaq üçün daha mürrəkkəb tiplərə ehtiyac olur:
* **Box** (Siyahı tipi)
* **Map** (Xəritə tipi)

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

## 🌐 Community & Official Links
RevanScript inkişaf prosesini izləmək və layihəyə dəstək olmaq üçün aşağıdakı rəsmi resurslardan istifadə edə bilərsiniz:

* **📺 YouTube Tutorials:** [RvCodes9 YouTube Channel](https://youtube.com/@RvCodes9) — Praktik nümunələr və video bələdçilər.
* **📄 Official Documentation:** [RevanScript Pages Site](https://rvcodes9.github.io/RevanScript-RVS-Documetation-Site/) — Geniş məlumat və dərsliklər.
* **💬 Reddit Community:** [r/RevanScript](https://www.reddit.com/r/RevanScript/) — Fikir bildirmək, müzakirə etmək və sual vermək üçün rəsmi sub-reddit.

## 💡 Creator & Developer
RevanScript (RVS) proqramlaşdırma dili 2026-cı ildə Rəvan Babayev tərəfindən yaradılmışdir və hazırda aktiv ikişaf etdirilən lahiyədir.