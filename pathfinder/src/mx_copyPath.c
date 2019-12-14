#include "path.h"

static void addLink(t_path **cur, t_path *new) {
	t_path *current = *cur;

	while(current->nextBond) {
		current->nextPath = new;
		current = current->nextBond;
	}
}


static t_path *addOne(t_path **previous) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	res = mx_create_path(last->bondIsl, last->bondDist);
	new = res;
	if (last->nextBond != NULL)
		last = last->nextBond;
	while (last->nextBond != NULL) {
		new->nextBond = mx_create_path(last->bondIsl, last->bondDist);
		last = last->nextBond;
		new = new->nextBond;
	}
	return res;
}


t_path *mx_copyPath(t_path **data) {
	t_path *prev = *data;
	t_path *new = NULL;
	t_path *res = NULL;
	t_path *cur = NULL;

	if (prev) {
		new = addOne(&prev);
		res = new;
		cur = new;
		prev = prev->nextPath;
		while (prev) {
			new = addOne(&prev);
			addLink(&cur, new);
			cur = cur->nextPath;
			prev = prev->nextPath;
		}
	}
	return res;
}

