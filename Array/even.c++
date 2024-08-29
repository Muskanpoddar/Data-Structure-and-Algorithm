#include<bits/stdc++.h>
using namespace std;
 int main(){
    int a[7]= {2,5,4,7,8,13,15};

    int count = 0;
    for (int i =0; i<7 ; i++){
        
        if ( a[i] %2 ==0){
            count = count +1;
        }
    }
    cout << "The number of even elements =" <<count <<endl;
 }
