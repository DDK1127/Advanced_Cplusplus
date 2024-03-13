// LeetCode 402.Remove K Digits
class Solution {
public:
    string removeKdigits(string num, int k) {
        string str = "";
        int size = num.size();
        stack<char> ss;

        ss.push(num[0]);

        for(int i = 1; i < size; i++){
            if(k <= 0){}
            else if(ss.top() > num[i]){
                ss.pop();
                k--;
            }
            ss.push(num[i]);
        }
        while(k > 0){
            ss.pop();
            k--;
        }
        if(ss.empty()){
            str = "0";
            return str;
        }

        while(!ss.empty()){
            str += ss.top();
            ss.pop();
        }
        reverse(str);

        return str;
    }
    void reverse(string &str){
        int l = 0, r = str.size()-1;
        while(l < r){
            swap(str[l], str[r]);
            l++, r--;
        }
    }
};
