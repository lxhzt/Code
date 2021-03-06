// Super Number
// UVa ID: 10624
// Verdict: Accepted
// Submission Date: 2018-02-28
// UVa Run Time: 1.560s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int number[32], n, m, finished;

void dfs(int d)
{
    if (finished) return;
    if (d == m)
    {
        finished = 1;
        return;
    }

    for (int i = (d ? 0 : 1); i <= 9; i++)
    {
        number[d] = i;
        int r = 0;
        if ((d + 1) >= n)
        {
            for (int j = 0; j <= d; j++)
            {
                r = r * 10 + number[j];
                r %= (d + 1);
            }
        }
        if (r == 0) dfs(d + 1);
        if (finished) break;
    }
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cout << "Case " << c << ": ";

        cin >> n >> m;

        memset(number, 0, sizeof(number));
        finished = 0;
        dfs(0);

        if (finished)
        {
            for (int i = 0; i < m; i++)
                cout << number[i];
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}
