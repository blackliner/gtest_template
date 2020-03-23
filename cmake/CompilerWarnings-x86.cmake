# x86-specific Compiler Settings add compiler settings for x86 architecture
# here. Architecture-independent compiler settings must be placed inside the
# CompilerSettgins.cmake file, and not here.

ADD_COMPILE_OPTIONS ("-Wall")
ADD_COMPILE_OPTIONS ("-Wextra")
ADD_COMPILE_OPTIONS ("-Wwrite-strings")
ADD_COMPILE_OPTIONS ("-Wunreachable-code")
ADD_COMPILE_OPTIONS ("-Wpointer-arith")
ADD_COMPILE_OPTIONS ("-Winit-self")
ADD_COMPILE_OPTIONS ("-Wredundant-decls")
ADD_COMPILE_OPTIONS ("-Wpedantic")
ADD_COMPILE_OPTIONS ("-Wshadow")
ADD_COMPILE_OPTIONS ("-Wfloat-equal")
ADD_COMPILE_OPTIONS ("-fdiagnostics-color=always")

ADD_COMPILE_OPTIONS ("-Werror")
ADD_COMPILE_OPTIONS ("-Wno-error=deprecated-declarations")

ADD_COMPILE_OPTIONS ("-pedantic-errors")
