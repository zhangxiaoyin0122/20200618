#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void  test() {
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);

 }
void test2() {
	unsigned int i;
	for ( i = 9; i >= 0; i--) {
		printf("%u\n", i);
	}
}	

template<class T,size_t N=10>
class array {
public:
	T& operator[](size_t index) {
		return _array[index];
	}
	const T& operator[](size_t index)const {
		return _array[index];
	}
	size_t size()const {
		return _size;
	}
	bool empty()const {
		return 0 == size;
	}
private:
	T _array[N];
	size_t _size;
};

template<class T>
bool IsEqual(T& left, T& right) {
	return left == right;
}
void test3() {
	const char* p1 = "hello";
	const char* p2 = "warld";

	if (IsEqual(p1, p2)) {
		cout << p1 << endl;
	}
	else {
		cout << p2 << endl;
	}
}
//.h
template<class T>
T Add(const T& left, const T& right);
//.c
template<class T>
T Add(const T& left, const T& right) {
	return left + right;
}

//Æ«ÌØ»¯
template<class T1,class T2>
class Date <T1*,T2*>{
public:
	Date() {
		cout << "Date<T1*,T2*>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<class T1,class T2>
class Date<T1&, T2&> {
public:
	Date(const T1& d1, const T2& d2)
		:_d1(d1)
		,_d2(d2)
	{
		cout << "Date<T1&,T2&>" << endl;
	}


private:
	const T1& _d1;
	const T2& _d2;
};


void test4() {
	Date<double, int> d1;
	Date<int, double> d2;
	Date<int*, int*> d3;
	Date<int&, int&> d4(1, 2);
}
int main() {
	test3();
	return 0;
}

