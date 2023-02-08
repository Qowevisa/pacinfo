#include "../inc/pacfo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void
parse_pacinfo_str(__pacinfo_str *pstr, const char *source, int type)
{
	// Getting name from source
	memset(pstr->name, 0, NAME_LEN);
	strncat(pstr->name, source, NAME_LEN - 1);
	// Getting type of str
	pstr->type = type;
	// Getting content
	memset(pstr->content, 0, CONTENT_LEN);
	strncat(pstr->content, source+18, CONTENT_LEN - 1);
	pstr->content[strlen(pstr->content) - 1] = '\0';
}

