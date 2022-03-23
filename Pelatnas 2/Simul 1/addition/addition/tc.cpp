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

string a, b, c;

int main() {
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        if(i % 2 == 0)
            c += char(((b[i] - '0') + (a[i] - '0')) % 10 + '0');
        else c += char(((b[i] - '0') + (a[i] - '0') + 1) % 10 + '0');
    }
    cout << a << "\n" << b << "\n" << c << "\n";
}
