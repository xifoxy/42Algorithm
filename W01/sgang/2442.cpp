#include <cstdio>
#include <cstring>
const int sz = 3e2 + 1;
int n;
char s[sz];

// 배열을 이용하여 반복문 생략 및 출력
void line(int star) {
  s[n - 1 + star] = s[n - 1 - star] = '*';
  puts(s);
}

// 반복문
void sol(int loop) {
  if (loop == n) // 탈출조건
    return;
  // 출력과 재귀함수의 위치에 따른 변화를 생각 해볼 필요가 있다.
  // 별찍기 1-4 를 살펴보면 출력을 먼저 할껀지 재귀를 먼저 탈껀지는
  // 출력해야 되는 별의 모양 혹은 main함수에서 넘겨주는 인자 값으로 결정된다고
  // 할 수 있다. 그렇다면 재귀함수 내에서 반복문을 선언하면 어떤 구조가 될까?
  line(loop);
  sol(loop + 1);
}

int main() {
  scanf("%d", &n);
  memset(s, ' ', n);
  sol(0);
}
// 2441풀이와 비교해보자.
// 2438~2442 이렇게 5문제는 뼈대 변환 없이 출력부분 위치,
// 재귀호출 위치 이것들만 조절해주면 된다.

// 반복문 구조가 이중적인 구조가 좀 필요하기에 함수를 두군데로 나눴다.