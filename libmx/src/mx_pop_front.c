#include "libmx.h"

void mx_pop_front(t_list **head) {

	t_list *tmp = *head;

	*head = tmp->next;
	free(tmp);
	tmp = NULL;
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
	mx_pop_front(&node);
	display(node);
}*/ 
