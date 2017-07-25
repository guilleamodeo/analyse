#   Mac OS X makefile for Analyse Library
#
#	Written by Guillermo Amodeo (cloud-nueve uk ltd.)
#

### Flags ###

mkANALYSE_LIB=libAnalyse.A.dylib

mkARCH=-arch x86_64
mkVERSION=1.0
mkCOMPAT=1.0

mkC_FLAGS=$(mkARCH) -Wall -o $@

mkLIB_FLAGS=$(mkC_FLAGS) -dynamiclib -current_version $(mkVERSION) -compatibility_version $(mkCOMPAT)
mkEXE_FLAGS=$(mkC_FLAGS)

### Commands ###

mkCC=gcc
mkCPP=g++

mkCC_LIB=$(mkCC)  $(mkLIB_FLAGS)
mkCC_EXE=$(mkCPP) $(mkC_FLAGS)

### Targets ###

dummy:
	@echo usage make [test_dep] [test_dyn] [all] [clean]

all: test_dep test_dyn

clean:
	rm -f test_dep
	rm -f test_dyn
	rm -f $(mkANALYSE_LIB)

$(mkANALYSE_LIB): analyse.c
	$(mkCC_LIB) analyse.c

test_dep: $(mkANALYSE_LIB) test_dep.cpp analyse.h
	$(mkCC_EXE) test_dep.cpp $(mkANALYSE_LIB) -lm

test_dyn: $(mkANALYSE_LIB) test_dyn.cpp analyse.h
	$(mkCC_EXE) test_dyn.cpp -ldl

