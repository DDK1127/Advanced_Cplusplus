#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int times, a, b, t, counter;
    cin >> times;
    while(times-- > 0){
        cin >> a >> b >> t;
        counter = ((a+t)/a)+((b+t)/b);
        cout << counter << endl;
    }
    return 0;
}
