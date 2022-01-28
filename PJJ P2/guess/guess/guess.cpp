#include "guess.h"

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

int na, nb, nc, k;
int ia, ib, ic;
int res;

void initialize(int NA, int NB, int NC) {
    na = NA, nb = NB, nc = NC;
}

int query(int a, int b, int c){
    return ask(min(a, na), min(b, nb), min(c, nc));
}

int guess(int K) {
    k = K;
    ia = ib = ic = 0;
    while(k > 0){
        res = query(ia + (k + 2) / 3 - 1, ib + (k + 2) / 3 - 1, ic + (k + 2) / 3 - 1);
        if(res == 0) ia += (k + 2) / 3;
        else if(res == 1) ib += (k + 2) / 3;
        else ic += (k + 2) / 3;
        k -= (k + 2) / 3;
    }
    res = query(ia, ib, ic);
    if(res == 0) return ia;
    else if(res == 1) return na + ib;
    else return na + nb + ic;
}