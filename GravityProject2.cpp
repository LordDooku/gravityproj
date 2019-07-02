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
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double fRand(double fMin, double fMax) // Methode zum Generieren von zuflligen double numbers
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

	int n;  // n ist die Anzahl der Massenobjekte
	int t;  // t ist die Anzahl der Zeiteinheiten
	double posx [n];// neue Positionen
	double posy [n];
	double Upposx [n][t];
	double Upposy [n][t];
	cout << "Bitte gebe die gewuenschte Anzahl der Massenobjekte ein." << endl;
	cin >> n;
	cout << "Bitte gebe nun die gewuenschte Anzahl von Zeiteinheiten ein." << endl;
	cin >> t;

double l = -1;

// creates masses
	mass masses[n+1]; //Array mit n Massen
	double sunmass = 10;
	double newsunmass = 10 * sunmass;
	double supernewsunmass = 1000000 * newsunmass;
	double AbsAbs [n+1];
				for(int i=1; i< n+1; i++){
					masses [i].vx = i+1;
					masses [i].vy = i+1+2 * i;
					masses [i].beginx = i+1;
					masses [i].beginy = i+2;
					masses [i].m = 10000;
				}


				double xAbs[n+1]; // Array mit n-1 Abstanden in x-Richtung
				double yAbs[n+1];
				double UpxAbs [n+1][n+1]; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
				double UpyAbs [n+1][n+1];

				double Fx[n+1]; // Kraft in x-Richtung
					double Fy[n+1]; // Kraft in y-Richtung
					double UpFx[n+1][n+1];
					double UpFy[n+1][n+1];

					for (int h = 0; h<n+1; h++){

						 xAbs[h] = 0; // Array mit n-1 Abstanden in x-Richtung
						 yAbs[h] = 0;

						 Fx[h] = 0; // Kraft in x-Richtung
						 Fy[h] = 0; // Kraft in y-Richtung

					}

					for(int r = 1; r< n+1; r++){


					for (int h = 0; h<n+1; h++){
						 UpxAbs [h][r] = 0; // Array mit den Arrays xAbs (jeder Eintrag ist ein Array)
						 UpyAbs [h][r] = 0;
						 UpFx[h][r] = 0;
						 UpFy[h][r] = 0;
					}
					}



// ab hier Abstand





				double AbsAbsfinal [n][n]; // Array aus Arrays mit den Betrgen der Abstnde
					for(int k = 1  ;k < n+1; k++){


						for(int i=1; i< n+1; i++){

							xAbs [i] = masses[i].beginx + (l * masses[k].beginx);
							yAbs [i] = masses[i].beginy + (l * masses[k].beginy);
							double x = xAbs [i];
							double y = yAbs [i];
							AbsAbs [i] = sqrt(x * x + y * y);
							UpxAbs [i][k] = xAbs[i];
							UpyAbs [i][k] = yAbs[i];
							AbsAbsfinal [i][k] = AbsAbs[i];
						}


					}

// ab hier Kraft
					double G = 0.00000000006674408; //Gravitationskonstante

						for(int k = 1; k<n+1; k++){
							for(int i=1; i<n+1; i++){
								double GesFx[n]; // GEsamtkraft in x-Richtung
								double GesFy[n];
								GesFx[0] = 0;
								GesFy[0] = 0;
									for(int j=1; j < n+1; j++){ //Berechnet Gesamtkraft auf k-tes Teilchen in x-Richtung
										GesFx[j] = GesFx[j-1]  + (G * masses[j].m / (AbsAbsfinal[j][k] * AbsAbsfinal[j][k] * AbsAbsfinal[j][k]) * UpxAbs[k][i]);
									}
								Fx[i] = GesFx[n];
									for(int j=1; j < n+1; j++){ //Berechnet Gesamtkraft auf k-tes Teilchen in x-Richtung
										GesFy[j] = GesFy[j-1]  + (G * masses[j].m / (AbsAbsfinal[j][k] * AbsAbsfinal[j][k] * AbsAbsfinal[j][k]) * UpyAbs[k][i]);
										}
								Fy[i] = GesFy[n];
								UpFx[i][k] = Fx[i];
								UpFy[i][k] = Fy[i];
							}

						}





//ab hier new position

	for (int p=1; p<t+1; p++){

			     for (int i=1; i<n+1; i++) {
				            posx [i]= masses [i].beginx +(masses [i].vx+(Fx[i]));
				            posy [i]= masses [i].beginy +(masses [i].vy+(Fy[i]));
				            Upposx[i][p] = posx [i];
				            Upposy[i][p] = posy [i];
				            cout << Upposx[i][p]<< endl;
				            cout << Upposy[i][p]<< endl;
				            masses[i].beginx = posx[i];
				            masses[i].beginy = posy[i];
				            masses[i].vx = masses [i].vx+(Fx[i]);
				            masses[i].vy = masses [i].vx+(Fy[i]);
			     }


			}







	return 0;
}
