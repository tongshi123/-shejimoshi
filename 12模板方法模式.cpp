/*
	2019/11/28
	���ģʽ---ģ�巽��ģʽ 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//����ģ��
class DrinkTemplate{
public:
	virtual void BoilWater() = 0;		//��ˮ 
	virtual void Brew() = 0;			//���� 
	virtual void PourInCup() = 0;		//���뱭�� 
	virtual void AddSomething() = 0;	//���� 
	
//ģ�巽��
	void Make(){
		this->BoilWater();
		this->Brew();
		this->PourInCup();
		this->AddSomething();
	} 
}; 

//������ˮ
class Tea : public  DrinkTemplate{
	virtual void BoilWater(){
		cout << "��ˮ" << endl;
	}
	virtual void Brew(){
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourInCup(){
		cout << "��ˮ���뱭��" << endl; 
	}
	virtual void AddSomething(){
		cout << "��������" << endl;
	}
};

//�������� 
class Caffee : public  DrinkTemplate{
	virtual void BoilWater(){
		cout << "��ˮ" << endl;
	}
	virtual void Brew(){
		cout << "���ݿ��ȷ�" << endl;
	}
	virtual void PourInCup(){
		cout << "���ȵ��뱭��" << endl; 
	}
	virtual void AddSomething(){
		cout << "������" << endl;
	}
};

void test01(){
	DrinkTemplate* tea = new Tea;
	tea->Make();
}

int main(){
	test01();
	return 0;
}














