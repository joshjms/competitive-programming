#include "addition.h"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"

const ll mod = 1e9 + 7;

ll n, cnt[4], ans;
ll chinatsu, yui, akari, kyouko;

int count_arrangements(string A, string B, string C) {
    n = A.size();
    vector <int> v;
    for(int i = 0; i < n; i++)
        v.pb(i);
    do{
        int newA = 0, newB = 0, newC = 0;
        if(A[v[0]] == '0' || B[v[0]] == '0' || C[v[0]] == '0') continue;
        for(int i = 0; i < n; i++){
            newA = newA * 10 + A[v[i]] - '0';
            newB = newB * 10 + B[v[i]] - '0';
            newC = newC * 10 + C[v[i]] - '0';
        }
        if(newA + newB == newC){
            akari++;
        }
    } while(next_permutation(v.begin(), v.end()));
    return akari;
}

int main() {
    std::string A, B, C;
    std::cin >> A >> B >> C;
    std::cout << count_arrangements(A, B, C) << '\n';
    return 0;
}
