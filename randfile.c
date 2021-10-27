#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int random_num() {
	int f = open("/dev/random", O_RDONLY);
	int buffer;
	int bytes_read = read(f, &buffer, sizeof(&buffer));
	if(bytes_read != sizeof(&buffer)) printf("Not all bytes were read\n");
	// printf("%d", bytes_read);
	// int i = 0;
	// for(i; i < 10; i++) {
		// printf("%u ", buffer);
	// }
	close(f);
	return buffer;
}

int main() {
	int arr[10];
	int buffer[10];
	int i = 0;
	for(i; i < 10; i++) {
		arr[i] = random_num();
		printf("Random %d: %u\n", i, arr[i]);
	}

	int f = open("random.txt", O_WRONLY);
	int bytes_written = write(f, &arr, 5*sizeof(&arr));
	if(bytes_written != 5*sizeof(&arr)) printf("Not all bytes were written\n");
	// printf("%d\n", bytes_written);
	close(f);
	printf("\n\n");
	f = open("random.txt", O_RDONLY);
	int bytes_read = read(f, &buffer, 5*sizeof(&buffer));
	if(bytes_read != 5*sizeof(&arr)) printf("Not all bytes were read\n");
	// printf("%d\n", bytes_read);
	int j = 0;
	for(j; j < 10; j++) {
		printf("Random %d: %u\n", j, buffer[j]);
	}

	return 0;
}
