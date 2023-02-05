#include "../inc/util.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 128

static
char *
package_to_info_command(char *arg)
{
	char *command = malloc(MAX_STR_LEN);
	memset(command, 0, MAX_STR_LEN);
	strcat(command, "pacman -Qi ");
	strncat(command, arg, 116);
	return command;
}

void
test(char *package_name)
{
	FILE *out;
	char buf[10240];

	char *command = package_to_info_command(package_name);
	printf("%s\n", command);

	out = popen(command, "r");
	if (out == NULL) {
		fprintf(stderr, "Error: can't run command!");
		return;
	}

	while (fgets(buf, sizeof(buf), out) != NULL) {
		printf("%s", buf);
	}

	pclose(out);
}
