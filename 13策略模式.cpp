/*
	2019/11/30
	���ģʽ---����ģʽ 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//�������� ��������
class WeaponStrategy{
public:
	virtual void UserWeapon() = 0;
}; 

class Knife : public WeaponStrategy{
public:
	virtual void UserWeapon(){
		cout << "ʹ��ذ��" << endl;
	}
};

class AK47 : public WeaponStrategy{
public:
	virtual void UserWeapon(){
		cout << "ʹ��AK47" << endl;
	}
};

class Person {
public:
	void setWeapon(WeaponStrategy* Weapon){
		this->m_pWeapon = Weapon;
	}
	void ThrowWeapon(){
		m_pWeapon->UserWeapon();
	}
	
public:	
	WeaponStrategy* m_pWeapon;
	
};

void test01(){
	//������ɫ 
	Person* p = new Person;
	
	//�������� 
	WeaponStrategy* knief = new Knife;
	WeaponStrategy* ak47 = new AK47;
	
	p->setWeapon(knief); 
	p->ThrowWeapon();	
	
	p->setWeapon(ak47); 
	p->ThrowWeapon();

	delete knief;
	delete ak47;
	delete p;
}

int main(){
	test01();
	return 0;
}
