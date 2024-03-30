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

        int** arr = new int* [ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            arr[i] = new int[COLS];
        }
        this->arr = arr;
    };

    void cinf() {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
            {
                cout << "Enter\n";
                cin >> this->arr[i][j];
            }
    }

    void deletef() {
        for (int i = 0; i < ROWS; i++)
            delete[] this->arr[i];
        delete[] this->arr;
    }

    void coutf() {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < ROWS; j++)
                cout << this->arr[i][j] << " ";
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

    void summation() {
        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++) {
                arr[i][j] += Sarr[i][j];
            }
        }
    }

    void trans() {
        int** Tarr = new int* [ROWS];

        for (size_t i = 0; i < ROWS; i++)
        {
            Tarr[i] = new int[COLS];
        }

        cout << "TRANS" << endl;

        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++) {
                Tarr[i][j] = arr[i][j];
            }
        }

        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++) {
                arr[i][j] = Tarr[j][i];
            }
        }

        for (int i = 0; i < ROWS; i++)
            delete[] Tarr[i];
        delete[] Tarr;
    }

    void multiplication() {
        
        cout << "multiplication" << endl;

        int** Tarr = new int* [ROWS];

        for (size_t i = 0; i < ROWS; i++)
        {
            Tarr[i] = new int[COLS];
        }

        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++) 
            {
                Tarr[i][j] = 0;
                for (size_t k = 0; k < COLS; k++)
                {
                    Tarr[i][j] += this->arr[k][j] * this->Sarr[i][k];
                }
            }
        }
        
        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++) {
                this->arr[i][j] = Tarr[i][j];
            }
        }

        for (int i = 0; i < ROWS; i++)
            delete[] Tarr[i];
        delete[] Tarr;
    }

private:
    int ROWS, COLS;
    int **arr = 0;
    int **Sarr = 0;
};

int main()
{
    Matrix one(3, 3);

    one.cinf();
    one.coutf();

    cout << endl;

    Matrix two(3, 3, one.getarr());

    two.cinf();
    two.coutf();
    two.multiplication();
    two.coutf();
    
    two.deletef();
    one.deletef();

    return 0;
}