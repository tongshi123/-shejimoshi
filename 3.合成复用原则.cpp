/*
	2019/11/26 
	设计模式---合成复用原则--
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//抽象车
class AbstractCar{
public:
	virtual void  run() = 0;
}; 

//大众 
class Dazhong : public AbstractCar{
public:
	virtual void  run(){
		cout << "大众 run..." << endl;
	}
};

//拖拉机 
class Tuolaji : public AbstractCar{
public:
	virtual void  run(){
		cout << "拖拉机  run..." << endl;
	}
};
/*
//针对具体类 
class PersonA : public Dazhong{
public:
	void Doufeng(){
		run();
	}
};

class PersonB : public Tuolaji{
public:
	void Doufeng(){
		run();
	}
};
*/

//可以使用组合 
class  Person{
public:
	void setCar(AbstractCar* car){
		this->car = car;
	}
	void Doufeng(){
		car->run();
		if(car != NULL){
			delete car;
			car = NULL;
		}
	}

public:
	AbstractCar* car;			//组合起来了 兄弟们 
};

void test02(){
	Person* p = new Person;
	p->setCar(new Tuolaji);
	p->Doufeng();
	
	p->setCar(new Dazhong);
	p->Doufeng();
	
	delete p;
}
int main(){
	test02();
	return 0;
}
