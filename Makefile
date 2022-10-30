.PHONY: all clean distclean install

# Follow the OpenBSD release scheme.
VERSION =	7.2
PROG =		slowcgi
DISTNAME =	${PROG}-${VERSION}

SOURCES =	compats.c \
		slowcgi.c

OBJS =		${SOURCES:.c=.o}

DISTFILES =	Makefile \
		configure \
		queue.h \
		slowcgi.8 \
		${SOURCES} \
		tests.c

all: ${PROG}

Makefile.configure config.h: configure tests.c
	@echo "$@ is out of date; please run ./configure"
	@exit

include Makefile.configure

# -- targets --

${PROG}: ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS} ${LDADD}

clean:
	rm -f ${OBJS} ${PROG}

distclean: clean
	rm -f Makefile.configure config.h config.h.old config.log config.log.old

install: ${PROG}
	mkdir -p ${DESTDIR}${BINDIR}
	mkdir -p ${DESTDIR}${MANDIR}/man1
	${INSTALL_PROGRAM} ${PROG} ${DESTDIR}${BINDIR}
	${INSTALL_MAN} slowcgi.8 ${DESTDIR}${MANDIR}/man8/${PROG}.8

uninstall:
	rm ${DESTDIR}${BINDIR}/${PROG}
	rm ${DESTDIR}${MANDIR}/man8/${PROG}.8

# -- maintainer targets --

dist: ${DISTNAME}.sha256

${DISTNAME}.sha256: ${DISTNAME}.tar.gz
	sha256 ${DISTNAME}.tar.gz > $@

${DISTNAME}.tar.gz: ${DISTFILES}
	mkdir -p .dist/${DISTNAME}
	${INSTALL} -m 0644 ${DISTFILES} .dist/${DISTNAME}
	chmod 755 .dist/${DISTNAME}/configure
	cd .dist && tar zcf ../$@ ${DISTNAME}
	rm -rf .dist
