#include <stdio.h>
#include <string.h>
#include <unistd.h> // exec

int main() {
	char *argv[] = {"echo", "hello", "world", 0};
	execv("/bin/echo", argv);
	printf("exec error\n");
}
