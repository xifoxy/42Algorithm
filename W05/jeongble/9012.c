#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  scanf("%d", &n);
  while (n--) {
    char cmd[51];
    scanf("%s", cmd);
    int cnt = 0;
    for (int i = 0; cmd[i]; i++) {
      if (cmd[i] == '(')
        cnt++;
      else if (cmd[i] == ')')
        cnt--;
      if (cnt < 0) break;
    }
    printf("%s\n", cnt ? "NO" : "YES");
  }
}

// 굳이 스택을 안 쓰고 카운트만 해줘도 됨