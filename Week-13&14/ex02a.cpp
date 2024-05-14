#include<bits/stdc++.h>
using namespace std;

vector<vector<long long int> > vv(100, vector<long long int>(100, 0));

long long int Binomial(int n, int m){
    if(vv[n][m])
        return vv[n][m];
    if(m == 1)
        return n;
    if(m == 0 || n == m)
        return 1;
    return Binomial(n-1, m-1)+Binomial(n-1, m);
}

void init(){
    for(int i = 0; i < vv.size(); i++){
        for(int j = i; j < vv.size(); j++){
            vv[j][i] = Binomial(j, i);
        }
    }
}

int main(){
    int n, k;
    init();

    cout << "10th Pascal's triangle" << endl;
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j <= i; j++)
            if(vv[i][j])
                cout << setw(5) << vv[i][j];
        cout << endl;
    }
    cout << "\nBinomial coefficient - Dynamic-Programming\nPlease input two number (n, k)!" << endl;
    cin >> n >> k;
    cout << "The Answer is : " << vv[n][k] << endl;
    vv.clear();

    return 0;
}
