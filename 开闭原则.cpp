/*
	2019/11/26 
	设计模式---开闭原则---计算器
*/

//抽象类 

#include <iostream>
using namespace std;

class AbstractCaculator{
public:
	virtual int getResylt() = 0;
	virtual void  setOperatorNumber(int, int) = 0;
 };
 
 //加法计算器
 class  PlusCaculator : public AbstractCaculator{
 public:
 	virtual void setOperatorNumber(int a, int b){
 		this->mA  = a;
 		this->mB  = b;
	 }
	
	virtual int getResylt(){
		return mA + mB;
	}
 public:
 	int mA;
 	int mB;
 };
 
 //减法计算器
 class  MinuteCaculator : public AbstractCaculator{
 public:
 	virtual void setOperatorNumber(int a, int b){
 		this->mA  = a;
 		this->mB  = b;
	 }
	
	virtual int getResylt(){
		return mA - mB;
	}
 public:
 	int mA;
 	int mB;
 };
 
 //乘法计算器
 class  MultiplyCaculator : public AbstractCaculator{
 public:
 	virtual void setOperatorNumber(int a, int b){
 		this->mA  = a;
 		this->mB  = b;
	 }
	
	virtual int getResylt(){
		return mA * mB;
	}
 public:
 	int mA;
 	int mB;
 };
 
 void test01(){
 	AbstractCaculator* caculator = new PlusCaculator;
 	caculator->setOperatorNumber(1, 5); 
 	cout << "ret : " << caculator->getResylt() << endl;
 }
 
 int main(){
 	test01();
 	return 0;
 }
