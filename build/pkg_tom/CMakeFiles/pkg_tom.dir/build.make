# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/nearlab/ws_tom/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nearlab/ws_tom/build

# Include any dependencies generated for this target.
include pkg_tom/CMakeFiles/pkg_tom.dir/depend.make

# Include the progress variables for this target.
include pkg_tom/CMakeFiles/pkg_tom.dir/progress.make

# Include the compile flags for this target's objects.
include pkg_tom/CMakeFiles/pkg_tom.dir/flags.make

pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o: pkg_tom/CMakeFiles/pkg_tom.dir/flags.make
pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o: /home/nearlab/ws_tom/src/pkg_tom/src/bicoag.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nearlab/ws_tom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o"
	cd /home/nearlab/ws_tom/build/pkg_tom && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o -c /home/nearlab/ws_tom/src/pkg_tom/src/bicoag.cpp

pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pkg_tom.dir/src/bicoag.cpp.i"
	cd /home/nearlab/ws_tom/build/pkg_tom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nearlab/ws_tom/src/pkg_tom/src/bicoag.cpp > CMakeFiles/pkg_tom.dir/src/bicoag.cpp.i

pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pkg_tom.dir/src/bicoag.cpp.s"
	cd /home/nearlab/ws_tom/build/pkg_tom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nearlab/ws_tom/src/pkg_tom/src/bicoag.cpp -o CMakeFiles/pkg_tom.dir/src/bicoag.cpp.s

pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.requires:

.PHONY : pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.requires

pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.provides: pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.requires
	$(MAKE) -f pkg_tom/CMakeFiles/pkg_tom.dir/build.make pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.provides.build
.PHONY : pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.provides

pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.provides.build: pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o


# Object files for target pkg_tom
pkg_tom_OBJECTS = \
"CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o"

# External object files for target pkg_tom
pkg_tom_EXTERNAL_OBJECTS =

/home/nearlab/ws_tom/devel/lib/libpkg_tom.so: pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o
/home/nearlab/ws_tom/devel/lib/libpkg_tom.so: pkg_tom/CMakeFiles/pkg_tom.dir/build.make
/home/nearlab/ws_tom/devel/lib/libpkg_tom.so: pkg_tom/CMakeFiles/pkg_tom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nearlab/ws_tom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/nearlab/ws_tom/devel/lib/libpkg_tom.so"
	cd /home/nearlab/ws_tom/build/pkg_tom && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pkg_tom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pkg_tom/CMakeFiles/pkg_tom.dir/build: /home/nearlab/ws_tom/devel/lib/libpkg_tom.so

.PHONY : pkg_tom/CMakeFiles/pkg_tom.dir/build

pkg_tom/CMakeFiles/pkg_tom.dir/requires: pkg_tom/CMakeFiles/pkg_tom.dir/src/bicoag.cpp.o.requires

.PHONY : pkg_tom/CMakeFiles/pkg_tom.dir/requires

pkg_tom/CMakeFiles/pkg_tom.dir/clean:
	cd /home/nearlab/ws_tom/build/pkg_tom && $(CMAKE_COMMAND) -P CMakeFiles/pkg_tom.dir/cmake_clean.cmake
.PHONY : pkg_tom/CMakeFiles/pkg_tom.dir/clean

pkg_tom/CMakeFiles/pkg_tom.dir/depend:
	cd /home/nearlab/ws_tom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nearlab/ws_tom/src /home/nearlab/ws_tom/src/pkg_tom /home/nearlab/ws_tom/build /home/nearlab/ws_tom/build/pkg_tom /home/nearlab/ws_tom/build/pkg_tom/CMakeFiles/pkg_tom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pkg_tom/CMakeFiles/pkg_tom.dir/depend

