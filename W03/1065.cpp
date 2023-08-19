#include <iostream>
using namespace std;

int n;
bool IsArithmeticSequence(int value)
{
    int a, b;
    b = value % 10;
    value /= 10; a = value % 10;
    int diff = a - b;

    while (value >= 10)
    {
        b = value % 10;
        value /= 10; a = value % 10;

        if (diff != (a - b))
            return false;
    }
    return true;
}
int main()
{
    scanf("%d", &n);

    int count = 0;

    // 100보다 이상인 경우
    if (n >= 100)
    {
        count = 99;
        for (int i = 100 ; i < n + 1 ; ++i)
        {
            
            if (IsArithmeticSequence(i))
                count++;
        }
    }
    else
        count = n;
    printf("%d\n", count);   
}

// 99까지는 무조건 등차수열로 이루어짐.
// 100부터 모든 자리수를 비교하여 차이를 구해봄. 1000까지 구하는게 맞지만 사실 1000은 무조건 아니므로 999까지 해도 되고, 3자리까지만 비교하면 됨.