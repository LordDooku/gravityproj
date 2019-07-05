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

#include <fstream>

class mass // Die Klasse der Massenobjekte
{
public:
	double vx;		// Geschwindigkeit in x-Richtung
	double vy;		// Geschwindigkeit in y-Richtung
	double vz;
	double beginx; 	// x-Koordinate der Anfangsposition
	double beginy;	// y-Koordinate der Anfangsposition
	double beginz;
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

double u, r, l; // nur Hilfsvariablen
double xAbs[n+1]; // Array mit n-1 Abstanden in x-Richtung
double yAbs[n+1];
double zAbs[n+1];

double UpxAbs [n+1][n+1]; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
double UpyAbs [n+1][n+1];
double UpzAbs [n+1][n+1];


double Fx[n+1]; // Kraft in x-Richtung
double Fy[n+1]; // Kraft in y-Richtung
double Fz[n+1];
double UpFx[n+1][n+1];
double UpFy[n+1][n+1];
double UpFz[n+1][n+1];
double GesFx[n+1]; // GEsamtkraft in x-Richtung
double GesFy[n+1];
double GesFz[n];

double posx [n+1];// neue Positionen
double posy [n+1];
double posz [n+1];

double nvx[n+1]; // nur Hilfsarrays
double nvy[n+1];
double nvz[n+1];





// creates masses
	mass masses[n+1]; //Array mit n Massen

				for(int i=1; i< n+1; i++){
					masses[i].beginx = 5 * i;
					masses[i].beginy = 12 * i + 33 *i * i;
					masses[i].beginz = 14 * i + 60 *i;
					masses[i].vx = 10 * i;
					masses[i].vy = 5 * i - 3;
					masses[i].vz = 6 * i;
					masses[i].m = 15 * i;
				}

FILE* fs;
fs = fopen("GravityProject.txt","w");
//Begin
for(int j = 0; j<t; j++){


//Abstand
for(int j = 1; j<n+1; j++){
	for(int i = 1; i < n+1; i++){
		xAbs[i] = masses[i].beginx - masses[j].beginx;
		yAbs[i] = masses[i].beginy - masses[j].beginy;
		zAbs[i] = masses[i].beginz - masses[j].beginz;
		UpxAbs[i][j] = xAbs[i];
		UpyAbs[i][j] = yAbs[i];
		UpzAbs[i][j] = zAbs[i];
	}
}



//Kraft Komponenten
for(int j = 1; j<n+1; j++){
	for(int i = 1; i < n+1; i++){
		Fx[i] =( masses[i].m * masses[j].m * G * UpxAbs[i][j] ) /
				(sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j]) *
				 sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j]) *
				 sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j]));

		Fy[i] =( masses[i].m * masses[j].m * G * UpyAbs[i][j] ) /
				(sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j]) *
				 sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j]) *
				 sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j]));


		Fz[i] =( masses[i].m * masses[j].m * G * UpzAbs[i][j] ) /
				(sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j]+ UpzAbs[i][j] * UpzAbs[i][j] ) *
				 sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j] ) *
				 sqrt(UpxAbs[i][j] * UpxAbs[i][j] + UpyAbs[i][j] * UpyAbs[i][j] + UpzAbs[i][j] * UpzAbs[i][j] ));

		UpFx[i][j] = Fx[i];
		UpFy[i][j] = Fy[i];
		UpFz[i][j] = Fz[i];
	}
}


//Absolute Kraft
for(int j = 1; j<n+1; j++){
	GesFx[j] = 0;
	GesFy[j] = 0;
	GesFz[j] = 0;
	r = 0;
	u = 0;
	l = 0;
	for(int i = 1; i<n+1; i++){
		if(i != j){
		GesFx[j] = u + UpFx[j][i]; //Falls was falschlaeuft hier i und j tauschen (und fuer y-Komponente)
		u = GesFx[j];
		GesFy[j] = r + UpFy[j][i];
		r=GesFy[j];
		GesFz[j] = l + UpFz[j][i];
	    l=GesFz[j];
	}
}
}


cout << "Nach " << j +1   << " Sekunden" << endl;
//new positions
	for(int i = 1; i<n+1; i++){
		posx[i] = masses[i].beginx + (masses[i].vx + (GesFx[i] / masses[i].m));
		posy[i] = masses[i].beginy + (masses[i].vy + (GesFy[i] / masses[i].m));
		posz[i] = masses[i].beginz + (masses[i].vz + (GesFz[i] / masses[i].m));
		cout << "(" << posx[i] << "," << posy[i] << "," << posz[i] << ")" << endl;




		fprintf(fs,"%e %e %e\n", posx[i], posy[i], posz[i]);



		masses[i].beginx = posx[i];
		masses[i].beginy = posy[i];
		masses[i].beginz = posz[i];
		nvx[i] = masses[i].vx;
		nvy[i] = masses[i].vy;
		nvz[i] = masses[i].vz;
		masses[i].vx = nvx[i] + (GesFx[i] / masses[i].m);
		masses[i].vy = nvy[i] + (GesFy[i] / masses[i].m);
		masses[i].vz = nvz[i] + (GesFz[i] / masses[i].m);
	}

}
fclose(fs);




return 0;
}


