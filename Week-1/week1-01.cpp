#include<iostream>
using namespace std;

int main(){
    cout << "三角形金字塔，請輸入高：" << endl;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--)
            cout << " ";
        for(int k = 0; k < 2*i+1; k++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
