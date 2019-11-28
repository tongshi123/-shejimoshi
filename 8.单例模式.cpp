/*
	2019/11/27 
	���ģʽ---����ģʽԭ��--
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A{
private:
	A(){
		a = new A;
	}
public:
	static A* getInstance(){
		return a;
	}
private:
	static A* a;
};

A* A::a = NULL;			//


//����ʽ
class Singleton_lazy{
private:
	Singleton_lazy(){}
public:
	static Singleton_lazy* getInstance(){
		if(pSingleton == NULL){
			pSingleton = new Singleton_lazy;	
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};
//�����ʼ��
Singleton_lazy* Singleton_lazy::pSingleton = NULL;
 
 
 
//����ʽ
class Singleton_hungry{
private:
	Singleton_hungry(){ 
		cout << "����ʽ�Ĺ��캯��" << endl; 
	}
public:
	static Singleton_hungry* getInstance(){
		return pSingleton;
	}
/*		�����ṩ����ӿڣ� �ͷ�������ͱ����ˣ��� 
	static void freeSpace(){
		if(pSingleton != NULL){
			delete pSingleton;
		}	
	}
*/
private:
	static Singleton_hungry* pSingleton;
};
 //�����ʼ��
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;


void test01(){
	Singleton_lazy* p1 =  Singleton_lazy::getInstance();
	Singleton_lazy* p2 =  Singleton_lazy::getInstance();
	if(p1 == p2){
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬 �ǵ���" << endl;
	}
	else{
		cout << "���ǵ����� �ֵ�" << endl; 
	}
	
	
	Singleton_hungry* p3 =  Singleton_hungry::getInstance();
	Singleton_hungry* p4 =  Singleton_hungry::getInstance();
	if(p3 == p4){
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬 �ǵ���" << endl;
	}
	else{
		cout << "���ǵ����� �ֵ�" << endl; 
	}
	
}

int main(){
	cout << "main������ʼִ��!" << endl;
	test01();
	return 0;
}
