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

	static void create(int n); // Creates n Massenobjekte mit random Anfangsbedingungen

};


void mass::create( int n){

		mass masses[n]; //Array mit n Massen
		double sunmass = 1988000000;
		double newsunmass = 1000000 * sunmass;
		double supernewsunmass = 1000000 * newsunmass;
		double AbsAbs [n];
			for(int i=0; i< n; i++){
				masses [i].vx = fRand(0, 1000000);
				masses [i].vy = fRand(0, 1000000);
				masses [i].beginx = fRand(0, 3000000000000);
				masses [i].beginy = fRand(0, 3000000000000);
				masses [i].m = fRand(newsunmass, supernewsunmass);
			}
	}


double Abs(int n, mass masses[]){ //zum Abstand berechnen

	double xAbs[n-1]; // Array mit n-1 Abstanden in x-Richtung
	double yAbs[n-1];
	double UpxAbs [n][n]; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
	double UpyAbs [n][n];
	double AbsAbs [n];
	double AbsAbsfinal [n][n]; // Array aus Arrays mit den Beträgen der Abstände
	for(int j = 0  ;j < n; j++){


		for(int k=j; k< n; k++){


		 xAbs [k] = masses[k+1].beginx - masses[j].beginx;
		 yAbs [k] = masses[k+1].beginy - masses[j].beginy;
		 double x = xAbs [k];
		 double y = yAbs [k];
		 AbsAbs [k] = sqrt(x * x + y * y);
		}
	 UpxAbs [j][j-1] = xAbs[j];
	 UpyAbs [j][j-1] = yAbs[j];
	 AbsAbsfinal [j][j-1] = AbsAbs[j];
}

	return AbsAbsfinal[n][n];

}



int main() {

	int n;  //n ist die Anzahl der Massenobjekte
	cout << "Bitte gebe die gewünschte Anzahl der Massenobjekte ein." << endl;
	cin >> n;

	mass::create(n);  // Jetzt werden n Massen erzeugt
	double Abs(n);





	return 0;
}
