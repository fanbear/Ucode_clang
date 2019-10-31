#include "libmx.h"

int mx_list_size(t_list *list) {

	int count = 1;
	t_list *temp = list;

	while(temp->next != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}
/*
void display(t_list *head)
{
  while (head != NULL)
  {
      printf("%s   ", head->data);
      head = head->next;
  }
  printf("\n");
}

int main() {
    t_list *node = mx_create_node("!");
    mx_push_front(&node, "Oleh");
    mx_push_front(&node, "Hi");
	mx_push_back(&node, "!");
	    mx_push_back(&node, "!");
	display(node);
	printf("%d", mx_list_size(node));
} */
