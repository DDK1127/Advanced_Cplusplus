// Tower of Hanoi - usnig Divide-and-Conquer

#include<bits/stdc++.h>
using namespace std;

long long int hanoi(int n, char a, char b, char c, int &t){
    if(n == 1){
        cout <<  "Step " << ++t << ". Move from " << a << " to " << c << endl;
    }
    else{
        hanoi(n-1, a, c, b, t);
        hanoi(1, a, b, c, t);
        hanoi(n-1, b, a, c, t);
    }
    return t;
};

int main(){
    int number, t = 0;
    cout << "Tower of Hanoi - usnig Divide-and-Conquer\nPlease input the number of disks!" << endl;
    cin >> number;
    
    cout << hanoi(number, 'A', 'B', 'C', t);
    return 0;
}