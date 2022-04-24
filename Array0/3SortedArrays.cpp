#include <iostream>
#include <vector>

using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>common{};
            
            int i{},j{},k{};
            
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]<B[j] || A[i]<C[k])
                    i++;
                
                else if(A[i]==B[j] && A[i]==C[k])
                    {   
                        common.push_back(A[i]); 
                        i++;j++;k++;
                    }
                    
                else if(A[i]>B[j])
                {
                    if(A[i]>C[k])
                        {
                            j++; k++;
                        }
                    else if(A[i]==C[k])
                        j++;
                }
                
                else if(A[i]>C[k])
                {
                    if(A[i]==B[j])
                        k++;
                }
            }
            
            if(common.size()!=0)
                 return common;
            else
                return vector<int>{-1};
            
        }


int main()
{   int arr[3]={1,2,3}; int brr[3]={4,5,6}; int crr[3]={7,8,9};

    vector<int>common{};
    common=commonElements(arr,brr,crr,3,3,3);
    
    if(common.size()!=0)
    {
        for(auto &i:common)
            cout<<i<<" ";
    }
    else
         {
        for(auto &i:common)
            cout<<i<<" ";
    }

    return 0;
}