#include <iostream>
#include <vector>

using namespace std;

//int countPrimes(int n) {
//       
//       if(n<=2)
//           return 0;
//        
//        vector<bool>primes(n+1,1);
//        primes[0]= primes[1]=0;
//        int count{};
//        
//        for(int i=2;i<n;i++)
//        {
//            if(primes[i])
//                count++;
//            for(int j=2*i;j<n;j+=i)
//            {
//                primes[j]=0;
//            }
//        }
//        
//        return count;
//    }

int main()
{
     int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n-1;i++)
    {
        arr.push_back(i+2);   
    }
    
    for(auto &i:arr)
        cout<<i<<" ";
        cout<<endl;
    cout<<"Primes among the above no.s are:- ";
    
    int count{};
    int p=2; int sq=p*p;
    while(sq<n)
    {   int i;
        for(i=sq;i<=n;i+=p)
        {
            arr[i-2]=0;
            count++;
        }
        
        
        for(int i=p-2 +1;i<n;i++)
        {
            if(arr[i]!=0)
            {    p=arr[i];
            
                break;
            }
        }
        sq=p*p;
    }
    
    for(auto &i:arr)
    {
        if(i!=0)
            cout<<i<<" ";
    }
    
    cout<<endl<<(n-1-count)<<endl;

    return 0;
}