    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    int main(){
         long int n{}; cin>>n;
    long int q{}; cin>>q;
    long long int y;
    
    std::vector<long long int> vec;
    
    long long int elem;
    
    for(long int i{0};i<n;i++)
    {
        cin>>elem;
        vec.push_back(elem);
    }
    
    std::vector<long long int>::iterator it{vec.begin()};
    while(q!=0)
    {
        cin>>y;
        it=std::find(vec.begin(),vec.end(),y);
        if(it!=vec.end())
        cout<<"Yes "<<(it-vec.begin())+1<<endl;
        else 
        cout<<"No "<<(std::lower_bound(vec.begin(),vec.end(),y)-vec.begin())+1<<endl;
        
        q--;
    }
    
    return 0;
    }