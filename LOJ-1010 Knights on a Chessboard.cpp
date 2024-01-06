#include "bits/stdc++.h"
using namespace std;


int  main() {

	int t, c = 0;

	cin >> t;

	while(t--) {
		cout<<"Case "<<++c<<": ";

		int n, m;
		cin >> n >> m;

		if(n==1 || m==1) cout<<n*m<<endl;
		else if(n==2 || m == 2) cout<<((n*m)/8)*4 + min((n*m)%8,4)<<endl;
		else cout<< (n*m+1)/2 <<endl;
	}
}
