#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

struct pod{
    int cabin, pod;
};

int N, A[100005];
vector <int> adj[100005];
vector <pair<pod,pod>> edges;
int parent[100005], entry_point[100005], prev_pod[100005];
int dp[100005];
vector <int> dfs_order;

void getParents(int pos, int par){
    dfs_order.push_back(pos);
    for(auto i : adj[pos]) if(i != par){
        parent[i] = pos;
        getParents(i, pos);
    }
}

int dist(int cabin, int entry, int ext){
    return min((entry - ext + A[cabin]) % A[cabin], (ext - entry + A[cabin]) % A[cabin]);
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    parent[0] = -1;
    for(int i = 1, a, b, c, d; i < N; i++){
        cin >> a >> b >> c >> d;
        adj[a].push_back(c);
        adj[c].push_back(a);
        edges.push_back({{a, b}, {c, d}});
    }
    getParents(0, -1);
    entry_point[0] = 0;
    for(auto i : edges){
        if(i.fi.cabin == parent[i.se.cabin]){
            entry_point[i.se.cabin] = i.se.pod;
            prev_pod[i.se.cabin] = i.fi.pod;
        }
        else if(i.se.cabin == parent[i.fi.cabin]){
            entry_point[i.fi.cabin] = i.fi.pod;
            prev_pod[i.fi.cabin] = i.se.pod;
        }
    }
    dp[0] = 0;
    for(auto i : dfs_order){
        if(i == 0) continue;
        dp[i] = dp[parent[i]] + dist(parent[i], entry_point[parent[i]], prev_pod[i]) + 1;
    }
    cout << dp[N - 1] << "\n";
}