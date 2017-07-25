# analyse
Analyse test

Code Test that creates a OS X dynamic library and build two examples of use<br>
one dynamically loading the library by dlopen()<br>
one dependant by dynamically linking the app.<br>

makefile is the makefile<br>
analyse.c is the library itself<br>
analyse.h is the header for dynamically linking<br>
test_dep.c is the dependant test<br>
test_dyn.c is the dynamic loading test<br>
libAnalyse.A.dylib is the lib compiled with Xcode 10.3<br>
test_dep is the dependant test compiled with Xcode 10.3<br>
test_dyn is the dynamic test compiled with Xcode 10.3<br>
in.txt is an example input with differnt inputs to try<br>
out.txt is the output file from a test.<br>
