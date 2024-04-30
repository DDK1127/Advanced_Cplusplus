#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    int l1 = s1.size(), l2 = s2.size();
    int carry;
    vector<int> ans(l1*l2+1, 0);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int i, j;
    for(i = 0; i < l1; i++){
        carry = 0;
        for(j = 0; j < l2; j++){
            int a1 = s1[i]-'0',  a2 = s2[j]-'0';

            ans[i+j] += carry;
            carry = (a1*a2+ans[i+j])/10;
            ans[i+j] = (a1*a2+ans[i+j])%10;

            // cout << "a1 = " << a1 << ", a2 = " << a2 << endl;
            // cout << "carry = " << carry << endl;
        }
        ans[i+j] += carry;
        // cout << i << "'th => " << endl;
    }
    reverse(ans.begin(), ans.end());

    bool start = false;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] != 0)
            start = true;
        if(start)
            cout << ans[i];
    }
    cout << endl;
    ans.clear();
    
    return 0;
}