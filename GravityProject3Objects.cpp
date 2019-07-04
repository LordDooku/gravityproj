//============================================================================
// Name        : Gravity.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


//============================================================================
// Name        : Gravity.cpp
// Author      : Daniel K. Biao Adza & Roswaldas Snaras
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cmath>
#include <random>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

double fRand(double fMin, double fMax) // Methode zum Generieren von zuf�lligen double numbers
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


class mass // Die Klasse der Massenobjekte
{
public:
	double vx;		// Geschwindigkeit in x-Richtung
	double vy;		// Geschwindigkeit in y-Richtung
	double beginx; 	// x-Koordinate der Anfangsposition
	double beginy;	// y-Koordinate der Anfangsposition
	double m;		// Masse



};











int main() {


	int t;  // t ist die Anzahl der Zeiteinheiten
	double xpos1 =0;// neue Positionen in x
	double xpos2 =0;
	double xpos3 =0;
	double ypos1 =0;// neue Positionen in y
	double ypos2 =0;
	double ypos3 =0;

	cout << "Bitte gebe nun die gewuenschte Anzahl von Zeiteinheiten ein." << endl;
	cin >> t;

// creates masses

	mass m1, m2, m3;
	double G = 6.67e-11;

	m1.beginx = 0;
	m1.beginy = 0;
	m1.vx = 0;
	m1.vy = 0;
	m1.m = 2e30;

	m2.beginx = 1.5e8;
	m2.beginy = 10;
	m2.vx = 0;
	m2.vy = 30000;
	m2.m = 5.97e24;

	m3.beginx = 1e7;
	m3.beginy = 1e8;
	m3.vx = 0;
	m3.vy = 2100;
	m3.m = 4.867e24;



	//Abstand

	double xAbs12 = 0;
	double xAbs13 = 0;
	double xAbs23 = 0;
	double xAbs21 = 0;
	double xAbs31 = 0;
	double xAbs32 = 0;

	double yAbs12 = 0;
	double yAbs13 = 0;
	double yAbs23 = 0;
	double yAbs21 = 0;
	double yAbs31 = 0;
	double yAbs32 = 0;


	//Kraft

	double xF12 = 0;
	double xF13 = 0;
	double xF23 = 0;
	double xF21 = 0;
	double xF31 = 0;
	double xF32 = 0;

	double yF12 = 0;
	double yF13 = 0;
	double yF23 = 0;
	double yF21 = 0;
	double yF31 = 0;
	double yF32 = 0;

	double xF1 = 0;
	double xF2 = 0;
	double xF3 = 0;

	double yF1 = 0;
	double yF2 = 0;
	double yF3 = 0;





















 xAbs12 = m2.beginx - m1.beginx;
 xAbs13 = m3.beginx - m1.beginx;
 xAbs23 = m3.beginx - m2.beginx;
 xAbs21 = m1.beginx - m2.beginx;
 xAbs31 = m1.beginx - m3.beginx;
 xAbs32 = m2.beginx - m3.beginx;

 yAbs12 = m2.beginy - m1.beginy;
 yAbs13 = m3.beginy - m1.beginy;
 yAbs23 = m3.beginy - m2.beginy;
 yAbs21 = m2.beginy - m1.beginy;
 yAbs31 = m1.beginy - m3.beginy;
 yAbs32 = m2.beginy - m3.beginy;


//Kraft

 xF12 = (G * m1.m * m2.m* (xAbs12)/sqrt(xAbs12 * xAbs12 + yAbs12 * yAbs12))/sqrt(xAbs12 * xAbs12 + yAbs12 * yAbs12);
 xF13 = (G * m1.m * m3.m* (xAbs13)/sqrt(xAbs13 * xAbs13 + yAbs13 * yAbs13))/sqrt(xAbs13 * xAbs13 + yAbs13 * yAbs13);
 xF23 = (G * m2.m * m3.m* (xAbs23)/sqrt(xAbs23 * xAbs23 + yAbs23 * yAbs23))/sqrt(xAbs23 * xAbs23 + yAbs23 * yAbs23);
 xF21 = (G * m2.m * m1.m* (xAbs21)/sqrt(xAbs21 * xAbs21 + yAbs21 * yAbs21))/sqrt(xAbs21 * xAbs21 + yAbs21 * yAbs21);
 xF31 = (G * m3.m * m1.m* (xAbs31)/sqrt(xAbs31 * xAbs31 + yAbs31 * yAbs31))/sqrt(xAbs31 * xAbs31 + yAbs31 * yAbs31);
 xF32 = (G * m3.m * m2.m* (xAbs32)/sqrt(xAbs32 * xAbs32 + yAbs32 * yAbs32))/sqrt(xAbs32 * xAbs32 + yAbs32 * yAbs32);

 yF12 = (G * m1.m * m2.m* (yAbs12)/sqrt(xAbs12 * xAbs12 + yAbs12 * yAbs12))/sqrt(xAbs12 * xAbs12 + yAbs12 * yAbs12);
 yF13 = (G * m1.m * m3.m* (yAbs13)/sqrt(xAbs13 * xAbs13 + yAbs13 * yAbs13))/sqrt(xAbs13 * xAbs13 + yAbs13 * yAbs13);
 yF23 = (G * m2.m * m3.m* (yAbs23)/sqrt(xAbs23 * xAbs23 + yAbs23 * yAbs23))/sqrt(xAbs23 * xAbs23 + yAbs23 * yAbs23);
 yF21 = (G * m2.m * m1.m* (yAbs21)/sqrt(xAbs21 * xAbs21 + yAbs21 * yAbs21))/sqrt(xAbs21 * xAbs21 + yAbs21 * yAbs21);
 yF31 = (G * m3.m * m1.m* (yAbs31)/sqrt(xAbs31 * xAbs31 + yAbs31 * yAbs31))/sqrt(xAbs31 * xAbs31 + yAbs31 * yAbs31);
 yF32 = (G * m3.m * m2.m* (yAbs32)/sqrt(xAbs32 * xAbs32 + yAbs32 * yAbs32))/sqrt(xAbs32 * xAbs32 + yAbs32 * yAbs32);

 xF1 = xF12 + xF13;
 xF2 = xF21 + xF23;
 xF3 = xF31 + xF32;

 yF1 = yF12 + yF13;
 yF2 = yF21 + yF23;
 yF3 = yF31 + yF32;

for(int i = 0; i<t; i++){



xpos1 = m1.beginx + (m1.vx + (xF1 / m1.m));
xpos2 = m2.beginx + (m2.vx + (xF2 / m2.m));
xpos3 = m3.beginx + (m3.vx + (xF3 / m3.m));

ypos1 = m1.beginy + (m1.vy + (xF1 / m1.m));
ypos2 = m2.beginy + (m2.vy + (xF2 / m2.m));
ypos3 = m3.beginy + (m3.vy + (xF3 / m3.m));
cout << "(" << xpos1 << "," << ypos1 << ")" << endl;
cout << "(" << xpos2 << "," << ypos2 << ")" << endl;
cout << "(" << xpos3 << "," << ypos3 << ")" << endl;
m1.beginx = xpos1;
m2.beginx = xpos2;
m3.beginx = xpos3;
m1.beginy = ypos1;
m2.beginy = ypos2;
m3.beginy = ypos3;
double nvx1 = m1.vx;
double nvx2 = m2.vx;
double nvx3 = m3.vx;

double nvy1 = m1.vy;
double nvy2 = m2.vy;
double nvy3 = m3.vy;

m1.vx = nvx1 + (xF1 / m1.m);
m2.vx = nvx2 + (xF2 / m2.m);
m3.vx = nvx3 + (xF3 / m3.m);
m1.vy = nvy1 + (yF1 / m1.m);
m2.vy = nvy2 + (yF2 / m2.m);
m3.vy = nvy3 + (yF3 / m3.m);

 nvx1 = m1.vx;
 nvx2 = m2.vx;
 nvx3 = m3.vx;

 nvy1 = m1.vy;
 nvy2 = m2.vy;
 nvy3 = m3.vy;


}


	return 0;
}
