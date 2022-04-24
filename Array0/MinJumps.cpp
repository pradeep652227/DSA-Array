#include <iostream>

using namespace std;

int minJumps(int arr[], int n){
        int jump=0, i=0;
        int temp=0, index=0;
        int max=arr[0];
      
        while(i<n)
        {
            if(arr[i]==0)
            return (-1);
            else{
                    temp=i;
                    i+=arr[i];
                   if(i>=(n-1))
                   {
                       jump++; break;
                   }
                    if(i<(n-1))
                    { max=arr[i];
                        for(int j=(temp+1);j<i;j++)
                        {
                            if(max<arr[j])
                            { max=arr[j]; index=j;}
                        }
                        
                        if(max!=arr[i])
                        i=index;
                        
                        jump++;
                    }
                    if(i==n-1)
                        i++;
                    
            }
        }
        
        return (jump);
    }
    
    int main()
    {
        int arr[10]={2,3,1,1,2,4,2,0,1,1};
        
        cout<<"Min. jumps = "<<minJumps(arr,15)<<endl;
        
        return 0;
    }