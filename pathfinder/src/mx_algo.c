#include "path.h"

static t_island *create_island(int isl, int dist) {

	t_island *node = (t_island *)malloc(1 * sizeof(t_list));

	node->currentIsl = isl;
	node->distTo = dist;
	// node->path = NULL;
	node->next = NULL;
	return node;
}

static void push_back_island(t_island **path, int isl, int dist) {
	t_island *new = create_island(isl, dist);
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

static void pop_front_island(t_island **head) {
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
	t_island *unvisited = NULL; // лист непройденных нод
	t_island *visited = NULL; // лист пройденных нод
	t_island *current = NULL;
	t_island *shortest = NULL;

	for (int i = 0; i < size; i++)
		push_back_island(&unvisited, i, 0);  // заполнение пустыми нодами
	current = unvisited;
	while(current->currentIsl != root)
		current = current->next;
	push_back_island(&visited, current->currentIsl, current->distTo);
	pop_front_island(&current);
	current = visited;

	while (unvisited) {
		t_island *head = unvisited;

/*
		1. root to visited;
		1. Найти кратчайшую
		2. Выделить из анвизитед 
		3. Добавить в визитед
		4. кратчайшая - карент
*/

		while (head != NULL) {
			int isl1 = current->currentIsl;
			int isl2 = head->currentIsl;

			if (matrix[isl1][isl2] != 0 && head->distTo != 0) { // запись еще неизвестной дист 
				head->distTo = current->distTo + matrix[isl1][isl2];
			} else if (matrix[isl1][isl2] != 0) // перезапись дист
				if (current->distTo + matrix[isl1][isl2] < head->distTo)
					head->distTo = current->distTo + matrix[isl1][isl2];

			head = head->next;
		}

		shortest = mx_shortest(&unvisited);
		push_back_island(&visited, shortest->currentIsl, shortest->distTo);
		pop_front_island(&shortest);
		current = current->next;
	}


	while (visited != NULL)
	{
		printf("%s  %d\n", set[visited->currentIsl], visited->distTo);
		// while (unvisited->path != NULL)
		// 	pop_front_path(&unvisited->path);
		pop_front_island(&visited);
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
