#pragma once
#include "Core.kano.h"
#include "WCD.kano.h"
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
	bool scoreCounted, removeSign;

	COORD prePos;

public:

	void setPosX(int x) { posX = x; };
	void setPosY(int y) { posY = y; };
	void setCarW(int w) { carW = w; };
	void setCarH(int h) { carH = h; };
	void setPrePos(int x, int y) { prePos.X = x; prePos.Y = y; };
	void count() { scoreCounted = true; };
	int getId() { return id; };
	int getPosX() { return posX; };
	int getPosY() { return posY; };
	int getCarH() { return carH; };
	int getCarW() { return carW; };
	int getOCarH() { return carOH; };
	int getOCarW() { return carOW; };
	bool isCounted() { return scoreCounted; };
	bool hasRemoveSign() { return removeSign; };
	COORD getPrePos() { return prePos; };
	bool decompose() { return !(--carH); };
	Car() {};
	Car(int x, int y, int w, int h) : id(regId()), scoreCounted(false), posX(x), posY(y), carW(w), carH(h), carOH(h), carOW(w), removeSign(false) { prePos.X = x; prePos.Y = y; };
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

		if (this->posY + this->carH + 2 > Setting::E->roadY && this->decompose())
			this->removeSign = true;
	
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
	CarB& behave() {

		this->posY += (getRand(3)) ? 1 : 0;
		
		if (this->posY + this->carH + 2 > Setting::E->roadY && this->decompose())
			this->removeSign = true;

		return *this;
	
	};
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

		if (this->posY + this->carH + 2 > Setting::E->roadY && this->decompose())
			this->removeSign = true;

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

	bool detAAOA(CarA* a) { return ((A != NULL && A != a) || B != NULL || C != NULL); };
	bool detAAOB(CarB* b) { return (A != NULL || (B != NULL && B != b) || C != NULL); };
	bool detAAOC(CarC* c) { return (A != NULL || B != NULL || (C != NULL && C != c)); };
	bool detect() { 

		if (A != NULL) {

			cout << "A(" << A->getId() << ")->";

		} else if (C != NULL) {

			cout << "C(" << C->getId() << ")->";

		} else if(B != NULL) {

			cout << "B(" << B->getId() << ")->";

		}

		return (A != NULL || B != NULL || C != NULL);

	};

	void setA(CarA* a) { A = a; };
	void setB(CarB* b) { B = b; };
	void setC(CarC* c) { C = c; };

	__Pixel() : A(NULL), B(NULL), C(NULL), Next(NULL) {};

};

class _Pixel {

	__Pixel* P[38][20]; // P[y][x]
	int C;

public:

	__Pixel& getPixel(int x, int y) { return *(P[y][x]); };

	__Pixel& setPixel(int x, int y, CarA* a) { P[y][x]->setA(a); return *(P[y][x]); };
	__Pixel& setPixel(int x, int y, CarB* b) { P[y][x]->setB(b); return *(P[y][x]); };
	__Pixel& setPixel(int x, int y, CarC* c) { P[y][x]->setC(c); return *(P[y][x]); };
	
	_Pixel(int x, int y) : C(x) {

		using std::endl;

		for (int i = 0; i++ < y;) {

			__Pixel *now;

			for (int j = 0; j++ < x; P[i - 1][j - 1] = now)
				now = new __Pixel;

		}

	};

	~_Pixel() {



	};

};

namespace Setting {

	static _Pixel* P;

}

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

	_Q& add(CarB* b, _Pixel& P) {

		int count = this->count[1]++;

		if (!count)
			BFront = b;

		b->setBefore(BRear);

		if (count)
			BRear->setNext(b);

		BRear = b;

		for (int j = 0; j++ < b->getCarH();)
			for (int k = 0; k++ < b->getCarW();)
				if (b->getPosY() + j - 1 >= 0)
					P.getPixel(b->getPosY() + j - 1, b->getPosX() + k - 1).B = b;

		return *this;

	};

	_Q& add(CarC* c, _Pixel& P) {

		int count = this->count[2]++;

		if (!count)
			CFront = c;

		c->setBefore(CRear);

		if (count)
			CRear->setNext(c);

		CRear = c;

		for (int j = 0; j++ < c->getCarH();)
			for (int k = 0; k++ < c->getCarW();)
				if (c->getPosY() + j - 1 >= 0)
					P.getPixel(c->getPosY() + j - 1, c->getPosX() + k - 1).C = c;

		return *this;

	};

	CarA* getAFront() { return AFront; };
	CarB* getBFront() { return BFront; };
	CarC* getCFront() { return CFront; };

	int* getCount() { return count; };

	inline _Q& randomInsert(_Pixel&);

	_Q() : AFront(NULL), ARear(NULL), BFront(NULL), BRear(NULL), CFront(NULL), CRear(NULL) { count[0] = 0; count[1] = 0, count[2] = 0; };

	inline _Q& behave(Setting::Env&, _Pixel&);

	inline _Q& remove(CarA *a);
	inline _Q& remove(CarB *b);
	inline _Q& remove(CarC *c);

};

