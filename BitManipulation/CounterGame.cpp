#include <iostream>

using namespace std;

string CounterGame( long n );
void checkWinner( long &a );

int main()
{   long n; cin>>n;
    
    cout<<"Game starts from Louise and the winner is "<<CounterGame(n)<<endl;
    
    return 0;
}

void checkWinner(long &a)
{   long temp{0};

    if ( (a & (a-1))==0 )
        a/=2;
    else
    {
        temp=a;
        while( a&(a-1) )
            a=a & (a-1);
        a= temp-a;
    }
}
string CounterGame(long n)
{   string answer{"Louise"};
    if(n==1)
        return "Richard";
        
    while(n!=1)
    {
        if( answer=="Louise")
        {
            checkWinner(n);
            if(n==1)
                return answer;
            answer="Richard";
        }
        
        if(answer=="Richard")
        {
            checkWinner(n);
            if(n==1)
                return answer;
            answer="Louise";
        }
    }
    
    return answer;
}