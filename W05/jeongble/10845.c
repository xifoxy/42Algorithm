#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
  int _data;
  struct Data *next;
} data;

typedef struct Queue {
  struct Data *front;
  struct Data *back;
  int size;
} queue;

queue *init_queue(void) {
  queue *q = malloc(sizeof(queue));
  q->front = q->back = NULL;
  q->size = 0;
  return q;
}

void push(queue *q, int a) {
  data *newData = malloc(sizeof(data));
  newData->_data = a;
  if (q->size == 0)
    q->front = newData;
  else
    q->back->next = newData;
  q->back = newData;
  q->size++;
}

int pop(queue *q) {
  if (q->size == 0) return -1;
  int ret = q->front->_data;
  data *next = q->front->next;
  free(q->front);
  q->front = next;
  q->size--;
  if (q->size == 0) q->back = NULL;
  return ret;
}

int size(queue *q) { return q->size; }

int empty(queue *q) { return !q->size; }

int front(queue *q) {
  if (q->size == 0) return -1;
  return q->front->_data;
}

int back(queue *q) {
  if (q->size == 0) return -1;
  return q->back->_data;
}

int main(void) {
  int n;
  scanf("%d", &n);
  queue *q = init_queue();
  while (n--) {
    char cmd[6];
    scanf("%s", cmd);
    if (cmd[0] == 'p' && cmd[1] == 'u') {
      int a;
      scanf("%d", &a);
      push(q, a);
    } else if (cmd[0] == 'p') {
      printf("%d\n", pop(q));
    } else if (cmd[0] == 's') {
      printf("%d\n", size(q));
    } else if (cmd[0] == 'e') {
      printf("%d\n", empty(q));
    } else if (cmd[0] == 'f') {
      printf("%d\n", front(q));
    } else if (cmd[0] == 'b') {
      printf("%d\n", back(q));
    }
  }
}

// 큐를 구현했습니다.