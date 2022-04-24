#include <iostream>
#include <vector>

using namespace std;

vector<int> nBonaccis(int n,int m);

int main()
{   int n,m;
    n=3,m=8;
    
    vector<int>ans=nBonaccis(n,m);
    
    for(auto &i:ans)
        cout<<i<<" ";
        
    return 0;
}

vector<int> nBonaccis(int n,int m)
{
    vector<int>ans(m);
    
    for(int i=0;i<n-1;i++)//first n-1 no.s are 0 for a nBonacci series
        ans[i]=0;
        
    ans[n-1]=1;//nth and n+1th no.s are 1
    int curr_sum=1;
    int w_start{};
    
    for(int i=n;i<m;i++)
    {
        if(i>=n)
        {
            ans[i]=curr_sum;
            curr_sum-=ans[w_start];
            w_start++;
        }
        
        curr_sum+=ans[i];
    }
    
    return ans;
}