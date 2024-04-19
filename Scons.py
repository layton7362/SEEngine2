from ast import arg
from glob import glob
from SCons.Environment import Environment
import os

print("Build....")

args = ["bal"]
# args = sys.argv

isTest = True if len(args) > 1 and args[1] == "test" else False
EXE_OUT = "build/Main.exe" if not isTest else "build_test/Main.exe"

env = Environment(tools=["mingw"], ENV = os.environ)

project_directory = "F:/MyProgProject/OpenGLC++"

LIBPATH = []
LIBPATH.append("F:/MyProgProject/Common/libs")
CPPFILES = glob(f'{project_directory}/src/**/*.c*', recursive=True)

if isTest:
        CPPFILES = glob(f'{project_directory}/test/**/*.c*', recursive=True)

LIBS = [
        "glfw3"
        ]

HEADERPATH= [
       f"{project_directory}/include",
       "F:/MyProgProject/Common/include"
        ]

CPPFLAGS = [
        "-g",
        "-O0"
        ]   

env.Program(
    EXE_OUT,
    CPPFILES,
    LIBPATH=  LIBPATH,
    LIBS=     LIBS,
    CPPPATH=  HEADERPATH,
    CPPFLAGS= CPPFLAGS
)

