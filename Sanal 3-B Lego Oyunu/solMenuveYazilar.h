#pragma once


class SolMenuButonKutucugu {
public:
	double xKaydirma;
	double yKaydirma;
	double zKaydirma;
	double kirmizi = 0.95;
	double yesil = 0.95;
	double mavi = 0.95;
	double cyan = 0.95;

	void isle(double xKaydirma, double yKaydirma, double zKaydirma, double kirmizi, double yesil, double mavi) {
		this->xKaydirma = xKaydirma;
		this->yKaydirma = yKaydirma;
		this->zKaydirma = zKaydirma;
		this->kirmizi = kirmizi;
		this->yesil = yesil;
		this->mavi = mavi;

		glLoadIdentity();
		glTranslatef(xKaydirma, yKaydirma, zKaydirma);
		glColor3f(kirmizi, yesil, mavi);
		glBegin(GL_QUADS);
		glVertex3f(0, 0, 0);
		glVertex3f(0.29, 0, 0);
		glVertex3f(0.29, 0.05, 0);
		glVertex3f(0, 0.05, 0);
		glEnd();
	}
};

SolMenuButonKutucugu kisa1x1Butonu;
SolMenuButonKutucugu uzun1x1Butonu;
SolMenuButonKutucugu kisa1x2Butonu;
SolMenuButonKutucugu uzun1x2Butonu;
SolMenuButonKutucugu kisa1x4Butonu;
SolMenuButonKutucugu uzun1x4Butonu;
SolMenuButonKutucugu kisa2x2Butonu;
SolMenuButonKutucugu uzun2x2Butonu;
SolMenuButonKutucugu kisa2x4Butonu;
SolMenuButonKutucugu uzun2x4Butonu;




YaziYazdir solMenuYazisiS;
YaziYazdir cizgiS;
YaziYazdir kisa1x1YazisiS;
YaziYazdir uzun1x1YazisiS;
YaziYazdir kisa1x2YazisiS;
YaziYazdir uzun1x2YazisiS;
YaziYazdir kisa1x4YazisiS;
YaziYazdir uzun1x4YazisiS;
YaziYazdir kisa2x2YazisiS;
YaziYazdir uzun2x2YazisiS;
YaziYazdir kisa2x4YazisiS;
YaziYazdir uzun2x4YazisiS;

void butunSolMenuYaziRenkleriVarsayilan();
void butunButonRenkleriVarsayilan();

void menuCizgileri2() {

	// SOL MENÜ
	glBegin(GL_QUADS);

	glColor3f(0.5, 0.2, 1);
	glVertex3f(0, 0.2, 0);
	glColor3f(0.8, 0.2, 1);
	glVertex3f(1.80, 0.2, 0);
	glColor3f(0.5, 0.5, 1);
	glVertex3f(1.80, 4.3, 0);
	glColor3f(0.5, 0.4, 0.8);
	glVertex3f(0, 4.3, 0);
	glEnd();
	

	kisa1x1Butonu.isle(-1.265, 0.594, -2.1, 0, kisa1x1Butonu.cyan, kisa1x1Butonu.cyan);
	uzun1x1Butonu.isle(-1.265, 0.52053, -2.1, 0, uzun1x1Butonu.cyan, uzun1x1Butonu.cyan);
	kisa1x2Butonu.isle(-1.265, 0.44706, -2.1, 0, kisa1x2Butonu.cyan, kisa1x2Butonu.cyan);
	uzun1x2Butonu.isle(-1.265, 0.37359, -2.1, 0, uzun1x2Butonu.cyan, uzun1x2Butonu.cyan);
	kisa1x4Butonu.isle(-1.265, 0.30012, -2.1, 0, kisa1x4Butonu.cyan, kisa1x4Butonu.cyan);
	uzun1x4Butonu.isle(-1.265, 0.22665, -2.1, 0, uzun1x4Butonu.cyan, uzun1x4Butonu.cyan);
	kisa2x2Butonu.isle(-1.265, 0.15318, -2.1, 0, kisa2x2Butonu.cyan, kisa2x2Butonu.cyan);
	uzun2x2Butonu.isle(-1.265, 0.07971, -2.1, 0, uzun2x2Butonu.cyan, uzun2x2Butonu.cyan);
	kisa2x4Butonu.isle(-1.265, 0.00624, -2.1, 0, kisa2x4Butonu.cyan, kisa2x4Butonu.cyan);
	uzun2x4Butonu.isle(-1.265, -0.06723, -2.1, 0, uzun2x4Butonu.cyan, uzun2x4Butonu.cyan);





}

