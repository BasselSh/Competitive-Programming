#include <iostream>
#include <math.h>


using namespace std;

#define ll long long
#define eps 0.0000001

double pi=acos(-1);
ll xp,yp,vx,vy,a,b,c,d;

double ang()
{
    if(fabs(vx)<eps)
    {
        return pi/2.0;
    }
    return atan2(vy,vx);
}

struct vecc
{
    ll vx;
    ll vy;
    vecc operator*(const ll& k)
    {
        vecc temp;
        temp.vx=vx*k;
        temp.vy=vy*k;
        return temp;
    }
};
struct point
{
    ll x;
    ll y;
    point operator*(const vecc& v)
    {
        point temp;
        temp.x=x+v.vx;
        temp.y=y+v.vy;
        return temp;
    }

};

int main()
{
    double angle;
    double ang2;
    double temp;
    point q[7];
    point p;
    vecc vn;
    vecc vl;
    vecc vnn;
    vecc vr;
    double leng;
    cin>>p.x>>p.y>>vx>>vy>>a>>b>>c>>d;
    leng=sqrt(vx*vx+vy*vy);
    vn.vx=double (vx)/leng;
    vn.vy=double (vy)/leng;
    q[0]=p*(vn*b);
    vl.vx=-vn.vy;
    vl.vy=vn.vx;
    q[1]=p*(vl*(double(a)/2.0));
    cout<<q[0].x<<","<<q[0].y<<" "<<q[1].x<<","<<q[1].y;
        return 0;
}
