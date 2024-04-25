from glob import glob
     
project_directory = "F:/MyProgProject/OpenGLC++"

def append_by_element(arr1, arr2):
    for e in arr2:
        arr1.append(e)

def print_dep():
    global HEADERPATH
    global CPPFILES
    print("Scons Header path:")
    print(HEADERPATH)
    print("============")
    print("Scons CPP path:")
    print(CPPFILES)
    print("============")

LIBPATH = [
    "F:/MyProgProject/Common/libs",
    "F:/MyProgProject/Common/libs/bullet3/Release"
    ]

CPPFILES = glob(f'{project_directory}/src/**/*.c*', recursive=True)
        
LIBS = [
    "glfw3",
    "OpenAL32"
    ]

HEADERPATH = [
       f"{project_directory}/include",
       "F:/MyProgProject/Common/include"
        ]

CPPFLAGS = [
        "-g",
        "-O0"
        ]   