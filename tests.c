#if TEST___PROGNAME
int
main(void)
{
	extern char *__progname;

	return !__progname;
}
#endif /* TEST___PROGNAME */
#if TEST_ENDIAN_H
#ifdef __linux__
# define _DEFAULT_SOURCE
#endif
#include <endian.h>

int
main(void)
{
	return !htole32(23);
}
#endif /* TEST_ENDIAN_H */
#if TEST_ERR
/*
 * Copyright (c) 2015 Ingo Schwarze <schwarze@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <errno.h>

int
main(void)
{
	warnx("%d. warnx", 1);
	warnc(ENOENT, "%d. warn", ENOENT);
	warn("%d. warn", 2);
	err(0, "%d. err", 3);
	errx(0, "%d. err", 3);
	errc(0, ENOENT, "%d. err", 3);
	/* NOTREACHED */
	return 1;
}
#endif /* TEST_ERR */
#if TEST_GETDTABLECOUNT
#include <unistd.h>

int
main(void)
{
	return getdtablecount() == 0;
}
#endif	/* TEST_GETDTABLECOUNT */
#if TEST_GETEXECNAME
#include <stdlib.h>

int
main(void)
{
	const char * progname;

	progname = getexecname();
	return progname == NULL;
}
#endif /* TEST_GETEXECNAME */
#if TEST_GETPROGNAME
#include <stdlib.h>

int
main(void)
{
	const char * progname;

	progname = getprogname();
	return progname == NULL;
}
#endif /* TEST_GETPROGNAME */
#if TEST_LIBEVENT
#include <event.h>

int
main(void)
{
	struct event ev;

	event_set(&ev, 0, EV_READ, NULL, NULL);
	event_add(&ev, NULL);
	event_del(&ev);
	return 0;
}
#endif	/* TEST_LIBEVENT */
#if TEST_LIBEVENT2
#include <event2/event.h>
#include <event2/event_compat.h>
#include <event2/event_struct.h>
#include <event2/buffer.h>
#include <event2/buffer_compat.h>
#include <event2/bufferevent.h>
#include <event2/bufferevent_struct.h>
#include <event2/bufferevent_compat.h>

int
main(void)
{
	struct event ev;

	event_set(&ev, 0, EV_READ, NULL, NULL);
	event_add(&ev, NULL);
	event_del(&ev);
	return 0;
}
#endif	/* TEST_LIBEVENT2 */
#if TEST_LIB_SOCKET
#include <sys/socket.h>

int
main(void)
{
	int fds[2], c;

	c = socketpair(AF_UNIX, SOCK_STREAM, 0, fds);
	return c == -1;
}
#endif /* TEST_LIB_SOCKET */
#if TEST_OSBYTEORDER_H
#include <libkern/OSByteOrder.h>

int
main(void)
{
	return !OSSwapHostToLittleInt32(23);
}
#endif /* TEST_OSBYTEORDER_H */
#if TEST_PATH_MAX
/*
 * POSIX allows PATH_MAX to not be defined, see
 * http://pubs.opengroup.org/onlinepubs/9699919799/functions/sysconf.html;
 * the GNU Hurd is an example of a system not having it.
 *
 * Arguably, it would be better to test sysconf(_SC_PATH_MAX),
 * but since the individual *.c files include "config.h" before
 * <limits.h>, overriding an excessive value of PATH_MAX from
 * "config.h" is impossible anyway, so for now, the simplest
 * fix is to provide a value only on systems not having any.
 * So far, we encountered no system defining PATH_MAX to an
 * impractically large value, even though POSIX explicitly
 * allows that.
 *
 * The real fix would be to replace all static buffers of size
 * PATH_MAX by dynamically allocated buffers.  But that is
 * somewhat intrusive because it touches several files and
 * because it requires changing struct mlink in mandocdb.c.
 * So i'm postponing that for now.
 */

#include <limits.h>
#include <stdio.h>

int
main(void)
{
	printf("PATH_MAX is defined to be %ld\n", (long)PATH_MAX);
	return 0;
}
#endif /* TEST_PATH_MAX */
#if TEST_PLEDGE
#include <unistd.h>

