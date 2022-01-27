#include "experiment.h"

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

ll n, m;
ll sum[300005][9];
/*  6 7 8
    3 4 5
    0 1 2   */
vector <ll> ans;

struct fenwick_tree{
    ll bit[300005];
    void upd(int idx, int val){
        for(; idx <= n; idx += (idx & -idx))
            bit[idx] += val;
    }
    ll sum(int idx){
        ll sum = 0;
        for(; idx >= 1; idx -= (idx & -idx)){
            sum += bit[idx];
        }
        return sum;
    }
    ll sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
} fwt;

struct dengklekium{
    ll x, y;
};

struct rectangle{
    ll idx, phase, lx, rx, y;
};

ll idx = 0;

vector <dengklekium> vd;
vector <rectangle> vr;

vector<long long> get_experiment_results(int N, int M,
                                            vector<int> P, vector<int> Q,
                                            vector<int> L, vector<int> R,
                                            vector<int> D, vector<int> U) {
    n = N;
    m = M;
    ans.assign(m, 0);
    for(int i = 0; i < n; i++)
        vd.pb({P[i] + 1, Q[i] + 1});
    sort(vd.begin(), vd.end(), [](dengklekium a, dengklekium b){
        return a.y < b.y;
    });
    for(int i = 0; i < m; i++){
        vr.pb({i, 0, L[i] + 1, R[i] + 1, D[i]});
        vr.pb({i, 1, L[i] + 1, R[i] + 1, U[i] + 1});
        vr.pb({i, 2, L[i] + 1, R[i] + 1, n + 1});
    }
    sort(vr.begin(), vr.end(), [](rectangle a, rectangle b){
        return a.y < b.y;
    });
    for(auto i : vr){
        while(idx < vd.size() && vd[idx].y <= i.y){
            fwt.upd(vd[idx].x, 1);
            idx++;
        }
        sum[i.idx][i.phase * 3 + 0] = fwt.sum(0, i.lx - 1);
        sum[i.idx][i.phase * 3 + 1] = fwt.sum(i.lx, i.rx);
        sum[i.idx][i.phase * 3 + 2] = fwt.sum(i.rx + 1, n);
    }
    for(int i = 0; i < m; i++){
        for(int j = 8; j >= 3; j--)
            sum[i][j] -= sum[i][j - 3];
    }
    for(int i = 0; i < m; i++){
        ans[i] += sum[i][0] * (sum[i][4] + sum[i][5] + sum[i][7] + sum[i][8]);
        ans[i] += sum[i][1] * (sum[i][3] + sum[i][4] + sum[i][5] + sum[i][6] + sum[i][7] + sum[i][8]);
        ans[i] += sum[i][2] * (sum[i][3] + sum[i][4] + sum[i][6] + sum[i][7]);
        ans[i] += sum[i][3] * (sum[i][4] + sum[i][5] + sum[i][7] + sum[i][8]);
        ans[i] += sum[i][4] * (sum[i][5] + sum[i][6] + sum[i][7] + sum[i][8]);
        ans[i] += sum[i][5] * (sum[i][6] + sum[i][7]);
        ans[i] += sum[i][4] * (sum[i][4] - 1) / 2;
    }
    return ans;
}
