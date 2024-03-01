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
}