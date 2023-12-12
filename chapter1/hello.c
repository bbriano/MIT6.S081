#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	char *s = "hello, world\n";
	write(1, s, strlen(s));
}
