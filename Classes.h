#pragma once
#include "Core.kano.h"
#include "Parameter.h"
#include <algorithm>
#include <ctime>

static int getRand(int d) { static int X = 0; srand(((X) ? X : time(NULL))); X = rand(); return (X % d); };
static int getRand(int d, int m) { return getRand(d) - m; };
static unsigned int regId() { return ++Setting::blockers; };

class Car {

protected:
	unsigned int id;
	int posX, posY, carW, carH, carOW, carOH;
	bool scoreCounted;
	COORD prePos;

public:
	void setPosX(int x) { posX = x; };
	void setPosY(int y) { posY = y; };
	void setCarW(int w) { carW = w; };
	void setCarH(int h) { carH = h; };
	void setPrePos(int x, int y) { prePos.X = x; prePos.Y = y; };
	void count() { scoreCounted = true; };
	int getPosX() { return posX; };
	int getPosY() { return posY; };
	int getCarH() { return carH; };
	int getCarW() { return carW; };
	int getOCarH() { return carOH; };
	int getOCarW() { return carOW; };
	bool isCounted() { return scoreCounted; };
	COORD getPrePos() { return prePos; };
	bool decompose() { prePos.X = posX; prePos.Y = posY--; return !(--carH); };
	Car() {};
	Car(int x, int y, int w, int h) : id(regId()), scoreCounted(false), posX(x), posY(y), carW(w), carH(h), carOH(h), carOW(w) { prePos.X = x; prePos.Y = y; };
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
	CarA& behave() { 
		
		this->posY += 1;
		int beX = 2 * getRand(3, 1);

		if (this->posX + beX >= 0 && this->posX + beX < (Setting::E->roadX * 2 - 1 - 2 * this->getCarW()))
			this->posX += beX;
	
		return *this;
	
	};
	CarA() : Next(NULL), Before(NULL), Car(0, -2, 2, 3) {};
	CarA(int x) : Next(NULL), Before(NULL), Car(x, -2, 2, 3) {};
	~CarA() {};
	CarA(CarA* a) : Next(NULL), Before(a), Car(0, -2, 2, 3) {};

};

class CarB : virtual public Car {

	CarB *Next, *Before;

public:

	int moveY(int y) { return (this->posY += y); };
	CarB* getNext() { return Next; };
	CarB* getBefore() { return Before; };
	CarB* setNext(CarB* b) { return (Next = b); };
	CarB* setBefore(CarB* b) { return (Before = b); };
	CarB& behave() { this->posY += (getRand(3)) ? 1 : 0; return *this; };
	CarB() : Next(NULL), Before(NULL), Car(0, -2, 2, 2) {};
	CarB(int x) : Next(NULL), Before(NULL), Car(x, -2, 2, 2) {};
	~CarB() {};
	CarB(CarB* b) : Next(NULL), Before(b), Car(0, -2, 2, 2) {};

};

class CarC : virtual public Car {

	CarC *Next, *Before;

public:

	void moveXY(int z) { this->posY += z; this->posX += z; };
	CarC* getNext() { return Next; };
	CarC* getBefore() { return Before; };
	CarC* setNext(CarC* c) { return (Next = c); };
	CarC* setBefore(CarC* c) { return (Before = c); };
	CarC& behave() {

		this->posY += getRand(2);

		int beX = 2* getRand(3, 1);

		if (this->posX + beX >= 0 && this->posX + beX < (Setting::E->roadX * 2 - 1 - 2 * this->getCarW()))
			this->posX += beX;

		return *this;

	};
	CarC() : Next(NULL), Before(NULL), Car(0,-2, 3, 2) {};
	CarC(int x) : Next(NULL), Before(NULL), Car(x, -2, 3, 2) {};
	~CarC() {};
	CarC(CarC* c) : Next(NULL), Before(c), Car(0, -2, 3, 2) {};

};


class __Pixel {

public:

	__Pixel* Next;

	CarA* A;
	CarB* B;
	CarC* C;

	bool detAAOA() { return (B != NULL && C != NULL); };
	bool detAAOB() { return (A != NULL && C != NULL); };
	bool detAAOC() { return (A != NULL && B != NULL); };
	void setA(CarA* a) { A = a; };

	__Pixel() : A(NULL), B(NULL), C(NULL), Next(NULL) {};

};

class _Pixel {

	__Pixel* P[41][23];
	int C;

public:

