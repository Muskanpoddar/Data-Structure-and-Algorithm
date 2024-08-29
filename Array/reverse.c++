#include<bits/stdc++.h>
using namespace std;

int main() {

    int a[5] = {2,3,4,5,6};

    int l =0;
    int r = 4;
    
    while(l<r){
       

        int temp = a[r];
        a[r] = a[l];
        a[l] = temp;

        l++;
        r--;
    }
    for(int i=0; i<5;i++){
        cout<< a[i]<< " ";
    }
}