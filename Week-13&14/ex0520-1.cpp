#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int n, input;
    cout << "Please input NxN Matrix!" << endl;
    cin >> n;

    vector<vector<int> > vv(n, vector<int>(n));
    cout << "Original Matrix" << endl;
    // Manual entry
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> input;
            vv[i][j] = input;
        }
    }
    */

    // Random numbers
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                vv[i][j] = 0;
            else
                vv[i][j] = rand()%(100)+1;
            cout << vv[i][j] << "   ";
        }
        cout << endl;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                vv[i][j] = min(vv[i][j], vv[i][k]+vv[k][j]);
        }
    }
    cout << "My ans is =>" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }

    vv.clear();
    return 0;
}