	__Pixel& getPixel(int x, int y) { /*cout << "[[" << x << "," << y << "]]";*/ return *(P[y][x]); };
	__Pixel& setPixel(int x, int y, CarA* a) { P[y][x]->setA(a); return *(P[y][x]); }
	_Pixel(int x, int y) : C(x) {

		using std::endl;

		for (int i = 0; i++ < y;) {

			__Pixel *now;

			for (int j = 0; j++ < x; P[i - 1][j - 1] = now) {

				now = new __Pixel;

				//cout << "i=" << i << ",j=" << j << "p=" << &P[i-1][j-1] << endl;

			}

		}

		con.csPause();

	};

};

class _Q {

	int count[3];

	CarA *AFront, *ARear;
	CarB *BFront, *BRear;
	CarC *CFront, *CRear;

public:

	_Q& add(CarA* a, _Pixel& P) {

		int count = this->count[0]++;

		if (!count)
			AFront = a;

		a->setBefore(ARear);

		if (count)
			ARear->setNext(a);

		ARear = a;

		for (int j = 0; j++ < a->getCarH();)
			for (int k = 0; k++ < a->getCarW();)
				if (a->getPosY() + j - 1 >= 0)
					P.getPixel(a->getPosY() + j - 1, a->getPosX() + k - 1).A = a;

		return *this;

	};

	_Q& add(CarB* b) {

		int count = this->count[1]++;

		if (!count)
			BFront = b;

		b->setBefore(BRear);

		if (count)
			BRear->setNext(b);

		BRear = b;

		return *this;

	};

	_Q& add(CarC* c) {

		int count = this->count[2]++;

		if (!count)
			CFront = c;

		c->setBefore(CRear);

		if (count)
			CRear->setNext(c);

		CRear = c;

		return *this;

	};

	CarA* getAFront() { return AFront; };
	//CarA* getARear() { return ARear; };
	CarB* getBFront() { return BFront; };
	//CarB* getBRear() { return BRear; };
	CarC* getCFront() { return CFront; };
	//CarC* getCRear() { return CRear; };

	int* getCount() { return count; };

	inline _Q& randomInsert(_Pixel&);

	_Q() : AFront(NULL), ARear(NULL), BFront(NULL), BRear(NULL), CFront(NULL), CRear(NULL) { count[0] = 0; count[1] = 0, count[2] = 0; };

	inline _Q& behave(Setting::Env&, _Pixel&);

};

_Q& _Q::randomInsert(_Pixel& P) {

	srand(time(NULL));
	int x = rand();

	srand(x);
	int rands = rand() % 10;

	CarA* a;
	CarB* b;
	CarC* c;

	x = x % (Setting::E->roadX * 2 - 3);

	switch (0) {

	case 7:
	case 3:
	case 0:
		a = new CarA(x - (x % 2));
		add(a, P);
		break;

	case 8:
	case 4:
	case 1:
		b = new CarB(x - (x % 2));
		add(b);
		break;

	case 9:
	case 5:
	case 2:
		c = new CarC((x = x - 3) - (x % 2));
		add(c);
		break;

	case 6:
		break;

	}

	return *this;

};

_Q& _Q::behave(Setting::Env& E, _Pixel& P) {

	bool breakSign = false;

	if (count[0]) {

		CarA* a = AFront;

		for (int i = 0; i++ < count[0]; a = a->getNext()) {

			a->behave();

			for (int j = 0; j++ < a->getCarH() && !breakSign;)
				for (int k = 0; k++ < a->getCarW() && !breakSign;)
					if(a->getPosY() + j - 1 >= 0)
						if (!P.getPixel(a->getPosX() + k - 1, a->getPosY() + j - 1).detAAOA()) {

							a->setPrePos(a->getPrePos().X, a->getPrePos().Y);

							breakSign = true;

						};

			if (!breakSign)
				for (int j = 0; j++ < a->getCarH();)
					for (int k = 0; k++ < a->getCarW();) {

						P.getPixel(a->getPrePos().X + k - 1, a->getPrePos().Y + j - 1).A = NULL;
						P.getPixel(a->getPosX() + k - 1, a->getPosY() + j - 1).A = a;

					}
			else
				breakSign = false;

		}

	}

	if (count[1]) {

		CarB* b = BFront;

		for (int i = 0; i++ < count[1]; b = b->behave().getNext());

	}

	if (count[2]) {

		CarC* c = CFront;

		for (int i = 0; i++ < count[2]; c = c->behave().getNext());

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
