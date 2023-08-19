#include <iostream>
using namespace std;
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int visited[9];
int v[3];
int total;

int n;
struct Data
{
    int value;
    int s;
    int b;
};
Data d[100];
void recur(int count)
{
    if (count == 3)
    {
        bool flag = true;
        for (int i = 0 ; i < n ; ++i)
        {
            int a = d[i].value / 100;
            int b = d[i].value / 10 % 10;
            int c = d[i].value % 10;
            // printf("%d%d%d %d%d%d\n", a,b,c,v[0],v[1],v[2]);
            int sc = 0, bc = 0;
            if (a == v[0])
                sc++;
            if (b == v[1])
                sc++;
            if (c == v[2])
                sc++;
            if (a == v[1] || a == v[2])
                bc++;
            if (b == v[0] || b == v[2])
                bc++;
            if (c == v[0] || c == v[1])
                bc++;
            // printf("%d%d %d%d\n", sc, bc, d[i].s, d[i].b);
            if (!(sc == d[i].s && bc == d[i].b))
            {
                flag = false;
                break;
            }
            
        }
        if (flag)
        {
            total++;
        }
        return ;
    }

    for (int i = 0 ; i < 9 ; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v[count] = arr[i];
            recur(count + 1);
            visited[i] = false;
        }
    }
}


int main()
{
    
    int i = 666;
    scanf("%d", &n);
    
    for (i = 0; i < n ; ++i)
    {  
        scanf("%d %d %d", &d[i].value, &d[i].s, &d[i].b);
    }
    recur(0);
    printf("%d\n", total);
}

// 0은 들어갈 수 없으므로 arr에 1부터 9까지 넣어놓은 다음에 visited로 이미 들어간 수 인지 판별후 for문을 돌면서 입력값이 올바르다면 count 올림.