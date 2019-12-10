#include "path.h"

static t_path *create_path(int isl, int dist) {
	t_path *node = (t_path *)malloc(1 * sizeof(t_path));

	node->bondIsl = isl;
	node->bondDist = dist;
	node->nextBond = NULL;
	node->nextPath = NULL;

	return node;
}

static t_path *push_back_path(t_path **path, int isl, int dist) {
	t_path *new = create_path(isl, dist);
	t_path *last = *path;

	if (*path == NULL) {
		*path = new;
		return;
	}
	while (last->nextBond != NULL)
		last = last->nextBond;
	last->nextBond = new;
	return;
}

static void pop_nextBond(t_path **head) {
    if (!head || !(*head)) return;

    if ((*head)->nextBond == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
    	while ((*head)->nextBond) {
       		t_path *p = (*head)->nextBond;
        	free(*head);
    	    *head = p;
       	}
    }
}

static void pop_nextPath(t_path **head) {
    if (!head || !(*head)) return;

    if ((*head)->nextPath == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        t_path *p = (*head)->nextPath;
        free(*head);
        *head = p;
    }
}

static void delPath(t_path **head) {
	if (!head || !(*head)) return;
	if ((*head)->nextBond == NULL && (*head)->nextPath)
		while((*head)->nextPath)
			pop_nextPath(&(*head));
	if ((*head)->nextBond != NULL)
}
