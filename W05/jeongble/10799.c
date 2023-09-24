#include <stdio.h>

char str[111111];
int res, pipe;

int main(void) {
  scanf("%s", str);
  for (int i = 0; str[i]; i++) {
    if (str[i] == '(') {
      pipe++;
    } else {
      pipe--;
      if (str[i - 1] == '(')
        res += pipe;
      else
        res++;
    }
  }
  printf("%d", res);
}

// '(' 가 나오면 파이프 추가
// '()'가 나오면 파이프 자름
// ')'가 나오면 파이프 끝남