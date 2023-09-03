#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int SZ = 3e5 + 1;
int n, cnt = 1, tri = 1, ans;
int dp[SZ];
vector<int> num{1};

int min(int a, int b) { return a > b ? b : a; }

int main() {
  scanf("%d", &n);
  while (num.back() <= n)
    num.push_back(num.back() + (tri += ++cnt));

  fill(&dp[1], &dp[SZ], 1e9);

  for (auto &p : num)
    for (int j = p; j <= n; ++j)
      dp[j] = min(dp[j], dp[j - p] + 1);

  printf("%d\n", dp[n]);
}

// 의식의 흐름대로 구현해도 풀리는 문제다.
// 정삼각형의 경우들을 다 구해서 저장하고,
// 그걸 토대로 디피배열에 인덱싱하여 갱신해준다.