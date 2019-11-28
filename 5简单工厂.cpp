/*
	2019/11/26 
	设计模式---简单工厂原则--
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstactFruit{
public:
	virtual void ShowName() = 0;
}; 

class Apple : public AbstactFruit{
public:
	virtual void ShowName(){
		cout << "我是苹果" << endl;
	}
};

class Lizi : public AbstactFruit{
public:
	virtual void ShowName(){
		cout << "我是梨子" << endl;
	}
};

//水果工厂 
class FruitFactory{
public:
	static AbstactFruit* CreateFruit(string flag){
		if(flag == "apple"){
			// 这里可以赋予apple这个对象很对复杂的属性 
			//
			// 
			return new Apple;
		}
		else if(flag == "lizi"){
			return new Lizi;
		}
		else 
			return NULL;
	}
}; 

void test01(){
	//创建过程不需要关心， 直接拿来用就可以了 
	FruitFactory* factory = new FruitFactory;
	AbstactFruit* fruit = factory->CreateFruit("lizi");
	fruit->ShowName();
	delete fruit;
	delete factory;
}

int main(){
	test01();
	return 0;
}
