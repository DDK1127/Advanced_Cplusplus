#include<bits/stdc++.h>
using namespace std;

long long int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}


int main(){
    int number;

    cout << "Fibonacci sequence - Divide-and-Conquer\nPlease input the number!" << endl;
    cin >> number;
    cout << "The Answer is : " << fib(number) << endl;

    return 0;
}
