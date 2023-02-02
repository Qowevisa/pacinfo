#ifndef __iterm_tests_h
#define __iterm_tests_h
#include <stdio.h>

#define IND "###"

#define START() printf("\n%s TEST %s ENTER\n", IND, __FILE__)
#define SYNOPSYS(str) printf("%s   %s\n", IND, str)
#define END() printf("### TEST %s EXIT\n", __FILE__)

#endif // __iterm_tests_h
