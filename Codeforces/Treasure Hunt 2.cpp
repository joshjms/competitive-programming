#include <bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rnd(rd());

struct Data
{
    string response;
    int d;
    vector<pair<int, int>> neighbors;

    Data() {}

    void input()
    {
        string res;
        cin >> res;
        response = res;
        if (res == "AC")
            return;
        cin >> d;
        for (int i = 0; i < d; i++)
        {
            int d, flag;
            cin >> d >> flag;
            neighbors.push_back({d, flag});
        }
    }
};

void solve()
{
    int n, m, start, base;
    cin >> n >> m >> start >> base;

    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (true)
    {
        Data data = Data();
        data.input();

        if (data.response == "AC")
            break;
            
        cout << 1 << endl;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}