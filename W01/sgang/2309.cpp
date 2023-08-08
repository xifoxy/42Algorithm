#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> arr;
int sum;
bool flag = true;
int main() {
  arr.resize(9);

  for (int i = 0; i < 9; ++i) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  for (int i = 0; i < 9; ++i) {
    for (int j = i + 1; j < 9 && flag; ++j) {
      if (!(sum - (arr[i] + arr[j]) == 100))
        continue;
      arr[i] = 1e4;
      arr[j] = 1e4;
      flag = false;
    }
  }

  sort(arr.begin(), arr.end());
  for (int i = 0; i < 7; ++i)
    printf("%d\n", arr[i]);
}

// 9명중 7명의 키의 합이 100이 되는것을 구해야 하는 문제다.
// 그러니 2명만 찾아내면 된다.