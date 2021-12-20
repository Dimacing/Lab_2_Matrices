#include "BinaryTree.h"
#include "Tests.h"

int main() {
    int s2 = 0;
    bin_tree<int> a;
    a.create_matrix();
    a.input_matrix();
    while (s2 != 7) {
        cout << ("Select the action with matrix:\n1 - add element\n2 - add matrix \n3 - diff matrix\n4 - multiply by matrix\n5 - Print matrix\n6 - Test\n7 - exit\n");
        cin >> s2;
        switch (s2) {
            case 1: {
                a.input_value();
                cout << endl;
                a.Print_matrix();
                break;
            }
            case 2: {
                bin_tree<int> b;
                b.create_matrix();
                b.input_matrix();
                a = a + b;
                cout <<endl;
                a.Print_matrix();
                break;
            }
            case 3: {
                bin_tree<int> b;
                b.create_matrix();
                b.input_matrix();
                a = a - b;
                cout <<endl;
                a.Print_matrix();
                break;
            }
            case 4: {
                bin_tree<int> b;
                b.create_matrix();
                b.input_matrix();
                bin_tree<int> multiplication = a * b;
                a = multiplication;
                cout <<endl;
                a.Print_matrix();
                break;
            }
            case 5: {
                a.Print_matrix();
                break;
            }
            case 6: {
                TestAll();
                break;
            }
            case 7: {
                return 0;
            }
            default: {
                cout<<("Enter a number from the list!\n");
                break;
            }
        }
    }
    return 0;
}

