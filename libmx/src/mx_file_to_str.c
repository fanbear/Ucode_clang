#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *mx_file_to_str(const char *filename) {
	char *target;
	int length = 0;
	int i = 0;
	char buffer[1];
	int file_descriptor;

	if (filename == NULL)
		return NULL;
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
		return NULL;
	while (read(file_descriptor, buffer, 1))
		length++;
	if (close(file_descriptor) < 0)
        return NULL;
    else
        close(file_descriptor);
	target = (char *) malloc(sizeof(char) * (length + 1));
	if (target == NULL)
		return NULL;
	file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor < 0)
        return NULL;
	while (read(file_descriptor, buffer, 1)) {
		target[i] = buffer[0];
		i++;
	}
	target[i] = '\0';
	if (close(file_descriptor) < 0)
		return NULL;
	else
		close(file_descriptor);
	return target;
}
