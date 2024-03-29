#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(int COLS, int ROWS) {
        this->COLS = COLS;
        this->ROWS = ROWS;
        
        int** arr = new int* [ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            arr[i] = new int[COLS];
        }
        this->arr = arr;
    };

    Matrix(int COLS, int ROWS, int**Sarr) {
        this->COLS = COLS;
        this->ROWS = ROWS;
        this->Sarr = Sarr;
    };

    void cinf(int** arr) {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
            {
                cout << "Enter\n";
                cin >> arr[i][j];
            }
    }

    void deletef(int** arr) {
        for (int i = 0; i < ROWS; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void coutf(int** arr) {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < ROWS; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    int** getarr() {
        return this->arr;
    }

    int** getSarr() {
        return this->Sarr;
    }

private:
    int ROWS, COLS;
    int **arr = 0;
    int **Sarr = 0;
};

int main()
{
    Matrix one(3, 3);

    one.cinf(one.getarr());
    one.coutf(one.getarr());

    return 0;
}

