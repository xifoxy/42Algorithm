#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char arr[50][50];

int main()
{
    int n, m;
    cin >> n >> m;
    string tmp;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> tmp;
        for (int j = 0 ; j < m ; ++j)
            arr[i][j] = tmp[j];
    }

    int minValue = 32;
    for (int i = 0 ; i < n - 7 ; ++i)
    {
        for (int j = 0 ; j < m - 7 ; ++j)
        {
            int count = 0;
            for (int a = i ; a < i + 8 ; ++a)
            {
                for (int b = j ; b < j + 8 ; ++b)
                {
                    if ((a + b) % 2 == 0)
                    {
                        if (arr[a][b] == 'B')
                            count++;
                    }
                    else
                        if (arr[a][b] == 'W')
                            count++;
                }
            }
            
            minValue = min(minValue, min(count, 64 - count));            
            
        }
    }
    cout << minValue;

}