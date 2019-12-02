/*
	2019/12/2 
	���ģʽ---װ��ģʽ 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//����Ӣ�� 
class AbstractHero{
public:
	virtual void ShowStatus() = 0;

public:
	int mHp;	
	int mMp;	
	int mAt;	
	int mDf;	
};

//����Ӣ��
class HeroA : public  AbstractHero{
public:
	HeroA(){
		mHp = 0;	
		mMp = 0;
		mAt = 0;
		mDf = 0;
	}
	virtual void ShowStatus(){
		cout << "Ѫ��" << mHp << endl;
		cout << "ħ��" << mMp << endl;
		cout << "����" << mAt << endl;
		cout << "����" << mDf << endl;
	}	
public:
	int mHp = 0;	
	int mMp = 0;
	int mAt = 0;
	int mDf = 0;	
};

//��Ӣ�۴���ĳ��װ��� ��ô������һ��Ӣ��
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

//�����ͽ
class  KuangTuEquipment : public AbstractEquipment{
public:	
	KuangTuEquipment(AbstractHero* hero) : AbstractEquipment(hero){}
	//���Ӷ��⹦��
	void AddKuangTu(){
		
		cout << "Ӣ�۴��Ͽ�ͽ֮��" << endl;
		this->mHp = this->pHero->mHp + 1000;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf;
	} 
	virtual void ShowStatus(){
		AddKuangTu();
		cout << "Ѫ��" << mHp << endl;
		cout << "ħ��" << mMp << endl;
		cout << "����" << mAt << endl;
		cout << "����" << mDf << endl;
	}
	
public:
	int mHp = 0;	
	int mMp = 0;
	int mAt = 0;
	int mDf = 0;	
};

//����޾�֮��
 class  Wujinzhiren : public AbstractEquipment{
public:	
	Wujinzhiren(AbstractHero* hero) : AbstractEquipment(hero){
	}
	//���Ӷ��⹦��
	void AddKuangTu(){
		
		cout << "Ӣ�۴����޾�֮��֮��" << endl;
		this->mHp = this->pHero->mHp ;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 999;
		this->mDf = this->pHero->mDf;
	} 
	virtual void ShowStatus(){
		AddKuangTu();
		cout << "Ѫ��" << mHp << endl;
		cout << "ħ��" << mMp << endl;
		cout << "����" << mAt << endl;
		cout << "����" << mDf << endl;
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
	
	//���Ͽ�ͽ 
	hero = new KuangTuEquipment(hero);
	hero->ShowStatus();
	
	cout << "-----------" << endl;
	//�����޾�֮�� 
	hero = new Wujinzhiren(hero);
	hero->ShowStatus();
} 

int main(){
	test01();
	return 0;
}






