
#include "Classes.h"
#include <iostream>

//:::::::::::::::::::::::::::::
//				Stack		  :
//:::::::::::::::::::::::::::::

template <class stacktype>
Stack<stacktype>::Stack(int count){
  size=count;
  stack=new stacktype[size];
  last=0;
}

template <class stacktype>
Stack<stacktype>::~Stack(){delete[]stack;}

template <class stacktype>
bool Stack<stacktype>::check(){
  if(last==size) std::cout <<"Stack is full" <<"\n";
  else std::cout <<"Alright, maaan" <<"\n";
  return last==size;
}

template <class stacktype>
void Stack<stacktype>::push(stacktype element){
  if(last==size){
   std::cout << "Stack is full\n";
  }
  stack[last]=element;
  ++last;
}

template <class stacktype>
stacktype Stack<stacktype>::get(){
  stacktype ch;
  if(last==0) std::cout << "Stack is empty\n";
  else{
   std::cout <<stack[last];
   ch=stack[last];
   --last;
  }
  return ch;
}

//:::::::::::::::::::::::::::::::::::
//				Queue				:
//:::::::::::::::::::::::::::::::::::


template <class Q>
Queue<Q>::Queue(int max_n){
  p=new int[max_n];
  n=max_n;
  i=j=0;
}

template <class Q>
Queue<Q>::~Queue() {delete[]p;}

template <class Q>
void Queue<Q>::add(Q x){
  if(j<n){
   p[j]=x;
   j++;
  }
  else if(j==n&&i==n){
   i=j=0;
   this->add(x);
  } else std:: cout << "Queue line is Full\n";
}

template <class Q>
Q Queue<Q>::get(){
  Q ch;
  ch=p[i];
  std::cout << p[i] << " ";
  i++;
  return ch;
}

template <class Q>
bool Queue<Q>::check(){
  if(n==j) std::cout <<"Queue is full" <<std::endl;
  else std::cout <<"Alright, maaan" <<"\n";
  return n==j;
}

//::::::::::::::::::::::::::::::::
//				Array			 :
//::::::::::::::::::::::::::::::::

template <class A>
Array<A>::Array(int n){
  vol=n;
  max_vol=vol+3;
  mem=new int[max_vol];
}

template <class A>
Array<A>::Array(int n, A Fill){
  int i;
  vol=n;
  max_vol=vol+3;
  mem=new int[max_vol];
  for(i=0; i<vol; i++) mem[i]=Fill;
}

template <class A>
Array<A>::~Array() {delete []mem;}


template <class A>
Array<A> &Array<A>::operator =(const Array<A> &a){
  int i;
  if(this==&a) return *this;
  delete []mem;
  vol=a.vol;
  max_vol=a.max_vol;
  mem=new int[max_vol];
  for(i=0; i<vol; i++) mem[i]=a.mem[i];
  return *this;
}

template <class A>
int &Array<A>::operator[](int index){
  if((0<=index)&&(index<vol)) return mem[index];
  exit(1);
}

template <class A>
void Array<A>::add(A element){
  int i;
  if(vol!=max_vol){
   i=vol;
   ++vol;
   mem[i]=element;
  }
  else{
   max_vol+=10;
   A *t=new A[max_vol];
   for(i=0; i<vol; i++) t[i]=mem[i];
   delete []mem;
   mem=t;
   ++vol;
   mem[vol-1]=element;
  }
}

template <class A>
void Array<A>::insert(int index, A element){    ///
  int i;
  if(vol!=max_vol){
   ++vol;
  for(i=vol-1; i>index; i--) mem[i]=mem[i-1];
  mem[i]=element;
  }
  else{
   max_vol+=10;
   A *t=new A[max_vol];
   for(i=0; i<index; i++) t[i]=mem[i];
   t[i]=element;
   ++vol;
   for(++i;i<vol; i++) t[i]=mem[i-1];
   delete []mem;
   mem=t;
  }
}

template <class A>
void Array<A>::remove(int index){       ///index=0
  int i=index;
  if((i<0)||(i>vol)){
   puts("error index is out of range"); exit(1);
  }
  while(i!=vol){
   mem[i]=mem[i+1];
   i++;
  }
  --vol;
}

template <class A>
void Array<A>::resize(int n){         ////vol
  if(n<=max_vol) vol=n;
  if(n>max_vol){
   max_vol=n+10;
   A *t=new A[max_vol];
   for(int i=0; i<vol; i++) t[i]=mem[i];
   vol=n;
   delete []mem;
   mem=t;
  }
}

template <class A>
int Array<A>::size()const{
  return vol;
}

//:::::::::::::::::::::::::::::::::::::
//				List				  :
//:::::::::::::::::::::::::::::::::::::

Spisok::Spisok(){
  nodes=0;
  end=begin=nullptr;
}

Spisok::Spisok(int val){
  nodes=1;
  node *cur=new node;
  cur->obj=val;
  cur->next=nullptr;
  begin=cur;
  end=cur;
}

