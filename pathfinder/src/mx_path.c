#include "path.h"

// static t_path *create_path(int isl, int dist) {
// 	t_path *node = (t_path *)malloc(1 * sizeof(t_path));

// 	node->bondIsl = isl;
// 	node->bondDist = dist;
// 	node->nextBond = NULL;
// 	node->nextPath = NULL;

// 	return node;
// }

// static t_path *push_back_path(t_path **path, int isl, int dist) {
// 	t_path *new = create_path(isl, dist);
// 	t_path *last = *path;

// 	if (*path == NULL) {
// 		*path = new;
// 		return;
// 	}
// 	while (last->nextBond != NULL)
// 		last = last->next;
// 	last->next = new;
// 	return;
// }

// static t_path *copy_path(t_path **path, int isl, int dist) {
	
// }
