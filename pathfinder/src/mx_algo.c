#include "path.h"

static t_path *create_path(int isl, int dist) {

	t_path *node = (t_path *)malloc(1 * sizeof(t_list));

	node->currentIsl = isl;
	node->distTo = dist;
	node->next = NULL;
	return node;
}

static void push_back_path(t_path **path, int isl, int dist) {
	t_path *new = create_path(isl, dist);
	t_path *last = *path;

	if (*path == NULL) {
		*path = new;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return;
}

static void pop_front_path(t_path **head) {
    if (!head || !(*head)) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        t_path *p = (*head)->next;
        free(*head);
        *head = p;
    }
}





static void deixtra(int **matrix, char **set, int root, int size) {
	// char *path = mx_strdup(mx_itoa(root));
	int dist = 0;
	// int flag = 0;
	// int dist1 = 0;
	// t_path *visited = NULL;
	t_path *unvisited = NULL;

	mx_print_strarr(set, "\n");
	for (int i = root; i < size; i++) {
		push_back_path(&unvisited, i, 0);  // заполнение пустыми нодами
	}


	unvisited->distTo = 0;

	for (int isl1 = root; isl1 < size; isl1++) {
		t_path *head = unvisited;
		t_path *current = unvisited;

		while(current->currentIsl != isl1) current = current->next;
		while(head->currentIsl != isl1) head = head->next; // поиск отправной точки
		for (int isl2 = isl1+1; head->next != NULL; isl2++) {

			if (matrix[current->currentIsl][isl2] != 0 && head->next->distTo) {
				if (head->distTo + matrix[isl1][isl2] < head->next->distTo) {
					head->next->distTo = current->distTo + matrix[isl1][isl2];
					// flag = head->next->currentIsl;
					// if (flag != head->next->currentIsl) {
					// 	path = mx_strjoin(path, "-");
					// 	path = mx_strjoin(path, mx_itoa(head->next->currentIsl));
					// }
					// mx_printstr("cur path = ");
					// mx_printstr(path);
				}
				// else if (head->distTo + matrix[isl1][isl2] == head->next->distTo)

			} else if (matrix[current->currentIsl][isl2] != 0 && !head->next->distTo) {
				head->next->distTo = current->distTo + matrix[isl1][isl2];
					// path = mx_strjoin(path, "-");
					// path = mx_strjoin(path, mx_itoa(head->next->currentIsl));
			}

			mx_printint(head->next->currentIsl);
			mx_printchar(' ');
			mx_printint(head->next->distTo);
			mx_printchar('\n');

			head = head->next;
		}
		current = current->next;
	}

	printf("%d\n", dist);
	// printf("**%s\n", path);









while (unvisited != NULL)
{
	printf("%d  %d\n", unvisited->currentIsl, unvisited->distTo);
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
