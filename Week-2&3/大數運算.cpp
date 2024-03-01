#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 10000

void init(string &str1, string &str2, int *n1, int *n2){
    for (int i = 0; i < str1.size(); i++)
        n1[i] = str1[i] - '0';
    for (int i = 0; i < str2.size(); i++)
        n2[i] = str2[i] - '0';
}

void reverse_array(int *n, int size){
    for (int i = 0; i < size / 2; ++i) {
        int temp = n[i];
        n[i] = n[size - 1 - i];
        n[size - 1 - i] = temp;
    }
}

void add_array(int *n1, int size_n1, int *n2, int size_n2, int *n3){
    int carry = 0;
    for(int i = 0; i < max(size_n1, size_n2)+1; i++){
        n3[i] = n1[i]+n2[i]+carry;
        carry = n3[i]/10;
        n3[i] %= 10; 
    }
}
void sub_array(int *n1, int size_n1, int *n2, int size_n2, int *n3, bool &sign){
    int borrow = 0;
    bool n1_n2 = true;

    if(size_n1 > size_n2)
        sign = true, n1_n2 = true;
    else if(size_n1 == size_n2){
        int i = 1;
        while(n1[size_n1]-i != n1[size_n2]-i){i++;}
        if(n1[size_n1]-i > n2[size_n2]){n1_n2 = true;sign = true;}
        else{n1_n2 = false;sign = false;}
    }
    else
        sign = false, n1_n2 = false;

    if(n1_n2){
        for(int i = 0; i < max(size_n1, size_n2); i++){
            n3[i] = n1[i] - n2[i] - borrow;
            if(n3[i] < 0){
                borrow = 1;
                n3[i] += 10;
            }
            else
                borrow = 0;
        }
    }
    else{
        for(int i = 0; i < max(size_n1, size_n2); i++){
            n3[i] = n2[i] - n1[i] - borrow;
            if(n3[i] < 0){
                borrow = 1;
                n3[i] += 10;
            }
            else
                borrow = 0;
        }
    }
}

void mul_array(int *n1, int size_n1, int *n2, int size_n2, int *n3){
    for(int i = 0; i <= size_n1; i++){
        for(int j = 0; j < size_n2; j++){
            n3[i+j] += n1[i]*n2[j];
        }
    }
    int carry = 0;
    for(int i = 0; i < size_n1+size_n2; i++){
        n3[i] += carry;
        if(n3[i] >= 10){
            carry = n3[i]/10;
            n3[i] %= 10;
        }
        else    
            carry = 0;
    }
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int n1[SIZE]={0}, n2[SIZE]={0}, n3[SIZE]={0};
    int n1_size = str1.size(), n2_size = str2.size();
    bool sign = true;

    init(str1, str2, n1, n2);
    reverse_array(n1, n1_size);
    reverse_array(n2, n2_size);
    int n3_size = n1_size+n2_size;
    mul_array(n1, n1_size, n2, n2_size, n3);


    // output number
    cout << "n1 is = ";
    for (int i = n1_size-1; i >= 0; i--)
        cout << n1[i];
    cout << endl;

    cout << "n2 is = ";
    for (int i = n2_size-1; i >= 0; i--)
        cout << n2[i];
    cout << endl;

    cout << "n3 is = ";
    if(!sign)
        cout << "-";
    for (int i = n3_size-1; i >= 0; i--)
        cout << n3[i];
    cout << endl;

    return 0;
}[?1049h[>4;2m[?1h=[?2004h[?1004h[1;29r[?12h[?12l[22;2t[22;1t[27m[23m[29m[m[H[2J[?25l[29;1H".gitignore" [New][1;1H[38;5;130m  1 [m
[94m~                                                                                                       [3;1H~                                                                                                       [4;1H~                                                                                                       [5;1H~                                                                                                       [6;1H~                                                                                                       [7;1H~                                                                                                       [8;1H~                                                                                                       [9;1H~                                                                                                       [10;1H~                                                                                                       [11;1H~                                                                                                       [12;1H~                                                                                                       [13;1H~                                                                                                       [14;1H~                                                                                                       [15;1H~                                                                                                       [16;1H~                                                                                                       [17;1H~                                                                                                       [18;1H~                                                                                                       [19;1H~                                                                                                       [20;1H~                                                                                                       [21;1H~                                                                                                       [22;1H~                                                                                                       [23;1H~                                                                                                       [24;1H~                                                                                                       [25;1H~                                                                                                       [26;1H~                                                                                                       [27;1H~                                                                                                       [28;1H~                                                                                                       [1;5H[?25h[?4m[29;1H[?2004l[>4;m[23;2t[23;1t[m[29;1H[K[29;1H[?1004l[?2004l[?1l>[?1049l[>4;m