#include<iostream>
#include"../utils.h"
#include <vector>

using namespace std;

class ChainingMap
{
public:
    vector<vector<int>> arr;
    int size;
    ChainingMap(int size);
    void Insert();
    void Print();
};

ChainingMap::ChainingMap(int size)
{
    arr = vector<vector<int>>(size, vector<int>());
    this->size = 0;
}

void ChainingMap::Insert()
{
    int key;
    cin >> key;
    pair<int , int> pr = multiplicationMethod(key , MAX_SIZE, 0.618033);
    arr[pr.first].push_back(pr.second);
    size++;
}

void ChainingMap::Print()
{
    cout << "index     " << "Values\n";
    for(int i = 0; i < arr.size(); i++){
        cout << i <<"     ";
        for(int j = 0; j < arr[i].size();j++){
            cout << arr[i][j] << ',';
        }
        cout << '\n';
    }
}
