/* This program removes utmp entries by name or number */

#include <utmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>

void usage(char *name) {
    printf("Usage: %s [ user ] or [ tty ]\n", name);
    exit(1);
}

main(int argc, char **argv) {
    int fd;
    struct utmp utmp;
    int size;
    int match, tty = 0;

    if (argc!=2)
       usage(argv[0]);

    if ( !strncmp(argv[1],"tty",3) )
       tty++;

    fd = open("/home/alsdk/code/wtmp.bin",O_RDWR);
    if (fd >= 0) {
       size = read(fd, &utmp, sizeof(struct utmp));
       while ( size == sizeof(struct utmp) )
       {
          if ( tty ? ( !strcmp(utmp.ut_line, argv[1]) ) :
            ( !strcmp(utmp.ut_name, argv[1]) ) )
          {
			printf("ut_name: %s  ut_line: %s", utmp.ut_name, utmp.ut_line);
             lseek( fd, -sizeof(struct utmp), L_INCR );
			 strncpy(utmp.ut_name, "novekerollo", sizeof(utmp.ut_name));
             //bzero( &utmp, sizeof(struct utmp) );
             write( fd, &utmp, sizeof(struct utmp) );
          }
          size = read( fd, &utmp, sizeof(struct utmp) );
       }
    }
	else
		printf("ERROR, open()\n");

    close(fd);
}
