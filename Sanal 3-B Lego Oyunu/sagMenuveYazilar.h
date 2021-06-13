#pragma once

void butunSagMenuYaziRenkleriVarsayilan();



class RenkKutucugu {
public:
	double xKaydirma;
	double yKaydirma;
	double zKaydirma;
	double kirmizi = 1.0;
	double yesil = 1.0;
	double mavi = 1.0;


	void isle(double xKaydirma, double yKaydirma, double zKaydirma, double kirmizi, double yesil, double mavi) {

		this->xKaydirma = xKaydirma;
		this->yKaydirma = yKaydirma;
		this->zKaydirma = zKaydirma;
		this->kirmizi = kirmizi;
		this->yesil = yesil;
		this->mavi = mavi;

		glLoadIdentity();
		glTranslatef(xKaydirma, yKaydirma, zKaydirma);
		glBegin(GL_QUADS);
		glColor3f(kirmizi, yesil, mavi);
		glVertex3f(0, 0, 0);
		glVertex3f(0.06, 0, 0);
		glVertex3f(0.06, 0.06, 0);
		glVertex3f(0, 0.06, 0);
		glEnd();
	}

};


class YaziYazdir {
public:
	double xKaydirma;
	double yKaydirma;
	double zKaydirma;
	double kirmizi = 5.0;
	double yesil = 5.0;
	double mavi = 5.0;
	double beyaz = 5.0;
	bool aktifMi = false;
	GLubyte yazi[];



	void isle(double xKaydirma, double yKaydirma, double zKaydirma, double kirmizi, double yesil, double mavi, GLubyte yazi[]) {
		this->xKaydirma = xKaydirma;
		this->yKaydirma = yKaydirma;
		this->zKaydirma = zKaydirma;
		this->kirmizi = kirmizi;
		this->yesil = yesil;
		this->mavi = mavi;
		this->yazi[2380] = yazi[2380];
		GLint ay, k;
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glTranslatef(xKaydirma, yKaydirma, zKaydirma);
		// Yazýyý yazdýr;
		glColor3f(kirmizi, yesil, mavi);

		xPiksely = 0;
		for (ay = 0; ay < 320; ay++) {

			glRasterPos3f(xPiksely, yPiksely, zPiksely);
			for (k = 100 * ay; k < 40 * ay + 40; k++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, yazi[k]);
			xPiksely += 1;
		}
	}
};

class SagMenuButonKutucugu {
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
		glVertex3f(0.38, 0, 0);
		glVertex3f(0.38, 0.06, 0);
		glVertex3f(0, 0.06, 0);
		glEnd();
	}
};

RenkKutucugu kirmiziKutucuk;
RenkKutucugu yesilKutucuk;
RenkKutucugu maviKutucuk;
RenkKutucugu sariKutucuk;
RenkKutucugu magentaKutucuk;
RenkKutucugu beyazKutucuk;

YaziYazdir legoDondurYazisiS;

YaziYazdir cikisYazisiS;
YaziYazdir sifirlaYazisiS;
YaziYazdir renklerYazisiS;
YaziYazdir kameraHareketiYazisiS;
YaziYazdir onBakisYazisiS;
YaziYazdir yanBakisYazisiS;
YaziYazdir serbestKameraYazisiS;
YaziYazdir carpismaTespitiYazisiS;
YaziYazdir silindirOturtmaKontroluYazisiS;
YaziYazdir legoSecYazisiS;
YaziYazdir serbestKameraHareketBilgisiYazisiS;
YaziYazdir serbestKameraHareketBilgisiYazisi2S;
YaziYazdir hassasHareketBilgisiYazisiS;
YaziYazdir hassasHareketBilgisiYazisi2S;
YaziYazdir legoSilYazisiS;



void menuCizgileri() {
	// MENÜ DÝRDÖRTGENÝ
	glBegin(GL_QUADS);

	glColor3f(0.2, 0.5, 1);
	glVertex3f(0, 0, 0);
	glColor3f(0.7, 0.5, 1);
	glVertex3f(2.5, 0, 0);
	glColor3f(0.2, 0.8, 1);
	glVertex3f(2.5, 3.8, 0);
	glColor3f(0.2, 0.7, 0.8);
	glVertex3f(0, 3.8, 0);
	glEnd();

	// RENK KARELERÝ:
	// Kýrmýzý

	kirmiziKutucuk.isle(0.85, 0.1, -2.0, kirmiziKutucuk.kirmizi, 0.0, 0.0);

	// Yeþil
	yesilKutucuk.isle(0.95, 0.1, -2.0, 0.0, yesilKutucuk.yesil, 0.0);

	// Açýk mavi (cyan)
	maviKutucuk.isle(1.05, 0.1, -2.0, 0.0, maviKutucuk.yesil, maviKutucuk.mavi);
	
	// Sarý
	sariKutucuk.isle(0.85, 0.0, -2.0, sariKutucuk.kirmizi, sariKutucuk.yesil, 0.0);

	// Magenta
	magentaKutucuk.isle(0.95, 0.0, -2.0, magentaKutucuk.kirmizi, 0.0, magentaKutucuk.mavi);

	// Siyah
	beyazKutucuk.isle(1.05, 0.0, -2.0, beyazKutucuk.kirmizi, beyazKutucuk.yesil, beyazKutucuk.mavi);

	
	
}

