#include "teleport.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

const ll mod = 1000000007;

int tmr;

struct hub {
    int id;
    vector <int> tp;
};

vector <hub> hubs;

int n;
int par[205];
vector <int> g[205];

void maketree(int prv){
    int visited = ask_news_channel();
    int cnttp = ask_count_teleporters();
    int lsttp = ask_last_teleporter();
    if(visited == 0){
        change_news_channel(++tmr);
    }
    visited = ask_news_channel();
    for(int i = 0; i < cnttp; i++){
        use_teleporter(i);
        int home = ask_last_teleporter();
        if(ask_news_channel() == 0){
            maketree(visited);
            use_teleporter(home);
        }
        else{
            // debug(visited - 1);
            // debug(ask_news_channel() - 1);
            g[visited - 1].pb(ask_news_channel() - 1);
            g[ask_news_channel() - 1].pb(visited - 1);
            use_teleporter(home);
        }
    }
}

vector <int> ans;

void bfs(int pos){
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    queue <pair<int,int>> bfs;
    bfs.push({pos, 0});
    vis[pos] = true;
    while(!bfs.empty()){
        int u = bfs.front().fi;
        int c = bfs.front().se;
        ans[c]++;
        bfs.pop();
        for(auto i : g[u]) if(vis[i] == false){
            vis[i] = true;
            bfs.push({i, c + 1});
        }
    }
}

vector<int> explore(int N, int X) {
    // make tree
    n = N;
    maketree(-1);
    ans.resize(n, 0);
    for(int i = 0; i < n; i++){
        bfs(i);
        // for(int j = 0; j < n; j++)
        //     cout << ans[j] << " ";
        // cout << "\n";
    }
    // for(int i = 0; i < n; i++){
    //     debug(i);
    //     for(auto j : g[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }
    // for(int i = 0; i < n; i++)
    //     cout << ans[i] << " ";
    // cout << "\n";
    for(int i = 1; i < n; i++)
        ans[i] /= 2;
    return ans;
}
