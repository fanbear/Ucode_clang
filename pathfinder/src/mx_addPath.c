#include "path.h"


t_path *mx_addPath(t_path **previous, int isl, int dist) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	if (!last)
		return res = mx_create_path(isl, dist);
	res = mx_create_path(last->bondIsl, last->bondDist);
	new = res;
	if (last->nextBond != NULL)
		last = last->nextBond;
	while (last->nextBond != NULL) {
		new->nextBond = mx_create_path(last->bondIsl, last->bondDist);
		last = last->nextBond;
		new = new->nextBond;
	}
	new->nextBond = mx_create_path(isl, dist);
	return res;
}
