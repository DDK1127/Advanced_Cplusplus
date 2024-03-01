#include <iostream>
using namespace std;

int main()
{
    cout << "菱形，請輸入高：" << endl;
    int n;
    cin >> n;
    
    if(n % 2 == 0){
        for(int i = 0; i < n/2; i++){
            for(int j = n/2-1; j > i; j--)
                cout << " ";
            for(int k = 0; k < 2*i+1; k++)
                cout << "*";
            cout << endl;
        }
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < i; j++)
                cout << " ";
            for(int k = n-1; k > 2*i; k--)
                cout << "*";
            cout << endl;
        }
        
    }
    else{
        for(int i = 0; i < n/2; i++){
            for(int j = n/2; j > i; j--)
                cout << " ";
            for(int k = 0; k <= 2*i; k++)
                cout << "*";
            cout << endl;
        }
        for(int i = 0; i <= n/2; i++){
            for(int j = 0; j < i; j++)
                cout << " ";
            for(int k = n; k > 2*i; k--)
                cout << "*";
            cout << endl;
        }
        
    }
    return 0;
}