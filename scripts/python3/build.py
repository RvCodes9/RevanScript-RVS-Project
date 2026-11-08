"""
    © 2026 Rəvan Babayev. All rights reserved.
    RevanScript (RVS) Interpreter (Python 3.12 Build System)
"""


# Python Standard Libraries
import tomllib as toml
import subprocess as sp
import os


# Source Files Compile Function
def source_file_compile(compiler: dict[str, str], build: dict[str, list[str]]) -> bool:
    compiler_gcc: str = compiler["Name0"]
    compiler_clang: str = compiler["Name1"]
    compiler_mingw_gcc: str = compiler["Name2"]
    source_file_names: list[str] = build["SourceFiles"]
    gcc_object_file_names: list[str] = build["GCCObjectFiles"]
    clang_object_file_names: list[str] = build["ClangObjectFiles"]
    mingw_gcc_object_file_names: list[str] = build["MinGWGCCObjectFiles"]
    compile_type: str = build["Flags"][0]
    language_standard: str = build["Flags"][1]
    optimization: str = build["Flags"][2]

    problem_flag: bool = False

    for sf_name, gcc_of_name, clang_of_name, mingw_gcc_of_name in zip(
        source_file_names, 
        gcc_object_file_names, 
        clang_object_file_names, 
        mingw_gcc_object_file_names):

        # GCC Compiler / Process 1
        result0 = sp.run(
            [compiler_gcc,
             compile_type,
             language_standard,
             optimization,
             "-c", 
             sf_name, 
             "-o", 
             gcc_of_name], 
            capture_output=True,
            text=True)
        if result0.returncode == 0:
            print("Successful GCC object file compile!!!")
        else:
            problem_flag = True
            print(result0.stderr)

        # Clang Compiler / Process 2
        result1 = sp.run(
            [compiler_clang,
              compile_type,
              language_standard,
              optimization,
              "-c", 
              sf_name, 
              "-o", 
              clang_of_name], 
            capture_output=True,
            text=True)
        if result1.returncode == 0:
            print("Successful Clang object file compile!!!")
        else:
            problem_flag = True
            print(result1.stderr)

        # MinGW-GCC Compiler / Process 3
        result2 = sp.run(
            [compiler_mingw_gcc,
             compile_type,
             language_standard,
             optimization,
             "-c", 
             sf_name, 
             "-o", 
             mingw_gcc_of_name], 
            capture_output=True,
            text=True)
        if result2.returncode == 0:
            print("Successful MinGW-GCC object file compile!!!")
        else:
            problem_flag = True
            print(result2.stderr)

    if problem_flag:
        return False
    else:
        return True


# Object Files Compile Function
def object_file_compile(compiler: dict[str, str], build: dict[str, list[str]]) -> bool:
    compiler_gcc: str = compiler["Name0"]
    compiler_clang: str = compiler["Name1"]
    compiler_mingw_gcc: str = compiler["Name2"]
    gcc_object_file_names: list[str] = build["GCCObjectFiles"]
    clang_object_file_names: list[str] = build["ClangObjectFiles"]
    mingw_gcc_object_file_names: list[str] = build["MinGWGCCObjectFiles"]

    problem_flag: bool = False

    # Operation System (OS) 
    if os.name == 'posix':
        output_file_name = str(build["LinuxOutputFile"])
    elif os.name == 'nt':
        output_file_name = str(build["WindowsOutputFile"])

    # GCC Compiler / Process 1
    result0 = sp.run(
        [compiler_gcc,
         str(gcc_object_file_names), 
         "-o",
         output_file_name], 
        capture_output=True,
        text=True)
    if result0.returncode == 0:
        print("Successful GCC object file compile!!!")
    else:
        problem_flag = True
        print(result0.stderr)

    # Clang Compiler / Process 2
    result1 = sp.run(
        [compiler_clang,
            str(clang_object_file_names), 
            "-o",
            output_file_name], 
        capture_output=True,
        text=True)
    if result1.returncode == 0:
        print("Successful Clang object file compile!!!")
    else:
        problem_flag = True
        print(result1.stderr)

    # MinGW (GCC) Compiler / Process 3
    result3 = sp.run(
        [compiler_mingw_gcc,
            str(mingw_gcc_object_file_names), 
            "-o",
            output_file_name], 
        capture_output=True,
        text=True)
    if result3.returncode == 0:
        print("Successful MinGW-GCC object file compile!!!")
    else:
        problem_flag = True
        print(result1.stderr)

    # Check Problem
    if problem_flag is True:
        return False
    else:
        return True


# Context Manager Python 
with open("../../config/PyConfig.toml", "rb") as file:
    config: dict = toml.load(file)

    project: dict = config["Project"]
    compiler: dict = config["Compiler"]
    build: dict = config["Build"]

    if source_file_compile(compiler, build) is False:
        print("[Source Files -> Object Files] Convert Process Failed!!!")
    else:
        if object_file_compile(compiler, build) is False:
            print("[Object Files -> Executable File] Convert Process Failed!!!")
        else:
            print("[Convert Process Successful!!!]")

