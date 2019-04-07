#ifndef SORTER_H
#define SORTER_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>


//:::::::::::::::::::::::::::::
//              Stack         :
//:::::::::::::::::::::::::::::

template <class stacktype>
class Stack{
private:
	int size, last;
	stacktype *stack;
public:
	Stack(int count=15);
	~Stack();
	bool check();
	void push(stacktype element);
	stacktype get();
};

//:::::::::::::::::::::::::::::::::::
//				Queue				:
//:::::::::::::::::::::::::::::::::::

template <class Q>
class Queue{
public:
Queue(int max_n=15);
	~Queue();
	void add(Q x);
	Q get();
	bool check();
private:
	int i, j, n;
	Q *p;
};

//::::::::::::::::::::::::::::::::
//				Array			 :
//::::::::::::::::::::::::::::::::

template <class A>
class Array{
public:
	Array(int n=10);
	Array(int n, A Fill);
	~Array();
	Array &operator =(const Array &a);
	int &operator [](int index);
public:
	void add(A element);
	void insert(int index, A element);
	void remove(int index);
	void resize(int n);
	int size()const;
private:
	A *mem;
	int vol, max_vol;
};

//:::::::::::::::::::::::::::::::::::::
//				List				  :
//:::::::::::::::::::::::::::::::::::::

class Spisok{
private:
	int nodes;
	struct node{
		int obj;
		node *next;
	};
	node *begin;
	node *end;
public:
	Spisok();
	Spisok(int val);
	~Spisok();
	void insert(int iterator, int val);
	void push_back(int val);
	void push_front(int val);
	void erase(int iterator);
	int pop_front();
	int pop_back();
	int getsize();
	void reverse();
	void print();
};

//:::::::::::::::::::::::::::::::::::::::
//				Complex Number			:
//:::::::::::::::::::::::::::::::::::::::

class Complex{
private:
	double re, im;
public:
	Complex(){re=im=0;}
	Complex(double r){
		re=r;
		im=0;
	}
	Complex(double r, double i){
		re=r;
		im=i;
	}
	int operator ==(const Complex &)const;
	Complex& operator +=(const Complex &);
	Complex& operator -=(const Complex &);
	Complex& operator *=(const Complex &);
	Complex& operator /=(const Complex &);
	Complex operator +(const Complex &)const;
	Complex operator -(const Complex &)const;
	Complex operator *(const Complex &)const;
	Complex operator /(const Complex &)const;
	Complex operator -()const;
	double operator !()const{
		return sqrt(re*re+im*im);
	}
	void print(){
		std::cout << "\n" << re << "+i*" << im;
	}
	operator double(){return re;}
	operator char *();
};


#endif
