# Makefile to build class 'helloworld' for Pure Data.
# Needs Makefile.pdlibbuilder as helper makefile for platform-dependent build
# settings and rules.

# library name
lib.name = listtosymbol

# input source file (class name == source file basename)
class.sources = listtosymbol.c

# all extra files to be included in binary distribution of the library
datafiles = listtosymbol-help.pd listtosymbol-meta.pd README.md

# include Makefile.pdlibbuilder from submodule directory 'pd-lib-builder'
include Makefile.pdlibbuilder
