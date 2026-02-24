//递归法
#include<bits/stdc++.h>

using namespace std;

int n,minium=INT_MAX;
string bestpath="";
vector<vector<int>> input;

int numtwo(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        cnt++;
        x /= 2;
    }
    return cnt;
}
int numfive(int x) {
    int cnt = 0;
    while (x % 5 == 0) {
        cnt++;
        x/=5;
    }
    return cnt;
}

void visit(string npath,int two,int five,int ten,int x,int y){
    //计算0的个数
    int total;
    two+=numtwo(input.at(x).at(y));
    five+=numfive(input.at(x).at(y));
    total=ten+min(two,five);
    //到达右下角之后停止并判断
    if(x+y==2*n){
        if(total<minium){
            bestpath=npath;
            minium=total;
        }
    }
    //向下
    if(x<n)visit(npath+'D',two,five,ten,x+1,y);
    //向右
    if(y<n)visit(npath+'R',two,five,ten,x,y+1);
}

int main(){
    cin>>n;
    input.resize(n + 1, vector<int>(n + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>input.at(i).at(j);
        }
    }
    
    visit("",0,0,0,1,1);

    cout<<minium<<endl
        <<bestpath;
}