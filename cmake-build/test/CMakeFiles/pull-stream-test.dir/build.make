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
CMAKE_BINARY_DIR = /Users/gongzian/src/pull-stream/cmake-build

# Include any dependencies generated for this target.
include test/CMakeFiles/pull-stream-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/pull-stream-test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/pull-stream-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/pull-stream-test.dir/flags.make

test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.o: test/CMakeFiles/pull-stream-test.dir/flags.make
test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.o: ../test/basic-test.cpp
test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.o: test/CMakeFiles/pull-stream-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gongzian/src/pull-stream/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.o"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.o -MF CMakeFiles/pull-stream-test.dir/basic-test.cpp.o.d -o CMakeFiles/pull-stream-test.dir/basic-test.cpp.o -c /Users/gongzian/src/pull-stream/test/basic-test.cpp

test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pull-stream-test.dir/basic-test.cpp.i"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gongzian/src/pull-stream/test/basic-test.cpp > CMakeFiles/pull-stream-test.dir/basic-test.cpp.i

test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pull-stream-test.dir/basic-test.cpp.s"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gongzian/src/pull-stream/test/basic-test.cpp -o CMakeFiles/pull-stream-test.dir/basic-test.cpp.s

test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o: test/CMakeFiles/pull-stream-test.dir/flags.make
test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o: ../test/end_or_error_test.cpp
test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o: test/CMakeFiles/pull-stream-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gongzian/src/pull-stream/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o -MF CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o.d -o CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o -c /Users/gongzian/src/pull-stream/test/end_or_error_test.cpp

test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.i"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gongzian/src/pull-stream/test/end_or_error_test.cpp > CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.i

test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.s"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gongzian/src/pull-stream/test/end_or_error_test.cpp -o CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.s

test/CMakeFiles/pull-stream-test.dir/state-test.cpp.o: test/CMakeFiles/pull-stream-test.dir/flags.make
test/CMakeFiles/pull-stream-test.dir/state-test.cpp.o: ../test/state-test.cpp
test/CMakeFiles/pull-stream-test.dir/state-test.cpp.o: test/CMakeFiles/pull-stream-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gongzian/src/pull-stream/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/pull-stream-test.dir/state-test.cpp.o"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/pull-stream-test.dir/state-test.cpp.o -MF CMakeFiles/pull-stream-test.dir/state-test.cpp.o.d -o CMakeFiles/pull-stream-test.dir/state-test.cpp.o -c /Users/gongzian/src/pull-stream/test/state-test.cpp

test/CMakeFiles/pull-stream-test.dir/state-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pull-stream-test.dir/state-test.cpp.i"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gongzian/src/pull-stream/test/state-test.cpp > CMakeFiles/pull-stream-test.dir/state-test.cpp.i

test/CMakeFiles/pull-stream-test.dir/state-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pull-stream-test.dir/state-test.cpp.s"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gongzian/src/pull-stream/test/state-test.cpp -o CMakeFiles/pull-stream-test.dir/state-test.cpp.s

# Object files for target pull-stream-test
pull__stream__test_OBJECTS = \
"CMakeFiles/pull-stream-test.dir/basic-test.cpp.o" \
"CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o" \
"CMakeFiles/pull-stream-test.dir/state-test.cpp.o"

# External object files for target pull-stream-test
pull__stream__test_EXTERNAL_OBJECTS =

bin/pull-stream-test: test/CMakeFiles/pull-stream-test.dir/basic-test.cpp.o
bin/pull-stream-test: test/CMakeFiles/pull-stream-test.dir/end_or_error_test.cpp.o
bin/pull-stream-test: test/CMakeFiles/pull-stream-test.dir/state-test.cpp.o
bin/pull-stream-test: test/CMakeFiles/pull-stream-test.dir/build.make
bin/pull-stream-test: lib/libgtest.a
bin/pull-stream-test: lib/libgtest_main.a
bin/pull-stream-test: lib/libgtest.a
bin/pull-stream-test: test/CMakeFiles/pull-stream-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gongzian/src/pull-stream/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/pull-stream-test"
	cd /Users/gongzian/src/pull-stream/cmake-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pull-stream-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/pull-stream-test.dir/build: bin/pull-stream-test
.PHONY : test/CMakeFiles/pull-stream-test.dir/build

test/CMakeFiles/pull-stream-test.dir/clean:
	cd /Users/gongzian/src/pull-stream/cmake-build/test && $(CMAKE_COMMAND) -P CMakeFiles/pull-stream-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/pull-stream-test.dir/clean

test/CMakeFiles/pull-stream-test.dir/depend:
	cd /Users/gongzian/src/pull-stream/cmake-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gongzian/src/pull-stream /Users/gongzian/src/pull-stream/test /Users/gongzian/src/pull-stream/cmake-build /Users/gongzian/src/pull-stream/cmake-build/test /Users/gongzian/src/pull-stream/cmake-build/test/CMakeFiles/pull-stream-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/pull-stream-test.dir/depend

