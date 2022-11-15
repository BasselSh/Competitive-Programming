#include <iostream>
#include<math.h>
#include <deque>
#include<vector>
#include<iomanip>

#define eps 0.00000000001
#define ll long long
#define pi acos(-1)
using namespace std;
struct vecc
{
    double x;
    double y;
    vecc operator*( double d)
    {
        vecc t;
        t.x=x*d;
        t.y=y*d;
        return t;
    }
};
struct point
{
    double x;
    double y;
    point operator+(vecc v)
    {
        point t;
        t.x=x+v.x;
        t.y=y+v.y;
        return t;
    }
};

 double dist(point a, point b)
{
    double dx=b.x-a.x;
    double dy=b.y-a.y;
    return sqrt(dx*dx+dy*dy);
}
vecc rot_vec( double ang)
{
    vecc t;
    t.x=-sin(ang);
    t.y=cos(ang);
    return t;
}
double calc_ang(point a, point b, point c)
{
    double x1=a.x-b.x;
    double y1=a.y-b.y;
    double x2=c.x-b.x;
    double y2=c.y-b.y;
    double d1=sqrt(x1*x1+y1*y1);
    double d2=sqrt(x2*x2+y2*y2);
    double ang=acos((x1*x2+y1*y2)/(d1*d2));
    /*if(x1*y2-y1*x2<0)
    {
        cout<<"KKKKKKKKKKKK"<<endl;
        ang=2*pi-ang;
    }*/

    return ang;
}
int main()
{
    int k=-1;
    vector<point> res;
    deque<int> pin;
    pin.push_back(1);
    pin.push_back(2);
    ll id=0;
    ll n,q;
    int tp;
    ll f,t,v;
    double angle;
    point m;
    double mx,my;
    mx=0;
    my=0;
    cin>>n>>q;
     double d[n+1];
    double ang[n+1];
    point poly[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>poly[i].x>>poly[i].y;
        mx+=poly[i].x;
        my+=poly[i].y;
    }
    mx=mx/double(n);
    my=my/double(n);
    m.x=mx;
    m.y=my;
    ang[1]=0;
    angle=2.0*pi/double(n);
    for(int i=1;i<=n;i++)
    {
        d[i]=dist(m,poly[i]);
        if(i==1)
        {
            cout<<"ang="<<ang[i]<<endl;
            continue;
        }
        else
        {
            ang[i]=ang[i-1]+calc_ang(poly[i-1],m,poly[i]);
            cout<<"ang="<<calc_ang(poly[i-1],m,poly[i])<<endl;
        }
    }
    int kk=-1;
    if(m.x==poly[1].x) id=1;
    if(m.x==poly[2].x) id=2;
    if(poly[1].x==poly[2].x)
    {
        if(poly[1].y>poly[2].y)
        id=1;
        else id=2;
    }
    cout<<"M="<<m.x<<","<<m.y<<endl;
    for(int i=1;i<=q;i++)
    {
        cin>>tp;
        if(tp==1)
        {
            if(k==-1) k=1;
            cin>>f>>t;
            if(id==0)
            {
           //     cout<<"PP"<<endl;
                if(f==1)
                {
                    pin.pop_front();
                    if(m.x==poly[pin.back()].x)
                    {
                     id=pin.back();
                     pin.push_back(t);
                     cout<<"PP"<<endl;

                    }
                    else
                    {
                        id=pin.back();
                        m.x=poly[id].x;
                        m.y=poly[id].y-d[id];
                        pin.push_back(t);
                    }

                }
                else
                {

                    pin.pop_back();
                    if(m.x==poly[pin.back()].x)
                    {
                     id=pin.back();
                     pin.push_back(t);
                     cout<<"PP"<<endl;

                    }
                    else
                    {
                        id=pin.back();
                        m.x=poly[id].x;
                        m.y=poly[id].y-d[id];
                        pin.push_back(t);
                    }

                }
            }
            else
            {
                if(pin.back()==f)
            {
                pin.pop_back();
                pin.push_back(t);
            }
            else
            {
                pin.pop_front();
                id=pin.back();
                m.x=poly[id].x;
                m.y=poly[id].y-d[id];
                pin.push_back(t);
            }
            }
            poly[t]=m+(rot_vec(ang[t]-ang[id])*d[t]);
            cout<<"X_t="<<poly[t].x<<endl;
            cout<<"y_t="<<setprecision(11)<<poly[t].y<<endl;
            cout<<"X_id="<<poly[id].x<<endl;
            cout<<pin.back()<<","<<pin.front()<<endl;
            cout<<"M="<<m.x<<","<<m.y<<endl;
        }
        else if(tp==2)
        {
           cin>>v;
           if(k==-1)
           {
               res.push_back(poly[v]);
               continue;
           }
           point temp=m+(rot_vec(ang[v]-ang[id])*d[v]);
           res.push_back(temp);
        }
    }
 //    cout<<m.x<<" "<<m.y<<endl;
 //cout<<setprecision(20)<<pi<<endl;
 //cout<<cos(pi)<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<setprecision(11)<<res[i].x<<" "<<setprecision(11)<<res[i].y<<endl;
     //   res.pop_back();
    }
    //X_t=-5.53798
    return 0;
}
