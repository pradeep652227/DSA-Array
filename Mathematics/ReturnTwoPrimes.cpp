#include <iostream>
#include <vector>

using namespace std;
//bool minPrime(vector<int>isPrime,int num);
vector<int> primeDivision(int n);
    
int main()
{
    int n;
    cin>>n;
    vector<int>temp;
    temp=primeDivision(n);
    
    for(auto &i:temp)
        cout<<i<<" ";
        cout<<endl;
    
    return 0;
}


vector<int>primeDivision(int n)
{
    if(n<=3)
        return {0};
    if(n&1)//n->odd
return {0};
    
    vector<int>isPrime(n+1,1);
    isPrime[0]=isPrime[1]=0;
    
    for(int i=2;i*i<=n-2;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=n-2;j+=i)
                isPrime[j]=0;
        }
    }
    int limit{n>>1};
    vector<int>ans(2,2);
  for(int i=2;i<=limit;i++)
  {
      if(isPrime[i])
      {
          if(isPrime[n-i])
          {
              ans[0]=i;ans[1]=n-i;
              return ans;
          }
      }
  }
  
  return {0};
        

}