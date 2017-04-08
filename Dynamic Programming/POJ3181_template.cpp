/*
 * The following code is from: http://poj.org/showmessage?message_id=168333
 * C++ does not have BigInteger library but the following code somehow works
 */

#include<iostream>
#include<cmath>
#define __int64 long long
using namespace std;
int main()
{
    int n,k;
    __int64 sum=0,sum1=0,sum2=0,pp=pow(10.0,17),p[1001][101][2]={0};
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
            if(i==j||i==1)
               p[j][i][0]=1;
            else
                if(j>i)
                    for(int b=1;b<=i;b++)
                    {
                        p[j][i][0]+=p[j-i][b][0];
                        p[j][i][1]+=p[j-i][b][1]+p[j][i][0]/pp;
                        p[j][i][0]%=pp;
    //                    p[j][i][2]+=p[j-i][b][2]+p[j][i][1]/pp;
      //                  p[j][i][1]%=pp;
                    }
        sum+=p[n][i][0];
        sum1+=p[n][i][1]+sum/pp;
        sum%=pp;
        sum2+=sum1/pp;
        sum1%=pp;
    }
    if(sum2!=0)cout<<sum2;
    if(sum1!=0)cout<<sum1;
    cout<<sum<<endl;
    return 0;
}
