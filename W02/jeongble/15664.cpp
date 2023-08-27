#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int arr2[8];

void rec(int count, int last) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[arr2[i]]);
    printf("\n");
    return;
  }
  int i = last + 1;
  while (i <= n - m + count) {
    arr2[count] = i;
    rec(count + 1, i);
    while (i <= n - m + count && arr[i] == arr[arr2[count]]) i++;
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
  rec(0, -1);
}

// 15655에서 한 단계에서 같은 숫자를 2번 선택할 수 없게
// while loop를 사용해 다른 숫자가 나올 때까지 i를 옮겨주는 부분이 추가됨