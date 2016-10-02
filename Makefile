# *******************************************************************************
#   This program is free software; you can redistribute it and/or modify it
#   under the terms of the GNU General Public License version 2 as published by
#   the Free Software Foundation.
#
#   This program is distributed in the hope that it will be useful, but WITHOUT
#   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
#   version 2 for more details.
#
#   You should have received a copy of the GNU General Public License version 2
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
#   USA.
#
#   For further information contact:
#   icaro.lmag@gmail.com
#   mateusplpl@gmail.com
# *******************************************************************************

PROJECTNAME = compendium-lib
DOXYFILE    = Doxyfile
DOCDIR      = ./doc
MODULES     = ./modules

include ${MODULES}/Makefile.top

DOXYVERSION = $(shell doxygen --version)
MODULESDIRS = $(shell find ${MODULES} -maxdepth 2 -type f -name "Makefile" -exec dirname {} \;)

__default__: release

all build env run:
	@for i in ${MODULESDIRS}; do $(MAKE) -C $$i $@ && echo || echo "${ERROR}"; done

clean:
	@if [ -d ${DOCDIR} ]; then rm -r ${DOCDIR}; fi
	@for i in ${MODULESDIRS}; do $(MAKE) -C $$i $@ && echo || echo "${ERROR}"; done

doc:
	@if [ ! -d ${DOCDIR} ]; then mkdir -p ${DOCDIR}; fi
	@echo -n "${call color,34,Generating} ${DOXYFILE} ... "
	@echo \
	"PROJECT_NAME           = \"${PROJECTNAME}\"\n"\
	"FULL_PATH_NAMES        = NO\n"\
	"INPUT                  = ../\n"\
	"RECURSIVE              = YES" > ${DOCDIR}/${DOXYFILE} && ${CHECK}
	@echo -n "${call color,34,Generating} documentation HTML ... "
	@cd ${DOCDIR} && doxygen ${DOXYFILE} > /dev/null 2>&1 && ${CHECK}
	@echo -n "${call color,34,Generating} documentation PDF ... "
	@${MAKE} -sC ${DOCDIR}/latex pdf > /dev/null 2>&1 && ${CHECK}

release install uninstall:
	@$(MAKE) -sC ${MODULES} $@

.PHONY: clean doc
