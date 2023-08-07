#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(9);
vector<int> total;

bool flag = false;
void recursive(int index, int sum, int size)
{
    if (size == 7)
    {
        if (!flag && sum == 100)
        {
            for (int i = 0 ; i < 7 ; ++i)
            {
                cout << total[i] << '\n';
            }
            flag = true;
            return ;
        }
    }
    for (int i = index ; i < 9 ; ++i)
    {
        total.push_back(v[i]);
        recursive(i + 1, sum + v[i], size + 1);
        total.pop_back();
    }
}

int main()
{
    for (int i = 0 ; i < 9 ; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    recursive(0, 0, 0);
}

// 하나씩 전부 보면서 합이 100인 경우를 찾음.