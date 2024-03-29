#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(int COLS, int ROWS) {
        this->COLS = COLS;
        this->ROWS = ROWS;
    };

    Matrix(int COLS, int ROWS, int**Sarr) {
        this->COLS = COLS;
        this->ROWS = ROWS;
        this->Sarr = Sarr;
    };

    void creatMat() {
        int** arr = new int* [ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            arr[i] = new int[COLS];
        }
        this->Tarr = arr;
    }

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

    int** getTarr() {
        return this->Tarr;
    }

    int** getSarr() {
        return this->Sarr;
    }

private:
    int ROWS, COLS;
    int **Tarr = 0;
    int **Sarr = 0;
};

int main()
{
    Matrix one(3, 3);
    one.creatMat();
    one.cinf(one.getTarr());
    one.coutf(one.getTarr());

    Matrix second(3, 3);
    second.creatMat();
    second.cinf(second.getTarr());
    second.coutf(second.getTarr());

    return 0;
}

