#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    vector<int> v[5];
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(34);
    v[0].push_back(46);
    v[1].push_back(53);
    v[1].push_back(68);
    v[1].push_back(7);
    v[2].push_back(85);
    v[2].push_back(93);
    v[2].push_back(10);
    v[3].push_back(11);
    v[3].push_back(12);
    v[4].push_back(13);
    v[4].push_back(14);
    v[4].push_back(16);
    v[4].push_back(17);
    v[4].push_back(18);
    v[4].push_back(19);
    v[4].push_back(20);
    
for(int i=0;i<5;i++)
    {
        for (int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
    cout<<"\n";
    }
    for(int i=0;i<5;i++)
    {
    sort(v[i].begin(),v[i].end());
cout<<"\n";
  
}
for(int i=0;i<5;i++)
    {
        for (int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
    cout<<"\n";
    }
return 0;
}


