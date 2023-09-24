#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *arr;
  int size;
  int _capacity;
} stack;

stack *init_stack(void) {
  stack *stk = malloc(sizeof(stack));
  stk->_capacity = 111111;
  stk->arr = malloc(sizeof(int) * stk->_capacity);
  stk->size = 0;
  return stk;
}

void push(stack *stk, int a) {
  if (stk->size == stk->_capacity) {
    stk->_capacity *= 2;
    stk->arr = realloc(stk->arr, sizeof(int) * stk->_capacity);
  }
  stk->arr[stk->size++] = a;
}

int pop(stack *stk) {
  if (stk->size == 0) return -1;
  stk->size--;
  return stk->arr[stk->size];
}

int size(stack *stk) { return stk->size; }

int empty(stack *stk) { return !stk->size; }

int top(stack *stk) {
  if (stk->size == 0) return -1;
  return stk->arr[stk->size - 1];
}

int main(void) {
  int n;
  scanf("%d", &n);
  stack *stk = init_stack();
  while (n--) {
    char cmd[6];
    scanf("%s", cmd);
    if (cmd[0] == 'p' && cmd[1] == 'u') {
      int a;
      scanf("%d", &a);
      push(stk, a);
    } else if (cmd[0] == 'p') {
      printf("%d\n", pop(stk));
    } else if (cmd[0] == 's') {
      printf("%d\n", size(stk));
    } else if (cmd[0] == 'e') {
      printf("%d\n", empty(stk));
    } else if (cmd[0] == 't') {
      printf("%d\n", top(stk));
    }
  }
}

// 스택을 구현했습니다.