_Q& _Q::remove(CarA* a) {

	if (a->getBefore() != NULL)
		a->getBefore()->setNext(a->getNext());

	if (a->getNext() != NULL)
		a->getNext()->setBefore(a->getBefore());

	if (a == this->AFront)
		this->AFront = a->getNext();
	if (a == this->ARear)
		this->ARear = a->getBefore();

	this->count[0]--;

	COORD LastLeft = { (((Setting::scrSize[0]) - (Setting::E->roadX)) / 4) - 2, 2 + Setting::E->roadY };

	COORD LastRight = { Setting::scrSize[0] - (((Setting::scrSize[0]) - (Setting::E->roadX)) / 4), 2 + Setting::E->roadY };

	COORD XY = { LastLeft.X + a->getPosX(), LastLeft.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

	for (int i = -1; i++ <= a->getCarW();)
		cout << "  ";

	/*for (int i = 0; i++ < a->getCarW();)
		for (int j = 0; j++ < a->getCarH();)
			if (Setting::P->getPixel(a->getPosX() + i * 2 + 5, a->getPosY() + j - 1).A == a)
				Setting::P->setPixel(a->getPosX() + i * 2 + 5, a->getPosY() + j - 1, (CarA*) NULL);
				*/


	Setting::setColor(15);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastLeft);
	cout << "бс";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "бс";
	Setting::setColor(7);

	delete a;

	return *this;

};

_Q& _Q::remove(CarB* b) {

	if (b->getBefore() != NULL)
		b->getBefore()->setNext(b->getNext());

	if (b->getNext() != NULL)
		b->getNext()->setBefore(b->getBefore());

	if (b == this->BFront)
		this->BFront = b->getNext();
	if (b == this->BRear)
		this->BRear = b->getBefore();

	this->count[1]--;

	COORD LastLeft = { (((Setting::scrSize[0]) - (Setting::E->roadX)) / 4) - 2, 2 + Setting::E->roadY };

	COORD LastRight = { Setting::scrSize[0] - (((Setting::scrSize[0]) - (Setting::E->roadX)) / 4), 2 + Setting::E->roadY };

	COORD XY = { LastLeft.X + b->getPosX(), LastLeft.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

	for (int i = -1; i++ <= b->getCarW();)
		cout << "  ";


	Setting::setColor(15);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastLeft);
	cout << "бс";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "бс";
	Setting::setColor(7);

	delete b;

	return *this;

};

_Q& _Q::remove(CarC* c) {

	if (c->getBefore() != NULL)
		c->getBefore()->setNext(c->getNext());

	if (c->getNext() != NULL)
		c->getNext()->setBefore(c->getBefore());

	if (c == this->CFront)
		this->CFront = c->getNext();
	if (c == this->CRear)
		this->CRear = c->getBefore();

	this->count[2]--;

	COORD LastLeft = { (((Setting::scrSize[0]) - (Setting::E->roadX)) / 4) - 2, 2 + Setting::E->roadY };

	COORD LastRight = { Setting::scrSize[0] - (((Setting::scrSize[0]) - (Setting::E->roadX)) / 4), 2 + Setting::E->roadY };

	COORD XY = { LastLeft.X + c->getPosX(), LastLeft.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);

	for (int i = -1; i++ <= c->getCarW();)
		cout << "  ";


	Setting::setColor(15);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastLeft);
	cout << "бс";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), LastRight);
	cout << "бс";
	Setting::setColor(7);

	delete c;

	return *this;

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
		add(b, P);
		break;

	case 9:
	case 5:
	case 2:
		c = new CarC((x = x - 3) - (x % 2));
		add(c, P);
		break;

	case 6:
		break;

	}

	return *this;

};

