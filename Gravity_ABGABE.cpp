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
#include <cstdlib>


//Methode um "random" double numbers zu erstellen
double rand( double low, double high ) {
    return ( ( double )rand() * ( high - low ) ) / ( double )RAND_MAX + low;
}


class mass // Die Klasse der Massenobjekte
{
public:
	double vx;		// Geschwindigkeit in x-Richtung
	double vy;		// Geschwindigkeit in y-Richtung
	double vz;		// Geschwindigkeit in z-Richtung
	double beginx; 	// x-Koordinate der Anfangsposition
	double beginy;	// y-Koordinate der Anfangsposition
	double beginz;	// z-Koordinate der Anfangsposition
	double m;		// Masse



};

int main() {

double G = 6.067e-11;
int t;  // Die Anzahl der Zeiteinheiten
int n ; // Die Anzahl der Massenbjekte

int c; // c, d, p, w sind die Variablen die benutzt werde um Specific Time text Dateien zu erstellen
int d;
int p;
int w;


cout << "Bitte gebe die gewuenschte Anzahl der Massenobjekte ein." << endl;
cin >> n;
cout << "Bitte gebe nun die gewuenschte Anzahl von Zeiteinheiten ein." << endl;
cin >> t;


cout << "Bitte gebe nun die 1. Specific Time ein." << endl;
cin >> c;
cout << "Bitte gebe nun die 2. Specific Time ein." << endl;
cin >> d;
cout << "Bitte gebe nun die 3. Specific Time ein." << endl;
cin >> p;
cout << "Bitte gebe nun die 4. Specific Time ein." << endl;
cin >> w;


double xAbs[n+1]; // Array mit n+1 Abstanden in x-Richtung, der 0te Eintrag wird nicht verwendet
double yAbs[n+1]; // Array mit n+1 Abstanden in y-Richtung, der 0te Eintrag wird nicht verwendet
double zAbs[n+1]; // Array mit n+1 Abstanden in z-Richtung, der 0te Eintrag wird nicht verwendet

double UpxAbs [n+1][n+1]; // Hier sind alle Kombinationen der x-Abstaende gespeichert
double UpyAbs [n+1][n+1]; // Hier sind alle Kombinationen der y-Abstaende gespeichert
double UpzAbs [n+1][n+1]; // Hier sind alle Kombinationen der z-Abstaende gespeichert


double Fx[n+1]; // Kraft in x-Richtung fuer je ein Teilchen
double Fy[n+1]; // Kraft in y-Richtung fuer je ein Teilchen
double Fz[n+1]; // Kraft in z-Richtung fuer je ein Teilchen
double UpFx[n+1][n+1]; // Kraft in x-Richtung fuer alle Teilchen
double UpFy[n+1][n+1]; // Kraft in y-Richtung fuer alle Teilchen
double UpFz[n+1][n+1]; // Kraft in z-Richtung fuer alle Teilchen
double GesFx[n+1]; // Gesamtkraft in x-Richtung
double GesFy[n+1]; // Gesamtkraft in y-Richtung
double GesFz[n+1]; // Gesamtkraft in z-Richtung

double posx [n+1]; // neue x-Position nach einem Zeitschritt
double posy [n+1]; // neue y-Position nach einem Zeitschritt
double posz [n+1]; // neue z-Position nach einem Zeitschritt

double nvx[n+1]; // nur Hilfsarrays
double nvy[n+1];
double nvz[n+1];

double u, r, l; // nur Hilfsvariablen



// create masses and assign "random" values to speed, initial position and mass
	mass masses[n+1]; //Array mit n Massen

				for(int i=1; i< n+1; i++){
					masses[i].beginx = rand(-1000, 1000);
					masses[i].beginy = rand(-1000, 1000);
					masses[i].beginz =rand(-1000, 1000);
					masses[i].vx = rand(-1000, 1000);
					masses[i].vy = rand(-1000, 1000);
					masses[i].vz =rand(-1000, 1000);
					masses[i].m =  rand(1e10, 1e12);
				}

//Die .txt Dateien, die am Ende ausgegeben werde, werden erstellt
FILE* fs;
fs = fopen("GravityProject.txt","w");

FILE* ds;
ds = fopen("GravityProjectSpecificTime1.txt","w");

FILE* dp;
dp = fopen("GravityProjectSpecificTime2.txt","w");


FILE* dk;
dk = fopen("GravityProjectSpecificTime3.txt","w");

FILE* dw;
dw = fopen("GravityProjectSpecificTime4.txt","w");



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


//Gesamtkraft
for(int j = 1; j<n+1; j++){
	GesFx[j] = 0;
	GesFy[j] = 0;
	GesFz[j] = 0;
	r = 0;
	u = 0;
	l = 0;
	for(int i = 1; i<n+1; i++){
		if(i != j){
				GesFx[j] = u + UpFx[i][j];
				u = GesFx[j];
				GesFy[j] = r + UpFy[i][j];
				r=GesFy[j];
				GesFz[j] = l + UpFz[i][j];
				l=GesFz[j];
		}
	}
}


cout << "Nach " << j +1   << " Sekunden" << endl; // Macht Ausgabe lesbarer

//new positions
	for(int i = 1; i<n+1; i++){
		posx[i] = masses[i].beginx + (masses[i].vx + (GesFx[i] / masses[i].m)); // Zeitabstand ist Eins
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

		if(j == c){ 		// Specific Time .txt Dateien werden erstellt
			fprintf(ds,"%e %e %e\n", posx[i], posy[i], posz[i]);
		}

		if(j == d){
			fprintf(dp,"%e %e %e\n", posx[i], posy[i], posz[i]);
		}

		if(j == p){
			fprintf(dk,"%e %e %e\n", posx[i], posy[i], posz[i]);
		}

		if(j == w){
			fprintf(dw,"%e %e %e\n", posx[i], posy[i], posz[i]);
		}
	}

}

fclose(fs);




return 0;
}


