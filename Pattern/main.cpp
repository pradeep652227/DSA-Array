#include <iostream>

using namespace std;

void hollow_rect();
void pyramids();
int main(){
//    hollow_rect();
    pyramids();
    return 0;
}

void hollow_rect(){// incomplete(bug)
    int n,m;
    cout<<"Enter rows and colums of a rectangle:- "; cin>>n>>m;
    
    for(int i{0};i<n;i++)
    {
        for(int j{0};j<m;j++)
        {
            if(i==0 || i==n-1)
                cout<<"* ";
             else if(j==0 || j==m-1)
                 cout<<"* ";
                else 
                    cout<<"  ";
        }
        
        cout<<endl;
    }
}

void pyramids(){
    int n,m; cout<<"Enter number of rows and colums:- "; cin>>n>>m;
    /*Inverted Half Pyramids*/
    for(int i{};i<n;i++)
    {
        for(int j{};j<m;j++)
        {
            if(i==0)
            cout<<"* ";
            else if(j==0 || j==(n-1)-i)
                cout<<"* ";
            else
                cout<<"  ";
        }
            
       cout<<endl;
    }
}