# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /opt/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/Documents/github/read-write

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Documents/github/read-write/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tests-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tests-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests-test.dir/flags.make

CMakeFiles/tests-test.dir/tests/tests.cpp.o: CMakeFiles/tests-test.dir/flags.make
CMakeFiles/tests-test.dir/tests/tests.cpp.o: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Documents/github/read-write/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests-test.dir/tests/tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests-test.dir/tests/tests.cpp.o -c /home/david/Documents/github/read-write/tests/tests.cpp

CMakeFiles/tests-test.dir/tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests-test.dir/tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Documents/github/read-write/tests/tests.cpp > CMakeFiles/tests-test.dir/tests/tests.cpp.i

CMakeFiles/tests-test.dir/tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests-test.dir/tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Documents/github/read-write/tests/tests.cpp -o CMakeFiles/tests-test.dir/tests/tests.cpp.s

CMakeFiles/tests-test.dir/src/rw.cpp.o: CMakeFiles/tests-test.dir/flags.make
CMakeFiles/tests-test.dir/src/rw.cpp.o: ../src/rw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Documents/github/read-write/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests-test.dir/src/rw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests-test.dir/src/rw.cpp.o -c /home/david/Documents/github/read-write/src/rw.cpp

CMakeFiles/tests-test.dir/src/rw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests-test.dir/src/rw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Documents/github/read-write/src/rw.cpp > CMakeFiles/tests-test.dir/src/rw.cpp.i

CMakeFiles/tests-test.dir/src/rw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests-test.dir/src/rw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Documents/github/read-write/src/rw.cpp -o CMakeFiles/tests-test.dir/src/rw.cpp.s

# Object files for target tests-test
tests__test_OBJECTS = \
"CMakeFiles/tests-test.dir/tests/tests.cpp.o" \
"CMakeFiles/tests-test.dir/src/rw.cpp.o"

# External object files for target tests-test
tests__test_EXTERNAL_OBJECTS =

tests-test: CMakeFiles/tests-test.dir/tests/tests.cpp.o
tests-test: CMakeFiles/tests-test.dir/src/rw.cpp.o
tests-test: CMakeFiles/tests-test.dir/build.make
tests-test: CMakeFiles/tests-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Documents/github/read-write/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests-test.dir/build: tests-test

.PHONY : CMakeFiles/tests-test.dir/build

CMakeFiles/tests-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests-test.dir/clean

CMakeFiles/tests-test.dir/depend:
	cd /home/david/Documents/github/read-write/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Documents/github/read-write /home/david/Documents/github/read-write /home/david/Documents/github/read-write/cmake-build-debug /home/david/Documents/github/read-write/cmake-build-debug /home/david/Documents/github/read-write/cmake-build-debug/CMakeFiles/tests-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests-test.dir/depend

