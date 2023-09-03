#include <cstdio>

int n, ans, conNum, temp;

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    temp = i * 10;
    conNum = i;

    while (temp /= 10)
      conNum += (temp % 10);

    if (conNum == n) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
}

// N까지 생성자를 찾을떄까지 다 돌아보면 된다.