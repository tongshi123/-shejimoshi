/*
	2019/12/2 
	设计模式---装饰模式 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//抽象英雄 
class AbstractHero{
public:
	virtual void ShowStatus() = 0;

public:
	int mHp;	
	int mMp;	
	int mAt;	
	int mDf;	
};

//具体英雄
class HeroA : public  AbstractHero{
public:
	HeroA(){
		mHp = 0;	
		mMp = 0;
		mAt = 0;
		mDf = 0;
	}
	virtual void ShowStatus(){
		cout << "血量" << mHp << endl;
		cout << "魔法" << mMp << endl;
		cout << "攻击" << mAt << endl;
		cout << "防御" << mDf << endl;
	}	
public:
	int mHp = 0;	
	int mMp = 0;
	int mAt = 0;
	int mDf = 0;	
};

//当英雄穿上某个装饰物， 那么他还是一个英雄
class AbstractEquipment : public AbstractHero{
public:
	AbstractEquipment(AbstractHero* hero){
		this->pHero = hero;
	}
	virtual void ShowStatus(){
		
	}
public:
	AbstractHero* pHero;
};

//搞个狂徒
class  KuangTuEquipment : public AbstractEquipment{
public:	
	KuangTuEquipment(AbstractHero* hero) : AbstractEquipment(hero){}
	//增加额外功能
	void AddKuangTu(){
		
		cout << "英雄穿上狂徒之后" << endl;
		this->mHp = this->pHero->mHp + 1000;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf;
	} 
	virtual void ShowStatus(){
		AddKuangTu();
		cout << "血量" << mHp << endl;
		cout << "魔法" << mMp << endl;
		cout << "攻击" << mAt << endl;
		cout << "防御" << mDf << endl;
	}
	
public:
	int mHp = 0;	
	int mMp = 0;
	int mAt = 0;
	int mDf = 0;	
};

//搞个无尽之刃
 class  Wujinzhiren : public AbstractEquipment{
public:	
	Wujinzhiren(AbstractHero* hero) : AbstractEquipment(hero){
	}
	//增加额外功能
	void AddKuangTu(){
		
		cout << "英雄穿上无尽之刃之后" << endl;
		this->mHp = this->pHero->mHp ;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 999;
		this->mDf = this->pHero->mDf;
	} 
	virtual void ShowStatus(){
		AddKuangTu();
		cout << "血量" << mHp << endl;
		cout << "魔法" << mMp << endl;
		cout << "攻击" << mAt << endl;
		cout << "防御" << mDf << endl;
	}
	
public:
	int mHp = 0;	
	int mMp = 0;
	int mAt = 0;
	int mDf = 0;	
};

void test01(){
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();
	
	cout << "-----------" << endl;
	
	//穿上狂徒 
	hero = new KuangTuEquipment(hero);
	hero->ShowStatus();
	
	cout << "-----------" << endl;
	//穿上无尽之刃 
	hero = new Wujinzhiren(hero);
	hero->ShowStatus();
} 

int main(){
	test01();
	return 0;
}






