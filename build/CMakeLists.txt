# ----- 1. Runtime environment
cmake_minimum_required(VERSION 3.22)
project(prepare-cs2040)

# cmake -DCMAKE_C_COMPILER=/usr/bin/clang-17

# ----- 2. Debugging
# for debugging with gdb in Terminal
# set(CMAKE_BUILD_TYPE DEBUG)
# set(CMAKE_C_FLAGS "-O0 -ggdb")
# set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
# set(CMAKE_C_FLAGS_RELEASE "-O0 -ggdb")

# ----- 3. Global variable

# ----- 4. Software library
# set(includes /usr/local/include/libxml2)
# include_directories(${includes})

# ----- 3. Static and shared library
# Static (A file)
# set(libs_static libxml2.a)
# link_directories(/usr/local/lib)

# Shared (SO file)
# set(libs_shared libxml2.so)
# link_directories(/usr/local/lib)

# ----- 4. File to compile
set(sources /home/shankar/Shiva/prepare-cs2040/Extra/conformity/conformity.cpp)

add_executable(main ${sources})

# Follow https://github.com/nus-cs1010/libcs1010/blob/master/compile_flags.txt
target_compile_options(main PUBLIC -g -I/include
    -Wall
    -Wbad-function-cast
    -Wconversion
    -Wextra
    -Wfloat-equal
    -Wmissing-variable-declarations
    -Wpedantic
    -Wshadow
    -Wunreachable-code-aggressive
    -Wvla
    -Wtautological-compare
    -Wtautological-constant-in-range-compare
    -Wcomma
    -Wformat-non-iso
    -Wdocumentation
    -Wstrict-prototypes)

# This is for math.h tool: "-l m" which calling "libm.so"
target_link_libraries(main ${libs_static} ${libs_shared} m)

# Look in /lib or /usr/lib. The libraries are all named lib<name>.a or lib<name>.so - it's the "<name>" you put after the -l. In this case, the math library is named libm.so, so we call it -lm. - https://stackoverflow.com/questions/8671366/undefined-reference-to-pow-and-floor, https://stackoverflow.com/questions/39598323/how-to-properly-link-libraries-with-cmake

# Learning
# https://stackoverflow.com/questions/11783932/how-do-i-add-a-linker-or-compile-flag-in-a-cmake-file
# https://cliutils.gitlab.io/modern-cmake/examples/root-simple/?q=target_compile
# https://stackoverflow.com/questions/72235289/how-do-you-set-compile-flags-in-cmake

# compile in 1 line
# https://nus-cs1010.github.io/2324-s1/guides/clang.html#5-linking-with-the-standard-library

# https://stackoverflow.com/a/71383158/9633932
# cmake -D CMAKE_CXX_COMPILER="/bin/clang++-17" -D CMAKE_C_COMPILER="/bin/clang-17"