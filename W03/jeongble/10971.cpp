#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, board[11][11];
vector<vector<int>> dp;

void saler(int index, int cost, int mask) {
  if (cost < dp[index][mask])
    dp[index][mask] = cost;
  else
    return;
  if (mask == (1 << n) - 1) return;
  for (int i = 0; i < n; i++) {
    if (board[index][i] == 0 || (mask & (1 << i))) continue;
    saler(i, cost + board[index][i], mask | (1 << i));
  }
}

int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];
  dp = vector<vector<int>>(n, vector<int>(1 << n, 99999999));
  saler(0, 0, 1);
  int m = 99999999;
  for (int i = 1; i < n; i++)
    if (board[i][0] && board[i][0] + dp[i][(1 << n) - 1] < m)
      m = board[i][0] + dp[i][(1 << n) - 1];
  cout << m << endl;
}

// 0번부터 시작해서 모든 마을을 방문했을 때,
// 마지막으로 간 마을이 K라고 하면
// K 마을에서 0 마을로 올 수 있는지 확인하고 올 수 있으면
// (0에서 모든 마을을 방문하며 K로 가는 비용 +
// K에서 0으로 오는 비용) 중 최소를 구함