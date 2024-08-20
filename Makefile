.POSIX:

XCFLAGS = ${CPPFLAGS} ${CFLAGS} -nostdlib -std=c99 -fPIC -pthread -D_XOPEN_SOURCE=700 \
		  -Wall -Wextra -Wpedantic \
		  -Wno-unused-parameter
XLDFLAGS = ${LDFLAGS} -shared -Wl,-soname,libgbm.so.1

LIBDIR ?= /lib64

OBJ = libgbm.o

all: libgbm.so.1.0.0

.c.o:
	${CC} ${XCFLAGS} -c -o $@ $<

libgbm.so.1.0.0: ${OBJ}
	${CC} ${XCFLAGS} -o $@ ${OBJ} ${XLDFLAGS}

install: libgbm.so.1.0.0
	mkdir -p ${DESTDIR}/usr${LIBDIR}
	cp -f libgbm.so.1.0.0 ${DESTDIR}/usr${LIBDIR}/libgbm.so.1.0.0
	ln -rsf ${DESTDIR}/usr${LIBDIR}/libgbm.so.1.0.0 ${DESTDIR}/usr${LIBDIR}/libgbm.so.1
	ln -rsf ${DESTDIR}/usr${LIBDIR}/libgbm.so.1 ${DESTDIR}/usr${LIBDIR}/libgbm.so
	mkdir -p ${DESTDIR}/usr${LIBDIR}/pkgconfig
	sed -i gbm.pc s/__libdir__/\${LIBDIR}/g
	cp -f gbm.pc ${DESTDIR}/usr${LIBDIR}/pkgconfig/gbm.pc

uninstall:
	rm -f ${DESTDIR}/usr${LIBDIR}/libgbm.so.1.0.0 ${DESTDIR}/usr${LIBDIR}/libgbm.so.1 ${DESTDIR}/usr${LIBDIR}/libgbm.so ${DESTDIR}/usr${LIBDIR}/pkgconfig/gbm.pc
clean:
	rm -f libgbm.so.1.0.0 ${OBJ}

.PHONY: all clean install uninstall
