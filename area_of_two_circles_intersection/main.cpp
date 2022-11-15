#include <iostream>
#include <math.h>
#include<iomanip>

#define eps 0.0000001
#define pi acos(-1)
#define ll long long


using namespace std;

struct vec
{
    double x;
    double y;
    vec operator*(double d)
    {
        vec v;
        v.x=x*d;
        v.y=y*d;
        return v;
    }
    vec operator/(double d)
    {
        vec v;
        v.x=x/d;
        v.y=y/d;
        return v;
    }
};


struct pt
{
    double x;
    double y;
    vec operator-(pt p)
    {
        vec v;
        v.x=x-p.x;
        v.y=y-p.y;
        return v;
    }
    pt operator+(vec v)
    {
        pt p;
        p.x=x+v.x;
        p.y=y+v.y;
        return p;
    }
};
double dis(pt a, pt b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}
vec rot(vec v,double ang)
{
    vec nn;
    nn.x=v.x*cos(ang)-v.y*sin(ang);
    nn.y=v.x*sin(ang)+v.y*cos(ang);
    return nn;
}

double cross(pt a, pt b,pt c)
{
    double x1=a.x-b.x;
    double y1=a.y-b.y;
    double x2=c.x-b.x;
    double y2=c.y-b.y;
    return fabs(x1*y2-y1*x2);
}

int main()
{
    pt p1,p2,temp;
    pt d1,d2,d1new,d2new;
    ll r1,r2;
    double s11,s12,s21,s22,s1,s2;
    vec nn,v,n90;
    cin>>p1.x>>p1.y>>r1;
    cin>>p2.x>>p2.y>>r2;
    double d=dis(p1,p2);
    double rmin=min(r1,r2);
    if((d+r1)<=r2||(d+r2)<=r1)
    {

        cout<<setprecision(20)<<pi*rmin*rmin;
        return 0;
    }
    if(d>=(r1+r2))
    {
        cout<<0;
        return 0;
    }
    nn=p2-p1;
    nn=nn/dis(p1,p2);
    double ang=acos(double(r2*r2-r1*r1-d*d)/double(-2.0*r1*d));
    v=rot(nn,ang);
    d1=p1+v*r1;
    v=rot(nn,-ang);
    d2=p1+v*r1;
    s11=ang*r1*r1;
    s12=cross(d1,p1,d2)/2.0;
    s1=s11-s12;
    s21=ang*r1*r1;
    s22=cross(d1,p1,d2)/2.0;
    s2=s21-s22;
    cout<<setprecision(20)<<pi*rmin*rmin-fabs(s1-s2)<<endl;
    if(d<r1&&d<r2)
  {
      cout<<setprecision(20)<<s1+s2;
      return 0;
  }
  if(d<r1||d<r2)
  {
      cout<<setprecision(20)<<pi*rmin*rmin-fabs(s1-s2);
  }
  else
    cout<<setprecision(25)<<s1+s2;
    return 0;
}
