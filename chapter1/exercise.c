// Pingpong passses a byte back and forth between two processes
// using a pair of unix pipe.
//
// % cc exercise.c && for(i in `{seq 5}){ time a.out }
//         4.71 real         0.50 user         1.85 sys
//         4.49 real         0.48 user         1.75 sys
//         4.49 real         0.48 user         1.76 sys
//         4.49 real         0.48 user         1.76 sys
//         4.51 real         0.48 user         1.77 sys
// ~220,000 cycles per seconds

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 1000000

int main() {
	int p2c[2], c2p[2];
	int err = pipe(p2c);
	if (err != 0) {
		fprintf(stderr, "cannot create pipe\n");
		exit(1);
	}
	err = pipe(c2p);
	if (err != 0) {
		fprintf(stderr, "cannot create pipe\n");
		exit(1);
	}
	int pid = fork();
	if (pid < 0) {
		fprintf(stderr, "cannot fork\n");
		exit(1);
	} else if (pid == 0) {
		char buf[1];
		for (int i = 0; i < N; i++) {
			read(p2c[0], buf, 1);
			write(c2p[1], buf, 1);
		}
	} else {
		write(p2c[1], "x", 1);
		char buf[1];
		for (int i = 0; i < N; i++) {
			read(c2p[0], buf, 1);
			write(p2c[1], buf, 1);
		}
	}
}
