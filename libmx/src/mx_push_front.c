#include "libmx.h"

void mx_push_front(t_list **list, void *data) {

	t_list *node = mx_create_node(data);

	node->next = *list;
	*list = node;
}

//void display(t_list *head)
//{
//  while (head != NULL)
//  {
//      printf("%s   ", head->data);
//      head = head->next;
//  }
//  printf("\n");
//}
//
//int main() {
//    t_list *node = mx_create_node("Hi");
//    display(node);
//    mx_push_front(&node, "hi Oleh");
//    display(node);
//}
