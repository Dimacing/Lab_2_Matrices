#include "BinaryTree.h"
void TestAll(){
    int M = 2;
    int N = 2;
    int K = 2;
    int A = 2;

    bin_tree<int> a(M,N);
    bin_tree<int> b(K,A);

    a.insert({1,1},3);
    a.insert({1,2},6);
    a.insert({2,1},6);
    a.insert({2,2},5);


    b.insert({1,1},1);
    b.insert({1,2},3);
    b.insert({2,1},4);
    b.insert({2,2},7);

    bin_tree<int> sum = a + b;
    bin_tree<int> diff = a - b;
    bin_tree<int> multiplication = a * b;


    if(sum.get({1,1}) != 4 || sum.get({1,2}) != 9 ||
    sum.get({2,1}) != 10 || sum.get({2,2}) != 12)
        cout << "Sum ERROR" << endl;
    else
        cout << "Sum ok" << endl;


    if(diff.get({1,1}) != 2 || diff.get({1,2}) != 3 ||
    diff.get({2,1}) != 2 || diff.get({2,2}) != -2)
        cout <<  "Diff ERROR !" << endl;
    else
        cout << "Diff ok" << endl;


    if(multiplication.get({1,1}) != 27 || multiplication.get({1,2}) != 51 ||
    multiplication.get({2,1}) != 26 || multiplication.get({2,2}) != 53)
        cout <<  "Mult ERROR !" << endl;
    else
        cout << "Mult ok" << endl;

}