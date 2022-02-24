// AKARINNN!!!!!!!!! <3

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, k, arr[1000005], akari, max_bit, chinatsu;

struct node{
    int val = 0;
    node *child[2];
    node() : val(0) {child[0] = child[1] = nullptr;};
};

node* root = new node();

void query(node *u, int bit, int x){
    if(bit == -1) return;
    if(bit > max_bit){
        bool v = (x & (1ll << bit));
        if(u -> child[v])
            query(u -> child[v], bit - 1, x);
    }
    else{
        bool kyouko = (x & (1ll << bit));
        bool yui = (k & (1ll << bit));
        bool v = kyouko ^ yui;
        if(yui){
            if(u -> child[1 ^ v])
                chinatsu += u -> child[1 ^ v] -> val;
        }
        if(u -> child[v])
            query(u->child[v], bit - 1, x);
    }
}

void update(node *u, int bit, int x){
    if(bit == -1){
        u -> val += 1;
        return;
    }
    bool v = (x & (1ll << bit));
    if(!u -> child[v])
        u -> child[v] = new node();
    update(u -> child[v], bit - 1, x);
    u -> val = 0;
    if(u->child[0])
        u -> val += u -> child[0] -> val;
    if(u->child[1])
        u -> val += u -> child[1] -> val;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < 30; i++)
        if(k & (1ll << i))
            max_bit = i;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
    }
    update(root, 30, 0);
    for(int i = 1; i <= n; i++){
        chinatsu = 0;
        query(root, 30, arr[i]);
        akari += chinatsu;
        update(root, 30, arr[i]);
    }
    akari = (n * (n + 1) / 2) - akari;
    cout << akari << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}