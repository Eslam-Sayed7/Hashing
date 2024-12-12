#include<iostream>
#include"Maps/ChainingMap.cpp"
#include"Maps/OpenAddressingMap.cpp"
#include"Maps/mp.cpp"
#include"Maps/DoubleHashingMap.cpp"
using namespace std;

int main() {
    int choice;
    int input;
    // int MAX_SIZE = 10;
    
    pair<int ,int> pr = make_pair(0 , 0);
        
    NormMap normalMap(MAX_SIZE);    
    ChainingMap chainingMap(MAX_SIZE);
    OpenAddressingMap openAdressingMap(MAX_SIZE);
    DoubleHashingMap doubleHashingMap(MAX_SIZE);

    NormMap mp(MAX_SIZE);
    do {
        displayMenu();  
        cin >> choice;  

        switch (choice) {
            case 1:
                input = GetInput();
                pr = normalMap.divisionMethod(input , MAX_SIZE);
                normalMap.Insert(pr);
                
                break;
            case 2:
                input = GetInput();
                pr = normalMap.multiplicationMethod(input , MAX_SIZE , 0.618033);
                normalMap.Insert(pr);
                
                break;
            case 3:
                input = GetInput();
                pr = normalMap.midSquareMethod(input , MAX_SIZE);
                normalMap.Insert(pr); 
                
                break;
            case 4:
                input = GetInput();
                pr = normalMap.foldingMethod(input , MAX_SIZE);
                normalMap.Insert(pr); 
                
                break;
            case 5:
                cout << "Enter "<< MAX_SIZE << " Numbers\n";
                cout << "Enter the key you want to hash using the Chainging method for handling collision: ";
                for(int i = 0; i < MAX_SIZE; i++)
                {
                    chainingMap.Insert();
                }
                chainingMap.Print(); 
                break;
            case 6:
                cout << "Enter "<< MAX_SIZE << " Numbers\n";
                cout << "Enter the key you want to hash using the Open Addressing method for handling collision: ";
                for(int i = 0; i < MAX_SIZE; i++)
                {
                    openAdressingMap.Insert();
                }
                openAdressingMap.Print();

                break;
            case 7:
                cout << "Enter "<< MAX_SIZE << " Numbers\n";
                cout << "Enter the key you want to hash using the Double Hashing method for handling collision: ";
                for(int i = 0; i < MAX_SIZE; i++) {
                    doubleHashingMap.Insert();
                }
                doubleHashingMap.Print();
                break;
            case 8:
                normalMap.PrintGUI(normalMap.arr , MAX_SIZE);
                break;
            case 0:
                cout << "Exiting the program.\n";
                

                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 8.\n";
                break;
        }

        cout << "\n";  

    } while (choice != 0);

    return 0;
}