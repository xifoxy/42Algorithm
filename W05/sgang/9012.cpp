#include <iostream>
#include <string>

using namespace std;

string answer;
string input;

int main() {
  cin >> input;

  while (cin >> input) {

    int stack = 0;
    for (auto &p : input) {
      p == '(' ? ++stack : stack--;
      if (stack < 0)
        break;
    }

    answer += stack ? "NO\n" : "YES\n";
  }

  cout << answer;
}

// 스택의 사이즈는 -가 될수 없다.
// 그리고 문자열에 대한 검사가 끝났을때 스택의 사이즈가 있을 수 없다.