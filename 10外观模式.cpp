/*
	2019/11/28
	���ģʽ---���ģʽԭ��--ͨ������ȥ����ϵͳ 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//��ϵͳ1 
class SubSystem1{
public:
	void run(){
		cout << "��ϵͳ1���С���" << endl;
	}
}; 

//��ϵͳ2
class SubSystem2{
public:
	void run(){
		cout << "��ϵͳ2���С���" << endl;
	}
}; 

//��ϵͳ3
class SubSystem3{
public:
	void run(){
		cout << "��ϵͳ3���С���" << endl;
	}
}; 

//�����
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



