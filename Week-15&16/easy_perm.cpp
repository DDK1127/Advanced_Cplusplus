// no repeat character
#include<bits/stdc++.h>
using namespace std;

// void SWAP(vector<char> &a, vector<char> &b){
    
// }

int perm(vector<char> &vv, int n, int &counter){
    if(n == vv.size()-1){
        counter++;
        for(int i = 0; i < vv.size(); i++)
            cout << vv[i];
        cout << endl;
    }
    else{
        for(int i = n; i < vv.size(); i++){
            swap(vv[n], vv[i]);
            perm(vv, n+1, counter);
            swap(vv[n], vv[i]);
        }
    }
    return counter;
}

int main(){
    vector<char> vv;
    char input;
    int counter = 0;
    
    while(cin >> input){
        vv.push_back(input);
    }
    cout << "total = " << perm(vv, 0, counter) << endl;
    return 0;
}