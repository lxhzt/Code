// Group Reverse
// UVa ID: 11192
// Verdict: Accepted
// Submission Date: 2017-12-31
// UVa Run Time: 0.000s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int G;
    string S;
    
    while (cin >> G, G > 0)
    {
        cin >> S;
        int k = S.length() / G;
        for (int i = 0; i < S.length(); i += k)
        {
            string block = S.substr(i, k);
            reverse(block.begin(), block.end());
            cout << block;
        }
        cout << '\n';
    }

    return 0;
}
