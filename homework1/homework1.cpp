#include<bits/stdc++.h>
using namespace std;
int main(){
    int input_n,input_m,input_a;
    int output_n,output_m,output_total;
    cin>>input_n>>input_m>>input_a;
    output_n=input_n/input_a;
    if(input_n%input_a!=0){
        output_n++;
    }
    output_m=input_m/input_a;
    if(input_m%input_a!=0){
        output_m++;
    }
    output_total=output_n*output_m;
    cout<<output_total<<endl;
    return 0;
}