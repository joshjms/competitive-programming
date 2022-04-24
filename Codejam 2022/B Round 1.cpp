#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int ntc;

int n, arr[1005], sa, sb, sc;
vector <int> ans, a, b, outa;

void solve () {
    cin >> n;
    // debug(n);

    sa = 0, sb = 0, sc = 0;
    ans.clear();
    a.clear();
    b.clear();
    outa.clear();

    for(int m = 1; m <= 1e9; m *= 10) {
        for(int j = 0; j * m <= 1e9 && j <= 9; j++) {
            if(a.size() < n && j * m > 0 && j * m <= 1e9) {
                outa.pb(j * m);
                a.pb(j * m);
                sa += a.back();
            }
        }
    }

    for(int i = 1e9 - 1; outa.size() < n; i--) {
        outa.pb(i);
        b.pb(i);
    }

    for(int i = 0; i < n; i++) {
        cout << outa[i] << " ";
    }
    cout << endl;
    cout.flush();

    for(int i = 0; i < n; i++) {
        int amogus; cin >> amogus;
        b.push_back(amogus);
    }

    sort(b.begin(), b.end());

    int f = 0;

    // debug(sc);
    
    for(int i : a)
        sc += i;
    for(int i : b)
        sc += i;

    f = sc;

    assert(sc % 2 == 0);

    sc /= 2;

    int u = b.size() - 1;

    // debug(sc);
    // debug(sa);
    while(sc >= 2e9) {
        sc -= b[u];
        ans.pb(b[u]);
        u--;
    }

    int akari = 1;

    // debug(sc);
    while(sc) {
        ans.pb(akari * (sc % 10));
        akari *= 10;
        sc /= 10;
    }

    int peko = 0;

    for(auto i : ans) {
        if(i > 0 && i <= 1e9)
            cout << i << " ";
        peko += i;
    }
    cout << endl;

    cout.flush();

    assert(peko == f / 2);

    // debug(peko);
    // debug(f);
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC; cin >> TC;
    for(ntc = 1; ntc <= TC; ntc ++) {
        solve (); 
    }
}

// 851303747 260544608 741164563 916070890 11977547 268731076 634291232 375283616 648624915 786125459 811733929 831389154 600157552 809415334 252781927 445902035 22148636 683589888 669038071 519960556 274333614 189213014 702130444 691412163 714187024 685180874 569956552 245180709 147238981 675646736 151259259 620155910 918015398 633398362 89370410 759937808 504073357 299239267 459229730 17363836 679181885 377152807 739673078 398126897 486178088 306622389 545581749 707694503 573427626 546826160 184181251 909335981 123317320 387749630 806799098 920485697 45756454 244181478 26211037 255050742 271754009 813237058 329434711 712034036 134838251 55925966 542189269 769512463 235862842 615928367 207714228 582849039 208439223 595731588 689102654 136971659 43479315 993175067 738207170 835453065 23680265 935688310 112582450 194887621 520625408 363930024 984194068 847381800 466714080 664752806 876697853 340580083 772683506 700699364 77119366 217606055 707160644 500686310 397173711 935078851