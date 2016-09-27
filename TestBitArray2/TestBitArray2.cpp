//// TestBitArray2.cpp : Defines the entry point for the console application.
////
//
#include "stdafx.h"
//#include <iostream>
//#include <algorithm>
//#include <bitset>
//using namespace std;
//
//class BitArray
//{	
//	unsigned int set[4];
//public:
//	BitArray() {
//		for (int i = 0;i < 4;i++) {
//			set[i] = 0;
//		}
//	}
//	~BitArray() {}
//
//	void add(int x) {
//		for (int i = 0;i < 4;i++) {
//			set[i] = (1 << x);
//		}
//}
//	BitArray Do_Union(BitArray x) {
//		BitArray res[4];
//		for (int i = 0;i < 4;i++) {
//			res[i].set[i] = set[i] | x.set[i];
//		}
//		for (int i = 0;i < 4;i++) {
//			return res[i];
//		}
//	}
//	void print_set() {
//		double counter = 2147483648;
//		unsigned int k[4];
//		
//
//			for (int i = 31,j=0;j<0,i >= 0;j++,i--)
//			{	
//				k[j] = set[j];
//				double a = k[j] / counter;
//				int b = k[j] / counter;
//				if (k[j] / counter >= 1)
//				{
//					cout << 1;
//					k[j] = (a - b)*counter;
//				}
//				else
//					cout << 0;
//				counter /= 2;
//			}
//			cout << endl;
//	}
//
//};
//
//
//int main()
//{
//	BitArray x;
//	BitArray y;
//	x.add(1);
//	y.add(2);
//	y.add(1);
//	x.add(10);
//	y.add(12);
//	y.add(100);
//	/*x.add(96);
//	x.add(85);
//	y.add(77);*/
//	/*x.print_set();*/
//	BitArray z;
//	z = x.Do_Union(y);
//	z.print_set();
//
//    return 0;
//}
//
#include<iostream>
#include<bitset>
#include<initializer_list>
using namespace std;

class BitArray {
private:
	bitset<64> a;
	/*int k[4];int n;*/
public:
	
	BitArray() {
		a = 0;
	}
	//void add(int n)/* Method(function) to input elements into the set. */ {
	//	a[n] = 1;
	//}
	template <typename T>/* Method(function) to input elements into the set. */
	void add(T t) {
		a[t] = 1;
	}
	template <typename T, typename... A>/* Method(function) to input elements into the set. */
	void add(T t , A... list)
	{
		a[t] = 1;
		add(list...);
	}
	template <typename T>/* in case you messed up and want to delete some stuff */
	void delete_stuff(T t) {
		a[t] = 0;
	}
	template <typename T, typename... A>/* in case you messed up and want to delete some stuff */
	void delete_stuff(T t, A... list)
	{
		a[t] = 0;
		delete(list...);
	}

	//void delete_stuff(int n)/* in case you messed up and want to delete some stuff */ {
	//	a[n] = 0;
	//}
	BitArray Union(BitArray x)/* Method(function) to find out the union of two sets */ {
		BitArray temp;
		temp.a = a | x.a; // algorithm to find out the union of two sets
		return temp;
	}
	BitArray Intersection(BitArray x)/* Method(function) to find out the intersection of two sets */ {
		BitArray temp;
		temp.a = a & x.a; // algorithm to find out the intersection of two sets
		return temp;
	}
	BitArray Substraction(BitArray x)/* Method(fucntion) to find the substraction of two sets */ {
		BitArray temp;
		temp.a = a & ~(x.a); // algorithm to find out the substraction of two sets
		return temp;
	}
	void print() /* print function..........displays the contents of the bitset */ {
		cout << a; // display the contents of the bitset on the console window
	}
	
};
void main() {
	// Test function
	BitArray x,y,z,a,b;//Declare objects 

	/*x.add(10);y.add(12); 
	x.add(20);y.add(22);
	x.add(15);y.add(17);
	x.add(44);y.add(44);
	x.add(50);y.add(60);
	x.add(23);y.add(27);
	x.add(33);y.add(33);*/

	x.add(10, 20, 30, 40, 50, 55, 6, 2, 4, 8, 5, 7, 3); // assign values(or switch on or off......as you wish to call it)
	y.add(10, 20, 32, 42, 52, 60, 8, 4, 9, 15);
	
	z = x.Union(y);
	a = x.Intersection(y);  // Perform operations 
	b = x.Substraction(y);

	x.print();
	cout << endl; // Print the contents of the data sets
	y.print();
	cout << endl;

	z.print();
	cout << endl;
	a.print();         // Print the contents of the result sets
	cout << endl;
	b.print();
	cout << endl;
}