#include "path.h"

static t_island *create_island(int isl, int dist) {

	t_island *node = (t_island *)malloc(1 * sizeof(t_island));

	node->currentIsl = isl;
	node->distTo = dist;
	node->path = NULL;
	node->next = NULL;
	return node;
}

static void push_back_island(t_island **island, t_path **path, int isl, int dist) {
	t_island *new = create_island(isl, dist);
	t_island *last = *island;

	if (path && *path) {  // if only *path -> seagfault and if only path -> seagfault with separated;
		new->path = mx_copyPath(&(*path));
	} else  if (path && *path == NULL) { // "if" obyazatelno
		mx_printerr("error: combination of two islands has not a path between them\n"); //88 columns
		exit(EXIT_FAILURE);
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

static void pop_middle_island(t_island **unvisited, int index) {
	if (!unvisited || !(*unvisited)) return;
	if ((*unvisited)->currentIsl == index)
		pop_front_island(&(*unvisited));
	else {
		t_island *temp = *unvisited;
		t_island *leftOne = temp;
		while (temp != NULL && temp->currentIsl != index) {
			leftOne = temp;
			temp = temp->next;
		}
		if (temp && temp->currentIsl == index) {
			if (temp->next)
				leftOne->next = temp->next;
			else 
				leftOne->next = NULL;

			free(temp);
			temp = NULL;
		}
	}
}

static void displayPath(t_path **disp, char **set) {
	t_path *bond = *disp;

	while(bond) {
		while(bond->nextBond){
			printf("%s  %d\n", set[bond->bondIsl], bond->bondDist);
			bond = bond->nextBond;
		}
		printf("%s  %d\n\n", set[bond->bondIsl], bond->bondDist);
		bond = bond->nextPath;
	}
	printf("%s\n", "next");
}




static void deixtra(int **matrix, char **set, int root, int size) {
	t_island *unvisited = NULL; // лист непройденных нод
	t_island *visited = NULL; // лист пройденных нод
	t_island *current = NULL;
	t_island *shortest = NULL;
	t_path *first = mx_create_path(root, 0);
	for (int i = 0; i < size; i++)
		push_back_island(&unvisited, NULL, i, 0);  // заполнение пустыми нодами
	current = unvisited;
	while(current->currentIsl != root)
		current = current->next;
	push_back_island(&visited, &first, current->currentIsl, current->distTo);
	pop_middle_island(&unvisited, root);
	current = visited;

	while (unvisited) {
		t_island *head = unvisited;
		while (head != NULL) {
			int isl1 = current->currentIsl;
			int isl2 = head->currentIsl;
			int mat = matrix[isl1][isl2];

			if (mat != 0 && head->distTo == 0) { // запись еще неизвестной дист 
				head->distTo = current->distTo + mat;
				head->path = mx_addPath(&current->path, isl2, mat);
			} else if (mat != 0) {// перезапись дист
				if (current->distTo + mat == head->distTo)
					mx_push_backPath(&head->path, &current->path, isl2, mat);
				if (current->distTo + mat < head->distTo) {
					head->distTo = current->distTo + mat;
					mx_delPath(&head->path);
					head->path = mx_addPath(&current->path, isl2, mat);
				}
			}
			head = head->next;
		}
		shortest = mx_shortest(&unvisited);
		push_back_island(&visited, &shortest->path, shortest->currentIsl, shortest->distTo);
		pop_middle_island(&unvisited, shortest->currentIsl);
		current = current->next;
		
	}
	mx_printchar('\n');

	for(int j = 0; j < size; j++) {
		current = visited;
		while (current->currentIsl != j)
			current = current->next;
		displayPath(&current->path, set);
	}


	while (visited != NULL)
	{
		// printf("%s  %d\n", set[visited->currentIsl], visited->distTo);
		mx_delPath(&visited->path);
		pop_front_island(&visited);
	}
	// mx_print_strarr(set, " ");
}

void mx_algo(int **matrix, char **set) {
	int size = 0;

	int i = 0;
	while (set[size]) size++;

	 // while (i < size - 1) {
		deixtra(matrix, set, i, size);
		// i++;
	 // }
}
