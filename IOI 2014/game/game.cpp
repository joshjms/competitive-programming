#include "game.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int N;
int cnt[1505];

void initialize(int n) {
    N = n;
}

int hasEdge(int u, int v) {
    if(u > v) swap(u, v);
    if(cnt[v] == v - 1) return 1;
    cnt[v]++;
    return 0;
}
