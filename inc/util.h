#ifndef __pacinfo__util_h
#define __pacinfo__util_h
#include "pacfo.h"

void
parse_package(__pacinfo_pkg *pkg, char *package_name);

void
get_all_packages();

void
debug_line(__pacinfo_str pstr);

void
debug_package(__pacinfo_pkg pkg);

#endif // __pacinfo__util_h