void menuYazilari2() {
	
	solMenuYazisiS.isle(-1.17, 0.65, 0.0, 3.0f, 8.0f, 8.0f, solMenuYazisi);
	cizgiS.isle(-1.23, 0.645, 0.0, 3.0f, 8.0f, 8.0f, cizgi);
	kisa1x1YazisiS.isle(-1.19, 0.58, 0.0, kisa1x1YazisiS.beyaz, kisa1x1YazisiS.beyaz, kisa1x1YazisiS.beyaz, kisa1x1Yazisi);
	uzun1x1YazisiS.isle(-1.192, 0.51, 0.0, uzun1x1YazisiS.beyaz, uzun1x1YazisiS.beyaz, uzun1x1YazisiS.beyaz, uzun1x1Yazisi);
	kisa1x2YazisiS.isle(-1.19, 0.44, 0.0, kisa1x2YazisiS.beyaz, kisa1x2YazisiS.beyaz, kisa1x2YazisiS.beyaz, kisa1x2Yazisi);
	uzun1x2YazisiS.isle(-1.192, 0.37, 0.0, uzun1x2YazisiS.beyaz, uzun1x2YazisiS.beyaz, uzun1x2YazisiS.beyaz, uzun1x2Yazisi);
	kisa1x4YazisiS.isle(-1.19, 0.30, 0.0, kisa1x4YazisiS.beyaz, kisa1x4YazisiS.beyaz, kisa1x4YazisiS.beyaz, kisa1x4Yazisi);
	uzun1x4YazisiS.isle(-1.192, 0.23, 0.0, uzun1x4YazisiS.beyaz, uzun1x4YazisiS.beyaz, uzun1x4YazisiS.beyaz, uzun1x4Yazisi);
	kisa2x2YazisiS.isle(-1.19, 0.16, 0.0, kisa2x2YazisiS.beyaz, kisa2x2YazisiS.beyaz, kisa2x2YazisiS.beyaz, kisa2x2Yazisi);
	uzun2x2YazisiS.isle(-1.192, 0.09, 0.0, uzun2x2YazisiS.beyaz, uzun2x2YazisiS.beyaz, uzun2x2YazisiS.beyaz, uzun2x2Yazisi);
	kisa2x4YazisiS.isle(-1.19, 0.02, 0.0, kisa2x4YazisiS.beyaz, kisa2x4YazisiS.beyaz, kisa2x4YazisiS.beyaz, kisa2x4Yazisi);
	uzun2x4YazisiS.isle(-1.192, -0.05, 0.0, uzun2x4YazisiS.beyaz, uzun2x4YazisiS.beyaz, uzun2x4YazisiS.beyaz, uzun2x4Yazisi);

}


void butunSolMenuYaziRenkleriVarsayilan() {
	kisa1x1YazisiS.beyaz = 5.0;
	uzun1x1YazisiS.beyaz = 5.0;
	kisa1x2YazisiS.beyaz = 5.0;
	uzun1x2YazisiS.beyaz = 5.0;
	kisa1x4YazisiS.beyaz = 5.0;
	uzun1x4YazisiS.beyaz = 5.0;
	kisa2x2YazisiS.beyaz = 5.0;
	uzun2x2YazisiS.beyaz = 5.0;
	kisa2x4YazisiS.beyaz = 5.0;
	uzun2x4YazisiS.beyaz = 5.0;

}

void butunButonRenkleriVarsayilan() {
	kisa1x1Butonu.cyan = 0.95;
	uzun1x1Butonu.cyan = 0.95;
	kisa1x2Butonu.cyan = 0.95;
	uzun1x2Butonu.cyan = 0.95;
	kisa1x4Butonu.cyan = 0.95;
	uzun1x4Butonu.cyan = 0.95;
	kisa2x2Butonu.cyan = 0.95;
	uzun2x2Butonu.cyan = 0.95;
	kisa2x4Butonu.cyan = 0.95;
	uzun2x4Butonu.cyan = 0.95;
	
}