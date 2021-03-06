// String Computer
// UVa ID: 164
// Verdict: Accepted
// Submission Date: 2016-02-12
// UVa Run Time: 0.019s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int NONE = -1, DELETE = 0, INSERT = 1, CHANGE = 2, MATCH = 3;

struct cell { int cost, operation; };

cell cells[25][25];
string S, T, operationCode = "DIC";
int M, N, deletions, insertions;

void displayPath(int i, int j)
{
    if (cells[i][j].operation >= DELETE && cells[i][j].operation <= CHANGE) {
        cout << operationCode[cells[i][j].operation];
        if (cells[i][j].operation == CHANGE) {
            cout << T[j];
            cout << setw(2) << setfill('0') << j;
        }
        else if (cells[i][j].operation == DELETE) {
            cout << S[i];
            cout << setw(2) << setfill('0') << (i + insertions - deletions);
            deletions++;
        }
        else if (cells[i][j].operation == INSERT) {
            cout << T[j];
            cout << setw(2) << setfill('0') << j;
            insertions++;
        }
    }
}

void findPath(int i, int j)
{
    if (cells[i][j].operation != NONE) {
        if (cells[i][j].operation == DELETE)
            findPath(i - 1, j);
        else if (cells[i][j].operation == INSERT)
            findPath(i, j - 1);
        else
            findPath(i - 1, j - 1);
    }
    displayPath(i, j);
}

void med()
{
    S = ' ' + S;
    T = ' ' + T;
    M = S.length() - 1;
    N = T.length() - 1;

    cells[0][0] = (cell){0, NONE};
    for (int i = 1; i <= M; i++) cells[i][0] = (cell){i, DELETE};
    for (int j = 1; j <= N; j++) cells[0][j] = (cell){j, INSERT};

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            cells[i][j] = (cell){cells[i - 1][j].cost + 1, DELETE};
            if (cells[i][j].cost > (cells[i][j - 1].cost + 1))
                cells[i][j] = (cell){cells[i][j - 1].cost + 1, INSERT};
            if (S[i] == T[j]) {
                if (cells[i][j].cost > cells[i - 1][j - 1].cost)
                    cells[i][j] = (cell){cells[i - 1][j - 1].cost, MATCH};
            } else {
                if (cells[i][j].cost > (cells[i - 1][j - 1].cost + 1))
                    cells[i][j] = (cell){cells[i - 1][j - 1].cost + 1, CHANGE};
            }
        }

    deletions = insertions = 0;
    findPath(M, N);
    cout << "E" << endl;
}

int main(int argc, char *argv[])
{
    while (cin >> S, S != "#" && cin >> T) med();
    return 0;
}
