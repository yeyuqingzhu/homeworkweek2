#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,size,C;
    bool RXCY=0;
    int line,column;
    string sline,scolumn;
    vector<string> input;
    string singleinput;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>singleinput;
        input.push_back(singleinput);
    }
    /********************************************************************************/
    for(int i=0;i<num;i++){
        singleinput=input.at(i);
        size=singleinput.size();
        RXCY=0;
        for(int j=1;j<=size-1;j++){
            if(isupper(singleinput[j])&&isdigit(singleinput[j-1])){
                RXCY=1;
                C=j;
                break;
            }
        }
    /*******************判断表达格式*****************/        
        if(RXCY){
            column=0;
            line=0;
            for(int j=1;j<C;j++){
                column=column*10+singleinput[j]-48;
            }
            for(int j=C+1;j<size;j++){
                line=line*10+singleinput[j]-48;
            }
            sline="";
            while(line){
                if(line%26){
                    sline=char(line%26+64)+sline;
                }
                else{
                    sline=char(90)+sline;
                }
                line/=26;
            }
            cout<<sline<<column<<endl;
        }
    /*********RXCY格式转化**************************/
        else{
            column=0;
            line=0;
            for(int j=0;j<size;j++){
                if(isupper(singleinput[j])){
                    if(singleinput[j]=='Z'){
                        column=column*26+26;
                    }   
                    else{
                        column=column*26+singleinput[j]-64;
                    }
                }
                else{
                    line=line*10+singleinput[j]-48;
                }
            }
            cout<<'R'<<line<<"C"<<column<<endl;
        }
    }
    return 0;
}