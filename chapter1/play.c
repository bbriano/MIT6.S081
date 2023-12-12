#include <stdio.h>         // printf
#include <unistd.h>        // getpid read close
#include <fcntl.h>         // open O_RDONLY

int main() {
	int pid = getpid();
	printf("the current pid is %d\n", pid);
	printf("\n");

	int fd = open("helo", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("\n");

	char buf[1024];
	int n = read(fd, buf, 1024);
	printf("n = %d\n", n);
	printf("%s\n", buf);
	printf("\n");

	int err = close(fd);
	printf("err = %d\n", err);
	err = close(fd);
	printf("err = %d\n", err);
	printf("\n");
}
