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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/Documents/github/read-write/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Documents/github/read-write/build

# Include any dependencies generated for this target.
include CMakeFiles/rw_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rw_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rw_lib.dir/flags.make

CMakeFiles/rw_lib.dir/rw.cpp.o: CMakeFiles/rw_lib.dir/flags.make
CMakeFiles/rw_lib.dir/rw.cpp.o: /home/david/Documents/github/read-write/src/rw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Documents/github/read-write/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rw_lib.dir/rw.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rw_lib.dir/rw.cpp.o -c /home/david/Documents/github/read-write/src/rw.cpp

CMakeFiles/rw_lib.dir/rw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rw_lib.dir/rw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Documents/github/read-write/src/rw.cpp > CMakeFiles/rw_lib.dir/rw.cpp.i

CMakeFiles/rw_lib.dir/rw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rw_lib.dir/rw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Documents/github/read-write/src/rw.cpp -o CMakeFiles/rw_lib.dir/rw.cpp.s

# Object files for target rw_lib
rw_lib_OBJECTS = \
"CMakeFiles/rw_lib.dir/rw.cpp.o"

# External object files for target rw_lib
rw_lib_EXTERNAL_OBJECTS =

librw_lib.a: CMakeFiles/rw_lib.dir/rw.cpp.o
librw_lib.a: CMakeFiles/rw_lib.dir/build.make
librw_lib.a: CMakeFiles/rw_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Documents/github/read-write/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librw_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rw_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rw_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rw_lib.dir/build: librw_lib.a

.PHONY : CMakeFiles/rw_lib.dir/build

CMakeFiles/rw_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rw_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rw_lib.dir/clean

CMakeFiles/rw_lib.dir/depend:
	cd /home/david/Documents/github/read-write/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Documents/github/read-write/src /home/david/Documents/github/read-write/src /home/david/Documents/github/read-write/build /home/david/Documents/github/read-write/build /home/david/Documents/github/read-write/build/CMakeFiles/rw_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rw_lib.dir/depend

