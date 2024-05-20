#include<bits/stdc++.h>
using namespace std;

vector<vector<bool> > vv(9, vector<bool>(9, true));

void check(vector<vector<bool> > &vv, int r, int c, int n){
    for(int i = 1; i <= n; i++){
        if(i != c)
            vv[r][i] = false;
        if(i != r)
            vv[i][c] = false;
    }
    int rr = r, cc = c;
    while(++rr <= n && ++cc <= n){
        vv[rr][cc] = false;
    }
    rr = r, cc = c;
    while(++rr <= n && --cc >= 0){
        vv[rr][cc] = false;
    }
    rr = r, cc = c;
    while(--rr >= 0 && --cc >= 0){
        vv[rr][cc] = false;
    }
    rr = r, cc = c;
    while(--rr >= 0 && ++cc <= n){
        vv[rr][cc] = false;
    }
}

int main(){
    srand(time(NULL));
    int r, c, result = 0;
    vector<pair<int, int> > ans;

    cout << "Queen's location : ";
    for(int i = 1; i <= 8; i++){
        c = rand()%8+1;
        cout << "[" << i << ", " << c << "] ";
        ans.push_back({i, c});
        check(vv, i, c, 8);
    }
    cout << endl;
    for(int i = 0; i < 8; i++){
        if(vv[ans[i].first][ans[i].second] == true){
            cout << "[" << ans[i].first << ", " << ans[i].second << "]  ";
            result++;
        }
    }
    cout << "\nhave " << result <<  " queens is safe!" << endl;

    vv.clear();
    ans.clear();
    return 0;
}
