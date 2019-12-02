/*
	2019/11/28
	设计模式---模板方法模式 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//抽象模板
class DrinkTemplate{
public:
	virtual void BoilWater() = 0;		//煮开水 
	virtual void Brew() = 0;			//冲泡 
	virtual void PourInCup() = 0;		//倒入杯子 
	virtual void AddSomething() = 0;	//加料 
	
//模板方法
	void Make(){
		this->BoilWater();
		this->Brew();
		this->PourInCup();
		this->AddSomething();
	} 
}; 

//制作茶水
class Tea : public  DrinkTemplate{
	virtual void BoilWater(){
		cout << "煮开水" << endl;
	}
	virtual void Brew(){
		cout << "冲泡茶叶" << endl;
	}
	virtual void PourInCup(){
		cout << "茶水倒入杯中" << endl; 
	}
	virtual void AddSomething(){
		cout << "加入柠檬" << endl;
	}
};

//制作咖啡 
class Caffee : public  DrinkTemplate{
	virtual void BoilWater(){
		cout << "煮开水" << endl;
	}
	virtual void Brew(){
		cout << "冲泡咖啡粉" << endl;
	}
	virtual void PourInCup(){
		cout << "咖啡倒入杯中" << endl; 
	}
	virtual void AddSomething(){
		cout << "加入糖" << endl;
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














