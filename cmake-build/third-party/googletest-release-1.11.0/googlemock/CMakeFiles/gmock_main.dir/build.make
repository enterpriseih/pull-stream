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
include third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.make

# Include the progress variables for this target.
include third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/flags.make

third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/flags.make
third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: ../third-party/googletest-release-1.11.0/googlemock/src/gmock_main.cc
third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gongzian/src/pull-stream/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -MF CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.d -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /Users/gongzian/src/pull-stream/third-party/googletest-release-1.11.0/googlemock/src/gmock_main.cc

third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gongzian/src/pull-stream/third-party/googletest-release-1.11.0/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gongzian/src/pull-stream/third-party/googletest-release-1.11.0/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.a: third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_main.a: third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.a: third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gongzian/src/pull-stream/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgmock_main.a"
	cd /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.a
.PHONY : third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/build

third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/clean

third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /Users/gongzian/src/pull-stream/cmake-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gongzian/src/pull-stream /Users/gongzian/src/pull-stream/third-party/googletest-release-1.11.0/googlemock /Users/gongzian/src/pull-stream/cmake-build /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock /Users/gongzian/src/pull-stream/cmake-build/third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third-party/googletest-release-1.11.0/googlemock/CMakeFiles/gmock_main.dir/depend
