/*
	2019/11/28
	���ģʽ---���ģʽԭcase
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���ӻ� 
class TV{
public:
	void On(){
		cout << "���ӻ���..." << endl;
	}
	void Off(){
		cout << "���ӻ��ر�..."  << endl; 
	}
};

//��
class Light{
public:
	void On(){
		cout << "�ƴ�..." << endl;
	}
	void Off(){
		cout << "�ƹر�..."  << endl; 
	}
}; 

//����
class Audio{
public:
	void On(){
		cout << "�����..." << endl;
	}
	void Off(){
		cout << "�����..."  << endl; 
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








