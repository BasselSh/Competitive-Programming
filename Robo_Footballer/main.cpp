#include <iostream>
#include<iomanip>
#include<complex>

#define eps 0.000000001
#define x real()
#define y imag()
#define pt complex<double>

using namespace std;

double l1,l2,lw,xb,lb,r,x2;
pt pp1,pp2,ppn1,ppn2;

bool check(pt a, pt b, pt c)
{
    pt aa=b-a;
    pt bb=c-a;
    return ((conj(aa)*bb).y)>0;
}
double calc(double l)
{
    double d2=lw-l-r;
    double d1=lw-lb-r;
    double ans=(d2*xb)/(d1+d2);
    return ans;
}
void calc_points_c(double mid)
{
    pt p1=pt(0,mid);
    pt p2=pt(x2,lw-r);
    pt v=p2-p1;
    double d=hypot(v.x,v.y);
    v=v/d;
    pt v90;
    v90=pt(-v.y,v.x);
    v90=v90*r;
    pp1=p1+v90;
    pp2=p2+v90;
}
void calc_points_cc(double mid)
{
    pt p1=pt(0,mid);
    pt p2=pt(x2,lw-r);
    pt v=p2-p1;
    double d=hypot(v.x,v.y);
    v=v/d;
    pt v90;
    v90=pt(v.y,-v.x);
    v90=v90*r;
    ppn1=p1+v90;
    ppn2=p2+v90;
}

double bsh(double dn,double up)
{
    double mid=(up+dn)/2.0;
    x2=calc(mid);
    if(up-dn<eps)
    {
        calc_points_c(mid);
        if(!check(pp1,pp2,pt(0,l2)))
        {
           // cout<<up;
            return -1;
        }
        calc_points_cc(mid);
        if(check(ppn1,ppn2,pt(0,l1)))
        {
            return -1;
        }
        return up;
    }
    calc_points_c(mid);
    calc_points_cc(mid);
    cout<<mid<<" "<<pp1<<" "<<pp2<<endl;
    if(check(pp1,pp2,pt(0,l2))&&(!check(ppn1,ppn2,pt(0,l1))))
    return x2;
   // if((!check(pp1,pp2,pt(0,l2)))&&(check(ppn1,ppn2,pt(0,l1))))
 //   return -1;
    if(check(pp1,pp2,pt(0,l2)))
    {
        return bsh(mid,up);
    }
    else return bsh(dn,mid);

}

int main()
{
    cin>>l1>>l2>>lw>>xb>>lb>>r;
    double ans=bsh(l1,l2);
    cout<<setprecision(20)<<ans;

  //  cout<<setprecision(20)<<ans;
    return 0;
}