Spisok::~Spisok(){
  node *cur;
  cur=begin;
  node *todel;
  while(cur){
   todel=cur;
   cur=cur->next;
   delete todel;
  }
}
void Spisok::insert(int iterator, int val){     ///проверка на
  if(iterator>nodes){                           ///nullptr
   puts("Iterator is larger than can be.");     ///index=0
   exit(1);
  }
  int i=0;
  node *cur;
  cur=begin;
  node *temp=new node;
  temp->obj=val;
  if(iterator==0){
   temp->next=begin;
   if(nodes==0) end=begin;
   else begin=temp;
  }
  else if(iterator==nodes){
   end->next=temp;
   end=temp;
  }
  else{
   while(iterator-1!=i){
    i++;
    cur=cur->next;
   }
   temp->next=cur->next;
   cur->next=temp;
  }
  nodes++;
}
void Spisok::push_back(int val){      //nullptr
  node *cur=new node;
  cur->obj=val;
  cur->next=nullptr;
  if(nodes==0) begin=end=cur;
  else{
   end->next=cur;
   end=cur;
  }
  nodes++;
}
void Spisok::push_front(int val){      //nullptr
  node *cur=new node;
  cur->obj=val;
  cur->next=begin;
  begin=cur;
  if(nodes==0) end=cur;
  nodes++;
}

void Spisok::erase(int iterator){
  if(iterator>nodes-1){
   puts("iterator is larger than number of nodes.");
   exit(1);
  }
  int i=0;
  node *cur, *tmp;
  cur=begin;
  while(i<iterator){
   tmp=cur;
   cur=cur->next;
   i++;
  }
  if(i==0){
   if(begin!=end) begin=begin->next;
   else{
    begin=end=nullptr;
    std::cout <<"List is Empty" <<"\n";
   }
   delete cur;
  }
  else if(i==nodes-1){                  //nodes-1
   end=cur;
   delete cur->next;
   end->next=nullptr;
  }
  else{
   tmp->next=cur->next;
   delete cur;
  }
  nodes--;
}

int Spisok::pop_front(){
  int tmp;
  node *cur;
  if(nodes==0){
   puts("ERROR. List is empty");
   exit(1);                         //return;
  }
  cur=begin;
  std::cout<<cur->obj<<"\n";
  tmp=cur->obj;
  if(begin!=end) begin=cur->next;
  else{
   begin=end=nullptr;
   std::cout <<"It was last element. Now list is Empty." <<"\n";
  }
  nodes--;
  delete cur;
  return tmp;
}

int Spisok::pop_back(){
  node *cur;
  int tmp;
  if(nodes==0){
   puts("ERROR. List is empty");
   exit(1);                         //return;
  }
  cur=begin;
  if(nodes==1){
   std::cout <<cur->obj <<"\n";
   tmp=cur->obj;
   delete cur;
   begin=end=nullptr;
   std::cout <<"It was last element. Now list is Empty." <<"\n";
   return tmp;
  }
  while(cur->next->next){
   cur=cur->next;
  }
  std::cout<<cur->next->obj<<"\n";
  tmp=cur->next->obj;
  end=cur;
  delete cur->next;
  end->next=nullptr;
  nodes--;
  return tmp;
}

int Spisok::getsize(){
  return nodes;
}

void Spisok::reverse(){
  if(nodes!=0&&nodes!=1){
   node *one;
   node *two;
   node *three;
   one=begin;
   begin=end;
   end=one;
   two=one->next;
   end->next=nullptr;
   three=two->next;
   while(two){
    two->next=one;
    one=two;
    two=three;
    if(three) three=three->next;
   }
  }
}

void Spisok::print(){
  node *cur;
  cur=begin;
  while(cur){
   std::cout<<cur->obj<<" ";
   cur=cur->next;
  }
  std::cout<<"\n";
}


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
int Complex::operator ==(const Complex &c)const{
  if(re==c.re&&im==c.im) return 1;
  return 0;
}
Complex &Complex::operator +=(const Complex &c){
  re+=c.re;
  im+=c.im;
  return *this;
}
Complex &Complex::operator -=(const Complex &c){
  re-=c.re;
  im-=c.im;
  return *this;
}
Complex &Complex::operator *=(const Complex &c){
  Complex tmp;
  tmp.re=re*c.re-im*c.im;
  tmp.im=im*c.re+re*c.im;
  *this=tmp;
  return *this;
}
Complex &Complex::operator /=(const Complex &c){
  Complex tmp;
  double a;
  a=c.re*c.re+c.im*c.im;
  if(a==0){
   std::cout << "\ndevide 0!";
   exit(1);
  }
  tmp.re=(re*c.re+im*c.im)/a;
  tmp.im=(im*c.re-re*c.im)/a;
  *this=tmp;
  return *this;
}
Complex Complex::operator +(const Complex &c)const{
  Complex tmp;
  tmp.re=re+c.re;
  tmp.im=im+c.im;
  return tmp;
}
Complex Complex::operator *(const Complex &c)const{
  Complex tmp;
  tmp.re=re*c.re-im*c.im;
  tmp.im=im*c.re+re*c.im;
  return tmp;
}
Complex Complex::operator /(const Complex &c)const{
  Complex tmp;
  double a;
  a=c.re*c.re+c.im*c.im;
  if(a==0){
   std::cout << "\n devide 0!";
   getchar();
   exit(1);
  }
  tmp.re=(re*c.re+im*c.im)/a;
  tmp.im=(im*c.re-re*c.im)/a;
  return tmp;
}
Complex Complex::operator -(const Complex &c)const{
  Complex tmp;
  tmp.re=re-c.re;
  tmp.im=im-c.im;
  return tmp;
}
Complex Complex::operator -()const{
  Complex tmp;
  tmp.re=-re;
  tmp.im=-im;
  return tmp;
}
Complex::operator char *(){
  char *s=new char[15], ss[10];
  sprintf(s,"%5.2f", re);
  if(im>0)strcat(s, "+");
  else if(im<0) strcat(s, "-");
  if(!im){
   sprintf(ss, "%5.2f", fabs(im));
   strcat(s, ss);
   strcat(s, "*i");
  }
  return s;
}
