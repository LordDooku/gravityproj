//============================================================================
// Name        : Gravity.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <cmath>

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

double G = 6.067e-11;
int t;  // t ist die Anzahl der Zeiteinheiten

int n ;

cout << "Bitte gebe die gewuenschte Anzahl der Massenobjekte ein." << endl;
cin >> n;
cout << "Bitte gebe nun die gewuenschte Anzahl von Zeiteinheiten ein." << endl;
cin >> t;

double u, r; // nur Hilfsvariablen
double xAbs[n]; // Array mit n-1 Abstanden in x-Richtung
double yAbs[n];
double UpxAbs [n][n]; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
double UpyAbs [n][n];


double Fx[n]; // Kraft in x-Richtung
double Fy[n]; // Kraft in y-Richtung
double UpFx[n][n];
double UpFy[n][n];
double GesFx[n]; // GEsamtkraft in x-Richtung
double GesFy[n];

double posx [n];// neue Positionen
double posy [n];

double nvx[n];
double nvy[n];






// creates masses
	mass masses[n]; //Array mit n Massen

				for(int i=0; i< n; i++){
					masses[i].beginx = 1e3 * i * i;
					masses[i].beginy = 5e3 * i + 33 *i * i;
					masses[i].vx = 10 * i;
					masses[i].vy = 5 * i - 3;
					masses[i].m = 15 * i;
				}

for(int j = 0; j<n; j++){
	 xAbs[j] =0; // Array mit n-1 Abstanden in x-Richtung
	 yAbs[j]=0;
	 Fx[j]=0; // Kraft in x-Richtung
	 Fy[j]=0; // Kraft in y-Richtung
	 posx[j]=0;// neue Positionen
	 posy[j]=0;
	 nvx[j]=0;
	 nvy[j]=0;
	 GesFx[j]=0; // GEsamtkraft in x-Richtung
	 GesFy[j]=0;
	 for(int i = 0; i<n; i++){
		  UpxAbs [j][i]=0; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
		  UpyAbs [j][i]=0;
		  UpFx[j][i]=0;
		  UpFy[j][i]=0;

	 }
}


//Begin
for(int j = 0; j<t; j++){


//Abstand
for(int j = 0; j<n; j++){
	for(int i = 0; i < n; i++){
		xAbs[i] = masses[i].beginx - masses[j].beginx;
		yAbs[i] = masses[i].beginy - masses[j].beginy;
		UpxAbs[i][j] = xAbs[i];
		UpyAbs[i][j] = yAbs[i];
	}
}

//Kraft Komponenten
for(int j = 0; j<n; j++){
	for(int i = 0; i < n; i++){
		Fx[i] =( masses[i].m * masses[j].m * G * UpxAbs[i][j] )/ (sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]) *
				sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]) * sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]));

		Fy[i] =( masses[i].m * masses[j].m * G * UpyAbs[i][j] )/ (sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]) *
						sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]) * sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]));

		UpFx[i][j] = Fx[i];
		UpFy[i][j] = Fy[i];
	}
}


//Absolute Kraft
for(int j = 0; j<n; j++){
	GesFx[j] = 0;
	GesFy[j] = 0;
	r = 0;
	u = 0;
	for(int i = 0; i<n; i++){
		GesFx[j] = u + UpFx[j][i]; //Falls was falschlaeuft hier i und j tauschen (und fuer y-Komponente)
		u = GesFx[j];
		GesFy[j] = r + UpFy[j][i];
		r=GesFy[j];
	}
}

//new positions
	for(int i = 0; i<n; i++){
		posx[i] = masses[i].beginx + (masses[i].vx + (GesFx[i] / masses[i].m));
		posy[i] = masses[i].beginy + (masses[i].vy + (GesFy[i] / masses[i].m));
		cout << "(" << posx[i] << "," << posy[i] << ")" << endl;
		masses[i].beginx = posx[i];
		masses[i].beginy = posy[i];
		nvx[i] = masses[i].vx;
		nvy[i] = masses[i].vy;
		masses[i].vx = nvx[i] + (GesFx[i] / masses[i].m);
		masses[i].vy = nvy[i] + (GesFy[i] / masses[i].m);
	}

}





return 0;
}


