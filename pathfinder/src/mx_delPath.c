#include "path.h"

static void pop_allBond(t_path **head) {
    if (!head || !(*head)) return;

    if (!(*head)->nextBond && !(*head)->nextPath) {
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

void mx_delPath(t_path **head) {
	if (!head || !(*head)) return;
    while((*head)->nextBond || (*head)->nextPath) {
        pop_allBond(&(*head));
    	if ((*head)->nextBond == NULL && (*head)->nextPath)
    		pop_nextPath(&(*head));
        if (!(*head))
            return;
    }
}


