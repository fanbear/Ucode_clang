#include "path.h"


static void addBond(t_path **path, int isl, int dist) {
	t_path *new = mx_create_path(isl, dist);
	t_path *last = *path;

	while (last->nextBond != NULL)
		last = last->nextBond;
	last->nextBond = new;
	return;
}

void mx_push_backBond(t_path **path, int isl, int dist) {
	t_path *last = *path;
	t_path *new = mx_create_path(isl, dist);

	if (*path == NULL) {
		*path = new;
		return;
	}
	while (last->nextPath != NULL) {
		addBond(&last, isl, dist);
		last = last->nextPath;
	}
	addBond(&last, isl, dist);
	return;
}
