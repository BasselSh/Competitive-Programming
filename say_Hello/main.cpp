#include <iostream>
#include <math.h>
#define ll long long
#define eps 0.0000001
using namespace std;

struct vecc
{
    double x;
    double y;
    vecc operator*(double d)
    {
        vecc temp;
        temp.x=x*d;
        temp.y=y*d;
        return temp;
    }
    vecc operator-(vecc a)
    {
        vecc t;
        t.x=x-a.x;
        t.y=y-a.y;
        return t;
    }
};

struct point
{
    ll x;
    ll y;
    vecc operator-(point a)
    {
        vecc t;
        t.x=x-a.x;
        t.y=y-a.y;
        return t;
    }
    point operator+(vecc v)
    {
        point t;
        t.x=v.x+x;
        t.y=v.y+y;
        return t;
    }
};

double dist(point p1, point p2)
{
    double dx=p2.x-p1.x;
    double dy=p2.y-p1.y;
    return sqrt(dx*dx+dy*dy);
}

int cross(point a,point b, point c)
{
    double dx1=b.x-a.x;
    double dy1=b.y-a.y;
    double dx2=c.x-a.x;
    double dy2=c.y-a.y;
    double test=dx1*dy2-dy1*dx2;
    if(test>eps)
    return 1;
    if(test<-eps)
    return -1;
    return 0;
}

double dot(point a,point b,point c)
{
    double x1=a.x-b.x;
    double y1=a.y-b.y;
    double x2=c.x-b.x;
    double y2=c.y-b.y;
    return x1*x2+y1*y2;
}

double cross_val(point a,point b,point c)
{
    double dx1=b.x-a.x;
    double dy1=b.y-a.y;
    double dx2=c.x-a.x;
    double dy2=c.y-a.y;
    return (dx1*dy2-dy1*dx2);
}

double dis_from_line(point a,point b,point c)
{
    if(fabs(cross_val(a,b,c))<eps)
    {
        long double tx=(c.x-a.x)*(c.x-b.x);
        long double ty=(c.y-a.y)*(c.y-b.y);
        if(tx<0||ty<0)
        {
            return 0;
        }
        else
        {
            return dist(b,c);
        }
    }

    if(dot(a,b,c)<(-eps))
    {
        return dist(b,c);
    }
    if(dot(b,a,c)<(-eps))
    {
        return dist(a,c);
    }
    double dx1=b.x-a.x;
    double dy1=b.y-a.y;
    double dx2=c.x-a.x;
    double dy2=c.y-a.y;
    double d1=sqrt(dx1*dx1+dy1*dy1);
    return fabs((dx1*dy2-dy1*dx2)/d1);
}

int main()
{
    int n;
    cin>>n;
    point p1[n],p2[n];
    double cr1=0;
    double cr2=0;
    ll d1,d2;
    cin>>d1>>d2;
    int cnt=0;
    bool mem=false;
    for(int i=0;i<n;i++)
    {
        cin>>p1[i].x>>p1[i].y>>p2[i].x>>p2[i].y;
    }
    if(dist(p1[0],p2[0])<d1)
    {
        cnt++;
        mem=true;
    }
    for(int i=0;i<n-1;i++)
    {
        vecc v1=p1[i+1]-p1[i];
        vecc v2=p2[i+1]-p2[i];
        vecc v=v2-v1;
        point p=p2[i]+v;
            double d=dis_from_line(p2[i],p,p1[i]);
            if(d<=d1)
            {
                if(!mem)
                {
                    cnt++;
                    mem=true;
                }

            }
    //    }
        if(dist(p2[i+1],p1[i+1])>=d2)
        mem=false;
    }
    cout<<cnt;
/*
8
100 200
500 500 301 301
500 500 301 699
500 500 500 500
500 500 699 301
500 500 499 301
500 500 499 400
500 500 400 500
500 500 480 520


*/

    return 0;
}
