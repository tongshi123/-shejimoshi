/*
	2019/11/28
	设计模式---外观模式原case
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//电视机 
class TV{
public:
	void On(){
		cout << "电视机打开..." << endl;
	}
	void Off(){
		cout << "电视机关闭..."  << endl; 
	}
};

//灯
class Light{
public:
	void On(){
		cout << "灯打开..." << endl;
	}
	void Off(){
		cout << "灯关闭..."  << endl; 
	}
}; 

//音响
class Audio{
public:
	void On(){
		cout << "音响打开..." << endl;
	}
	void Off(){
		cout << "音响打开..."  << endl; 
	}
}; 

class KTVMode{
public:
	KTVMode(){
		ptv = new TV;
		plight  = new Light;
	}
	~KTVMode(){
		delete ptv;
		delete plight;
	}
	void runKTVMode(){
		ptv->On();
		plight->Off();
	}
	void StopKTVMode(){
		ptv->Off();
		plight->On();
	}
	
public:
	TV*	 ptv;
	Light* plight;
}; 

void test01(){
	KTVMode* ktvmode = new KTVMode;
	ktvmode->runKTVMode();
}

int main(){
	test01();
	return 0;
}








