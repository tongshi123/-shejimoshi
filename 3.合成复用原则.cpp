/*
	2019/11/26 
	���ģʽ---�ϳɸ���ԭ��--
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//����
class AbstractCar{
public:
	virtual void  run() = 0;
}; 

//���� 
class Dazhong : public AbstractCar{
public:
	virtual void  run(){
		cout << "���� run..." << endl;
	}
};

//������ 
class Tuolaji : public AbstractCar{
public:
	virtual void  run(){
		cout << "������  run..." << endl;
	}
};
/*
//��Ծ����� 
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

//����ʹ����� 
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
	AbstractCar* car;			//��������� �ֵ��� 
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
