// Ultra-QuickSort
// UVa ID: 10810
// Verdict: Accepted
// Submission Date: 2017-12-02
// UVa Run Time: 0.090s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;

int temp[MAXN];

long long merge(int data[], int left, int middle, int right)
{
    long long count = 0;
    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right)
        temp[k++] = data[i] <= data[j] ? data[i++] : (count += middle + 1 - i, data[j++]);
    while (i <= middle) temp[k++] = data[i++];
    while (j <= right) temp[k++] = data[j++];
    for (int i = 0; i < k; i++) data[left + i] = temp[i];
    return count;
}

long long mergeSort(int data[], int left, int right)
{
    long long count = 0;
    if (left < right)
    {
        int middle = (left + right) >> 1;
        count += mergeSort(data, left, middle);
        count += mergeSort(data, middle + 1, right);
        count += merge(data, left, middle, right);
    }
    return count;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int n, data[MAXN];
    while (cin >> n, n > 0)
    {
        for (int i = 0; i < n; i++)
            cin >> data[i];
            
        cout << mergeSort(data, 0, n - 1) << '\n';
    }

    return 0;
}
