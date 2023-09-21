#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[12];
int min_value = 1e9;
int max_value = -1e9;
void recursive(int plus, int minus, int mul, int div, int index, int value)
{
    if (index == n)
    {
        max_value = max(max_value, value);
        min_value = min(min_value, value);
        return ;
    }
    
    if (plus > 0)
        recursive(plus -1, minus, mul, div, index + 1, value + arr[index]);
    if (minus > 0)
        recursive(plus, minus -1, mul, div, index + 1, value - arr[index]);
    if (mul > 0)
        recursive(plus, minus, mul -1, div, index + 1, value * arr[index]);
    if (div > 0)
        recursive(plus, minus, mul, div -1, index + 1, value / arr[index]);
    return ;
}


int main()
{
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);
    int p, m, mul, d;
    scanf("%d %d %d %d", &p, &m, &mul, &d);
    int ret;
    recursive(p, m, mul, d, 1, arr[0]);
    printf("%d\n%d", max_value, min_value);
}

// visited로 하게 되면 중복값이 있기떄문에 각각의 경우를 -1해서 재귀.
