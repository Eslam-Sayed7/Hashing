#include<iostream>
#include<math.h>
#include"../utils.h"
#include<vector>

using namespace std;


class OpenAddressingMap
{
public:
    vector<Item> arr;
    int size;
    OpenAddressingMap(int size);
    void Insert();
    void Print();
};

OpenAddressingMap::OpenAddressingMap(int max_size)
{
    arr = vector<Item>( max_size);
    this->size = 0;

}

void OpenAddressingMap::Insert()
{
    if(size == MAX_SIZE){
        cout << "Map is full\n";
        return;
    }
    int key;
    cin >> key;
    pair<int , int> pr = multiplicationMethod(key , MAX_SIZE, 0.618033);
    
    int counter = 0;
    bool added = false;

    for (int i = pr.first ; (counter < MAX_SIZE) || added ; i++)
    {
        int idx = (pr.first + counter) % MAX_SIZE;
        if(arr[idx].stat == EMPTY || arr[pr.first].stat == DELETED){
            arr[idx].setItem(pr.second);
            arr[idx].stat = STAT::OCCUPIED;
            size++;
            return;
        }
        counter++;
    }
}

void OpenAddressingMap::Print()
{
    cout << "index     " << "Values\n";
    for(int i = 0; i < arr.size(); i++){
        cout << i <<"     " << arr[i].value;
        cout << '\n';
    }
}
