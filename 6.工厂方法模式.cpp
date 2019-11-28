/*
	2019/11/27 
	设计模式---工厂方法模式原则--
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

//抽象工厂
class  AbstractFruitFactory{
public:
	virtual AbstactFruit* CreateFruit() = 0;
	
};

//苹果工厂 
class AppleFactory : public AbstractFruitFactory{
public:
		virtual AbstactFruit* CreateFruit(){
			return new Apple;
		}
};

//栗子工厂 
class LiziFactory : public AbstractFruitFactory{
public:
		virtual AbstactFruit* CreateFruit(){
			return new Lizi;
		}
};

test01(){
	AbstractFruitFactory* fruitFactory = new AppleFactory;
	AbstactFruit* fruit = fruitFactory->CreateFruit();
	fruit->ShowName();
	
	delete fruit;
	delete fruitFactory;
}

int main()
{
	test01();
	return 0;
}




