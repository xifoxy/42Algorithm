#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int arr2[8];

void rec(int count, int mask) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[arr2[i]]);
    printf("\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      arr2[count] = i;
      rec(count + 1, mask | (1 << i));
    }
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    arr.push_back(a);
  }
  sort(arr.begin(), arr.end());
  rec(0, 0);
}

// 15649에서 숫자를 추가로 입력받고, 정렬하고, 원래 출력했던 숫자들을 인덱스로
// 사용해 출력하는 부분이 추가됨