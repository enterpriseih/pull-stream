# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gongzian/src/pull-stream

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gongzian/src/pull-stream/build

# Include any dependencies generated for this target.
include CMakeFiles/pull-stream-demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pull-stream-demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pull-stream-demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pull-stream-demo.dir/flags.make

CMakeFiles/pull-stream-demo.dir/src/main.cpp.o: CMakeFiles/pull-stream-demo.dir/flags.make
CMakeFiles/pull-stream-demo.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/pull-stream-demo.dir/src/main.cpp.o: CMakeFiles/pull-stream-demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gongzian/src/pull-stream/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pull-stream-demo.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pull-stream-demo.dir/src/main.cpp.o -MF CMakeFiles/pull-stream-demo.dir/src/main.cpp.o.d -o CMakeFiles/pull-stream-demo.dir/src/main.cpp.o -c /Users/gongzian/src/pull-stream/src/main.cpp

CMakeFiles/pull-stream-demo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pull-stream-demo.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gongzian/src/pull-stream/src/main.cpp > CMakeFiles/pull-stream-demo.dir/src/main.cpp.i

CMakeFiles/pull-stream-demo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pull-stream-demo.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gongzian/src/pull-stream/src/main.cpp -o CMakeFiles/pull-stream-demo.dir/src/main.cpp.s

# Object files for target pull-stream-demo
pull__stream__demo_OBJECTS = \
"CMakeFiles/pull-stream-demo.dir/src/main.cpp.o"

# External object files for target pull-stream-demo
pull__stream__demo_EXTERNAL_OBJECTS =

pull-stream-demo: CMakeFiles/pull-stream-demo.dir/src/main.cpp.o
pull-stream-demo: CMakeFiles/pull-stream-demo.dir/build.make
pull-stream-demo: CMakeFiles/pull-stream-demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gongzian/src/pull-stream/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pull-stream-demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pull-stream-demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pull-stream-demo.dir/build: pull-stream-demo
.PHONY : CMakeFiles/pull-stream-demo.dir/build

CMakeFiles/pull-stream-demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pull-stream-demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pull-stream-demo.dir/clean

CMakeFiles/pull-stream-demo.dir/depend:
	cd /Users/gongzian/src/pull-stream/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gongzian/src/pull-stream /Users/gongzian/src/pull-stream /Users/gongzian/src/pull-stream/build /Users/gongzian/src/pull-stream/build /Users/gongzian/src/pull-stream/build/CMakeFiles/pull-stream-demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pull-stream-demo.dir/depend

