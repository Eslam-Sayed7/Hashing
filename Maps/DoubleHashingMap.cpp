#include<iostream>
#include<math.h>
#include"../utils.h"
#include<vector>
using namespace std;


class DoubleHashingMap
{
public:
    vector<Item> arr;
    int size;
    DoubleHashingMap(int size);
    void Insert();
    void Print();
};

DoubleHashingMap::DoubleHashingMap(int max_size)
{
    arr = vector<Item>( max_size);
    this->size = 0;

}
void DoubleHashingMap::Insert()
{
    int key;
    cin >> key;
    if (size == MAX_SIZE)
    {
        cout << "Hash table is full!" << endl;
        return;
    }

    int primaryHash = multiplicationMethod(key, MAX_SIZE, 0.618033).first;
    int secondaryHash = midSquareMethod(primaryHash, MAX_SIZE).first;

    // Ensure secondaryHash is not zero
    if (secondaryHash == 0) secondaryHash = 1;

    int probeCount = 0;
    while (probeCount < MAX_SIZE)
    {
        int index = (primaryHash + probeCount * secondaryHash) % MAX_SIZE;
        if (arr[index].stat == STAT::EMPTY || arr[index].stat == STAT::DELETED)
        {
            arr[index].setItem(key);
            arr[index].stat = STAT::OCCUPIED;
            size++;
            return;
        }
        probeCount++;
    }

    cout << "Failed to insert key: " << key << " after probing entire table." << endl;
}


void DoubleHashingMap::Print()
{
    cout << "index     " << "Values\n";
    for(int i = 0; i < arr.size(); i++){
        cout << i <<"     " << arr[i].value;
        cout << '\n';
    }
}