void menuYazilari() {
	// ------------ YAZI YAZDIRMA ALGORÝTMALARI -------------
	
	
	
	legoDondurYazisiS.isle(0.89, 0.32, 0.0, legoDondurYazisiS.beyaz, legoDondurYazisiS.beyaz, legoDondurYazisiS.beyaz, legoDondurYazisi);
	cikisYazisiS.isle(0.94, -0.20, 0.0, 5.0f, cikisYazisiS.yesil, 5.0f, cikisYazisi);
	sifirlaYazisiS.isle(0.9615, -0.14, 0.0, 5.0f, 5.0f, sifirlaYazisiS.mavi, sifirlaYazisi);
	renklerYazisiS.isle(0.9515, 0.22, 0.0, 3.0f, 3.0f, 5.0f, renklerYazisi);
	kameraHareketiYazisiS.isle(0.90, -0.079, 0.0, 5.0f, 5.0f, kameraHareketiYazisiS.mavi, kameraHareketiYazisi);
	if (legoSilYazisiS.aktifMi == true) {
		legoSilYazisiS.isle(0.74, 0.59, 0.0, 5.0f, 5.0f, 5.0f, legoSilYazisi);
	}

	

}

void kameraYazilari() {

	

	if (onBakis) {

		onBakisYazisiS.isle(-0.05, 0.65, 0.0, 2.0f, 5.0f, 2.0f, onBakisYazisi);

	}

	if (yanBakis) {

		yanBakisYazisiS.isle(-0.07, 0.65, 0.0, 5.0f, 5.0f, 0.0f, yanBakisYazisi);

	}

	if (kameraHareket) {

		serbestKameraYazisiS.isle(-0.08, 0.65, 0.0, 5.0f, 0.0f, 5.0f, serbestKameraYazisi);
		serbestKameraHareketBilgisiYazisiS.isle(-0.35, -0.65, 0.0, 0.0f, 5.0f, 5.0f, serbestKameraHareketBilgisi);
		serbestKameraHareketBilgisiYazisi2S.isle(0.29, -0.65, 0.0, 0.0f, 5.0f, 5.0f, serbestKameraHareketBilgisi2);
	}

	if (carpismaTespiti) {

		carpismaTespitiYazisiS.isle(-0.14, 0.15, 0.0, 5.0f, 2.0f, 2.0f, carpismaTespitiYazisi);

	}

	if (silindirOturtmaKontrolu) {

		silindirOturtmaKontroluYazisiS.isle(-0.14, 0.20, 0.0, 0.0f, 5.0f, 5.0f, silindirOturtmaKontroluYazisi);
		hassasHareketBilgisiYazisiS.isle(-0.30, -0.61, 0.0, 5.0f, 5.0f, 5.0f, hassasHareketBilgisi);
		hassasHareketBilgisiYazisi2S.isle(0.28, -0.61, 0.0, 5.0f, 5.0f, 5.0f, hassasHareketBilgisi2);
	}

	
	if (legoSecYazisiS.aktifMi == true) {

		legoSecYazisiS.isle(-0.14, 0.23, 0.0, 5.0f, 5.0f, 2.0f, legoSecYazisi);


	}
	

}


void butunSagMenuYaziRenkleriVarsayilan() {

	cikisYazisiS.yesil = 5.0;
	sifirlaYazisiS.mavi = 5.0;
	kameraHareketiYazisiS.mavi = 5.0;
	legoDondurYazisiS.beyaz = 5.0;
	
}


void butunRenkKutucuguRenkleriVarsayilan() {
	kirmiziKutucuk.kirmizi = 1.0;
	yesilKutucuk.yesil = 1.0;
	maviKutucuk.yesil = 1.0;
	maviKutucuk.mavi = 1.0;
	sariKutucuk.kirmizi = 1.0;
	sariKutucuk.yesil = 1.0;
	magentaKutucuk.kirmizi = 1.0;
	magentaKutucuk.mavi = 1.0;
	beyazKutucuk.kirmizi = 1.0;
	beyazKutucuk.yesil = 1.0;
	beyazKutucuk.mavi = 1.0;

	
}