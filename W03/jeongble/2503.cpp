#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, res;
vector<int> number;
vector<int> strike;
vector<int> ball;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num, s, b;
    cin >> num >> s >> b;
    number.push_back(num);
    strike.push_back(s);
    ball.push_back(b);
  }
  for (int i = 123; i < 1000; i++) {
    int a = i / 100;
    int b = i / 10 % 10;
    int c = i % 10;
    if (a == b || b == c || c == a || b == 0 || c == 0) continue;
    int j;
    for (j = 0; j < n; j++) {
      int x = number[j] / 100;
      int y = number[j] / 10 % 10;
      int z = number[j] % 10;
      if ((a == x) + (b == y) + (c == z) != strike[j] ||
          (a == y || a == z) + (b == x || b == z) + (c == x || c == y) !=
              ball[j])
        break;
    }
    if (j == n) res++;
  }
  cout << res << endl;
}

// 1부터 1000까지 돌면서 하나하나 확인함