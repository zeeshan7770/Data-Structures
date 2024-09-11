#include <iostream>
using namespace std;
void addint(int *a)
{
	
	*a=30;
	cout<<"inside function call "<<*a<<endl;
}
struct Student{
    	int reg;
    	float cgpa;
    	void display(){
    		cout<<reg<<cgpa;
		}
	};

int main() {
	/*int a=20;
	cout<<"before function call "<<a<<endl;
	addint(&a);
	cout<<"after function call "<<a<<endl;
	//int addr; //wrong way of pointer
	int* addr;
	addr=&a;
	//cout<<&a<<endl;
	//cout<<addr<<endl;
	cout<<*addr<<endl;
	int arr[5] = {10, 20, 30, 40, 50};
    int* ptrArr = arr;  // Points to the first element of the array
   	ptrArr=ptrArr+2;
    //cout<<*ptrArr<<endl;*/
    Student s1;
    s1.reg=1;
    s1.cgp=3.1;
    Student s2={2,2.0};
    cout<<s1.reg<<s2.reg;
    Student *ptr=s1;
    cout<<ptr->cgpa
    s2.display()
    
	return 0;
}
