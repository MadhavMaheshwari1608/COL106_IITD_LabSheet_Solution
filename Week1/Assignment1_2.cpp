#include <iostream>
using namespace std;

void swapper(int *p, int *q){
	int temp;
	temp = *q;
	*q = *p;
	*p = temp;
}

void swapper_without(int &p, int &q){
	int temp = q;
	q = p;
	p = temp;
}

int main(){
	int p = 3;
	int q = 5;
	swapper_without(p,q);
	cout << p << q << endl;
	int *x = &p;
	int *y = &q;
	swapper(x,y);
	cout << p << q << endl;	
	return 0;
}
