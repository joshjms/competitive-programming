#include "city.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

ll n, m, s, t;
vector <pair<ll,ll>> g[100005];
vector <pair<ll,pair<ll,ll>>> edge, newedge;
vector <pair<ll,ll>> imp;

ll maxw, md[2][100005];
pair<ll,pair<ll,ll>> ans;

vector <ll> cc[100005];
pair<ll,ll> cmds, cmdt, cmi, mds, mdt, mi;

struct disjoint_set_union{
    ll par[100005];
    disjoint_set_union(){
        for(int i = 0; i <= 100000; i++)
            par[i] = i;
    }
    ll find(ll u){
        if(u == par[u])
            return u;
        return par[u] = find(par[u]);
    }
    ll join(ll u, ll v){
        u = find(u), v = find(v);
        if(u == v) return 0;
        par[u] = v;
        return 1;
    }
} dsu, newdsu;

void dijkstra(ll source, ll idx){
    priority_queue <pair<ll,ll>> pq;
    md[idx][source] = 0;
    pq.push({0, source});
    while(pq.empty() == false){
        ll dist = -pq.top().fi;
        ll node = pq.top().se;
        pq.pop();
        if(dist > md[idx][node]) continue;
        for(auto i : g[node]){
            if(dist + i.se < md[idx][i.fi]){
                md[idx][i.fi] = dist + i.se;
                pq.push({-md[idx][i.fi], i.fi});
            }
        }
    }
}

pair<int,int> getBestXY(int N, int M, int S, int T, vector<int> A,  vector<int> B,  vector<int> C) {
    n = N, m = M, s = S, t = T;
    for(int i = 0; i < m; i++){
        g[A[i]].pb({B[i], C[i]});
        g[B[i]].pb({A[i], C[i]});
        edge.pb({C[i], {A[i], B[i]}});
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        if(dsu.join(edge[i].se.fi, edge[i].se.se) == 1){
            // cout << "join " << edge[i].se.fi << " and " << edge[i].se.se << "\n";
            maxw = edge[i].fi;
            newedge.pb(edge[i]);
        }
    }
    for(int i = 0; i < n; i++)
        md[0][i] = md[1][i] = 1e18 + 7;
    dijkstra(s, 0);
    dijkstra(t, 1);
    for(int i = 0; i < newedge.size(); i++){
        if(newedge[i].fi >= maxw) break;
        newdsu.join(newedge[i].se.fi, newedge[i].se.se);
    }
    for(int i = 0; i < n; i++)
        cc[newdsu.find(i)].pb(i);
    ans = {1e18, {1e9, 1e9}};
    mds = mdt = mi = cmds = cmdt = cmi = {1e18 + 7, -1};
    for(int i = 0; i < n; i++){
        if(cc[i].size() == 0) continue;
        for(auto j : cc[i]){
            if(mds.se != -1)
                ans = min(ans, {md[1][j] + md[0][mds.se], {min(j, mds.se), max(j, mds.se)}});
            if(mdt.se != -1)
                ans = min(ans, {md[0][j] + md[1][mdt.se], {min(j, mdt.se), max(j, mdt.se)}});
            if(mi.se != -1)
                ans = min(ans, {md[0][t], {min(j, mi.se), max(j, mi.se)}});
            cmds = min(cmds, {md[0][j], j});
            cmdt = min(cmdt, {md[1][j], j});
            cmi = min(cmi, {0, j});
        }
        mds = min(mds, cmds);
        mdt = min(mdt, cmdt);
        mi = min(mi, cmi);
    }
    return ans.se;
}  