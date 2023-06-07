#include <iostream>

using namespace std;


class Vector{
    friend Matrix;

private:
    int size;
    int* elements;

public:

    Vector(const int* elems, int sz) {
        size = sz;
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = elems[i];
        }
    }

    Vector operator+(const Vector & other) const{
        if (size == other.size) {
            int* result = new int[size];
            for (int i = 0; i < size; i++)
                result[i] = elements[i] + other.elements[i];

        return {result, size};
        } else{
            throw runtime_error("Error");
        }
    };

    Vector operator-(const Vector& other) const {
        if (size == other.size) {
            int* result = new int[size];
            for (int i = 0; i < size; i++) {
                result[i] = elements[i] - other.elements[i];
            }
            return {result, size};
        } else{
            throw runtime_error("Error");
        }
    }

    int operator*(const Vector & other) const{
        int result = 0;
        if (size == other.size) {
            for (int i = 0; i < size; i++) {
                result += (elements[i] * other.elements[i]);
            }
        } else{
            throw runtime_error("Error");
        }
        return result;
    };

    Vector operator*(const Matrix & other) const{
        int* result = new int[size];
        if (size == other.columns()) {
            for (int i = 0; i < size; i++) {
                int sum = 0;
                for (int j = 0; j < other.rows(); j++)
                    sum += other.elements()[i][j];
                result += (elements[i] * sum);
            }
        } else if (size == other.rows()) {
            for (int i = 0; i < size; i++) {
                int sum = 0;
                for (int j = 0; j < other.columns(); j++)
                    sum += other.elements()[i][j];
                result += (elements[i] * sum);
            }
        }
        return {result, size};
    };

    Vector operator*(const int& num){
        int* result = new int[size];
        for(int i =0; i < size; i++){
            result[i] = elements[i]*num;
        }
        return {result, size};
    }
    Vector operator/(const int& num) const {
        if (num == 0) {
            throw runtime_error("Error");
        }
        int* result = new int[size];
        for (int i = 0; i < size; i++) {
            result[i] = elements[i] / num;
        }
        return {result, size};
    }

    void PrintVector(){
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};