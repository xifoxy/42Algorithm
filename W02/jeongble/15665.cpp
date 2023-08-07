#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int arr2[8];
int is_visited[11111];

void rec(int count) {
  if (count == m) {
    for (int i = 0; i < m; i++) printf("%d ", arr[arr2[i]]);
    printf("\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    arr2[count] = i;
    rec(count + 1);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (!is_visited[a]) {
      arr.push_back(a);
      is_visited[a] = 1;
    }
  }
  n = arr.size();
  sort(arr.begin(), arr.end());
  rec(0);
}

// 같은 숫자를 여러번 골라도 되니, 여러 개 있을 필요가 없어서
// 배열에 이미 있는 숫자면 추가 안 함. 나머지는 15656랑 동일