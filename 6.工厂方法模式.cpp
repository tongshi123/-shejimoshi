/*
	2019/11/27 
	���ģʽ---��������ģʽԭ��--
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
		cout << "����ƻ��" << endl;
	}
};

class Lizi : public AbstactFruit{
public:
	virtual void ShowName(){
		cout << "��������" << endl;
	}
};

//���󹤳�
class  AbstractFruitFactory{
public:
	virtual AbstactFruit* CreateFruit() = 0;
	
};

//ƻ������ 
class AppleFactory : public AbstractFruitFactory{
public:
		virtual AbstactFruit* CreateFruit(){
			return new Apple;
		}
};

//���ӹ��� 
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




