/*
	2019/11/27 
	设计模式---单例模式原则--
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


//懒汉式
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
//类外初始化
Singleton_lazy* Singleton_lazy::pSingleton = NULL;
 
 
 
//饿汉式
class Singleton_hungry{
private:
	Singleton_hungry(){ 
		cout << "饿汉式的构造函数" << endl; 
	}
public:
	static Singleton_hungry* getInstance(){
		return pSingleton;
	}
/*		不能提供这个接口， 释放了这个就悲催了！！ 
	static void freeSpace(){
		if(pSingleton != NULL){
			delete pSingleton;
		}	
	}
*/
private:
	static Singleton_hungry* pSingleton;
};
 //类外初始化
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;


void test01(){
	Singleton_lazy* p1 =  Singleton_lazy::getInstance();
	Singleton_lazy* p2 =  Singleton_lazy::getInstance();
	if(p1 == p2){
		cout << "两个指针指向同一块内存空间， 是单例" << endl;
	}
	else{
		cout << "不是单例啊 兄弟" << endl; 
	}
	
	
	Singleton_hungry* p3 =  Singleton_hungry::getInstance();
	Singleton_hungry* p4 =  Singleton_hungry::getInstance();
	if(p3 == p4){
		cout << "两个指针指向同一块内存空间， 是单例" << endl;
	}
	else{
		cout << "不是单例啊 兄弟" << endl; 
	}
	
}

int main(){
	cout << "main函数开始执行!" << endl;
	test01();
	return 0;
}
