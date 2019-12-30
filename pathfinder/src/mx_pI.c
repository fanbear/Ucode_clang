#include "path.h"

void mx_pI(t_island **island, t_path **path, int isl, int dist) {
	t_island *new = mx_create_island(isl, dist);
	t_island *last = *island;

	if (path && *path) {
		new->path = mx_copyPath(&(*path));
	}
	if (*island == NULL) {
		*island = new;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return;
}
