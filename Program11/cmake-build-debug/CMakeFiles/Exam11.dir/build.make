# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\C Programming\Exam11"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\C Programming\Exam11\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Exam11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exam11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exam11.dir/flags.make

CMakeFiles/Exam11.dir/main.c.obj: CMakeFiles/Exam11.dir/flags.make
CMakeFiles/Exam11.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\C Programming\Exam11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exam11.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Exam11.dir\main.c.obj   -c "D:\C Programming\Exam11\main.c"

CMakeFiles/Exam11.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exam11.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\C Programming\Exam11\main.c" > CMakeFiles\Exam11.dir\main.c.i

CMakeFiles/Exam11.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exam11.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\C Programming\Exam11\main.c" -o CMakeFiles\Exam11.dir\main.c.s

# Object files for target Exam11
Exam11_OBJECTS = \
"CMakeFiles/Exam11.dir/main.c.obj"

# External object files for target Exam11
Exam11_EXTERNAL_OBJECTS =

Exam11.exe: CMakeFiles/Exam11.dir/main.c.obj
Exam11.exe: CMakeFiles/Exam11.dir/build.make
Exam11.exe: CMakeFiles/Exam11.dir/linklibs.rsp
Exam11.exe: CMakeFiles/Exam11.dir/objects1.rsp
Exam11.exe: CMakeFiles/Exam11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\C Programming\Exam11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Exam11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Exam11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exam11.dir/build: Exam11.exe

.PHONY : CMakeFiles/Exam11.dir/build

CMakeFiles/Exam11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Exam11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Exam11.dir/clean

CMakeFiles/Exam11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\C Programming\Exam11" "D:\C Programming\Exam11" "D:\C Programming\Exam11\cmake-build-debug" "D:\C Programming\Exam11\cmake-build-debug" "D:\C Programming\Exam11\cmake-build-debug\CMakeFiles\Exam11.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Exam11.dir/depend

