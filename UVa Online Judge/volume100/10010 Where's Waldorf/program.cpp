// Where's Waldorf?
// PC/UVa IDs: 110302/10010, Popularity: B, Success rate: average Level: 2
// Verdict: Accepted
// Submission Date: 2016-01-27
// UVa Run Time: 0.000s
//
// 版权所有（c）2016，metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int directions[8][2] = {
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
    {1, 0}, {1, 1}, {0, 1}, {-1, 1}
};

vector<string> matrix;
int cases, nlines, nrows, nwords;
string line, word;

bool matchWord(int x, int y, int index, int length)
{
    if (length == word.length())
        return true;

    if (x < 0 || y < 0 || x >= nlines || y >= nrows)
        return false;

    if (tolower(word[length]) != tolower(matrix[x][y]))
        return false;

    x += directions[index][0];
    y += directions[index][1];
    return matchWord(x, y, index, length + 1);
}

bool findPosition()
{
    for (int i = 0; i < nlines; i++)
        for (int j = 0; j < nrows; j++)
        {
            if (tolower(word[0]) != tolower(matrix[i][j]))
                continue;

            for (int k = 0; k < 8; k++)
                if (matchWord(i, j, k, 0))
                {
                    cout << (i + 1) << " " << (j + 1) << endl;
                    return true;
                }
        }

    return false;
}

int main(int ac, char *av[])
{
    cin >> cases;
    while (cases--)
    {
        matrix.clear();
        cin >> nlines >> nrows;
        for (int i = 1; i <= nlines; i++)
        {
            cin >> line;
            matrix.push_back(line);
        }

        cin >> nwords;
        for (int i = 1; i <= nwords; i++)
        {
            cin >> word;
            findPosition();
        }

        if (cases > 0)
            cout << endl;
    }

    return 0;
}
