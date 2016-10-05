#include "stdafx.h"
#include<iostream>
#include<bitset> // Do some reading about what it is and what kinda stuff you can do with this 
using namespace std;

class BitArray {
private:
	bitset<64> a; // The value of the bitset can be changed 
public:
	
	BitArray() {
		a = 0;
	}

	//void add(int n)/* Method(function) to input one element at a time into the set. */ {
	//	a[n-1] = 1;
	//}

	/* Method(function) to input elements into the set. */
	void add(int t) {
		a[t-1] = 1;
	}
	template <typename... A>/* Method(function) to input elements into the set. */
	void add(int t , A... list)
	{
		a[t-1] = 1;
		add(list...);
	}
	/* in case you messed up and want to delete some stuff */
	void delete_stuff(int t) {
		a[t-1] = 0;
	}
	template <typename... A>/* in case you messed up and want to delete some stuff */
	void delete_stuff(int t, A... list)
	{
		a[t-1] = 0;
		delete(list...);
	}

	//void delete_stuff(int n)/* in case you messed up and want to delete some stuff */ {
	//	a[n-1] = 0;
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
		/*cout << a <<endl;*/ // display the contents of the bitset on the console window
		for (int i = 0;i < a.size();i++) {
			if (a[i] == 1) {
				cout << i+1 << " ";
			}
		}
	
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
	cout << endl;
	y.print();
	cout << endl;
	z.print();
	cout << endl;
	a.print();
	cout << endl;
	b.print();
	cout << endl;
		
}