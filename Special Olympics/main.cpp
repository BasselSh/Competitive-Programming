#include <iostream>

#include<math.h>

#define eps 0.0000001
//#define pt complex<int>
using namespace std;
struct pt{
int x;
int y;
};
pt p1,p2;
int cnt;
double dis(pt p11, pt p22)
{
    int x=p11.x-p22.x;
    int y=p11.y-p22.y;
    return sqrt(x*x+y*y);
}
int check_ins(double u1,double u2)
{
    double d=dis(p1,p2);
    if(d>=u1+u2)
    {
        return 1;
    }
    if((d+u2)<=u1||(d+u1)<=u2)
    return -1;
    return 0;
}
int main()
{
    int r1,R1,r2,R2;
    cnt=0;
    cin>>p1.x>>p1.y>>r1>>R1>>p2.x>>p2.y>>r2>>R2;
    int a1,a2,b1,b2;
    a1=check_ins(r1,r2);
    a2=check_ins(r1,R2);
    b1=check_ins(R1,r2);
    b2=check_ins(R1,R2);
  //  cout<<a1<<a2<<b1<<b2<<endl;
  if((a1+a2+b1+b2)==-4)
  {
      cout<<2;
      return 0;
  }
    int r[4];
    r[0]=1;
    r[1]=1;
    r[2]=1;
    r[3]=1;
    if(a1*a2<0) r[0]=-1;
    if(b1*b2<0) r[1]=-1;
    if(a1*b1<0) r[2]=-1;
    if(a2*b2<0) r[3]=-1;
    if(a1==0)
    {
        r[0]=-1;
        r[2]=-1;
    }
    if(a2==0)
    {
        r[0]=-1;
        r[3]=-1;
    }
    if(b1==0)
    {
        r[1]=-1;
        r[2]=-1;
    }
    if(b2==0)
    {
        r[1]=-1;
        r[3]=-1;
    }

    for(int i=0;i<4;i++)
    {
        if(r[i]==1) cnt++;
    }
    cout<<cnt;
    return 0;
}
