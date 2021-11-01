#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<double>>;

void randMatrix(Matrix& matrix) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		matrix[i].resize(matrix.size());
	}
	auto size = matrix.size();

	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix.size(); ++j) {
			matrix[i][j] = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) - 0.5; // number = [-0.5, 0.5]
		}
	}
}void testMatrix(Matrix& matrix, int num) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		matrix[i].resize(matrix.size());
	}
	auto size = matrix.size();

	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix.size(); ++j) {
			matrix[i][j] = num;
		}
	}
}
void printMatrix(const Matrix& matrix) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix.size(); ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

Matrix multiplyMatrix(const Matrix& a, const Matrix& b){
	auto ssize = a.size();
	Matrix c(ssize); 
	for (size_t i = 0; i < ssize; ++i) {
		c[i].resize(ssize);
	}
		for (size_t j = 0; j < ssize; ++j) {
			for (size_t k = 0; k < ssize; ++k) {
				for (size_t i = 0; i < ssize; ++i) {
					c[i][j] += a[i][k] * b[k][j];
				}
			}
			cout << endl;
		}

		return c;
}

int main() {
	srand(static_cast<unsigned>(time(0)));
	Matrix matrix1(5);
	Matrix matrix2(5);
	randMatrix(matrix1);
	randMatrix(matrix2);
	printMatrix(matrix1);
	printMatrix(matrix2);
	printMatrix(multiplyMatrix(matrix1, matrix2));
}
