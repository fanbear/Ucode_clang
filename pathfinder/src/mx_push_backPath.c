#include "path.h"

void mx_push_backPath(t_path **path, t_path **previous, int isl, int dist) {
	t_path *last = *path;
	t_path *cur = *previous;

	while (last->nextPath != NULL) {
		last = last->nextPath;
	}
	while (cur->nextPath != NULL) {
		last->nextPath = addPath(&cur, isl, dist);
		cur = cur->nextPath;
	}
	return;
}
