//原理：采用辗转相除法，先求得圆心角，再求出最小公约数以算得边数，最后采用面积公式求解
#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
/*---------------------------定义点结构-----------------------------*/
struct point{
    double x,y;
};
/*-----------------------------------------------------------------*/
/*----------------------------长度计算-------------------------------*/
double distant(point pa,point pb){
    return sqrt(pow((pa.x-pb.x),2)+pow((pa.y-pb.y),2));
}
/*-----------------------------------------------------------------*/
/*-----------------------------浮点数判断相等-------------------------*/
bool feq(double a,double b){
    return abs(a-b)<1e-6;
}
/*-----------------------------------------------------------------*/
/*---------------------------------辗转相除法------------------------*/
double fgcd(double anga,double angb){
    if(feq(angb,0))return anga;
    return fgcd(angb,fmod(anga,angb));
}
/*-----------------------------------------------------------------*/

/*---------------------------------主函数---------------------------*/
int main(){
    point p1,p2,p3;
    double dis1,dis2,dis3;
    double ang1,ang2,ang3;
    double angmin;
    double r,p,area;
    cin>>p1.x>>p1.y
       >>p2.x>>p2.y
       >>p3.x>>p3.y;
    dis1=distant(p1,p2);
    dis2=distant(p2,p3);
    dis3=distant(p3,p1);                         //计算长度
    p=(dis1+dis2+dis3)/2;
    area=sqrt(p*(p-dis1)*(p-dis2)*(p-dis3));     //计算面积
    r=(dis1*dis2*dis3)/(4.0*area);               //计算外接圆半径
    ang1=2*asin(dis1/(2*r));
    ang2=2*asin(dis2/(2*r));
    ang3=2*asin(dis3/(2*r));                     //计算圆心角
    if(ang1<ang2)swap(ang1,ang2);
    if(ang1<ang3)swap(ang1,ang3);
    if(ang2<ang3)swap(ang2,ang3);                //判断三个角的大小以方便使用辗转相除法
    /*辗转相除法依次求最小角*/
    angmin=fgcd(ang1,ang2);
    if(ang3<angmin)swap(ang3,angmin);
    angmin=fgcd(ang3,angmin);                    //计算正多边形的最小角
    cout<<((PI*r*r*sin(angmin))/angmin);
}