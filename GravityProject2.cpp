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
	float vx;		// Geschwindigkeit in x-Richtung
	float vy;		// Geschwindigkeit in y-Richtung
	float r; 		// Radius
	float beginx; 	// x-Koordinate der Anfangsposition
	float beginy;	// y-Koordinate der Anfangsposition
	float m;		// Masse



};











int main() {

	int n;  // n ist die Anzahl der Massenobjekte
	int t;  // t ist die Anzahl der Zeiteinheiten
	float posx [n];// neue Positionen
	float posy [n];
	float Upposx [n][t];
	float Upposy [n][t];
	cout << "Bitte gebe die gewuenschte Anzahl der Massenobjekte ein." << endl;
	cin >> n;
	cout << "Bitte gebe nun die gew�nschte Anzahl von Zeiteinheiten ein." << endl;
	cin >> t;

// creates masses
	mass masses[n]; //Array mit n Massen
	float sunmass = 10;
	float newsunmass = 10 * sunmass;
	float supernewsunmass = 1000000 * newsunmass;
	float AbsAbs [n];
				for(int i=1; i< n+1; i++){
					masses [i].vx = i;
					masses [i].vy = i;
					masses [i].beginx = i;
					masses [i].beginy = i;
					masses [i].m = 10000;
				}

// ab hier Abstand
				float xAbs[n-1]; // Array mit n-1 Abstanden in x-Richtung
				float yAbs[n-1];
				float UpxAbs [n][n]; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
				float UpyAbs [n][n];

				float AbsAbsfinal [n][n]; // Array aus Arrays mit den Betr�gen der Abst�nde
					for(int j = 0  ;j < n; j++){


						for(int k=j; k< n-1; k++){

							xAbs [k] = masses[k].beginx - masses[j].beginx;
							yAbs [k] = masses[k].beginy - masses[j].beginy;
							float x = xAbs [k];
							float y = yAbs [k];
							AbsAbs [k] = sqrt(x * x + y * y);
							UpxAbs [j][k] = xAbs[j];
							UpyAbs [j][k] = yAbs[j];
							AbsAbsfinal [j][k] = AbsAbs[j];
						}


					}

// ab hier Kraft
					float G = 0.00000000006674408; //Gravitationskonstante
					float Fx[n]; // Kraft in x-Richtung
					float Fy[n]; // Kraft in y-Richtung
					float UpFx[n][n];
					float UpFy[n][n];
					UpFx[n][n] = 0;
						for(int i = 0; i<n; i++){
							for(int j=i; j<n; j++){
								Fx[j] = G * (masses[j+1].m / (AbsAbsfinal [i][j+1] * AbsAbsfinal [i][j+1])) * UpxAbs[i][j+1];
								Fy[j] = G * (masses[j+1].m / (AbsAbsfinal [i][j+1] * AbsAbsfinal [i][j+1])) * UpyAbs[i][j+1];
								UpFx[i][j] = Fx[i];
								UpFy[i][j] = Fy[i];
							}

						}

//ab hier  Rest
			for (int k=0; k<t; k++){


			     for (int i=0; i<n; i++) {
				            posx [i]= masses [i].beginx +(masses [i].vx+(UpFx[i][i+1])*k)*k;
				            posy [i]= masses [i].beginy +(masses [i].vy+(UpFy[i][i+1])*k)*k;
				            Upposx[i][k] = posx [k];
				            Upposy[i][k] = posy [k];
				            cout << Upposx[i][k]<< endl;
				            masses[i].beginx = posx[i];
				            masses[i].beginy = posy[i];

			   }


						}







	return 0;
}
