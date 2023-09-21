#include <iostream>
using namespace std;

#define MAX_VALUE 1e6 + 1

int n;
int GetConstructValue(int i)
{
    int total = i;
    while (i)
    {
        total += i % 10;
        i /= 10;
    }
    return total;
}

int main()
{
    bool flag = false;
    scanf("%d", &n);

    for (int i = 1 ; i < MAX_VALUE ; ++i)
    {
        if (GetConstructValue(i) == n)
        {
            flag = true;
            n = i;
            break;   
        }   
    }
    printf("%d", flag ? n : 0);
}

// 생성자 구하는 방법 (원래 값 + 각 자리수)
// ex 213 = (213 + 2 + 1 + 3)

// 1,000,000 이므로 100만 * 7 이므로 최악 ㄱㅊ
