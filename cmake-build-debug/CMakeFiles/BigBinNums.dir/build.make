# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nyada\CLionProjects\BigBinNums

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BigBinNums.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BigBinNums.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigBinNums.dir/flags.make

CMakeFiles/BigBinNums.dir/main.cpp.obj: CMakeFiles/BigBinNums.dir/flags.make
CMakeFiles/BigBinNums.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigBinNums.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigBinNums.dir\main.cpp.obj -c C:\Users\nyada\CLionProjects\BigBinNums\main.cpp

CMakeFiles/BigBinNums.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigBinNums.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nyada\CLionProjects\BigBinNums\main.cpp > CMakeFiles\BigBinNums.dir\main.cpp.i

CMakeFiles/BigBinNums.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigBinNums.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nyada\CLionProjects\BigBinNums\main.cpp -o CMakeFiles\BigBinNums.dir\main.cpp.s

CMakeFiles/BigBinNums.dir/TBigNum.cpp.obj: CMakeFiles/BigBinNums.dir/flags.make
CMakeFiles/BigBinNums.dir/TBigNum.cpp.obj: ../TBigNum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BigBinNums.dir/TBigNum.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigBinNums.dir\TBigNum.cpp.obj -c C:\Users\nyada\CLionProjects\BigBinNums\TBigNum.cpp

CMakeFiles/BigBinNums.dir/TBigNum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigBinNums.dir/TBigNum.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nyada\CLionProjects\BigBinNums\TBigNum.cpp > CMakeFiles\BigBinNums.dir\TBigNum.cpp.i

CMakeFiles/BigBinNums.dir/TBigNum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigBinNums.dir/TBigNum.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nyada\CLionProjects\BigBinNums\TBigNum.cpp -o CMakeFiles\BigBinNums.dir\TBigNum.cpp.s

# Object files for target BigBinNums
BigBinNums_OBJECTS = \
"CMakeFiles/BigBinNums.dir/main.cpp.obj" \
"CMakeFiles/BigBinNums.dir/TBigNum.cpp.obj"

# External object files for target BigBinNums
BigBinNums_EXTERNAL_OBJECTS =

BigBinNums.exe: CMakeFiles/BigBinNums.dir/main.cpp.obj
BigBinNums.exe: CMakeFiles/BigBinNums.dir/TBigNum.cpp.obj
BigBinNums.exe: CMakeFiles/BigBinNums.dir/build.make
BigBinNums.exe: CMakeFiles/BigBinNums.dir/linklibs.rsp
BigBinNums.exe: CMakeFiles/BigBinNums.dir/objects1.rsp
BigBinNums.exe: CMakeFiles/BigBinNums.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BigBinNums.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BigBinNums.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigBinNums.dir/build: BigBinNums.exe

.PHONY : CMakeFiles/BigBinNums.dir/build

CMakeFiles/BigBinNums.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BigBinNums.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BigBinNums.dir/clean

CMakeFiles/BigBinNums.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nyada\CLionProjects\BigBinNums C:\Users\nyada\CLionProjects\BigBinNums C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug C:\Users\nyada\CLionProjects\BigBinNums\cmake-build-debug\CMakeFiles\BigBinNums.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigBinNums.dir/depend

