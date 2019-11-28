/*
	2019/11/26 
	���ģʽ---�򵥹���ԭ��--
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

//ˮ������ 
class FruitFactory{
public:
	static AbstactFruit* CreateFruit(string flag){
		if(flag == "apple"){
			// ������Ը���apple�������ܶԸ��ӵ����� 
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
	//�������̲���Ҫ���ģ� ֱ�������þͿ����� 
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
