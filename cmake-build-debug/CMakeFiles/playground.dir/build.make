# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "/Users/zw/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/zw/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zw/code/C++_Projects/COSC480

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zw/code/C++_Projects/COSC480/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/playground.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/playground.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/playground.dir/flags.make

CMakeFiles/playground.dir/playground.cpp.o: CMakeFiles/playground.dir/flags.make
CMakeFiles/playground.dir/playground.cpp.o: ../playground.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/playground.dir/playground.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/playground.dir/playground.cpp.o -c /Users/zw/code/C++_Projects/COSC480/playground.cpp

CMakeFiles/playground.dir/playground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/playground.dir/playground.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zw/code/C++_Projects/COSC480/playground.cpp > CMakeFiles/playground.dir/playground.cpp.i

CMakeFiles/playground.dir/playground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/playground.dir/playground.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zw/code/C++_Projects/COSC480/playground.cpp -o CMakeFiles/playground.dir/playground.cpp.s

CMakeFiles/playground.dir/playground.cpp.o.requires:

.PHONY : CMakeFiles/playground.dir/playground.cpp.o.requires

CMakeFiles/playground.dir/playground.cpp.o.provides: CMakeFiles/playground.dir/playground.cpp.o.requires
	$(MAKE) -f CMakeFiles/playground.dir/build.make CMakeFiles/playground.dir/playground.cpp.o.provides.build
.PHONY : CMakeFiles/playground.dir/playground.cpp.o.provides

CMakeFiles/playground.dir/playground.cpp.o.provides.build: CMakeFiles/playground.dir/playground.cpp.o


CMakeFiles/playground.dir/MyLib.cpp.o: CMakeFiles/playground.dir/flags.make
CMakeFiles/playground.dir/MyLib.cpp.o: ../MyLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/playground.dir/MyLib.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/playground.dir/MyLib.cpp.o -c /Users/zw/code/C++_Projects/COSC480/MyLib.cpp

CMakeFiles/playground.dir/MyLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/playground.dir/MyLib.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zw/code/C++_Projects/COSC480/MyLib.cpp > CMakeFiles/playground.dir/MyLib.cpp.i

CMakeFiles/playground.dir/MyLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/playground.dir/MyLib.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zw/code/C++_Projects/COSC480/MyLib.cpp -o CMakeFiles/playground.dir/MyLib.cpp.s

CMakeFiles/playground.dir/MyLib.cpp.o.requires:

.PHONY : CMakeFiles/playground.dir/MyLib.cpp.o.requires

CMakeFiles/playground.dir/MyLib.cpp.o.provides: CMakeFiles/playground.dir/MyLib.cpp.o.requires
	$(MAKE) -f CMakeFiles/playground.dir/build.make CMakeFiles/playground.dir/MyLib.cpp.o.provides.build
.PHONY : CMakeFiles/playground.dir/MyLib.cpp.o.provides

CMakeFiles/playground.dir/MyLib.cpp.o.provides.build: CMakeFiles/playground.dir/MyLib.cpp.o


CMakeFiles/playground.dir/MyPlane.cpp.o: CMakeFiles/playground.dir/flags.make
CMakeFiles/playground.dir/MyPlane.cpp.o: ../MyPlane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/playground.dir/MyPlane.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/playground.dir/MyPlane.cpp.o -c /Users/zw/code/C++_Projects/COSC480/MyPlane.cpp

CMakeFiles/playground.dir/MyPlane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/playground.dir/MyPlane.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zw/code/C++_Projects/COSC480/MyPlane.cpp > CMakeFiles/playground.dir/MyPlane.cpp.i

CMakeFiles/playground.dir/MyPlane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/playground.dir/MyPlane.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zw/code/C++_Projects/COSC480/MyPlane.cpp -o CMakeFiles/playground.dir/MyPlane.cpp.s

CMakeFiles/playground.dir/MyPlane.cpp.o.requires:

.PHONY : CMakeFiles/playground.dir/MyPlane.cpp.o.requires

CMakeFiles/playground.dir/MyPlane.cpp.o.provides: CMakeFiles/playground.dir/MyPlane.cpp.o.requires
	$(MAKE) -f CMakeFiles/playground.dir/build.make CMakeFiles/playground.dir/MyPlane.cpp.o.provides.build
.PHONY : CMakeFiles/playground.dir/MyPlane.cpp.o.provides

CMakeFiles/playground.dir/MyPlane.cpp.o.provides.build: CMakeFiles/playground.dir/MyPlane.cpp.o


CMakeFiles/playground.dir/Camera.cpp.o: CMakeFiles/playground.dir/flags.make
CMakeFiles/playground.dir/Camera.cpp.o: ../Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/playground.dir/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/playground.dir/Camera.cpp.o -c /Users/zw/code/C++_Projects/COSC480/Camera.cpp

CMakeFiles/playground.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/playground.dir/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zw/code/C++_Projects/COSC480/Camera.cpp > CMakeFiles/playground.dir/Camera.cpp.i

CMakeFiles/playground.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/playground.dir/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zw/code/C++_Projects/COSC480/Camera.cpp -o CMakeFiles/playground.dir/Camera.cpp.s

CMakeFiles/playground.dir/Camera.cpp.o.requires:

.PHONY : CMakeFiles/playground.dir/Camera.cpp.o.requires

