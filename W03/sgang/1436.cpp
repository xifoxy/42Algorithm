#include <cstdio>

int n, cnt, temp, ans;

int main() {
  scanf("%d", &n);

  for (int i = 1; cnt != n; ++i) {
    temp = i * 10;

    while (temp /= 10) {
      if (temp % 1000 != 666)
        continue;
      cnt++;
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
}

// N번째가 나올때까지 증가시키며 검사를 하면 되는데,
// 조건식이 생각보다 간단하다. 자릿수를 한쪽으로 밀면서
// 나머지가 666일때이다.