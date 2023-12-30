#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    vector<int> v;

    cout << v.size() << "\n";

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int N = v.size();

    for (int i = 0; i < N; i++)  
        cout << v[i] << " ";
    cout << "\n";

    for (auto i : v)
        cout << i << " ";

    sort(v.begin(), v.end());

    cout << "\n";

    for (auto i : v)
        cout << i << " ";

    return 0;
}
