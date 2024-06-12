#include<bits/stdc++.h>

using namespace std;

int gcd(int m, int n){
  return n != 0 ? gcd(n, m % n) : m;	
}

int lcm(int m,int n){
	return m * n / gcd(m, n);
}

int main(){
	int a, b;
	while(cin >> a >> b){
		cout << "GCD = " << gcd(a, b) << endl;
		cout << "LCM = " << lcm(a, b) << endl;
	}
	
	return 0;
}
