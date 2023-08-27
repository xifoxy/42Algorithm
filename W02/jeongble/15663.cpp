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
  int i = 0;
  while (i < n) {
    if (!(mask & (1 << i))) {
      arr2[count] = i;
      rec(count + 1, mask | (1 << i));
      while (i < n - 1 && arr[i] == arr[i + 1]) i++;
    }
    i++;
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

// 15654에서 한 단계에서 같은 숫자를 2번 선택할 수 없게
// while loop를 사용해 다른 숫자가 나올 때까지 i를 옮겨주는 부분이 추가됨