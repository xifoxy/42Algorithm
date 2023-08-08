#include <cstdio>

const int sz = 1e2 + 1;
int n;
char s[sz];
void line(int star) {
  s[star] = '*';
  puts(s);
}

void sol(int loop) {
  if (!loop)
    return;
  sol(loop - 1);
  line(loop - 1);
}

int main() {
  scanf("%d", &n);
  sol(n);
}

// 반복문 없이 풀어보자.
// 재귀에 익숙해질 필요가 있다.
// 2438부터 2441까지는 코드 구조만 살펴보자
// 해설은 2442에