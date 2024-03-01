#include<iostream>
using namespace std;

int main(){
    cout << "空心倒金字塔，請輸入高：" << endl;
    int n; 
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            cout << " ";
        for(int k = 2*(n-i)-1; k > 0; k--){
            if((k == 1 || k == 2*(n-i)-1) || i == 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}