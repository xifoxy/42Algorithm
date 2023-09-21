#include <iostream>
using namespace std;
int n, m;
int arr[20];
int recursive(int start, int sum)
{
    int ret = 0;
    if (sum == m && start != 0)
    {
        ret += 1;
    }
    
    for (int i = start ; i < n ; ++i)
        ret  += recursive(i + 1, sum + arr[i]);
    return ret;
}


int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);
    printf("%d\n", recursive(0, 0));
}

// 이어지는 숫자를 재귀로 돌면서 sum값과 같은지 비교.