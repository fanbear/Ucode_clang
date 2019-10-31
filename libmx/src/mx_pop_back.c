#include "libmx.h"

void mx_pop_back(t_list **head) {

	t_list *tmp = *head;

	while (tmp->next->next != NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
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
    t_list *node = mx_create_node("Hi");
    mx_push_front(&node, "Oleh");
    display(node);
    mx_pop_back(&node);
    display(node);
} */
