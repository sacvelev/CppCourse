#include <iostream>
#include <vector>

using namespace std;
class Matrix{
    private:
        int rows;
        int cols;
        vector<vector<int>> data;

    public:
        Matrix(int rows, int cols): rows(rows), cols(cols), data(rows, vector<int>(cols)) {}

        void setElement(int row, int col, int value) {
            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                cout << "Invalid index" << endl;
                return;
            }
            data[row][col] = value;
        }

        void fill() {
            int n;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << "Row: " << i+1 << " Col: " << j+1 << ": ";
                    cin >> n;
                    setElement(i, j, n);
                }
            }
        }

        int getElement(int row, int col){
            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                cout << "Invalid index" << endl;
                return 0;
            }
            return data[row][col];
        }

        Matrix operator+(const Matrix& other) const{
            if (rows != other.rows || cols != other.cols) {
                cout << "Invalid sizes" << endl;
                return Matrix(0,0);
            }

            Matrix result(rows, cols);


            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }

            return result;
        }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Invalid sizes" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Invalid sizes for matrix multiplication" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

        void print() {
            for(int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
                }
            }
        };


int main() {
    int rows, cols;
    cout << "Rows: "; cin >> rows;
    cout << endl;
    cout << "Cols: "; cin >> cols;
    cout << endl;

    Matrix matrix1(rows, rows);
    matrix1.fill();

    cout << endl;

    cout << "Matrix1:" << endl;
    matrix1.print();
    cout << endl;

    int rows2, cols2;
    cout << "Rows: "; cin >> rows2;
    cout << endl;
    cout << "Cols: "; cin >> cols2;
    cout << endl;

    Matrix matrix2(rows2, cols2);
    matrix2.fill();

    cout << endl;

    cout << "Matrix2:" << endl;
    matrix2.print();
    cout << endl;

    Matrix sum = matrix1 + matrix2;
    cout << "Matrix sum:" << endl;
    sum.print();

    Matrix minus = matrix1 - matrix2;
    cout << "Matrix minus:" << endl;
    minus.print();

    Matrix product = matrix1 * matrix2;
    cout << "Matrix product:" << endl;
    product.print();


}