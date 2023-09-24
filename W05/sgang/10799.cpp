#include <cstdio>

const int SZ = 1e5 + 1;
char str[SZ];

int ans, stack;
int main() {
  scanf("%s", str);

  for (int i = 0; str[i]; ++i) {
    if (str[i] == '(')
      stack++;
    else {
      stack--;

      if (str[i - 1] == '(')
        ans += stack;
      else
        ans++;
    }
  }

  printf("%d\n", ans);
}

// 문제의 설명대로 열리는 괄호가 핵심인데 괄호는 레이저 이면서 쇠파이프다.
// 그러니 어렵게 생각할 필요 없이,
// 열릴때 스택을 쌓아가고 닫힐때 계산해주면 된다.