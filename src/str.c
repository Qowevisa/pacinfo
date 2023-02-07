#include "../inc/pacfo.h"
#include <string.h>
#include <stdlib.h>

#define name_equ_to(str) strcmp(pstr->name, str) == 0

void
parse_pacinfo_str(__pacinfo_str *pstr, const char *source)
{
	const char *p = source;
	int i;
	// Getting name from source
	for (i = 0; i < NAME_LEN; i++, p++) {
		pstr->name[i] = *p;
	}
	// Getting type of str
	//
	// It is the fastest way to get things done...
	if        (name_equ_to("Name            ")) {
		pstr->type = NAME;
	} else if (name_equ_to("Version         ")) {
		pstr->type = VERSION;
	} else if (name_equ_to("Description     ")) {
		pstr->type = DESCRIPTION;
	} else if (name_equ_to("Architecture    ")) {
		pstr->type = ARCHITECTURE;
	} else if (name_equ_to("URL             ")) {
		pstr->type = URL;
	} else if (name_equ_to("Licenses        ")) {
		pstr->type = LICENSES;
	} else if (name_equ_to("Groups          ")) {
		pstr->type = GROUPS;
	} else if (name_equ_to("Provides        ")) {
		pstr->type = PROVIDES;
	} else if (name_equ_to("Depends On      ")) {
		pstr->type = DEPENDS_ON;
	} else if (name_equ_to("Optional Deps   ")) {
		pstr->type = OPTIONAL_DEPS;
	} else if (name_equ_to("Required By     ")) {
		pstr->type = REQUIRED_BY;
	} else if (name_equ_to("Optional For    ")) {
		pstr->type = OPTIONAL_FOR;
	} else if (name_equ_to("Conflicts With  ")) {
		pstr->type = CONFLICTS_WITH;
	} else if (name_equ_to("Replaces        ")) {
		pstr->type = REPLACES;
	} else if (name_equ_to("Installed Size  ")) {
		pstr->type = INSTALLED_SIZE;
	} else if (name_equ_to("Packager        ")) {
		pstr->type = PACKAGER;
	} else if (name_equ_to("Build Date      ")) {
		pstr->type = BUILD_DATE;
	} else if (name_equ_to("Install Date    ")) {
		pstr->type = INSTALL_DATE;
	} else if (name_equ_to("Install Reason  ")) {
		pstr->type = INSTALL_REASON;
	} else if (name_equ_to("Install Script  ")) {
		pstr->type = INSTALL_SCRIPT;
	} else if (name_equ_to("Validated By    ")) {
		pstr->type = VALIDATED_BY;
	}
	// Skipping ':'
	p++;
	// Skipping empty space
	p++;
	// Getting content
	for (i = 0; (i < CONTENT_LEN - 1) || *p == '\n'; i++, p++) {
		pstr->content[i] = *p;
	}
	pstr->content[i] = '\0';
}

