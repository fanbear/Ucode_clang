#include "path.h"

// static int numPath(t_path *bond) {
// 	int num = 0;

// 	while(bond) {
// 		bond = bond->nextPath;
// 		num++;
// 	}
// 	return num;
// }

static void addLink(t_path **cur, t_path **new) {
	t_path *current = *cur;

	while(current->nextBond) {
		current->nextPath = *new;
		current = current->nextBond;
	}
	current->nextPath = *new;
}

static int cmp(t_path *bond, t_path *fast) {
	while (bond->nextBond && fast->nextBond) {
		if (bond->bondIsl > fast->bondIsl)
			return 1;
		bond = bond->nextBond;
		fast = fast->nextBond;
	}
	if (bond && !fast)
		return 1;
	return 0;
}

static void swp(t_path **disp, t_path **bond, t_path **fast) {
	t_path *temp = (*fast)->nextPath;
	t_path *cur = *disp;

		addLink(&(*fast), &(*bond));
		addLink(&(*bond), &temp);
	if (*disp == *bond)
		*disp = *fast;
	else {
		while(cur && cur->nextPath != *bond)
			cur = cur->nextPath;
		addLink(&cur, &(*fast));
	}
}

void mx_sortPath(t_path **disp) {
	t_path *bond = *disp;
	// int sizeP = numPath(*disp);
	t_path *fast = (*disp)->nextPath;
	t_path *cur = bond;

	while (cur->nextPath) {
		bond = cur;
		fast = bond->nextPath;
		while(fast) {
			if (cmp(bond, fast) == 1) {
				swp(&(*disp), &bond, &fast);
				fast = fast->nextPath->nextPath;
				bond = bond->nextPath;
			}
			else 
				fast = fast->nextPath;
		}
		cur = cur->nextPath;

	}		
}



// pathes to bond
// merge
// insert
