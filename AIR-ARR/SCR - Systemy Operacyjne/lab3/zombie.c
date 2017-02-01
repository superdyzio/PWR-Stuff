#include <stdio.h>

int main() {
	if (fork() == 0) {
		sleep(3);
		exit(0);
	}
	sleep(10);
	wait(NULL);
}