_Q& _Q::behave(Setting::Env& E, _Pixel& P) {

	bool breakSign = false;

	if (count[0]) {

		CarA *a = AFront, *tempA;

		for (int i = 0; i++ < count[0];) {

			if (a->behave().hasRemoveSign()) {

				tempA = a;

				a = a->getNext();

				this->remove(tempA);

			}
			else {

				for (int j = 0; j++ < a->getCarH() && !breakSign;)
					for (int k = 0; k++ < a->getCarW() && !breakSign;)
						if (a->getPosY() + j - 1 >= 0)
							if (P.getPixel(a->getPosX() + k * 2 + 5, a->getPosY() + j - 1).detAAOA(a)) {

								a->setPosX(a->getPrePos().X);
								a->setPosY(a->getPrePos().Y);

								breakSign = true;

							};

				//debc();

				if (!breakSign)
					for (int j = 0; j++ < a->getCarH();)
						for (int k = 0; k++ < a->getCarW();) {

							//debc();

							if (a->getPrePos().Y + j - 1 >= 0)
								P.getPixel(a->getPrePos().X + k * 2 + 5, a->getPrePos().Y + j - 1).A = NULL;
							if (a->getPosY() + j - 1 >= 0)
								P.getPixel(a->getPosX() + k * 2 + 5, a->getPosY() + j - 1).A = a;

							//debc();

							
							//COORD temp = { a->getPosX() + 2 * k + 5, a->getPosY() + j - 1 };
							//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
							//printf("%2d", a->getId());
							

						}
				else
					breakSign = false;

				//debc();

				a = a->getNext();

			}

		}

	}

	if (count[1]) {

		CarB *b = BFront, *tempB;

		for (int i = 0; i++ < count[1];) {

			if (b->behave().hasRemoveSign()) {

				tempB = b;

				b = b->getNext();

				this->remove(tempB);

			}
			else {

				for (int j = 0; j++ < b->getCarH() && !breakSign;)
					for (int k = 0; k++ < b->getCarW() && !breakSign;)
						if (b->getPosY() + j - 1 >= 0)
							if (P.getPixel(b->getPosX() + k * 2 + 5, b->getPosY() + j - 1).detAAOB(b)) {

								b->setPosX(b->getPrePos().X);
								b->setPosY(b->getPrePos().Y);

								breakSign = true;

							};

				if (!breakSign)
					for (int j = 0; j++ < b->getCarH();)
						for (int k = 0; k++ < b->getCarW();) {

							if (b->getPrePos().Y + j - 1 >= 0)
								P.getPixel(b->getPrePos().X + k * 2 + 5, b->getPrePos().Y + j - 1).B = NULL;
							if (b->getPosY() + j - 1 >= 0)
								P.getPixel(b->getPosX() + k * 2 + 5, b->getPosY() + j - 1).B = b;

						}
				else
					breakSign = false;

				b = b->getNext();

			}

		}

	}

	if (count[2]) {

		CarC *c = CFront, *tempC;

		for (int i = 0; i++ < count[2];) {

			if (c->behave().hasRemoveSign()) {

				tempC = c;

				c = c->getNext();

				this->remove(tempC);

			}
			else {

				for (int j = 0; j++ < c->getCarH() && !breakSign;)
					for (int k = 0; k++ < c->getCarW() && !breakSign;)
						if (c->getPosY() + j - 1 >= 0)
							if (P.getPixel(c->getPosX() + k * 2 + 5, c->getPosY() + j - 1).detAAOC(c)) {

								c->setPosX(c->getPrePos().X);
								c->setPosY(c->getPrePos().Y);

								breakSign = true;

							};

				if (!breakSign)
					for (int j = 0; j++ < c->getCarH();)
						for (int k = 0; k++ < c->getCarW();) {

							if (c->getPrePos().Y + j - 1 >= 0)
								P.getPixel(c->getPrePos().X + 2 * k + 5, c->getPrePos().Y + j - 1).C = NULL;
							if (c->getPosY() + j + - 1 >= 0)
								P.getPixel(c->getPosX() + 2 * k + 5, c->getPosY() + j - 1).C = c;

						}
				else
					breakSign = false;

				c = c->getNext();

			}

		}

	}

	return *this;

};

class _M : virtual public CarA, virtual public CarB {

	int Colour;

public:

	void setColor(int c) { Colour = c; };
	int getColor() { return Colour; };
	int* getPos() { static int x[2] = { 0, 0 }; x[0] = this->getPosX(); x[1] = this->getPosY(); return x; };
	_M(int posX, int posY, int c) : Colour(c) { this->setPosX(posX); this->setPosY(posY); };
	~_M() {};

};
