/*
	2019/12/01
	设计模式---观察者模式 
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <windows.h>
using namespace std;

//抽象的英雄 抽象的观察者 
class AbstractHero{
public:
	virtual void update() = 0;
	
}; 


//具体的英雄 具体的观察者 
class HeroA : public AbstractHero{
public:
	HeroA(){
		cout << "英雄A正在撸Boss" << endl;
	}
	
	virtual void update(){
		cout << "英雄A停止撸， 脱战了" << endl;
	}
};

class HeroB : public AbstractHero{
public:
	HeroB(){
		cout << "英雄B正在撸Boss" << endl;
	}
	
	virtual void update(){
		cout << "英雄B停止撸， 脱战了" << endl;
	}
};

class HeroC : public AbstractHero{
public:
	HeroC(){
		cout << "英雄C正在撸Boss" << endl;
	}
	
	virtual void update(){
		cout << "英雄C停止撸， 脱战了" << endl;
	}
};

class HeroD : public AbstractHero{
public:
	HeroD(){
		cout << "英雄D正在撸Boss" << endl;
	}
	
	virtual void update(){
		cout << "英雄D停止撸， 脱战了" << endl;
	}
};

//抽象的观察目标 
class AbstractBoss{
public:
	//添加观察者
	virtual void addHero(AbstractHero* hero) = 0; 
	//删除观察者
	virtual void deleteHero(AbstractHero* hero) = 0; 
	//通知所有观察者
	virtual void notify() = 0; 	
};


//具体的观察者 BOSSA
class BOSSA : public AbstractBoss{
public:
	//添加观察者
	virtual void addHero(AbstractHero* hero){
		pHeroList.push_back(hero);
	}
	//删除观察者
	virtual void deleteHero(AbstractHero* hero){
		pHeroList.remove(hero);
	}
	//通知所有观察者
	virtual void notify(){
		for(list<AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); ++ it){
			(*it)->update();
		}
	}	
public:
	list<AbstractHero*> pHeroList;
};

void test01(){
	//创建观察者 
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;

	//创建观察目标
	AbstractBoss* boss = new BOSSA;
	
	boss->addHero(heroA); 
	boss->addHero(heroB); 
	boss->addHero(heroC); 
	boss->addHero(heroD); 
	
	cout << "herC 阵亡..." << endl; 
	boss->deleteHero(heroC);
	
	cout << "Boss死了 通知英雄准备抢装备...." << endl;
	boss->notify();	
}

int main(){
	test01();
	return 0;
}





