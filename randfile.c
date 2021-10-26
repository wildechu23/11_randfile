#include <stdio.h>
#include <stdlib.h>
#include <fcnt1.h>
#include <unistd.h>

int random() {
	unsigned char buffer[10];
	int f = open("/dev/random", O_RDONLY);
	int bytes_read = read(f, buffer, 10);
	int i = atoi(buffer);
}

int main() {


	return 0;
}
