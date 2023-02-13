#include "../inc/manage.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

static
int
is_config_dir_created()
{
	// Getting path to ~/.config
	//
	// I don't know exactly if I should free this memory
	char *home = getenv("HOME");
	//
	char config_path[1024+16+1] = {0};
	strncat(config_path, home, 1024);
	strncat(config_path, "/.config", 16);
	//
	DIR* dir = opendir(config_path);
	if (dir) {
		/* Directory exists */
		closedir(dir);
		return 1;
	} else if (ENOENT == errno) {
		/* Directory does not exist. */
		return 0;
	} else {
		/* opendir() failed for some other reason. */
		return -1;
	}
}

static
inline
int
check_home_path_created(const char *path)
{
	// Getting path
	char *home = getenv("HOME");
	//
	char manage_path[2048] = {0};
	strncat(manage_path, home, 1024);
	strncat(manage_path, path, 1024);
	//
	DIR* dir = opendir(manage_path);
	if (dir) {
		/* Directory exists */
		closedir(dir);
		return 1;
	} else if (ENOENT == errno) {
		/* Directory does not exist. */
		return 0;
	} else {
		/* opendir() failed for some other reason. */
		return -1;
	}
}

static
int
is_manage_dir_created()
{
	if (is_config_dir_created()) {
		return check_home_path_created("/.config/pacfo");
	} else {
		return 0;
	}
}

void
create_manage_dir()
{
	if (is_manage_dir_created()) {
		return;
	}
	// Getting path
	char *home = getenv("HOME");
	//
	char manage_path[2048] = {0};
	strncat(manage_path, home, 1024);
	strncat(manage_path, "/.config", 16);
	strncat(manage_path, "/pacfo", 8);
	errno = 0;
	int ret = mkdir(manage_path, S_IRWXU);
	if (ret == -1) {
		switch (errno) {
		case EACCES :
			fprintf(stderr, "ERROR: ~/.config directory does not allow write!");
			break;
		default:
			perror("mkdir");
		}
	}
}

