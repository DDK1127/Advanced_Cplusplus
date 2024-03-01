#include<iostream>
#include<algorithm>
using namespace std;

int alg(long long int n, int t){
    if(n == 1)
        return t;
    else
        return (n % 2)? alg(3*n+1, ++t):alg(n/=2, ++t);
}
void Swap(long long int &i, long long int &j){
    long long int temp = i;
    i = j;
    j = temp;
}

int main(){
    long long int i, j;
    int max;
    while(cin >> i >> j){
        max = 0;
        if(i > j){
            for(long long int k = j; k <= i; k++){
                if(max < alg(k, 1))
                    max = alg(k ,1);
            }
        }
        else{
            for(long long int k = i; k <= j; k++){
                if(max < alg(k, 1))
                    max = alg(k ,1);
            }
        }
        cout << i << " " << j << " " << max << endl;
    }
    return 0;
}