/*
	2019/11/26 
	���ģʽ---�����ط���---������
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

//¥��A
class BuildingA : public  AbstractBuilding{
public:
	BuildingA(){
		mQuality = "��Ʒ��";
	}
	virtual void sale(){
		cout << "¥��A" << mQuality << "������" << endl;
	}
	virtual string getQuality(){
		return mQuality;
	}
public:	
	string mQuality;
};

//¥��B
class BuildingB : public  AbstractBuilding{
public:
	BuildingB(){
		mQuality = "��Ʒ��";
	}
	virtual void sale(){
		cout << "¥��B" << mQuality << "������" << endl;
	}
	virtual string getQuality(){
		return mQuality;
	}
public:	
	string mQuality;
};

//�н���  Ҳ���Խ��г��� 
class Mediator{
public:
	Mediator(){
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	//�����ṩ�Ľӿ� 
	AbstractBuilding* findMyBuilding(string quility){
		for(vector<AbstractBuilding*>::iterator it=vBuilding.begin(); it != vBuilding.end(); it ++){
			if((*it)->getQuality() == quility){
				return *it;
			}
		}
		return NULL;
	}
	
	
	~Mediator(){
		//�ͷ�ָ��
		for(vector<AbstractBuilding*>::iterator it=vBuilding.begin(); it != vBuilding.end(); it ++){
			if(*it != NULL){
				delete *it;
			}
		} 
	}
public:
	vector<AbstractBuilding*> vBuilding;
}; 

//�ͻ��� 
void test01(){
	BuildingA* ba = new BuildingA;
	if(ba->mQuality == "��Ʒ��"){
		ba->sale();
	}
	
	BuildingB* bb = new BuildingB;
	if(bb->mQuality == "��Ʒ��"){
		bb->sale();
	}
} 

//�ͻ��� 
void test02(){
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findMyBuilding("��Ʒ��");
	if(building != NULL){
		building->sale();
	}
	else{
		cout << "û�з�����������¥��" << endl;
	}
}

int main(){
	//test01();
	test02();
	return 0;
}
