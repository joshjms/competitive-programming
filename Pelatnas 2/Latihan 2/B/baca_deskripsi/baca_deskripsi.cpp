#include "baca_deskripsi.h"

// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define ll long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m;
vector <int> a, b;
vector <int> ans;

struct node{
    struct node * child[2];
    node(){
        child[0] = child[1] = nullptr;
    }
};

node * root = new node();

int query(node * cur, int pang, int val){
    if(pang < 0) return 0;
    int aqua = ((val >> pang) & 1) ^ 1;
    if(cur -> child[aqua])
        return query(cur -> child[aqua], pang - 1, val) + (1ll << pang);
    else return query(cur -> child[1 ^ aqua], pang - 1, val);
}

void upd(node * cur, int pang, int val){
    if(pang < 0) return;
    int aqua = (val >> pang) & 1;
    if(!cur -> child[aqua])
        cur -> child[aqua] = new node();
    upd(cur -> child[aqua], pang - 1, val);
}

vector<int> getAnswers(int in_n, int in_m, vector<int> in_A, vector<int> in_B){
	n = in_n;
    m = in_m;
    a = in_A;
    b = in_B;
    for(int i = 0; i < a.size(); i++)
        upd(root, 30, a[i]);
    for(int i = 0; i < b.size(); i++)
        ans.pb(query(root, 30, b[i]));
	return ans;
} 