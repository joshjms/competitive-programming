#include "addition.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

const ll mod = 1000000007;

ll n, cnt[4], ans, zero[2], ans1, ans2;
ll chinatsu, yui, akari, kyouko;

ll modex(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res % mod;
}

ll inv(ll x){
    return modex(x, mod - 2);
}

int count_arrangements(string A, string B, string C) {
    n = A.size();
    // there are four types:
    // A + B = C -> 0, 1, A + B + 1 = C -> 0, 1
    for(ll i = 0; i < n; i++){
        if((A[i] - '0') + (B[i] - '0') == (C[i] - '0')){
            cnt[0]++;
            if(A[i] == '0' || B[i] == '0') zero[0]++;
        }
        else if((A[i] - '0') + (B[i] - '0') + 1 == (C[i] - '0')){
            cnt[1]++;
            if(A[i] == '0' || B[i] == '0') zero[1]++;
        }
        else if(((A[i] - '0') + (B[i] - '0')) % 10 == (C[i] - '0'))
            cnt[2]++;
        else if(((A[i] - '0') + (B[i] - '0') + 1) % 10 == (C[i] - '0'))
            cnt[3]++;
        else return 0;
    }
    if(cnt[1] != cnt[2]){
        return 0;
    }
    // for(int i = 0; i < 4; i++)
    //     cout << cnt[i] << " ";
    // cout << "\n";

    // front is a non-zero type 0
    ans1 = cnt[0] - zero[0];
    akari = 1;
    for(int i = 1; i <= cnt[1]; i++)
        akari = (akari * i) % mod;
    chinatsu = 1;
    for(int i = 0; i < cnt[3]; i++)
        chinatsu = (chinatsu * (i + cnt[1])) % mod;
    yui = 1;
    for(ll i = 1; i <= cnt[1]; i++)
        yui = (yui * (i + cnt[0] - 1)) % mod;
    kyouko = 1;
    for(ll i = 1; i <= cnt[0] - 1; i++)
        kyouko = (kyouko * i) % mod;
    (ans1 *= (((akari * kyouko) % mod) * ((yui * chinatsu) % mod)) % mod) %= mod;
    // front is a non-zero type 1
    ans2 = cnt[2] - zero[1];
    akari = 1;
    for(int i = 1; i <= cnt[1]; i++)
        akari = (akari * i) % mod;
    chinatsu = 1;
    for(int i = 0; i < cnt[3]; i++)
        chinatsu = (chinatsu * (i + cnt[1])) % mod;
    yui = 1;
    for(ll i = 1; i < cnt[1]; i++)
        yui = (yui * (i + cnt[0])) % mod;
    kyouko = 1;
    for(ll i = 1; i <= cnt[0]; i++)
        kyouko = (kyouko * i) % mod;
    (ans2 *= (((akari * kyouko) % mod) * ((yui * chinatsu) % mod)) % mod) %= mod;
    ans = (ans1 + ans2) % mod;
    return ans;
}

// int main() {
//     std::string A, B, C;
//     std::cin >> A >> B >> C;
//     std::cout << count_arrangements(A, B, C) << '\n';
//     return 0;
// }
