# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/unlimitediw/CLionProjects/Leet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/unlimitediw/CLionProjects/Leet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Leet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Leet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Leet.dir/flags.make

CMakeFiles/Leet.dir/main.cpp.o: CMakeFiles/Leet.dir/flags.make
CMakeFiles/Leet.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/unlimitediw/CLionProjects/Leet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Leet.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Leet.dir/main.cpp.o -c /Users/unlimitediw/CLionProjects/Leet/main.cpp

CMakeFiles/Leet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Leet.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/unlimitediw/CLionProjects/Leet/main.cpp > CMakeFiles/Leet.dir/main.cpp.i

CMakeFiles/Leet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Leet.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/unlimitediw/CLionProjects/Leet/main.cpp -o CMakeFiles/Leet.dir/main.cpp.s

# Object files for target Leet
Leet_OBJECTS = \
"CMakeFiles/Leet.dir/main.cpp.o"

# External object files for target Leet
Leet_EXTERNAL_OBJECTS =

Leet: CMakeFiles/Leet.dir/main.cpp.o
Leet: CMakeFiles/Leet.dir/build.make
Leet: CMakeFiles/Leet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/unlimitediw/CLionProjects/Leet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Leet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Leet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Leet.dir/build: Leet

.PHONY : CMakeFiles/Leet.dir/build

CMakeFiles/Leet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Leet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Leet.dir/clean

CMakeFiles/Leet.dir/depend:
	cd /Users/unlimitediw/CLionProjects/Leet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/unlimitediw/CLionProjects/Leet /Users/unlimitediw/CLionProjects/Leet /Users/unlimitediw/CLionProjects/Leet/cmake-build-debug /Users/unlimitediw/CLionProjects/Leet/cmake-build-debug /Users/unlimitediw/CLionProjects/Leet/cmake-build-debug/CMakeFiles/Leet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Leet.dir/depend

