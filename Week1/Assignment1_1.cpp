#include <iostream>
using namespace std;

class Employee{
	protected:
		int password;
	public:
		int id;
		Employee(int i,int pass = 0){
		id = i;
		password = pass; 
		}
		virtual void work(){
			cout << "I am Employee " << id << " and I am working." << endl;
		}
		void login(int input){
			if(input==password){
				cout << "Login Successful" << endl;
			}
			else{
				cout << "Login Unsuccessful" << endl;
			}
		}	
};

class Developer : public Employee{
	public:
		Developer(int i) : Employee(i){
			id = i;
		}
};

class Manager : public Employee{
	public:
		int manager_id;
		Manager(int i, int j, int k) : Employee(i,k){
			id = i;
			manager_id = j;
			password = k;
		}
		void work(){
			cout << "I am Manager "<< manager_id << " and I am working" << endl; 
		}
		void change_password(int m, int n){
			if(password == m){
				password = n;
			}
			else{
				cout << "Wrong Password" << endl;
			}									
		}	
};

int main(){
	Manager m1(10,0,99);
	m1.work();
	m1.change_password(98,100);
	m1.change_password(99,100);
	return 0;
}

