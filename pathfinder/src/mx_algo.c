#include "path.h"

static t_island *create_path(int isl, int dist) {

	t_island *node = (t_island *)malloc(1 * sizeof(t_list));

	node->currentIsl = isl;
	node->distTo = dist;
	// node->path = NULL;
	node->next = NULL;
	return node;
}

static void push_back_path(t_island **path, int isl, int dist) {
	t_island *new = create_path(isl, dist);
	t_island *last = *path;

	if (*path == NULL) {
		*path = new;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return;
}

static void pop_front_path(t_island **head) {
    if (!head || !(*head)) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        t_island *p = (*head)->next;
        free(*head);
        *head = p;
    }
}





static void deixtra(int **matrix, char **set, int root, int size) {
	t_island *unvisited = NULL; // лист

	for (int i = root; i < size; i++)
		push_back_path(&unvisited, i, 0);  // заполнение пустыми нодами

	for (int isl1 = root; isl1 < size; isl1++) {
		t_island *head = unvisited;
		t_island *current = unvisited;

		while(current->currentIsl != isl1)
			current = current->next;
		while(head->currentIsl != isl1+1 && isl1+1 < size)
			head = head->next; // поиск отправной точки

		for (int isl2 = isl1+1; head && isl2 < size; isl2++) {

			if (matrix[isl1][isl2] != 0 && head->distTo) { // перезапись дист
				if (current->distTo + matrix[isl1][isl2] < head->distTo)
					head->distTo = current->distTo + matrix[isl1][isl2];

			} else if (matrix[isl1][isl2] != 0 && !head->distTo) // запись еще неизвестной дист
				head->distTo = current->distTo + matrix[isl1][isl2];
			head = head->next;
		}
		current = current->next;
	}


	while (unvisited != NULL)
	{
		printf("%s  %d\n", set[unvisited->currentIsl], unvisited->distTo);
		// while (unvisited->path != NULL)
		// 	pop_front_path(&unvisited->path);
		pop_front_path(&unvisited);
	}
}

void mx_algo(int **matrix, char **set) {
	// t_path *visited
	// t_path *unvisited
	// int root = i
	int size = 0;

	int i = 0;
	while (set[size]) size++;

	// while (set[i]) {
		deixtra(matrix, set, i, size);

	// }
}
