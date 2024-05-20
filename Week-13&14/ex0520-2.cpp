#include<bits/stdc++.h>
using namespace std;

vector<vector<bool> > vv(8, vector<bool>(8, true));

void check(vector<vector<bool> > &vv, int r, int c, int n){
    for(int i = 0; i < n; i++){
        vv[r][i] = false;
        vv[i][c] = false;
    }
    int rr = r, cc = c;
    while(++rr < n && ++cc < n){
        vv[rr][cc] = false;
    }
    rr = r, cc = c;
    while(++rr < n-1 && --cc > 0){
        vv[rr][cc] = false;
    }
    rr = r, cc = c;
    while(--rr > 0 && --cc > 0){
        vv[rr][cc] = false;
    }
    rr = r, cc = c;
    while(--rr > 0 && ++cc < n-1){
        vv[rr][cc] = false;
    }
}

int main(){

    int r, c, result = 0;
    vector<pair<int, int> > ans;
    for(int i = 0; i < 8; i++){
        cin >> r >> c;
        ans.push_back({r, c});
        check(vv, r, c, 8);
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < 8; i++){
        if(vv[ans[i].first][ans[i].second] == true){
            cout << "[" << ans[i].first << ", " << ans[i].second << "]" << endl;
            result++;
        }
    }


    cout << "It's safe to have " << result <<  " queens!" << endl;

    vv.clear();
    return 0;
}
