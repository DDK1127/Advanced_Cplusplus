#include<bits/stdc++.h>
using namespace std;

long long int Binomial(int n, int m){
        return vv[n][m];
    if(m == 1)
        return n;
    if(n == m || m == 0)
        return 1;
    return Binomial(n-1, m-1)+Binomial(n-1, m);
}

int main(){
    int n, k;

    cout << "Binomial coefficient - Divide-and-Conquer\nPlease input two number (n, k)!" << endl;
    cin >> n >> k;
    cout << "The Answer is : " << Binomial(n, k) << endl;

    return 0;
}
