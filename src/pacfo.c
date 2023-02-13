#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "../inc/pacfo.h"
#include "../inc/util.h"
#include "../inc/manage.h"

int
main(int argc, char **argv)
{
	if (argc < 1) {
		exit(1);
	}
	if (argv) {}

	// __pacinfo_pkg pkg;
	// parse_package(&pkg, argv[1]);

	// debug_package(pkg);

	get_all_packages();

	return 0;
}
