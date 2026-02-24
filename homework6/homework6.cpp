#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main(){
    double x1,y1,r1,x2,y2,r2,x3,y3,r3;
    cin>>x1>>y1>>r1>>x2>>y2>>r2>>x3>>y3>>r3;
    // 系数来自前两个圆 (1,2) 和 (1,3)
    double A12=2.0*(x2-x1);
    double B12=2.0*(y2-y1);
    double C12=x1*x1+y1*y1-x2*x2-y2*y2;
    double D12=r1*r1-r2*r2;
    double A13=2.0*(x3-x1);
    double B13=2.0*(y3-y1);
    double C13=x1*x1+y1*y1-x3*x3-y3*y3;
    double D13=r1*r1-r3*r3;
    double det=A12*B13-A13*B12;
    if (fabs(det)<EPS){
        // 三点共线（题目保证不共线，此处仅为防御）
        return 0;
    }
    // 将 x, y 表示为 K 的线性函数：x = αK + β,  y = γK + δ
    double alpha=(D12*B13-D13*B12)/det;
    double beta=(-C12*B13+C13*B12)/det;
    double gamma=(A12*D13-A13*D12)/det;
    double delta=(-A12*C13+A13*C12)/det;
    // 代入第一个圆的方程得到关于 K 的二次方程
    double Acoeff=alpha*alpha+gamma*gamma;
    double Bcoeff=2.0*(alpha*(beta-x1)+gamma*(delta-y1))-r1*r1;
    double Ccoeff=(beta-x1)*(beta-x1)+(delta-y1)*(delta-y1);
    vector<double> K_vals;
    if (fabs(Acoeff)<EPS){
        // 一次方程
        if (fabs(Bcoeff)>EPS){
            double K=-Ccoeff/Bcoeff;
            K_vals.push_back(K);
        }
    }else{
        double disc=Bcoeff*Bcoeff-4.0*Acoeff*Ccoeff;
        if(disc<-EPS){
            // 无实根
        }else{
            if(disc<0)disc=0;
            double sqrt_disc=sqrt(disc);
            double K1=(-Bcoeff+sqrt_disc)/(2.0*Acoeff);
            double K2=(-Bcoeff-sqrt_disc)/(2.0*Acoeff);
            K_vals.push_back(K1);
            K_vals.push_back(K2);
        }
    }
    vector<pair<double,pair<double,double>>>candidates; // (K, (x,y))
    for(double K:K_vals){
        if(K<1.0-EPS)continue;   // 点必须在圆外或圆上 (K ≥ 1)
        double x=alpha*K+beta;
        double y=gamma*K+delta;
        candidates.push_back({K,{x, y}});
    }
    if(candidates.empty()){
        return 0;   // 无解，不输出任何内容
    }
    // 选择视角最大的点，即 K 最小的点
    auto best=min_element(candidates.begin(),candidates.end(),
        [](const pair<double,pair<double,double>>& a,const pair<double,pair<double,double>>& b){
            return a.first<b.first;
        });
    double best_x=best->second.first;
    double best_y=best->second.second;
    cout<<fixed<< setprecision(5)<<best_x<<" "<< best_y<<endl;
    return 0;
}