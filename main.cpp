#include "Classes.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;


int main(){
	int i, d;
	srand(time(nullptr));
	cout << "Type 1 for Stack, 2 for Queue, 3 for Array, 4 for List" << endl;
	cin >> i;
	switch(i){
		case 1:{
			cout <<"Type Stack's size... ";
			cin >>d;
			Stack <int> st(d);
			st.check();
			for(i=0; i<d; i++){
				st.push(i+1);
			}
			st.check();
			cout <<"Stack: ";
			for(i=0; i<12; i++){
				st.get();
				cout <<" ";
			}
			cout <<endl;
		};
		break;

		case 2:{
			cout <<"Type queue's size... ";
			cin >>d;
			Queue <int> que(d);
			que.check();
			for(i=0; i<d; i++){
				que.add(i+1);
			}
			que.check();
			for(i=0; i<d; i++){
				que.get();
			}
			cout <<"\n";
		};
		break;

		case 3:{
			cout <<"Type array's size... ";
			cin >>d;
			Array<int> arra(d);
			for(i=0; i<d; i++){
				arra[i]=i+1;
				}
			Array<int> B(d,1);
			for(i=0; i<d; i++){
				cout <<arra[i] <<" ";
			}
			cout <<"\n";
			arra.remove(5);
			d=arra.size();
			cout <<"remove [5]\n";
			for(i=0; i<d; i++){
				cout <<arra[i] <<" ";
			}
			cout <<"\n";
			arra.add(d);
			d=arra.size();
			cout <<"add(d)\n";
			for(i=0; i<d; i++){
				cout <<arra[i] <<" ";
			}
			cout <<"\n";
			d+=5;
			arra.resize(d);
			cout <<"resize(d+5)\n";
			for(i=0; i<d; i++){
				cout <<arra[i] <<" ";
			}
			cout <<"\n";
			arra.insert(4, 4);
			d=arra.size();
			cout <<"insert 4, 4\n";
			for(i=0; i<d; i++){
				cout <<arra[i] <<" ";
			}
			cout <<"\n";
			arra=B;
			d=arra.size();
			cout <<d <<endl;
			cout <<"присвоение знач-ия B\n";
			for(i=0; i<d; i++){
				cout <<arra[i] <<" ";
			}
			cout <<endl;
		}
		;break;

		case 4:{
			int ch, d, i;
			Spisok A(12);
			A.push_back(13);
		//	cout <<ch <<"\n";
			A.push_front(11);
		//	cout <<ch <<"\n";
			ch=A.getsize();
			cout <<"size " <<ch <<"\n";
			cout <<"put number of extended list... ";
			cin >>d;
			for(i=0; i<d; i++){
				A.push_back(random()%10+1);
			}
			A.print();
			ch=A.getsize();
			cout <<"size " <<ch <<"\n";
			A.insert(2, 1);
			A.print();
			A.reverse();
			A.print();
			A.pop_back();
			A.print();
			A.erase(1);
			ch=A.getsize();
			cout <<"size " <<ch <<"\n";
			A.print();
			A.pop_front();
			A.print();
		}
		;break;

		default: break;
	}
	return 0;
}
