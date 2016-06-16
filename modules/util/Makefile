include ../Makefile.top

MODULE        = util
VERSION       = 1.0.0
DESCRIPTION   =
MAIN          = ./cppunit.cpp
AGRS          =
SOURCES       = ${MAIN} $(shell find .. -type f -path "*src/*.cpp")
INCLUDE       = $(addprefix -I , $(shell find .. -type d -name "include"))

include ../Makefile.build
