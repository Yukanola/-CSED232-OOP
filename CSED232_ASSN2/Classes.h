#pragma once
#include "libKano.cp.h"
#include "Parameter.h"
#include <algorithm>
#include <ctime>

class Car {

protected:
	int posX, posY, carW, carH;

public:
	void setPosX(int x) { posX = x; };
	void setPosY(int y) { posY = y; };
	void setCarW(int w) { carW = w; };
	void setCarH(int h) { carH = h; };
	int getPosX() { return posX; };
	int getPosY() { return posY; };
	int getCarH() { return carH; };
	int getCarW() { return carW; };
	Car() {};
	Car(int x, int y, int w, int h) : posX(x), posY(y), carW(w), carH(h) {};
	~Car() {};

};

class CarA : virtual public Car {

	CarA *Next, *Before;

public:

	int moveX(int x) { return (this->posX += x); };
	CarA* getNext() { return Next; };
	CarA* getBefore() { return Before; };
	CarA* setNext(CarA* a) { return (Next = a); };
	CarA* setBefore(CarA* a) { return (Before = a); };
	CarA& operator++() { this->posX += 1; return *this; };
	CarA() : Car(0, 0, 2, 3) {};
	~CarA() {};
	CarA(CarA* a) : Before(a), Car(0, 0, 2, 3) {};

};

class CarB : virtual public Car {

	CarB *Next, *Before;

public:

	int moveY(int y) { return (this->posY += y); };
	CarB* getNext() { return Next; };
	CarB* getBefore() { return Before; };
	CarB* setNext(CarB* b) { return (Next = b); };
	CarB* setBefore(CarB* b) { return (Before = b); };
	CarB& operator++() { this->posY += 1; return *this; };
	CarB() : Car(0, 0, 2, 3) {};
	~CarB() {};
	CarB(CarB* b) : Before(b), Car(0, 0, 2, 2) {};

};

class CarC : virtual public Car {

	CarC *Next, *Before;

public:

	void moveXY(int z) { this->posY += z; this->posX += z; };
	CarC* getNext() { return Next; };
	CarC* getBefore() { return Before; };
	CarC* setNext(CarC* c) { return (Next = c); };
	CarC* setBefore(CarC* c) { return (Before = c); };
	CarC& operator++() { this->posY += 1; this->posX += 1; return *this; };
	CarC() : Car(0, 0, 2, 3) {};
	~CarC() {};
	CarC(CarC* c) : Before(c), Car(0, 0, 3, 2) {};

};

class _Q {

	int count[3];

	CarA *AFront, *ARear;
	CarB *BFront, *BRear;
	CarC *CFront, *CRear;

public:

	_Q& operator+=(CarA* a) {

		int count = this->count[0]++;

		if (!count)
			AFront = a;
		
		a->setBefore(ARear);

		if(count)
			ARear->setNext(a);

		ARear = a;

		return *this;

	};

	_Q& operator+=(CarB* b) {

		int count = this->count[1]++;

		if (!count)
			BFront = b;

		b->setBefore(BRear);
		
		if (count)
			BRear->setNext(b);

		BRear = b;

		return *this;

	};

	_Q& operator+=(CarC* c) {

		int count = this->count[2]++;

		if (!count)
			CFront = c;

		c->setBefore(CRear);

		if (count)
			CRear->setNext(c);

		CRear = c;

		return *this;

	};

	_Q& operator++(int) {

		srand(time(NULL));

		int rands = rand() % 7;
		CarA* a;
		CarB* b;
		CarC* c;

		switch (0) {

		case 3:
		case 0:
			a = new CarA;
			operator+=(a);
			break;

		case 4:
		case 1:
			b = new CarB;
			operator+=(b);
			break;

		case 5:
		case 2:
			c = new CarC;
			operator+=(c);
			break;

		case 6:
			break;

		}

		return *this;

	};

	_Q& operator--(int x) {

		using std::max_element;

		int posYs[3] = { (AFront == NULL) ? 0 : AFront->getPosY(), (BFront == NULL) ? 0 : BFront->getPosY(), (CFront == NULL) ? 0 : CFront->getPosY() };

		switch ((x == -1) ? (int)(posYs - max_element(posYs, posYs + 3)) : x) {

		case 0:
		{

			CarA* temp = AFront->getNext();
			delete AFront;
			AFront = temp->setBefore(NULL);
			count[0]--;

		}

		break;

		case 1:
		{

			CarB* temp = BFront->getNext();
			delete BFront;
			BFront = temp->setBefore(NULL);
			count[1]--;

		}

		break;

		case 2:
		{

			CarC* temp = CFront->getNext();
			delete CFront;
			CFront = temp->setBefore(NULL);
			count[2]--;

		}

		break;

		}

		return *this;

	};
	
	_Q& operator--() { return operator--(-1); };

	_Q() : AFront(NULL), ARear(NULL), BFront(NULL), BRear(NULL), CFront(NULL), CRear(NULL) { count[0] = 0; count[1] = 0, count[2] = 0; };

	_Q& insert();

};

_Q& _Q::insert() {

	if (count[0]) {

		CarA* a = AFront;

		for (int i = 0; i++ < count[0]; a = (a++)->getNext());

	}

	if (count[1]) {

		CarB* b = BFront;

		for (int i = 0; i++ < count[1]; b = (b++)->getNext());

	}

	if (count[2]) {

		CarC* c = CFront;

		for (int i = 0; i++ < count[2]; c = (c++)->getNext());

	}

	return *this;

};

class _M : virtual public CarA, virtual public CarB {

	int Colour;

public:
	
	void setColor(int c) { Colour = c; };
	int* getPos() { static int x[2] = { 0, 0 }; x[0] = this->getPosX(); x[1] = this->getPosY(); return x; };
	_M() : Colour(14) {};
	_M(int posX, int posY) : Colour(14) { this->setPosX(posX); this->setPosY(posY); };
	~_M() {};

};
