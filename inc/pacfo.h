#ifndef __pacinfo__pacfo_h
#define __pacinfo__pacfo_h

typedef enum __pacinfo_type {
	NAME,
	VERSION,
	DESCRIPTION,
	ARCHITECTURE,
	URL,
	LICENSES,
	GROUPS,
	PROVIDES,
	DEPENDS_ON,
	OPTIONAL_DEPS,
	REQUIRED_BY,
	OPTIONAL_FOR,
	CONFLICTS_WITH,
	REPLACES,
	INSTALLED_SIZE,
	PACKAGER,
	BUILD_DATE,
	INSTALL_DATE,
	INSTALL_REASON,
	INSTALL_SCRIPT,
	VALIDATED_BY
} __pacinfo_type;

// Content len should be equal
// to 2^n - 17, so __pacinfo_str size
// will be 2^n.
#define CONTENT_LEN 1007

#define NAME_LEN 16

#define LINES_LEN 21

typedef struct __pacinfo_str {
	char name[NAME_LEN];
	__pacinfo_type type;
	char content[CONTENT_LEN];
} __pacinfo_str;

typedef struct __pacinfo_pkg {
	__pacinfo_str lines[LINES_LEN];
} __pacinfo_pkg;

#endif // __pacinfo__pacfo_h
