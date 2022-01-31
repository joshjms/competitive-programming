#include "shoes.h"

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

int n, arr[200005];
vector <int> pos[200005];
bool vis[200005];
ll ans;

struct fenwick_tree{
    int bit[200005];
    void upd(int idx, int val){
        for(; idx <= 2 * n; idx += (idx & -idx)){
            bit[idx] += val;
        }
    }
    int query(int idx){
        int res = 0;
        for(; idx >= 1; idx -= (idx & -idx)){
            res += bit[idx];
        }
        return res;
    }
    int query(int l, int r){
        return query(r) - query(l - 1);
    }
} fwt;

long long count_swaps(vector<int> s) {
    n = s.size() / 2;
    for(int i = 1; i <= 2 * n; i++)
        arr[i] = s[i - 1];
    for(int i = 2 * n; i >= 1; i--){
        pos[arr[i] + n].pb(i);
    }
    for(int i = 1, u, v; i <= 2 * n; i++){
        if(vis[i]) continue;
        u = i;
        v = pos[arr[i] * (-1) + n].back();
        vis[u] = vis[v] = 1;
        pos[arr[i] + n].pop_back();
        pos[arr[i] * (-1) + n].pop_back();
        if(arr[i] < 0)
            ans += (v - u - 1) - fwt.query(u, n) + fwt.query(v, n);
        else ans += (v - u) - fwt.query(u, n) + fwt.query(v, n);
        fwt.upd(v, 1);
    }
    return ans;
}