int
main(void)
{
	return !!pledge("stdio", NULL);
}
#endif /* TEST_PLEDGE */
#if TEST_PROGRAM_INVOCATION_SHORT_NAME
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <errno.h>

int
main(void)
{

	return !program_invocation_short_name;
}
#endif /* TEST_PROGRAM_INVOCATION_SHORT_NAME */
#if TEST_SETRESGID
#define _GNU_SOURCE /* linux */
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
	return setresgid(-1, -1, -1) == -1;
}
#endif /* TEST_SETRESGID */
#if TEST_SETRESUID
#define _GNU_SOURCE /* linux */
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
	return setresuid(-1, -1, -1) == -1;
}
#endif /* TEST_SETRESUID */
#if TEST_SOCK_NONBLOCK
/*
 * Linux doesn't (always?) have this.
 */

#include <sys/socket.h>

int
main(void)
{
	int fd[2];
	socketpair(AF_UNIX, SOCK_STREAM|SOCK_NONBLOCK, 0, fd);
	return 0;
}
#endif /* TEST_SOCK_NONBLOCK */
#if TEST_STATIC
int
main(void)
{
	return 0; /* not meant to do anything */
}
#endif /* TEST_STATIC */
#if TEST_STRLCAT
#include <string.h>

int
main(void)
{
	char buf[3] = "a";
	return ! (strlcat(buf, "b", sizeof(buf)) == 2 &&
	    buf[0] == 'a' && buf[1] == 'b' && buf[2] == '\0');
}
#endif /* TEST_STRLCAT */
#if TEST_STRLCPY
#include <string.h>

int
main(void)
{
	char buf[2] = "";
	return ! (strlcpy(buf, "a", sizeof(buf)) == 1 &&
	    buf[0] == 'a' && buf[1] == '\0');
}
#endif /* TEST_STRLCPY */
#if TEST_STRTONUM
/*
 * Copyright (c) 2015 Ingo Schwarze <schwarze@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifdef __NetBSD__
# define _OPENBSD_SOURCE
#endif
#include <stdlib.h>

int
main(void)
{
	const char *errstr;

	if (strtonum("1", 0, 2, &errstr) != 1)
		return 1;
	if (errstr != NULL)
		return 2;
	if (strtonum("1x", 0, 2, &errstr) != 0)
		return 3;
	if (errstr == NULL)
		return 4;
	if (strtonum("2", 0, 1, &errstr) != 0)
		return 5;
	if (errstr == NULL)
		return 6;
	if (strtonum("0", 1, 2, &errstr) != 0)
		return 7;
	if (errstr == NULL)
		return 8;
	return 0;
}
#endif /* TEST_STRTONUM */
#if TEST_SYS_BYTEORDER_H
#include <sys/byteorder.h>

int
main(void)
{
	return !LE_32(23);
}
#endif /* TEST_SYS_BYTEORDER_H */
#if TEST_SYS_ENDIAN_H
#include <sys/endian.h>

int
main(void)
{
	return !htole32(23);
}
#endif /* TEST_SYS_ENDIAN_H */
#if TEST_SYS_QUEUE
#include <sys/queue.h>
#include <stddef.h>

struct foo {
	int bar;
	TAILQ_ENTRY(foo) entries;
};

TAILQ_HEAD(fooq, foo);

int
main(void)
{
	struct fooq foo_q, bar_q;
	struct foo *p, *tmp;
	int i = 0;

	TAILQ_INIT(&foo_q);
	TAILQ_INIT(&bar_q);

	/*
	 * Use TAILQ_FOREACH_SAFE because some systems (e.g., Linux)
	 * have TAILQ_FOREACH but not the safe variant.
	 */

	TAILQ_FOREACH_SAFE(p, &foo_q, entries, tmp)
		p->bar = i++;

	/* Test for newer macros as well. */

	TAILQ_CONCAT(&foo_q, &bar_q, entries);
	return 0;
}
#endif /* TEST_SYS_QUEUE */
#if TEST_WAIT_ANY
#include <sys/wait.h>

int
main(void)
{
	int st;

	return waitpid(WAIT_ANY, &st, WNOHANG) != -1;
}
#endif /* TEST_WAIT_ANY */
