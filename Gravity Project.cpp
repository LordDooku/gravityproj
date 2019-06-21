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
using namespace std;

double fRand(double fMin, double fMax) // Methode zum Generieren von zufälligen double numbers
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


class mass // Die Klasse der Massenobjekte
{
public:
	double vx;		// Geschwindigkeit in x-Richtung
	double vy;		// Geschwindigkeit in y-Richtung
	double r; 		// Radius
	double beginx; 	// x-Koordinate der Anfangsposition
	double beginy;	// y-Koordinate der Anfangsposition
	double m;		// Masse

	static void create(int n); // Creates n Massenobjekte mit Anfangsbedingungen

};


void mass::create(int n){

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
	}


double Abs(){ //zum Abstand berechnen
	int n2 = n;
	double xAbs[n-1]; // Array mit n-1 Abstanden in x-Richtung
	double yAbs[n-1];
 for(int j=0; j < n-1; j++){
	 Abs[j] = masses[j].beginx - masses[j+1].beginx;
 }
}




int main() {

	int n;  //n ist die Anzahl der Massenobjekte
	cout << "Bitte gebe die gewünschte Anzahl der Massenobjekte ein." << endl;
	cin >> n;

	mass::create(n);  // Jetzt werden n Massen erzeugt






	return 0;
}
