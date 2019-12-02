/*
	2019/11/28
	设计模式---外观模式原则--通过代理去启动系统 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//子系统1 
class SubSystem1{
public:
	void run(){
		cout << "子系统1运行。。" << endl;
	}
}; 

//子系统2
class SubSystem2{
public:
	void run(){
		cout << "子系统2运行。。" << endl;
	}
}; 

//子系统3
class SubSystem3{
public:
	void run(){
		cout << "子系统3运行。。" << endl;
	}
}; 

//外观类
class Facede{
public:
	Facede(){
		pSystem1 = new SubSystem1;
		pSystem2 = new SubSystem2;
		pSystem3 = new SubSystem3;
	}
	
void runSystem(){
	pSystem1->run() ;
	pSystem2->run() ;
	pSystem3->run() ;
}

private:
	SubSystem1* pSystem1;
	SubSystem2* pSystem2;
	SubSystem3* pSystem3;
}; 

 void test01(){
 	Facede* facede = new Facede;
 	facede->runSystem();
 }
 
 int main(){
 	test01();
 	return 0;
 }



