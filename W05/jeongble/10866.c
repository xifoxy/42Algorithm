#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
  int _data;
  struct Data *prev;
  struct Data *next;
} data;

typedef struct Deque {
  struct Data *nil;
  int size;
} deque;

void push(deque *dq, int a, data *new_data, data *pos) {
  new_data->_data = a;
  new_data->prev = pos;
  new_data->next = pos->next;
  pos->next = pos->next->prev = new_data;
  dq->size++;
}

void push_front(deque *dq, int a) {
  push(dq, a, malloc(sizeof(data)), dq->nil);
}

void push_back(deque *dq, int a) {
  push(dq, a, malloc(sizeof(data)), dq->nil->prev);
}

int pop(deque *dq, data *pos) {
  if (dq->size == 0) return -1;
  int ret = pos->_data;
  pos->prev->next = pos->next;
  pos->next->prev = pos->prev;
  free(pos);
  dq->size--;
  return ret;
}

int pop_front(deque *dq) { return pop(dq, dq->nil->next); }

int pop_back(deque *dq) { return pop(dq, dq->nil->prev); }

int size(deque *dq) { return dq->size; }

int empty(deque *dq) { return !dq->size; }

int front(deque *dq) {
  if (dq->size == 0) return -1;
  return dq->nil->next->_data;
}

int back(deque *dq) {
  if (dq->size == 0) return -1;
  return dq->nil->prev->_data;
}

int main(void) {
  int n;
  scanf("%d", &n);
  deque *dq = malloc(sizeof(deque));
  dq->nil->prev = dq->nil->next = dq->nil = malloc(sizeof(data));
  dq->size = 0;
  while (n--) {
    char cmd[11];
    scanf("%s", cmd);
    if (cmd[0] == 'p' && cmd[1] == 'u') {
      int a;
      scanf("%d", &a);
      if (cmd[5] == 'f')
        push_front(dq, a);
      else
        push_back(dq, a);
    } else if (cmd[0] == 'p') {
      if (cmd[4] == 'f')
        printf("%d\n", pop_front(dq));
      else
        printf("%d\n", pop_back(dq));
    } else if (cmd[0] == 's') {
      printf("%d\n", size(dq));
    } else if (cmd[0] == 'e') {
      printf("%d\n", empty(dq));
    } else if (cmd[0] == 'f') {
      printf("%d\n", front(dq));
    } else if (cmd[0] == 'b') {
      printf("%d\n", back(dq));
    }
  }
}

// 덱을 구현했습니다.