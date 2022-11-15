#include <bits/stdc++.h>
#include<complex>
#define F first
#define S second
using namespace std;

const double PI  = acos(-1.0);
typedef complex<double> pt;

#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define eps 0.00005

int main()
{
#ifdef ONLINE_JUDGE
    freopen("joy.in" , "r" , stdin);
    freopen("joy.out" , "w" , stdout);
#endif
    vector<pt> pp;
    double x,y;
    int n,k,vm;
    cin>>x>>y;
    pt s(x,y);
    pp.push_back(s);
    cin>>x>>y;
    pt f(x,y);
    pt m=f-s;
    double d=length(m);
    pt m_n=normalize(m);
    cin>>n>>k>>vm;
    queue< pair<int , pt> > wt;

    for (int i=0;i<n;i++)
    {
        int tt; cin>>tt;
        double xx,yy;
        cin>>xx>>yy;
        pt tmp(xx,yy);
        wt.push( {tt , tmp} );
    }

    pt res;
    pt nnn;
    int kk=-1;
    pt s2;
    for (int i=0;i<k;i++)
    {
        if(i==wt.front().F)
        {
            if(length(wt.front().S)<eps)
            {
               res={m_n.real()*vm, m_n.imag()*vm};
            }
            else
            {

            if(fabs(cp(wt.front().S,m_n))<eps ||fabs(dp(wt.front().S,m_n))<eps)
            {
                if(fabs(cp(wt.front().S,m_n))<eps)
                {
                    if(dp(wt.front().S,m_n)>0)
                    res=m_n*(vm+length(wt.front().S));
                    else
                    res=m_n*(vm-length(wt.front().S));
                }

                else
                {
                  double len1=length(wt.front().S);
                double len3  = sqrt( vm * vm - len1 * len1 );
                res = m_n * len3;
                }

            }
            else
            {
            double tetta = acos((dp(m_n, wt.front().S )) / (length(wt.front().S) * length(m_n)));
           // cout<<tetta*180/PI<<endl;
         //  cout<<m_n.real()<<" "<< m_n.imag()<<endl;
            double len1  = length(wt.front().S) * sin(tetta);
            double len2  = length(wt.front().S) * ((dp(m_n, wt.front().S )) / (length(wt.front().S) * length(m_n)));
            double len3  = sqrt( vm * vm - len1 * len1 );
            double len4 = len2 + len3;
            res = m_n * len4;
            }
            }
            wt.pop();
        }
        double dd=length(f-s);
        pt vv=f-s;
        if(length(res) >= (dd-0.00001))
        {
            int rest = k - i;
            if(rest==1)
            {
                s=f;
               pp.push_back(f);
               break;
            }
            for(int j=1;j<=rest;j++)
            {
                double uu=(rest-j)*eps;
                nnn={m_n.real()*uu, m_n.imag()*uu};
              s=f-nnn;
              if(j==rest)
              {
                  s=f;
                  pp.push_back(f);
              }
              else
              pp.push_back(s);
            }
            break;
        }
        s2=s+m_n*vm+wt.front().S;
        if(length(f-s)<length(f-s2))
        {
           s = s + res;
            pp.push_back(s);
        }
        else
        {
            s=s2;
           pp.push_back(s);
        }

    }

    if(s==f){
        cout << "Yes\n";
        for(int i=1;i<pp.size();++i)
            cout << pp[i].real() << ' ' << pp[i].imag() << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
