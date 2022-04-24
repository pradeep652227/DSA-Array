#include <iostream>
#include <vector>

using namespace std;

 void wave(vector<int>& arr,int idx,int first,int sec, int third)
    {
        arr[idx]=third;
        arr[idx-1]=min(first,sec);
        arr[idx-2]=max(first,sec);
    }
void convertToWave(vector<int>&arr,int n);


int main()
{   
    vector<int>arr{1,2,3,4,5};

    convertToWave(arr, 5);
    for(auto &i:arr)
        cout<<i<<" ";
        
    return 0;
}
 
 void convertToWave(vector<int>& arr, int n){
        
    
        if(n<=1)
        return ;
        
        if(n==2)
        {
            int first=arr[0], sec=arr[1];
            arr[0]=max(first,sec);
            arr[1]=min(first,sec);
        }
        
        for(int i=2;i<n;)
        {
            
            int first=arr[i-2];
            int sec=arr[i-1];
            int third=arr[i];
            
            if(first<=sec)
            {
                if(sec<third)
                {
                    wave(arr,i,first,sec,third);
                }
                else if(sec>third)
                    wave(arr,i,first,third,sec);
            }
            
            else if(first>sec)
            {
                if(first>=third)
                    wave(arr,i,sec,third,first);
                else
                    wave(arr,i,first,sec,third);
            }
            
            if(i+2<n)
            i+=2;
            else if(i!=n-1)
            {
                int max_elem=max(arr[n-1],arr[n-2]);
                int min_elem=min(arr[n-1],arr[n-2]);
                arr[n-1]=max_elem;
                arr[n-2]=min_elem;
                break;
            }
            else
                i++;
        }
        
    }