CMakeFiles/playground.dir/Camera.cpp.o.provides: CMakeFiles/playground.dir/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/playground.dir/build.make CMakeFiles/playground.dir/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/playground.dir/Camera.cpp.o.provides

CMakeFiles/playground.dir/Camera.cpp.o.provides.build: CMakeFiles/playground.dir/Camera.cpp.o


CMakeFiles/playground.dir/Process.cpp.o: CMakeFiles/playground.dir/flags.make
CMakeFiles/playground.dir/Process.cpp.o: ../Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/playground.dir/Process.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/playground.dir/Process.cpp.o -c /Users/zw/code/C++_Projects/COSC480/Process.cpp

CMakeFiles/playground.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/playground.dir/Process.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zw/code/C++_Projects/COSC480/Process.cpp > CMakeFiles/playground.dir/Process.cpp.i

CMakeFiles/playground.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/playground.dir/Process.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zw/code/C++_Projects/COSC480/Process.cpp -o CMakeFiles/playground.dir/Process.cpp.s

CMakeFiles/playground.dir/Process.cpp.o.requires:

.PHONY : CMakeFiles/playground.dir/Process.cpp.o.requires

CMakeFiles/playground.dir/Process.cpp.o.provides: CMakeFiles/playground.dir/Process.cpp.o.requires
	$(MAKE) -f CMakeFiles/playground.dir/build.make CMakeFiles/playground.dir/Process.cpp.o.provides.build
.PHONY : CMakeFiles/playground.dir/Process.cpp.o.provides

CMakeFiles/playground.dir/Process.cpp.o.provides.build: CMakeFiles/playground.dir/Process.cpp.o


CMakeFiles/playground.dir/Blob.cpp.o: CMakeFiles/playground.dir/flags.make
CMakeFiles/playground.dir/Blob.cpp.o: ../Blob.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/playground.dir/Blob.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/playground.dir/Blob.cpp.o -c /Users/zw/code/C++_Projects/COSC480/Blob.cpp

CMakeFiles/playground.dir/Blob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/playground.dir/Blob.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zw/code/C++_Projects/COSC480/Blob.cpp > CMakeFiles/playground.dir/Blob.cpp.i

CMakeFiles/playground.dir/Blob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/playground.dir/Blob.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zw/code/C++_Projects/COSC480/Blob.cpp -o CMakeFiles/playground.dir/Blob.cpp.s

CMakeFiles/playground.dir/Blob.cpp.o.requires:

.PHONY : CMakeFiles/playground.dir/Blob.cpp.o.requires

CMakeFiles/playground.dir/Blob.cpp.o.provides: CMakeFiles/playground.dir/Blob.cpp.o.requires
	$(MAKE) -f CMakeFiles/playground.dir/build.make CMakeFiles/playground.dir/Blob.cpp.o.provides.build
.PHONY : CMakeFiles/playground.dir/Blob.cpp.o.provides

CMakeFiles/playground.dir/Blob.cpp.o.provides.build: CMakeFiles/playground.dir/Blob.cpp.o


# Object files for target playground
playground_OBJECTS = \
"CMakeFiles/playground.dir/playground.cpp.o" \
"CMakeFiles/playground.dir/MyLib.cpp.o" \
"CMakeFiles/playground.dir/MyPlane.cpp.o" \
"CMakeFiles/playground.dir/Camera.cpp.o" \
"CMakeFiles/playground.dir/Process.cpp.o" \
"CMakeFiles/playground.dir/Blob.cpp.o"

# External object files for target playground
playground_EXTERNAL_OBJECTS =

playground: CMakeFiles/playground.dir/playground.cpp.o
playground: CMakeFiles/playground.dir/MyLib.cpp.o
playground: CMakeFiles/playground.dir/MyPlane.cpp.o
playground: CMakeFiles/playground.dir/Camera.cpp.o
playground: CMakeFiles/playground.dir/Process.cpp.o
playground: CMakeFiles/playground.dir/Blob.cpp.o
playground: CMakeFiles/playground.dir/build.make
playground: CMakeFiles/playground.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable playground"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/playground.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/playground.dir/build: playground

.PHONY : CMakeFiles/playground.dir/build

CMakeFiles/playground.dir/requires: CMakeFiles/playground.dir/playground.cpp.o.requires
CMakeFiles/playground.dir/requires: CMakeFiles/playground.dir/MyLib.cpp.o.requires
CMakeFiles/playground.dir/requires: CMakeFiles/playground.dir/MyPlane.cpp.o.requires
CMakeFiles/playground.dir/requires: CMakeFiles/playground.dir/Camera.cpp.o.requires
CMakeFiles/playground.dir/requires: CMakeFiles/playground.dir/Process.cpp.o.requires
CMakeFiles/playground.dir/requires: CMakeFiles/playground.dir/Blob.cpp.o.requires

.PHONY : CMakeFiles/playground.dir/requires

CMakeFiles/playground.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/playground.dir/cmake_clean.cmake
.PHONY : CMakeFiles/playground.dir/clean

CMakeFiles/playground.dir/depend:
	cd /Users/zw/code/C++_Projects/COSC480/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zw/code/C++_Projects/COSC480 /Users/zw/code/C++_Projects/COSC480 /Users/zw/code/C++_Projects/COSC480/cmake-build-debug /Users/zw/code/C++_Projects/COSC480/cmake-build-debug /Users/zw/code/C++_Projects/COSC480/cmake-build-debug/CMakeFiles/playground.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/playground.dir/depend

