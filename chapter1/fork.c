#include <stdio.h>
#include <stdlib.h> // exit wait
#include <unistd.h> // fork

int main() {
	int pid = fork();
	if (pid < 0) {
		fprintf(stderr, "pid = %d < 0\n", pid);
	} else if (pid == 0) {
		printf("child: exiting\n");
		exit(0);
	} else {
		printf("parent: created child %d\n", pid);
		int status;
		int child = wait(&status);
		printf("parent: child %d exits with status %d\n", child, status);
	}
}
