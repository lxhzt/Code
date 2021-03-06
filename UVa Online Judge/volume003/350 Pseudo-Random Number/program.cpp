// Pseudo-Random Number
// UVa ID: 350
// Verdict: Accepted
// Submission Date: 2016-06-25
// UVa Run Time: 0.030s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    int Z, I, M, L, cases = 0;
    while (cin >> Z >> I >> M >> L, Z)
    {
        map<int, int> number;
        while (number.find(L) == number.end())
        {
            number[L] = number.size();
            L = (Z * L + I) % M;
        }
        
        cout << "Case " << ++cases << ": " << (number.size() - number[L] + 1) << endl;
    }
    
	return 0;
}
