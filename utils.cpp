#include<iostream>
#include<math.h>
#include"utils.h"
using namespace std;

void displayMenu() {
    cout << "Menu for Hashing and Collision Resolution Techniques\n";
    cout << "1. Division Method (Hashing)\n";
    cout << "2. Multiplication Method (Hashing)\n";
    cout << "3. Mid Square Method (Hashing)\n";
    cout << "4. Folding Method (Hashing)\n";
    cout << "5. Chaining Method (Collision Resolution)\n";
    cout << "6. Open Addressing Method (Collision Resolution)\n";
    cout << "7. Double Hashing (Collision Resolution)\n";
    cout << "8. Print the Hash Table\n";
    cout << "0. Exit\n ";
}

int NumberOfDigits(int n) {
    return n > 0 ? log10(n) + 1 : 1; // Handles cases where n <= 0.
}

int GetInput(){
    cout << "Enter a number you want to hash: ";
    int input;
    cin >> input;
    return input;
}

pair<int , int> divisionMethod( int key , int m) {
    std::cout << "Division Method: h(k) = k % p, where p is a prime number.\n";
    int p = 7;
    int hash  = key % p; 
    cout << "The hashed index: " << hash << '\n';
    return make_pair(hash , key);
}

pair<int, int> multiplicationMethod(int key, int m, double A) {
    // Compute the fractional part of key * A
    double fractionalPart = key * A - floor(key * A);

    // Apply the multiplication method formula
    int hash = floor(m * fractionalPart);

    // cout << key << " hashed to idx " << hash << '\n';
    return make_pair(hash, key);
}


pair<int, int> midSquareMethod(int key, int m) {
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

    // cout << "The hashed index: " << hash << '\n';
    return make_pair(hash, key);
}


pair<int , int> foldingMethod( int key , int m) {
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
    return make_pair(hash , key);

}