#include<bits/stdc++.h>
using namespace std;

vector<long long int> vv(100, 0);

long long int fib(int n){
    if(vv[n])
        return vv[n];
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}

void init(){
    for(int i = 0; i < vv.size(); i++)
        vv[i] = fib(i);
}

int main(){
    int number;
    init();

    cout << "Fibonacci sequence - Dynamic-Programming\nPlease input the number!" << endl;
    cin >> number;
    cout << "The Answer is : " << vv[number] << endl;

    vv.clear();

    return 0;
}
