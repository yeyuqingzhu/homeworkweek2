#include<bits/stdc++.h>
using namespace std;
struct player{
    string name;
    int score;
    player(){
        name="";
        score=0;
    }
};
int main(){
    string aname,wname="";
    int n,ascore,wscore=INT_MIN;
    cin>>n;
    bool find;
    player players[1001];
    for(int i=1;i<=n;i++){
        cin>>aname>>ascore;
        find=0;
        int j=0;
        for(j=1;players[j].name!=""&&j<=n;j++){
            if(players[j].name==aname){
                find=1;
                players[j].score+=ascore;
                if(players[j].score>wscore){
                    wscore=players[j].score;
                    wname=players[j].name;
                }
            }
        }
        if(find==0){
            players[j].name=aname;
            players[j].score+=ascore;
            if(players[j].score>wscore){
                wscore=players[j].score;
                wname=players[j].name;
            }
        }
    }
    cout<<wname;
    return 0;
}