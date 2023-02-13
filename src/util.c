#include "../inc/pacfo.h"
#include "../inc/util.h"
#include "../inc/str.h"
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
parse_package(__pacinfo_pkg *pkg, char *package_name)
{
	FILE *out;
	char buf[sizeof(__pacinfo_str)];

	char *command = package_to_info_command(package_name);

	out = popen(command, "r");
	if (out == NULL) {
		fprintf(stderr, "Error: can't run command!");
		return;
	}

	int i = 0;
	while (fgets(buf, sizeof(buf), out) != NULL) {
		if (i < LINES_LEN) {
			parse_pacinfo_str(&pkg->lines[i], buf, i);
		} else { break; }
		i++;
	}

	pclose(out);
}

void
get_all_packages()
{
	FILE *out;
	char buf[MAX_STR_LEN];

	out = popen("pacman -Qq", "r");
	if (out == NULL) {
		fprintf(stderr, "Error: can't run command!");
		return;
	}

	int count = 0;
	__pacinfo_pkg pkg;
	while (fgets(buf, sizeof(buf), out) != NULL) {
		buf[strlen(buf) - 1] = '\0';
		parse_package(&pkg, buf);
		count++;
		printf("%s :: %s : %s\n",
			pkg.lines[NAME].content,
			pkg.lines[INSTALL_REASON].name,
			pkg.lines[INSTALL_REASON].content
		);
	}
	printf("Scanned %d packages!\n", count);

	pclose(out);
}

void
debug_line(__pacinfo_str pstr)
{
	printf("'%s' :: %d :: '%s'\n",
		pstr.name,
		pstr.type,
		pstr.content
	);
}

void
debug_package(__pacinfo_pkg pkg)
{
	for (int i = 0; i < LINES_LEN; i++) {
		debug_line(pkg.lines[i]);
	}
}

