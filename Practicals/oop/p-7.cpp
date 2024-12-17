#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> populationMap;
    populationMap.insert(make_pair("Maharashtra", 2000));
    populationMap.insert(make_pair("Gujarat", 1000));
    populationMap.insert(make_pair("Karnatak", 2030));
    populationMap.insert(make_pair("Utter Pradesh", 1040));
    populationMap.insert(make_pair("Madhya Pradesh", 1200));

    map<string, int>::iterator it;
    cout << "\nTotal State and UT of india with size of population: " << endl;

    for(it = populationMap.begin(); it != populationMap.end(); it++)
    {
        cout << it->first << ": " << it->second << " millions\n";
    }

    return 0;
}