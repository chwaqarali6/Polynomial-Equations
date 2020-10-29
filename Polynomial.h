#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;

class Polynomial{
private:
	struct Term{
		int coeff;
		int deg;
	};
	struct Node{
		Term t;
		Node *next;
	};
	Node *start, *end;
	int size;
	Node *createNode(const Term &d)
	{
		Node *temp=new Node;
		temp->t=d;
		temp->next=NULL;
		return temp;
	}

public:
	Polynomial();
	Polynomial(char*);
	Polynomial(const Polynomial &obj);
	void addAtStart(const Term &d);
	void addAtEnd(const Term &d);
	Polynomial operator=(const Polynomial &obj);
	Polynomial operator+(const Polynomial &obj);
	Polynomial operator+(const int);
	Polynomial operator-(const Polynomial &obj);
	Polynomial operator-(const int);
	Polynomial operator*(const Polynomial &obj);
	Polynomial operator*(const int);
	const Polynomial& operator++();
	Polynomial operator++(int);
	bool operator==(const Polynomial &obj);
	const Polynomial& operator-();

	double evaluate(int);
	void clear();
	Polynomial derivate();
	int maxima(int,int);
	int minima(int,int);
	void deleteNegativeTerms(int);
	int whichX(int);

	friend ostream& operator<<(ostream &out,const Polynomial &obj);
	friend void operator>>(istream &in,Polynomial &obj);
	friend Polynomial operator*(const int num,const Polynomial &obj);
	friend Polynomial operator+(const int num,Polynomial &obj);
	friend Polynomial operator-(const int num,Polynomial &obj);
	~Polynomial();

};