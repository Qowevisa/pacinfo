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
	if (argc < 2) {
		exit(1);
	}

	__pacinfo_pkg pkg;
	parse_package(&pkg, argv[1]);

	debug_package(pkg);

	create_manage_dir();

	return 0;
}
