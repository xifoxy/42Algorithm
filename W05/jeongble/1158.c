#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
  int _data;
  struct Data *prev;
  struct Data *next;
} data;

typedef struct list {
  struct Data *nil;
  int size;
} list;

void push(list *lst, int a, data *new_data, data *pos) {
  new_data->_data = a;
  new_data->prev = pos;
  new_data->next = pos->next;
  pos->next = pos->next->prev = new_data;
  lst->size++;
}

void push_front(list *lst, int a) {
  push(lst, a, malloc(sizeof(data)), lst->nil);
}

void push_back(list *lst, int a) {
  push(lst, a, malloc(sizeof(data)), lst->nil->prev);
}

int pop(list *lst, data **pos) {
  if (lst->size == 0) return -1;
  data *next = (*pos)->next != lst->nil ? (*pos)->next : (*pos)->next->next;
  int ret = (*pos)->_data;
  (*pos)->prev->next = (*pos)->next;
  (*pos)->next->prev = (*pos)->prev;
  free(*pos);
  *pos = next;
  lst->size--;
  return ret;
}

int pop_front(list *lst) { return pop(lst, &lst->nil->next); }

int pop_back(list *lst) { return pop(lst, &lst->nil->prev); }

int size(list *lst) { return lst->size; }

int empty(list *lst) { return !lst->size; }

int front(list *lst) {
  if (lst->size == 0) return -1;
  return lst->nil->next->_data;
}

int back(list *lst) {
  if (lst->size == 0) return -1;
  return lst->nil->prev->_data;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  list *lst = malloc(sizeof(list));
  lst->nil->prev = lst->nil->next = lst->nil = malloc(sizeof(data));
  lst->size = 0;
  for (int i = 1; i <= n; i++) push_back(lst, i);
  printf("<");
  data *pos = lst->nil->next;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++)
      pos = pos->next != lst->nil ? pos->next : pos->next->next;
    printf("%d, ", pop(lst, &pos));
  }
  printf("%d>\n", pos->_data);
  return 0;
}

// 제거하고, m번 움직이고 반복