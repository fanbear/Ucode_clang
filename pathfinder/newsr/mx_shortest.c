#include "path.h"

t_island *mx_shortest(t_island **unvisited) {
	t_island *head = *unvisited;
	t_island *shortest = *unvisited;

	while(head) {
		if (shortest->distTo > head->distTo) {
			shortest = head;
		}
		head = head->next;
	}
	return shortest;
}
