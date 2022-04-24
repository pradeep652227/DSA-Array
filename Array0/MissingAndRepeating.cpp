#include <iostream>

using namespace std;

int *findTwoElement(int *arr, int n);

int main()
{  
 int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        cout<<endl;
    int *ans=findTwoElement(arr,n);

//int arr[5]={1,2,3,3,5};
//    int *ans=findTwoElement(arr,5);
    
    int first=ans[0], second=ans[1];
    cout<<first<<" "<<second<<endl;
    return 0;
}

   int *findTwoElement(int *arr, int n) {
       
       /*For sorted arrays */
        // int *ans=new int[2];
        
        // for(int i=1;i<=n;i++)
        // {
        //     if( (arr[i-1]-i)!=0 )
        //     {
        //         ans[0]=arr[i-1];
        //         ans[1]=i;
        //     }
        // }
        
        // return ans;
        
        int xor_arr{};
        for(int i=0;i<n;i++)
            xor_arr^=arr[i];
        
        int xor_n{};
        for(int i=1;i<=n;i++)
            xor_n^=i;
        
        int res=xor_arr ^ xor_n;
        
        int rsb=res& ~(res-1);
        
        /*Implementing Gap Method like approach*/
        int num1{},num2{};
        for(int i=0;i<n;i++)
        {
            if( (arr[i]&rsb)==0 )
                num1^=arr[i];
            else
                num2^=arr[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            if( (i&rsb)==0 )
                num1^=i;
            else
                num2^=i;
        }
        
        int *ans=new int[2];
        int flag=0;
        for(int i=0;i<n;i++)
        { int temp=arr[i];
        
            if( (temp ^ num1)== 0 )
              {  flag=1;
                 break;
              }
        }
    
        if(flag==1)
        {
            ans[0]=num1; ans[1]=num2;
        }
        else
        { 
            ans[0]=num2; ans[1]=num1;
        }
         
          int first=ans[0];
          int second=ans[1];
          
        return ans;
    }