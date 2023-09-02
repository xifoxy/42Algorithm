#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, s, arr[22], res;

void dfs(int index, int v) {
  if (index == n) {
    if (v == s) res++;
    return;
  }
  int count = 0;
  dfs(index + 1, v);
  dfs(index + 1, v + arr[index]);
}

int main(void) {
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> arr[i];
  dfs(0, 0);
  if (s == 0) res--;
  cout << res << endl;
}

// dfs 모든 부분수열을 탐색함