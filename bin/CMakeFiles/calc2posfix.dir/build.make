# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Thomas/Documents/Compiler/hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Thomas/Documents/Compiler/hw1/bin

# Include any dependencies generated for this target.
include CMakeFiles/calc2posfix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calc2posfix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calc2posfix.dir/flags.make

CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o: CMakeFiles/calc2posfix.dir/flags.make
CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o: ../evaluate_posfix.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Thomas/Documents/Compiler/hw1/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o -c /Users/Thomas/Documents/Compiler/hw1/evaluate_posfix.cpp

CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Thomas/Documents/Compiler/hw1/evaluate_posfix.cpp > CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.i

CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Thomas/Documents/Compiler/hw1/evaluate_posfix.cpp -o CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.s

CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.requires:
.PHONY : CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.requires

CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.provides: CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.requires
	$(MAKE) -f CMakeFiles/calc2posfix.dir/build.make CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.provides.build
.PHONY : CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.provides

CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.provides.build: CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o

# Object files for target calc2posfix
calc2posfix_OBJECTS = \
"CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o"

# External object files for target calc2posfix
calc2posfix_EXTERNAL_OBJECTS =

calc2posfix: CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o
calc2posfix: CMakeFiles/calc2posfix.dir/build.make
calc2posfix: lib/liblib.a
calc2posfix: CMakeFiles/calc2posfix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable calc2posfix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calc2posfix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calc2posfix.dir/build: calc2posfix
.PHONY : CMakeFiles/calc2posfix.dir/build

CMakeFiles/calc2posfix.dir/requires: CMakeFiles/calc2posfix.dir/evaluate_posfix.cpp.o.requires
.PHONY : CMakeFiles/calc2posfix.dir/requires

CMakeFiles/calc2posfix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calc2posfix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calc2posfix.dir/clean

CMakeFiles/calc2posfix.dir/depend:
	cd /Users/Thomas/Documents/Compiler/hw1/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Thomas/Documents/Compiler/hw1 /Users/Thomas/Documents/Compiler/hw1 /Users/Thomas/Documents/Compiler/hw1/bin /Users/Thomas/Documents/Compiler/hw1/bin /Users/Thomas/Documents/Compiler/hw1/bin/CMakeFiles/calc2posfix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calc2posfix.dir/depend
