import Build_Common as Common
from SCons.Environment import Environment
import os

print("Build")

env = Environment(tools=["mingw"], ENV = os.environ)

EXE_OUT = f"{Common.project_directory}/build/Main.exe"

# Common.print_dep()

env.Program(
    EXE_OUT,
    Common.CPPFILES,
    LIBPATH=  Common.LIBPATH,
    LIBS=     Common.LIBS,
    CPPPATH=  Common.HEADERPATH,
    CPPFLAGS= Common.CPPFLAGS
)