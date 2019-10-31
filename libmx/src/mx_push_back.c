#include "libmx.h"

void mx_push_back(t_list **list, void *data) {

	t_list *node = mx_create_node(data);
	t_list *back = *list;

	while(back->next != NULL)
		back = back->next;
	back->next = node;
}
//void display(t_list *head)
//{
// while (head != NULL)
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
//    mx_push_back(&node, "Bye");
//    display(node);
//}
