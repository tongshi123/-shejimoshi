/*
	2019/11/26 
	设计模式---迪米特法则---计算器
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractBuilding{
public:
	//string mQuality;
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

//楼盘A
class BuildingA : public  AbstractBuilding{
public:
	BuildingA(){
		mQuality = "高品质";
	}
	virtual void sale(){
		cout << "楼盘A" << mQuality << "被售卖" << endl;
	}
	virtual string getQuality(){
		return mQuality;
	}
public:	
	string mQuality;
};

//楼盘B
class BuildingB : public  AbstractBuilding{
public:
	BuildingB(){
		mQuality = "低品质";
	}
	virtual void sale(){
		cout << "楼盘B" << mQuality << "被售卖" << endl;
	}
	virtual string getQuality(){
		return mQuality;
	}
public:	
	string mQuality;
};

//中介类  也可以进行抽象 
class Mediator{
public:
	Mediator(){
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//对外提供的接口 
	AbstractBuilding* findMyBuilding(string quility){
		for(vector<AbstractBuilding*>::iterator it=vBuilding.begin(); it != vBuilding.end(); it ++){
			if((*it)->getQuality() == quility){
				return *it;
			}
		}
		return NULL;
	}
	
	
	~Mediator(){
		//释放指针
		for(vector<AbstractBuilding*>::iterator it=vBuilding.begin(); it != vBuilding.end(); it ++){
			if(*it != NULL){
				delete *it;
			}
		} 
	}
public:
	vector<AbstractBuilding*> vBuilding;
}; 

//客户端 
void test01(){
	BuildingA* ba = new BuildingA;
	if(ba->mQuality == "低品质"){
		ba->sale();
	}
	
	BuildingB* bb = new BuildingB;
	if(bb->mQuality == "低品质"){
		bb->sale();
	}
} 

//客户端 
void test02(){
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findMyBuilding("低品质");
	if(building != NULL){
		building->sale();
	}
	else{
		cout << "没有符合您条件的楼盘" << endl;
	}
}

int main(){
	//test01();
	test02();
	return 0;
}
