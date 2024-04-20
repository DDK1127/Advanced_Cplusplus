#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, col;
    string str;

    ifstream in;
    ofstream out;

    in.open("pa.in");

    if(in.fail()){
        cout << "input file opening failed." << endl;
        exit(1);
    }

    out.open("pa.out");

    if(out.fail()){
        cout << "output file opening failed." << endl;
        exit(1);
    }

    while(in >> row >> col){

        in.ignore();
        getline(in, str);

        if(str == "#")
            break;
        if(str.size() != row*col){
            out << "<encrypted length error>" << endl;
            continue;
        }

        int len = 0;
        int r = 0, c = 0;
        bool diag_down = false;

        vector<vector<string> > vv(row, vector<string>(col, ""));
        vector<vector<string> > ans(row, vector<string>(col, ""));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++)
                vv[i][j] = str[len++];
        }

        for(int x = 0; x < row*col; x++){
            ans[r][c] = vv[x/col][x%col];
            // cout << "r, c = " << r << ", " << c << endl;
            // cout << vv[r][c];

            if(diag_down && c != 0 && r != row-1){
                r++;
                c--;
                continue;
            }

            if(!diag_down && r != 0 && c != col-1){
                r--;
                c++;
                continue;
            }

            if((r == 0 || r == row-1) && c != col-1){
                c++;
                if(r == 0)
                    diag_down = true;
                if(r == row-1)
                    diag_down = false;
                continue;
            }

            if((c == 0 || c == col-1) && r != row-1){
                r++;
                if(c == 0)
                    diag_down = false;
                if(c == col-1)
                    diag_down = true;
                continue;
            }
        }

        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                if(ans[j][i] != "*")
                    out << ans[j][i];
            }
        }
        out << endl;
        vv.clear();
        ans.clear();
    }
    return 0;
}
