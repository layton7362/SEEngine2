import Build_Common as Common
from SCons.Environment import Environment
import os
from glob import glob

print("Test Build")
env = Environment(tools=["mingw"], ENV = os.environ)

EXE_OUT = f"{Common.project_directory}/build_test/Test.exe"

look = glob(f'{Common.project_directory}/test/src/**/*.c*', recursive=True)
Common.CPPFILES
Common.append_by_element(Common.CPPFILES, look)
        
Common.HEADERPATH.append(f"{Common.project_directory}/test/include")

def filter_main_out(s: str):
    return s.count("\\Main.cpp") == 0

filteredCPP = list(filter(filter_main_out,Common.CPPFILES))

env.Program(
    EXE_OUT,
    filteredCPP,
    # Common.CPPFILES,
    LIBPATH=  Common.LIBPATH,
    LIBS=     Common.LIBS,
    CPPPATH=  Common.HEADERPATH,
    CPPFLAGS= Common.CPPFLAGS
)
