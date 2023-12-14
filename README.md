MIT6.S081 Notes
===============

https://pdos.csail.mit.edu/6.S081/2021/

Xv6 System calls
----------------

	int fork()                             // Create a process, return child’s PID.
	int exit(int status)                   // Terminate the current process; status reported to wait(). No return.
	int wait(int *status)                  // Wait for a child to exit; exit status in *status; returns child PID.
	int kill(int pid)                      // Terminate process PID. Returns 0, or -1 for error.
	int getpid()                           // Return the current process’s PID.
	int sleep(int n)                       // Pause for n clock ticks.
	int exec(char *file, char *argv[])     // Load a file and execute it with arguments; only returns if error.
	char *sbrk(int n)                      // Grow process’s memory by n bytes. Returns start of new memory.

	int open(char *file, int flags)        // Open a file; flags indicate read/write; returns an fd (file descriptor).
	int write(int fd, char *buf, int n)    // Write n bytes from buf to file descriptor fd; returns n.
	int read(int fd, char *buf, int n)     // Read n bytes into buf; returns number read; or 0 if end of file.
	int close(int fd)                      // Release open file fd.
	int dup(int fd)                        // Return a new file descriptor referring to the same file as fd.
	int pipe(int p[])                      // Create a pipe, put read/write file descriptors in p[0] and p[1].

	int chdir(char *dir)                   // Change the current directory.
	int mkdir(char *dir)                   // Create a new directory.
	int mknod(char *file, int, int)        // Create a device file. 
	int fstat(int fd, struct stat *st)     // Place info about an open file into *st.
	int stat(char *file, struct stat *st)  // Place info about a named file into *st.
	int link(char *file1, char *file2)     // Create another name (file2) for the file file1.
	int unlink(char *file)                 // Remove a file.

Compiling with Docker
---------------------

Create docker container. You only need to run this once.

	local$ docker run -it -v `pwd`/xv6:/xv6 --name xv6 debian:12

Once logged in, install the dependencies.
`make qemu` runs xv6 with qemu, you should see a prompt.

	xv6$ apt update
	xv6$ apt install -y git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
	xv6$ cd /xv6/xv6-riscv
	xv6$ make qemu
	...blah blah...
	init: starting sh
	$

Note: To exit qemu emulation press `Control-A` followed by `X`.

To start and connect to the container:

	local$ docker start xv6 && docker attach xv6
