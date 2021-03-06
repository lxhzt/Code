// Sex Assignments and Breeding Experiments
// UVa ID: 359
// Verdict: Accepted
// Submission Date: 2018-05-04
// UVa Run Time: 0.060s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

bool sexy;
vector<int> color, degree, dfn, low, scc;
int dfstime, cscc;
vector<vector<int>> edges, parents;
stack<int> s;

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfstime; s.push(u);
    for (auto v : edges[u])
    {
        if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
        else if (!scc[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++cscc;
        while (true)
        {
            int v = s.top(); s.pop();
            scc[v] = cscc;
            if (u == v) break;
        }
    }
}

// Check if graph is DAG or not.
void dfs(int u)
{
    if (!sexy) return;
    color[u] = 0;
    for (auto v : edges[u])
        if (color[v] == -1)
            dfs(v);
        else if (color[v] == 0)
        {
            sexy = false;
            break;
        }
    color[u] = 1;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases = 0, x, y, n, m;
    while (cin >> n >> m)
    {
        edges.assign(n, vector<int>());
        parents.assign(n, vector<int>());
        degree.assign(n, 0);

        sexy = true;
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            x--, y--;
            edges[x].push_back(y);
            degree[y]++;
            // Every node has most two parents.
            if (degree[y] > 2) sexy = false;
            parents[y].push_back(x);
        }
        
        if (sexy)
        {
            // Check DAG.
            color.assign(n, -1);
            for (int i = 0; i < n; i++)
                if (color[i] == -1)
                    dfs(i);
        }
        
        // 2-SAT.
        if (sexy)
        {
            dfstime = 0, cscc = 0;
            while (!s.empty()) s.pop();
            edges.assign(2 * n, vector<int>());
            dfn.assign(2 * n, 0);
            low.assign(2 * n, 0);
            scc.assign(2 * n, 0);
            
            for (int i = 0; i < n; i++)
                if (parents[i].size() > 1)
                {
                    int b1 = parents[i][0], b2 = parents[i][1];
                    edges[b1 + n].push_back(b2);
                    edges[b2 + n].push_back(b1);
                    edges[b2].push_back(b1 + n);
                    edges[b1].push_back(b2 + n);
                }

            for (int i = 0; i < 2 * n; i++)
                if (!dfn[i])
                    tarjan(i);

            for (int i = 0; i < n; i++)
                if (scc[i] == scc[i + n])
                {
                    sexy = false;
                    break;
                }
        }

        cout << "Graph number " << ++cases << " is ";
        cout << (sexy ? "sexy" : "not sexy") << '\n';
    }

    return 0;
}
