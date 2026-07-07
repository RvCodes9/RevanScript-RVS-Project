// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvskey.h"

const unsigned short rvs_keywords_length[RVS_KEYWORD_COUNT] = {
    3, // -> Keyword 1 (var) Length
    3, // -> Keyword 2 (set) Length
    3, // -> Keyword 3 (get) Length
    3, // -> Keyword 4 (cst) Length
    3, // -> Keyword 5 (ref) Length
    3, // -> Keyword 6 (ptr) Length
    3, // -> Keyword 7 (int) Length
    3, // -> Keyword 8 (flt) Length
    3, // -> Keyword 9 (str) Length
    3, // -> Keyword 10 (bln) Length
    3, // -> Keyword 11 (bin) Length
    3, // -> Keyword 12 (dec) Length
    3, // -> Keyword 13 (hex) Length
    3, // -> Keyword 14 (chr) Length
    3, // -> Keyword 15 (obj) Length
    3, // -> Keyword 16 (out) Length
    3, // -> Keyword 17 (inp) Length
    3, // -> Keyword 18 (del) Length
    3, // -> Keyword 19 (prt) Length
    3, // -> Keyword 20 (ext) Length
    3, // -> Keyword 21 (lib) Length
    3, // -> Keyword 22 (sys) Length
    3, // -> Keyword 23 (end) Length
    3, // -> Keyword 24 (ret) Length
    2, // -> Keyword 25 (if) Length
    4, // -> Keyword 26 (elif) Length
    4, // -> Keyword 27 (else) Length
    4, // -> Keyword 28 (loop) Length
    4, // -> Keyword 29 (func) Length
    4, // -> Keyword 30 (temp) Length
    4, // -> Keyword 31 (call) Length
    4, // -> Keyword 32 (next) Length
    5, // -> Keyword 33 (class) Length
    5, // -> Keyword 34 (async) Length
    5  // -> Keyword 35 (await) Length
};

const char rvs_keyword_list[RVS_KEYWORD_COUNT][6] = {
    "var",   // -> 1 (Variable) -- Variable (Dynamic Types) Create and Convert (Static Type -> Dynamic Types) (Keyword)
    "set",   // -> 2 (Set) -- Variable Change Value (Keyword)
    "get",   // -> 3 (Get) -- Variable Meta-Data Print (Table) Display (Keyword)
    "cst",   // -> 4 (Constant) -- Variable Constant Define (Keyword)
    "ref",   // -> 5 (Referance) -- Variable Referance Define (Keyword)
    "ptr",   // -> 6 (Pointer) -- Variable Pointer Type Define - (Address Safe <Readable>) (Keyword)
    "int",   // -> 7 (Integer) (Multi Types Number) <Convert and Define Static Type Variable> -- (Keyword)
    "flt",   // -> 8 (Float) (Float Number Types) <Convert and Define Static Type Variable> -- (Keyword)
    "str",   // -> 9 (String) (String/Text Types) <Convert and Define Static Type Variable> -- (Keyword)
    "bln",   // -> 10 (Boolean) (Control Type) <Convert and Define Static Type Variable> -- (Keyword)
    "bin",   // -> 11 (Binary) (Binary Number Type) <Convert and Define Static Type Variable> -- (Keyword)
    "dec",   // -> 12 (Decemal) (Decemal Number Type) <Convert and Define Static Type Variable> -- (Keyword)
    "hex",   // -> 13 (Hexadecemal) (Hexadecemal Number Type) <Convert and Define Static Type Variable> -- (Keyword)
    "chr",   // -> 14 (Character) (Character Type One Symbol) <Convert and Define Static Type Variable> -- (Keyword)
    "obj",   // -> 15 (Object) (Object Type / Class) <Convert and Define Static Type Variable> -- (Keyword)
    "out",   // -> 16 (Output) -- Variable Value Console Output (Keyword)
    "inp",   // -> 17 (Input) -- Standard Keyboard Input (Keyword)
    "del",   // -> 18 (Delete) -- Variable Delete (Keyword)
    "prt",   // -> 19 (Print) -- Direct Console Output (Keyword)
    "ext",   // -> 20 (Extension) -- Library Import (Keyword)
    "lib",   // -> 21 (Library) -- System Library (DLL, SO) import (Keyword)
    "sys",   // -> 22 (System) -- Terminal Command-Line Interface (Keyword)
    "end",   // -> 23 (End) -- Process Finish (Keyword)
    "ret",   // -> 24 (Return) -- Function Return Value (Keyword)
    "if",    // -> 25 (If) -- Condition / Control Flow Logic (Keyword)
    "elif",  // -> 26 (Else if) -- Condition / Control Flow Logic (Keyword)
    "else",  // -> 27 (Else) -- Condition / Control Flow Logic (Keyword)
    "loop",  // -> 28 (Loop) -- Loop (Keyword)
    "func",  // -> 29 (Func) -- Function Create (Keyword)
    "temp",  // -> 30 (Temp) -- Template Create (No Scope Function - Consepts) (Keyword)
    "call",  // -> 31 (Call) -- Function / Template Call (Keyword)
    "next",  // -> 32 (Next) -- Loop Continue/Next (Keyword) 
    "class", // -> 33 (Class) -- (Object Oriented Programming - Consepts) OOP (Keyword)
    "async", // -> 34 (Async) -- (Asynchronous Programming - Consepts) (Keyword)
    "await"  // -> 35 (Await) -- (Asynchronous Programming - Consepts) (Keyword)
};