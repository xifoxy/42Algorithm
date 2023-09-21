#include <iostream>
using namespace std;

#define MAX_VALUE 1e4 + 1
int n;
int arr[10001];

void GetNumber(int i)
{
    int total = i;
    while (i)
    {
        total += i % 10;
        i /= 10;
    }
    if (total <= 10000)
    {
        arr[total] = 1;
        GetNumber(total);
    }
    else
        return;
}

int main()
{
    for (int i = 1 ; i < MAX_VALUE ; ++i)
    {
        GetNumber(i);
    }
    for (int i = 1 ; i < MAX_VALUE ; ++i)
        if (!arr[i])
            printf("%d\n",i);
}

// 1부터 10000까지 생성자가 있는지 다 확인.
// 좀 많이 비효율