#include <iostream>
using namespace std;
class A{
public:
	int id;
	A(int i){
		id = i;
		cout << "Created object with ID: " << id << endl;
	}
	~A(){
		cout << "Destroyed object with ID: " << id << endl;
	}
};

int main(){
	A a1(3);
	A* a2 = new A(5);
	A* a3 = new A(7);
	return 0;
}
