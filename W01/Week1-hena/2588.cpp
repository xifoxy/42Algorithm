#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int d1, d2, d3;
    int u, d;
    cin >> u >> d;

    d1 = d / 100;
    d2 = d % 100 / 10;
    d3 = d % 10;
    cout << u * d3 << '\n';
    cout << u * d2 << '\n';
    cout << u * d1 << '\n';
    cout << u * d;
}

// 100의 자리, 10의 자리, 1의 자리 수를 나눈 다음 곱한 값을 하나씩 구함.