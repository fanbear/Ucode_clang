#include "libmx.h"

t_list *mx_create_node(void *data) {

	t_list *node = (t_list *)malloc(1 * sizeof(t_list));

	node->data = data;
	node->next = NULL;
	return node;
}

//void display(t_list *head)
//{
//  while (head != NULL)
//  {
//        printf("%s   ", head->data);
//   	    head = head->next;
//  }
//  printf("\n");
//}

//int main() {
//    t_list *node = mx_create_node("Hi");
//    display(node);
//}
