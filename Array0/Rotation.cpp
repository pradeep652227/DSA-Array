#include <iostream>

using namespace std;
/* Clockwise rotation and for anti-clockwise, refer to the code below this one */

 /*int main()
{
    int arr[]{1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int k; cout<<"Enter k:- "; cin>>k;
    
    while(k>n)// if K>n then we are repeating the same rotation from 1 to 5 again, example:- k=6 which is same as k=1
    {
        k=k-n;
    }
    int brr[k];
    
    for(int i=0;i<k;i++)// storing first k elelents in an extra space
        brr[i]=arr[i];
        
    for(int i=n-1;i>=k;i--)
    {
        if(i+k>=n)
            arr[i+k-n]=arr[i];
        else
            arr[i+k]=arr[i];
    }
    
    for(int i=0;i<k;i++)
    {
        if(i+k>=n)
            arr[i+k-n]=brr[i];
        else
            arr[i+k]=brr[i];
    }
    
    for(auto i:arr)
        cout<<i<<" ";
        cout<<endl;
        
    return 0;
    
}
*/

int main()
{
    /* Approach no.1 :- 1.) Check while(k>n) k=k-n; 2.) Reverse the array 
     * 3.) Implement Clockwise rotation on reversed array 4.) Again reverse the array 5.) You got the result. 
     * Time complexity(worst):- O(k) + O(n) + O(n) + O(n)= 3*O(n) + O(k) or O(3*n) + O(k) = O(n)
       Space complexity(worst):- O(K) */
     
     /* Approach no. 2:- Generalised approach for anti-clockwise*/
     
     int arr[]{1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int k; cout<<"Enter k:- "; cin>>k;
    
    while(k>n)// if K>n then we are repeating the same rotation from 1 to 5 again, example:- k=6 which is same as k=1
    {
        k=k-n;
    }
    int brr[k];
    
    for(int i=0;i<k;i++)
        brr[i]=arr[n-1-i];
    
    for(int i=0;i<(n-k);i++)
    {
        if(i-k <0)
            arr[n+(i-k)]=arr[i];
        else
            arr[i-k]=arr[i];
    }
    
    for(int i=0;i<k;i++)
    {    if( (n-1)-i-k <0)
            arr[n + (n-1) -i-k]=brr[i];
        else arr[(n-1)-i-k]=brr[i];
    }
     for(auto i:arr)
         cout<<i<<" ";
         cout<<endl;
    
return 0;
}