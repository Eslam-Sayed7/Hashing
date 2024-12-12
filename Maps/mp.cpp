#include<iostream>
#include<string>
#include<math.h>
#include <iomanip> // For formatting
#include"../utils.cpp"


using namespace std;

class NormMap
{
public:
    int *arr;
    int size;
    NormMap(int size);
    pair<int , int> divisionMethod( int k , int m);
    pair<int , int> multiplicationMethod(int k , int m , double A);
    pair<int , int> midSquareMethod(int key , int m);
    pair<int , int> foldingMethod(int key, int m);
    void PrintGUI(int* arr, int size);
    void Insert(pair<int , int> pr);
    ~NormMap();
};

NormMap::NormMap(int size)
{
    arr = new int[size];
}

void NormMap::PrintGUI(int* arr, int size)
{
    const int boxWidth = 8; 

    cout << "\nArray Memory Layout (Vertical):\n";

    cout << "┌───────┬───────┐\n";
    cout << "│ Index │ Value │\n";
    cout << "├───────┼───────┤\n";

    for (int i = 0; i < size; i++) { cout << "│" << setw(7) << i << " │" << setw(7) << arr[i] << "│\n";
    }

    cout << "└───────┴───────┘\n";
}

void NormMap::Insert(pair<int, int> pr)
{
    arr[pr.first] = pr.second;
}

NormMap::~NormMap()
{
    delete[] arr;
}

pair<int , int> NormMap::divisionMethod( int key , int m) {
    std::cout << "Division Method: h(k) = k % p, where p is a prime number.\n";
    // int p = 7;
    int p = m; // normal division 
    int hash  = key % p; 
    cout << key << "The hashed index: " << hash << '\n';
    return make_pair(hash , key);
}

pair<int, int> NormMap::multiplicationMethod(int key, int m, double A) {
    // Compute the fractional part of key * A
    double fractionalPart = key * A - floor(key * A);

    // Apply the multiplication method formula
    int hash = floor(m * fractionalPart);

    cout << key << " hashed to idx " << hash << '\n';
    return make_pair(hash, key);
}


pair<int, int> NormMap::midSquareMethod(int key, int m) {
    cout << "Mid Square Method: Square the key, extract the middle digits.\n";

    long long squared = static_cast<long long>(key) * key; // Avoid overflow for large keys.
    string squared_str = to_string(squared);

    // Calculate required digits and middle section indices
    int totalDigits = squared_str.size();
    int requiredDigits = NumberOfDigits(m - 1);
    int startIdx = (totalDigits - requiredDigits) / 2;
    int endIdx = startIdx + requiredDigits;

    // Safely extract middle digits
    string midsquare_str = squared_str.substr(startIdx, requiredDigits);

    // Convert to integer and handle overflow
    int hash = stoi(midsquare_str);
    if (NumberOfDigits(hash) > NumberOfDigits(m))
        hash = hash % m;

    cout << "The hashed index: " << hash << '\n';
    return make_pair(hash, key);
}


pair<int , int> NormMap::foldingMethod( int key , int m) {
    cout << "Folding Method: Divide the key into parts, sum them, and apply a mod operation.\n";
    NumberOfDigits(m - 1);
    int hash = 0;
    int NumberOfParts = 0; 
    string keyStr = to_string(key);
    int length = keyStr.length();
    
    for(int i  = NumberOfDigits(m - 1); i >= 0; i--){
        if(keyStr.length() %  NumberOfDigits(m - 1) == 0){
            NumberOfParts = keyStr.length() / i;
            break;
        }
    }

    int sum = 0;

    for (int i = 0; i < length; i += NumberOfParts) {
        string part = keyStr.substr(i, 3);
        sum += stoi(part);  // Add the part to the sum
    }

    hash = sum % m;
    cout << "The hashed index: " << hash << '\n';
    return make_pair(hash , key);

}