/*
	2019/11/30
	设计模式---策略模式 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//抽象武器 武器策略
class WeaponStrategy{
public:
	virtual void UserWeapon() = 0;
}; 

class Knife : public WeaponStrategy{
public:
	virtual void UserWeapon(){
		cout << "使用匕首" << endl;
	}
};

class AK47 : public WeaponStrategy{
public:
	virtual void UserWeapon(){
		cout << "使用AK47" << endl;
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
	//创建角色 
	Person* p = new Person;
	
	//武器策略 
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
