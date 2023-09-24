#include <stdio.h>

int arr[1111111];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) arr[i] = i + 1;
  int begin = 0, end = n - 1;
  while (begin < end) {
    begin++;
    arr[end + 1] = arr[begin];
    begin++;
    end++;
  }
  printf("%d", arr[begin]);
}

// N의 최대 크기가 정해져있으므로, 굳이 큐를 쓰지 않고, 배열을 이용함