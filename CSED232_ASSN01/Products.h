#if _WIN32
#include "libKano.h"
#else
#include "libKano_Linux.h"
#endif

//using std::ostringstream;

class Snack {

	int ID, Stock, PrimeCost, SailCost;	// 상품 정보들

	string Name, Manufacturer;	// 상품 정보들

	float Margin;	// 마진값은 소수로 저장되(하)고 퍼센트로 표시합니다.

	Snack* Next;	// 다음 과자 노드를 가리키는 포인터
	Snack* Before;	// 이전 과자 노드를 가리키는 포인터

public:

	Snack(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };	// ID를 설정합니다.
	void setName(string name) { this->Name = name; };	// Name을 설정합니다.
	void setStock(int stock) { this->Stock = stock; };	// Stock을 설정합니다.
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };	// PrimeCost를 설정합니다.	SaleCost도 같이 수정됩니다.
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };	// Margin을 설정합니다.	SaleCost도 같이 수정됩니다.
	void setManufacturer(string man) { this->Manufacturer = man; };	// Manufacturer을 설정합니다.
	void setNext(Snack* aSnack) { this->Next = aSnack; };	// 다음 과자 노드를 설정합니다.
	void setBefore(Snack* aSnack) { this->Before = aSnack; };	//이전 과자 노드를 설정합니다.

	int getID() { return this->ID; };	// ID를 리턴합니다.
	string getName() { return this->Name; };	// Name을 리턴합니다.
	int getStock() { return this->Stock; };	// Stock을 리턴합니다.
	int getPrimeCost() { return this->PrimeCost; };	// PrimeCost를 리턴합니다.
	float getMargin() { return this->Margin; };	// Margin을 리턴합니다.
	string getManufacturer() { return this->Manufacturer; };	// Manufacturer을 리턴합니다.
	int getSailCost() { return this->SailCost; };	// SailCost를 리턴합니다. 판매가와 관련된 코드들을 쓸때까지만 해도 SailCost가 틀린 단어인 줄 모르고 있었습니다. 늦게 SaleCost로 바꿀 수 있었지만, 귀찮아서 냅뒀습니다.
	Snack* getNext() { return this->Next; };	// Next를 리턴합니다.
	Snack* getBefore() { return this->Before; };	// Before를 리턴합니다.

};

class Drink {	// Snack 참조.

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Drink* Next;
	Drink* Before;

public:

	Drink(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Drink* aDrink) { this->Next = aDrink; };
	void setBefore(Drink* aDrink) { this->Before = aDrink; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Drink* getNext() { return this->Next; };
	Drink* getBefore() { return this->Before; };

};

class Ice {	// Snack 참조.

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Ice* Next;
	Ice* Before;

public:

	Ice(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Ice* anIce) { this->Next = anIce; };
	void setBefore(Ice* anIce) { this->Before = anIce; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Ice* getNext() { return this->Next; };
	Ice* getBefore() { return this->Before; };

};

class Other {	// Snack 참조.

	int ID, Stock, PrimeCost, SailCost;

	string Name, Manufacturer;

	float Margin;

	Other* Next;
	Other* Before;

public:

	Other(int id, string name, int amount, int primeCost, float margin, int sailCost, string manufacturer);

	void setID(int id) { this->ID = id; };
	void setName(string name) { this->Name = name; };
	void setStock(int stock) { this->Stock = stock; };
	void setPrimeCost(int cost) { this->PrimeCost = cost; this->SailCost = cost*((float)1 + this->Margin); };
	void setMargin(float margin) { this->Margin = margin; this->SailCost = ((float)1 + margin)*this->PrimeCost; };
	void setManufacturer(string man) { this->Manufacturer = man; };
	void setNext(Other* aProd) { this->Next = aProd; };
	void setBefore(Other* aProd) { this->Before = aProd; };

	int getID() { return this->ID; };
	string getName() { return this->Name; };
	int getStock() { return this->Stock; };
	int getPrimeCost() { return this->PrimeCost; };
	float getMargin() { return this->Margin; };
	string getManufacturer() { return this->Manufacturer; };
	int getSailCost() { return this->SailCost; };
	Other* getNext() { return this->Next; };
	Other* getBefore() { return this->Before; };

};
