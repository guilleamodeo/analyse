# analyse
Analyse test

Code Test that creates a OS X dynamic library and build two examples of use
one dynamically loading the library by dlopen()
one dependant by dynamically linking the app.

makefile is the makefile
analyse.c is the library itself
analyse.h is the header for dynamically linking
test_dep.c is the dependant test
test_dyn.c is the dynamic loading test
libAnalyse.A.dylib is the lib compiled with Xcode 10.3
test_dep is the dependant test compiled with Xcode 10.3
test_dyn is the dynamic test compiled with Xcode 10.3
in.txt is an example input with differnt inputs to try
out.txt is the output file from a test.
