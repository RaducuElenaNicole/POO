#include<iostream>
using namespace std;

template<typename T>
T suma(T a, T b) {
	return a + b;
}

template<typename T>
class Vector {
public:
	int nrElemente;
	T* vector;

	Vector(int nr, T* vect) {
		nrElemente = nr;
		vector = new T[nr];
		for (int i = 0; i < nr; i++) {
			vector[i] = vect[i];
		}
	}

	friend ostream& operator<<(ostream& out, const Vector& v) {
		out << v.nrElemente << endl;
		for (int i = 0; i < v.nrElemente; i++) {
			out << v.vector[i] << " ";
		}
		out << endl;
		return out;
	}
};

void main() {
	int a = 10;
	int b = 6;
	cout << suma(a, b) << endl;

	float aF = 10.55;
	float bF = 6.49;
	cout << suma(aF, bF) << endl;

	Vector<int> v1(2, new int[2] {5, 7});
	cout << v1;

	Vector<float> v2(2, new float[2] {5.56, 7.88});
	cout << v2;

	// enum !!!!
}