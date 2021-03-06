// Traffic Volume
// UVa ID: 10693
// Verdict: Accepted
// Submission Date: 2018-03-03
// UVa Run Time: 0.000s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int L, f;
    while (cin >> L >> f, L > 0)
    {
        double v = sqrt(2 * L * f);
        double volume = 3600.0 * v / (L + 0.5 * v * v / f);
        cout << fixed << setprecision(8) << v;
        cout << ' ';
        cout << fixed << setprecision(8) << volume << '\n';
    }

    return 0;
}
