#pragma once
#define PI 3.14

bool kameraBakis = false;

double rad2deg(double radyan) {
	return radyan * 180 / PI;
}

double deg2rad(double derece) {
	return derece * PI / 180;
}


double upY = 1.0;
double phi, phi2 = 45;
double theta = 45;
int r = 28;
double gozX = r * sin(deg2rad(theta)) * sin(deg2rad(phi));
double gozY = r * cos(deg2rad(theta)) * sin(deg2rad(phi));
double gozZ = r * sin(deg2rad(theta)) * cos(deg2rad(phi));
double merkezX = 0, merkezY = 0, merkezZ = -20;
double tempX, tempY;
