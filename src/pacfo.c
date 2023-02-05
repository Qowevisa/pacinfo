#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "../inc/util.h"

int
main(int argc, char **argv)
{
	if (argc < 2) {
		exit(1);
	}

	test(argv[1]);

	return 0;
}
