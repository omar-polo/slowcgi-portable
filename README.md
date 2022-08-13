# slowcgi-portable

This is an **unofficial** portable version of [slowcgi(8)][slowcgi], a
FastCGI to CGI wrapper server.  It's intended to ship with as little
changes as possible to allow it to compile and work on a variety of
systems and otherwise follow closely the development in the OpenBSD
src tree.  All portable-specific commits have the "portable:" prefix
in the log message.

[slowcgi]: https://man.openbsd.org/slowcgi

The versioning scheme follows the OpenBSD one, that's why the first
version is 7.2.

## Building

The dependencies are:

 - libevent

and optionally pkg-config.

To build, issue:

	$ ./configure
	$ make
	# make install # eventually

The build can be customized by passing arguments to the configure
script or by using a `configure.local` file; see `./configure -h` and
[`configure.local.example`](configure.local.example) for more
information.

For Linux users with libbsd installed, the configure script can be
instructed to use libbsd as follows:

	CFLAGS="$(pkg-config --cflags libbsd-overlay)" \
	    ./configure LDFLAGS="$(pkg-config --libs libbsd-overlay)"
