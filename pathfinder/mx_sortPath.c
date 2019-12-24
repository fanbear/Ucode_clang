#include "path.h"

static int numPath(t_path **disp) {
	t_path *bond = *disp;
	int num = 1;

	if (*bond) {
		bond = bond->nextPath;
		while(bond->nextPath) {
			bond = bond->nextPath;
			num++;
		}
		if (*bond)
			num++;
	}
	else return 0;
	return num;
}


void mx_sortPath(t_path **disp, char **set) {
	t_path *bond = *disp;
	int sizePath = numPath(*bond);
	t_path *fast = *disp->nextPath;

	for(int i = 0; i < sizePath; i++) {
		if (fast) {

		}
	}		
}


// pathes to bond
// merge
// insert