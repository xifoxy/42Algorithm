#include <iostream>
using namespace std;

int main()
{
    int n;
    int i = 666;
    int total = 0;
    scanf("%d", &n);
    for (; ; ++i)
    {
        int tmp = i;
        bool flag = false;
        // printf("tmp:%d\n", tmp);
        while (tmp)
        {
            int r;
            r = tmp % 10;
            // printf("r:%d\n", r);
            tmp /= 10;
            if (r == 6 && tmp >= 10)
            {
                int a = tmp % 10;
                int b = tmp /10 % 10;
                if (a == b && b == r)
                {
                    // printf("%d %d %d\n", a, b, r);
                    flag = true;
                    break;
                }
                
            }

        }
        if (flag)
            total++;
        if (total == n)
        {
            printf("%d\n", i);
            break;
        }
        // printf("%d\n", total);
    }

}

// 사실 안될줄 알았는데, 정답이라서 놀람.