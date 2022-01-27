#include <bits/stdc++.h>
using namespace std;

#define ld long double

#define pb push_back
#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"
#define sp " "

#include "reverse.h"

int l, r, p;

vector<vector<int>> reverse_array(int N) {
    if(N == 1){
        return {};
    }
    if(N == 2){
        return {{1, 1, 2}};
    }
    vector <vector<int>> res;
    if(N & 1){
        res.push_back({1, N / 2, N - 1});
        l = N / 2, r = l + 1, p = N;
        while(l && r && p){
            res.push_back({l--, r--, p--});
        }
    }
    else{
        res.push_back({1, N / 2, N});
        l = N / 2, r = l + 1, p = N;
        while(l && r && p){
            res.push_back({l--, r--, p--});
        }
    }
    return res;
}