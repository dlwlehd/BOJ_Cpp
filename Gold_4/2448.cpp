#include <bits/stdc++.h>
using namespace std;

char t[3072][6144];    

void star(int n, int x, int y)
{
    if (n == 3)                             
    {
        t[y][x] = '*';

        t[y + 1][x - 1] = '*';
        t[y + 1][x + 1] = '*';

        t[y + 2][x - 2] = '*';
        t[y + 2][x - 1] = '*';
        t[y + 2][x] = '*';
        t[y + 2][x + 1] = '*';
        t[y + 2][x + 2] = '*';
    }
    else                         
    {
        star(n / 2, x, y);
        star(n / 2, x - n / 2, y + n / 2);
        star(n / 2, x - n / 2 + n, y + n / 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            t[i][j] = ' ';
        }
    }

    star(n, n - 1, 0);                       

    for (int i = 0; i < n; i++)                 
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << t[i][j];
        }
        cout << "\n";
    }
}
