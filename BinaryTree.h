#pragma once
#include <iostream>
#include "NODE.h"

using namespace std;

template<typename T>
class bin_tree {
private:
    NODE<T> *ROOT = nullptr;
    int SIZE = 0;

    void Print_Recursive(NODE<T> *curr) {
        if (curr) {
            Print_Recursive(curr->M_LEFT);
            cout << curr->indices_data << std::endl;
            Print_Recursive(curr->M_RIGHT);
        }
    }


public:
    int PR_ROWS = 0;
    int PR_COLUMNS = 0;

    bin_tree() : PR_ROWS(0), PR_COLUMNS(0),ROOT(nullptr), SIZE(0) {}

    bin_tree(int m, int n) : PR_ROWS(m), PR_COLUMNS(n),ROOT(nullptr), SIZE(0) {}

    bin_tree(const Pair<int, int> &indices, int data, int m, int n) : PR_ROWS(m), PR_COLUMNS(n),SIZE(1) {
        ROOT = new NODE<T>({indices, data});
    }

    int get_size() { return SIZE; }

    T get(const Pair<int, int> &indices) {

        NODE<T> *curr = ROOT;
        while (curr) {
            if (curr->ind_value.f != indices) {
                if (curr->ind_value.f > indices) {
                    curr = curr->LEFT;
                } else
                    curr = curr->RIGHT;
            } else
                return curr->ind_value.s;
        }
        return 0;
    }

    bool find(const Pair<int, int> &indices) {

        NODE<T> *curr = ROOT;
        while (curr && curr->ind_value.f != indices) {
            if (curr->ind_value.f > indices)
                curr = curr->LEFT;
            else
                curr = curr->RIGHT;
        }
        return (bool) curr;
    }

    void insert(const Pair<int, int> &indices, int data) {
        if (ROOT == nullptr) {
            ROOT = new NODE<T>({indices, data});
            SIZE = 1;
            if (indices.f > this->PR_ROWS)
                this->PR_ROWS = indices.f;
            if (indices.s > this->PR_COLUMNS) {
                this->PR_COLUMNS = indices.s;
            }
        } else {
            NODE<T> *curr = ROOT;
            while (curr && curr->ind_value.f != indices) {
                if (curr->ind_value.f > indices) {
                    if (curr->LEFT)
                        curr = curr->LEFT;
                    else {
                        curr->LEFT = new NODE<T>({indices, data});
                        SIZE++;
                        if (indices.f > this->PR_ROWS)
                            this->PR_ROWS = indices.f;
                        if (indices.s > this->PR_COLUMNS) {
                            this->PR_COLUMNS = indices.s;
                        }
                        return;
                    }
                } else {
                    if (curr->RIGHT)
                        curr = curr->RIGHT;
                    else {
                        curr->RIGHT = new NODE<T>({indices, data});
                        SIZE++;
                        if (indices.f > this->PR_ROWS)
                            this->PR_ROWS = indices.f;
                        if (indices.s > this->PR_COLUMNS) {
                            this->PR_COLUMNS = indices.s;
                        }
                        return;
                    }
                }
            }
        }

    }

    void Print() {
        NODE<T> *curr = ROOT;
        Print_Recursive(curr);
    }


    bin_tree<T> operator*(bin_tree<T> &matrix) {
        int M = this->PR_ROWS;
        int K = this->PR_COLUMNS;
        int N = matrix.PR_COLUMNS;

        if (this->PR_COLUMNS != matrix.PR_ROWS)
        {
            cout<< "Error";
            return *this;
        }
        bin_tree<T> res(M, N);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                T tmp = T();
                for (int k = 1; k <= K; ++k) {
                    if (this->find({i, k}) && matrix.find({k, j})) {
                        tmp += this->get({i, k}) * matrix.get({k, j});
                    }
                }
                if (tmp != T())
                    res.insert({i, j}, tmp);
            }
        }
        return res;
    }

    bin_tree<T> operator+(bin_tree<T> &matrix) {
        if (matrix.PR_COLUMNS != this->PR_COLUMNS || matrix.PR_ROWS != this->PR_ROWS) {
            cout << "Error" << endl;
            return *this;
        }
        int M = matrix.PR_ROWS;
        int N = matrix.PR_COLUMNS;
        bin_tree<T> res(M, N);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                T tmp = this->get({i, j}) + matrix.get({i, j});
                if (tmp != T())
                    res.insert({i, j}, tmp);
            }
        }
        return res;
    }

    bin_tree<T> operator-(bin_tree<T> &matrix) {
        if (matrix.PR_COLUMNS != this->PR_COLUMNS || matrix.PR_ROWS != this->PR_ROWS) {
            cout << "Error" << endl;
            return *this;
        }
        int M = matrix.PR_ROWS;
        int N = matrix.PR_COLUMNS;
        bin_tree<T> res(M, N);
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                T tmp = this->get({i, j}) - matrix.get({i, j});
                if (tmp != T())
                    res.insert({i, j}, tmp);
            }
        }
        return res;
    }

    void Print_matrix() {
        for (int i = 1; i <= this->PR_ROWS; i++) {
            cout << "|";
            for (int j = 1; j <= this->PR_COLUMNS; j++) {
                cout << get({i, j});
                if (j <= PR_COLUMNS - 1)
                    cout << "   ";
            }
            cout << "|" << endl;
        }
        cout << endl;
    }

    void input_value() {
        cout << " Row: ";
        int R, C;
        T V;
        cin >> R;
        while (R < 1)
        {
            printf("Enter a positive integer!\nRow: ");
            cin >> R;
        }
        cout << "Column: ";
        cin >> C;
        while (C < 1)
        {
            printf("Enter a positive integer!\nColumn: ");
            cin >> C;
        }
        cout << "Value: ";
        cin >> V;
        insert({R, C}, V);
    }

    void input_matrix()
    {
        T V;
        for (int i = 1; i <= this->PR_ROWS; i++) {
            for (int j = 1; j <= this->PR_COLUMNS; j++) {
                cout << "matrix[" << i << "][" << j << "]"<<endl;
                cin >> V;
                if(V != 0)
                {
                    insert({i,j},V);
                }
            }
        }
    }
    void create_matrix()
    {
        int R,C;
        cout << " Rows: ";
        cin >> R;
        while (R < 1)
        {
            cout<< "Enter a positive integer!\n Rows: ";
            cin >> R;
        }
        cout << "Columns: ";
        cin >> C;
        while (C < 1)
        {
            cout << "Enter a positive integer!\n Column: ";
            cin >> C;
        }
        bin_tree<int> b(R,C);
        *this = b;
    }
};

