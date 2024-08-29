#include<bits/stdc++.h>
using namespace std;
 int main(){

    int a[5] = {1,6,78,98,56};
    int mx= a[0];
    for(int i=0; i<5; i++){
        if(a[i]>mx){
            mx = a[i];
        }
    }
    cout<< "The maximum element in the array is ="<<mx <<endl;
 }

