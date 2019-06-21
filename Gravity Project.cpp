//============================================================================
// Name        : Gravity.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include <cmath>
#include <random>
using namespace std;




class mass // Die Klasse der Massenobjekte
{
public:
	double vx;		// Geschwindigkeit in x-Richtung
	double vy;		// Geschwindigkeit in y-Richtung
	double r; 		// Radius
	double beginx; 	// x-Koordinate der Anfangsposition
	double beginy;	// y-Koordinate der Anfangsposition
	double m;		// Masse

};

double Pos()
{

}

double fRand(double fMin, double fMax) // Methode zum Generieren von zufälligen double numbers
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main() {

	int n;  //n ist die Anzahl der Massenobjekte
	cout << "Bitte gebe die gewünschte Anzahl der Massenobjekte ein." << endl;
	cin >> n;
	mass masses[n]; //Array mit n Massen
	double sunmass = 1988000000;
	double newsunmass = 1000000 * sunmass;
	double supernewsunmass = 1000000 * newsunmass;

	for(int i=0; i< n; i++){
		masses [i].vx = fRand(0, 1000000);
		masses [i].vy = fRand(0, 1000000);
		masses [i].beginx = fRand(0, 3000000000000);
		masses [i].beginy = fRand(0, 3000000000000);
		masses [i].m = fRand(newsunmass, supernewsunmass);
	}


	/*cout << "Bitte gebe zuerst die Anfangsposition von m1 als Vektor an, dann die von m2." << endl;

	  cin >>  m1.beginx;
	  cin >>  m1.beginy;


	  cin >>  m2.beginx;
	  cin >>  m2.beginy;


	cout << "Bitte gebe nun die Anfangsgeschwindigkeit von m1 als Vektor an, dann die von m2." << endl;

	  cin >>  m1.vx;
	  cin >>  m1.vy;

	  cin >>  m2.vx;
	  cin >>  m2.vy;



	cout << "Bitte gebe nun die Masse von m1 und dann von m2 an" << endl;

	  cin >>  m1.m;
	  cin >>  m2.m;

	cout << "Bitte gebe nun den Radius von m1 an, dann den von m2" << endl;

	  cin >>  m1.r;
	  cin >>  m2.r;
*/




	return 0;
}
