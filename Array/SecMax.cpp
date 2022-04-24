#include <iostream>

using namespace std;

int secMax(int arr[], int n);
int main()
{   
    int arr[]{1,1,1,1};
    
    cout<<"2nd Max is "<<secMax(arr,4)<<endl;
    
    return 0;
}

int secMax(int arr[],int n)
{   
     int first=-1,sec=-1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>first)
            {   cout<<"First ="<<first<<" Second="<<sec<<"\t ";
                sec=first;
                first=arr[i];
                cout<<"First ="<<first<<" Second="<<sec<<endl;
            }
            else if(arr[i]>sec && arr[i]<first)
                    sec=arr[i];
                cout<<" Second="<<sec<<endl;
        }
    	
    	return sec;
    
    
    
//    	if(n==2)
//    	{
//    	    return (arr[0]<arr[1])?arr[0]:arr[1];
//    	    
//    	    return -1;
//    	}
//    	
//    	if(n<=1)
//    	return -1;
//    	
//    	int max1{},max2{};
//    	
//    	if(arr[n-1]>arr[n-2])
//    	   { max1=arr[n-1]; max2=arr[n-2]; }
//    	 else
//    	 { max2=arr[n-1]; max1=arr[n-2]; }
//    	 
//    	int flag{0};
//    	
//    	for(int i=n-3;i>=0;i--)
//    	{
//    	    if(arr[i]>max1)
//    	   {   
//    	       max2=max1;
//    	       max1=arr[i];
//    	       
//    	       flag=1;
//    	   }
//    	   else if(arr[i]!=max1)
//    	   {
//    	       if(max1==max2)
//    	           max2=arr[i];
//    	       
//    	       else if(arr[i]>max2)
//    	                max2=arr[i];
//    	           flag=1;
//    	   }
//    	            
//    	}
//    	
//    	if(flag==1)
//    	return max2;
//    	else
//    	return -1;
}