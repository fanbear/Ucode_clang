#include "path.h"

static void addLink(t_path **cur, t_path **new) {
	t_path *current = *cur;

	while(current->nextBond) {
		current->nextPath = *new;
		current = current->nextBond;
	}
}

static t_path *addOnePath(t_path **previous, int isl, int dist) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	if (!last)
		return res = mx_create_path(isl, dist);
	res = mx_create_path(last->bondIsl, last->bondDist);
	new = res;
	last = last->nextBond;
	while (last) {
		new->nextBond = mx_create_path(last->bondIsl, last->bondDist);
		last = last->nextBond;
		new = new->nextBond;
	}
	new->nextBond = mx_create_path(isl, dist);
	return res;
}

t_path *mx_addPath(t_path **previous, int isl, int dist) {
	t_path *cur = (*previous)->nextPath;
	t_path *res = addOnePath(&cur, isl, dist);
	t_path *new = NULL;
	t_path *fast = res;

	while (cur) {
		new = addOnePath(&cur, isl, dist);
		addLink(&fast, &new);
		fast = fast->nextPath;
		cur = cur->nextPath;
	}
	return res;
}
