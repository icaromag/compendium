include Makefile.top

MODULE        = compendium
VERSION       = 1.0.0
DESCRIPTION   =
MAIN          = ./main.cpp

HEADERS       = $(shell find . -type f -path "*include/*.h")
MODULES       = $(shell find . -type f -path "*src/*.cpp")
INCLUDE       = $(addprefix -I , $(dir ${HEADERS}))
MODULECONF    = ${MODULE}.conf
MODULEOBJS    = ${MODULES:.cpp=.o}
MODULEPC      = ${MODULE}.pc
SOURCES       = ${MAIN} ${MODULES}
SYMLINK       = lib${MODULE}.so

include Makefile.build

release: ${OBJECTS} ${SHAREDLIB}

install: ${MODULEPC} ${MODULECONF}
	@echo -n "\33[32;5mInstalling\33[m ... " && \
	if [ ! -d ${INCLUDECORE} ]; then mkdir -p ${INCLUDECORE}; fi && \
	cp ${HEADERS} ${INCLUDECORE} && \
	if [ ! -d ${INSTALLDIR} ]; then mkdir -p ${INSTALLDIR}; fi && \
	cp ${OUTDIR}/${SHAREDLIB} ${INSTALLDIR} && \
	ln -sf ${INSTALLDIR}/${SHAREDLIB} ${INSTALLDIR}/${SYMLINK} && \
	ldconfig && ${CHECK}

uninstall:
	@echo -n "\33[33;5mUninstalling\33[m ... " && \
	rm -f ${LDSOCONFDIR}/${MODULECONF} && \
	rm -f ${PKGDIR}/${MODULEPC} && \
	rm -rf ${INCLUDECOMPENDIUM} && \
	rm -rf ${LIBCOMPENDIUM} && \
	ldconfig && ${CHECK}
