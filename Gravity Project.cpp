//============================================================================
// Name        : Gravity.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std; 




class mass
{
public:
	vector3d v;
	double r;
	vector3d begin;
	double m;

};


int main() {

	mass m1, m2;

	cout << "Bitte gebe zuerst die Anfangsposition von m1 als Vektor an, dann die von m2." << endl;

	  cin >>  m1.begin.x;
	  cin >>  m1.begin.y;
	  cin >>  m1.begin.z;

	  cin >>  m2.begin.x;
	  cin >>  m2.begin.y;
	  cin >>  m2.begin.z;

	cout << "Bitte gebe nun die Anfangsgeschwindigkeit von m1 als Vektor an, dann die von m2." << endl;

	  cin >>  m1.v.x;
	  cin >>  m1.v.y;
	  cin >>  m1.v.z;

	  cin >>  m2.v.x;
	  cin >>  m2.v.y;
	  cin >>  m2.v.z;


	cout << "Bitte gebe nun die Masse von m1 und dann von m2 an" << endl;

	  cin >>  m1.m;
	  cin >>  m2.m;

	cout << "Bitte gebe nun den Radius von m1 an, dann den von m2" << endl;

	  cin >>  m1.r;
	  cin >>  m2.r;





	return 0;
}
