#include "path.h"

static t_path *create_island(int isl, int dist) {

	t_island *node = (t_island *)malloc(1 * sizeof(t_island));

	node->currentIsl = isl;
	node->distTo = dist;
	// node->path = NULL;
	node->next = NULL;
	return node;
}