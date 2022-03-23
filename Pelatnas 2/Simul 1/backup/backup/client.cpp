#include "client.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

const ll mod = 1000000007;

int ans;
pair <int,int> par[25];
vector <pair<int,int>> g[25];

void dfs(int pos, int prv, int edge){
    par[pos] = {prv, edge};
    for(auto i : g[pos]) if(i.fi != prv){
        dfs(i.fi, pos, i.se);
    }
}

int client(int N, std::vector<int> A, std::vector<int> B, int W) {  
    for(int i = 0; i < N; i++){
        g[i].clear();
        par[i] = {-1, -1};
    }
    ans = 0;
    for(int i = 0; i < N - 1; i++){
        g[A[i]].pb({B[i], i});
        g[B[i]].pb({A[i], i});
    }
    dfs(0, -1, -1);
    int u = W;
    while(u != 0){
        ans += get_bit(par[u].se);
        u = par[u].fi;
    }
    return ans;
}
