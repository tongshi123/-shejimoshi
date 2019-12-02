/*
	2019/12/01
	���ģʽ---�۲���ģʽ 
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <windows.h>
using namespace std;

//�����Ӣ�� ����Ĺ۲��� 
class AbstractHero{
public:
	virtual void update() = 0;
	
}; 


//�����Ӣ�� ����Ĺ۲��� 
class HeroA : public AbstractHero{
public:
	HeroA(){
		cout << "Ӣ��A����ߣBoss" << endl;
	}
	
	virtual void update(){
		cout << "Ӣ��Aֹͣߣ�� ��ս��" << endl;
	}
};

class HeroB : public AbstractHero{
public:
	HeroB(){
		cout << "Ӣ��B����ߣBoss" << endl;
	}
	
	virtual void update(){
		cout << "Ӣ��Bֹͣߣ�� ��ս��" << endl;
	}
};

class HeroC : public AbstractHero{
public:
	HeroC(){
		cout << "Ӣ��C����ߣBoss" << endl;
	}
	
	virtual void update(){
		cout << "Ӣ��Cֹͣߣ�� ��ս��" << endl;
	}
};

class HeroD : public AbstractHero{
public:
	HeroD(){
		cout << "Ӣ��D����ߣBoss" << endl;
	}
	
	virtual void update(){
		cout << "Ӣ��Dֹͣߣ�� ��ս��" << endl;
	}
};

//����Ĺ۲�Ŀ�� 
class AbstractBoss{
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) = 0; 
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) = 0; 
	//֪ͨ���й۲���
	virtual void notify() = 0; 	
};


//����Ĺ۲��� BOSSA
class BOSSA : public AbstractBoss{
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero){
		pHeroList.push_back(hero);
	}
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero){
		pHeroList.remove(hero);
	}
	//֪ͨ���й۲���
	virtual void notify(){
		for(list<AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); ++ it){
			(*it)->update();
		}
	}	
public:
	list<AbstractHero*> pHeroList;
};

void test01(){
	//�����۲��� 
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;

	//�����۲�Ŀ��
	AbstractBoss* boss = new BOSSA;
	
	boss->addHero(heroA); 
	boss->addHero(heroB); 
	boss->addHero(heroC); 
	boss->addHero(heroD); 
	
	cout << "herC ����..." << endl; 
	boss->deleteHero(heroC);
	
	cout << "Boss���� ֪ͨӢ��׼����װ��...." << endl;
	boss->notify();	
}

int main(){
	test01();
	return 0;
}





