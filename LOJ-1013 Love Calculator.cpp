#include "bits/stdc++.h"
using namespace std;

typedef long long LL;

LL dp[64][28][32][32]; // len, char, id1, id2

void solve(int cs) {
	cout<<"Case "<<cs<<": ";
	string s, t;
	cin >> s >> t;

	s = '#'+ s;
	t = '#' + t;

	memset(dp, 0, sizeof dp);
	for(int i=0; i<26; i++) dp[0][i][0][0] = 1;

	for(int i=0; i<=60; i++) {
		for(char c='A'; c<='Z'; c++) {
			for(int j=0;j<s.size(); j++) {
				for(int k=0; k<t.size(); k++) {
					if( j+1<s.size() && k+1<t.size() && s[j+1]==t[k+1])dp[i+1][t[k+1]-'A'][j+1][k+1] += dp[i][c-'A'][j][k];
					else {
						if( j+1<s.size()) dp[i+1][s[j+1]-'A'][j+1][k] += dp[i][c-'A'][j][k];
						if(k+1<t.size()) dp[i+1][t[k+1]-'A'][j][k+1] += dp[i][c-'A'][j][k];
					}
				}
			}
		}
	}

	int mn = min(s.size(), t.size()) - 1, ans = -1;
	for(int i=mn; i<=60; i++) {
		if(ans!=-1) break;
		for(int j=0; j<26; j++) {
			if(dp[i][j][s.size()-1][t.size()-1]) ans = i;
		}
	}
	LL res = 0;
	for(int i=0; i<26; i++) res += dp[ans][i][s.size()-1][t.size()-1];

	cout<<ans<<' '<<res/26<<endl;
}

int  main() {

	int t;
	cin >> t;

	for(int i=1; i<=t; i++) solve(i);
	
}
