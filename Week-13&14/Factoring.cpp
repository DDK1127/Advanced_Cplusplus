#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

ll gcd(ll m, ll n){
  return n != 0 ? gcd(n, m % n) : m;	
}

ll lcm(ll m,ll n){
	return m * n / gcd(m, n);
}

int main(){
	ll a, b;
	
	vector<vector<int> > vv(0);
	while(cin >> a >> b){
		cout << "GCD = " << gcd(a, b) << endl;
		cout << "LCM = " << lcm(a, b) << endl;
	}
	
	return 0;
}
