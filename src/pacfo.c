#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int
main(int argc, char **argv)
{
	if (argc < 2) {
		exit(1);
	}
	FILE *out;
	char buf[10240];

	char command[128] = {0};
	strcat(command, "pacman -Qi ");
	strncat(command, argv[1], 116);
	printf("%s\n", command);

	out = popen(command, "r");
	if (out == NULL) {
		fprintf(stderr, "Error: can't run command!");
		exit(2);
	}

	while (fgets(buf, sizeof(buf), out) != NULL) {
		printf("%s", buf);
	}

	pclose(out);
	return 0;
}
