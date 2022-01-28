#include <bits/stdc++.h>
using namespace std;

#include "guess.h"

#define debug(x) cout << #x << " => " << x << "\n"

int NA, NB, NC;

void initialize(int NA, int NB, int NC) {
	::NA = NA, ::NB = NB, ::NC = NC;
}

int iA, iB, iC;
int l, r, md, opp, ans;

int query(int a, int b, int c){
	if(a == NA) return 1;
	if(b == NB) return 0;
	if(a == -1) return 0;
	if(b == -1) return 1;
	return ask(a, b, NC);
}

int guess(int K) {
	if(K == 0){
		if(ask(0, 0, NC) == 0) return 0;
		else return NA;
	}

	int M = K + 1;
	l = max(0, M - NB), r = min(NA, M), ans = -1;
	// TAKE EXACTLY M

	while(l <= r){
		md = (l + r) / 2; // take md from A
		opp = M - md; // take opp from B
		if(query(md - 1, opp, -1) == 1) r = md - 1;
		else l = md + 1, ans = md;
	}
	if(query(ans - 1, M - ans - 1, NC) == 1) return ans - 1;
	else return NA + M - ans - 1;
}