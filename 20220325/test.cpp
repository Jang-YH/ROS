#include<iostream>
#include<vector>
using namespace std;

struct Vector
{
	float x;
	float y;
	float z;
};

Vector outer(Vector v1, Vector v2) {
	Vector ot;
	ot.x = v1.y * v2.z - v1.z * v2.y;
	ot.y = v1.z * v2.x - v1.x * v2.z;
	ot.z = v1.x * v2.y - v1.y * v2.x;

	return ot;
} //외적

float inner(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y + v2.y + v1.z * v2.z;
} //내적

int main() {
	Vector v1, v2, v3;
	v1.x = 1, v1.y = 2, v1.z = 3;
	v2.x = 2, v2.y = 3, v2.z = 4;

	v3 = outer(v1, v2);

	cout << v3.x << ", " << v3.y << ", " << v3.z << endl;
	cout << inner(v1, v2);

	return 0;
}