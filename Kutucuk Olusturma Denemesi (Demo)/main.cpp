#include "stdafx.h"
#include <iostream>
#include "tanimlayicilar.h"

using namespace std;

int cins = 0;
class Kutucuk {
public:
	double Xuzunlugu = 0.2;
	double Yuzunlugu = 0.2;
	double Zuzunlugu = 0.2;
	double dondur = 0;
	int cins;

	double xHareket;
	double yHareket;
	double zHareket;
	double xHareketEski;
	double yHareketEski;
	double zHareketEski;
	Kutucuk(double xHareket, double yHareket, double zHareket, int cins) {
		this->cins = cins;
		this->xHareket = xHareket;
		this->yHareket = yHareket;
		this->zHareket = zHareket;
		xHareketEski = xHareket;
		yHareketEski = yHareket;
		zHareketEski = zHareket;
		
	}

	void isle() {
		glLoadIdentity();
		if (kameraBakis) {
			gluLookAt(gozX + merkezX, gozY + merkezY, gozZ + merkezZ, merkezX, merkezY, merkezZ, 0, upY, 0);
		}
		glTranslatef(xHareket, yHareket, zHareket);
		glRotatef(dondur, 0, 1, 0);

		//glColor3f(uzunLegoKirmizi, uzunLegoYesil, uzunLegoMavi);


		glBegin(GL_QUADS);
		// Lego parçasýnýn ön yüzeyi
		glColor3f(1, 1, 1);
		glVertex3f(0.0, Yuzunlugu, Zuzunlugu);
		glVertex3f(Xuzunlugu, Yuzunlugu, Zuzunlugu);
		glVertex3f(Xuzunlugu, 0.0, Zuzunlugu);
		glVertex3f(0.0, 0.0, Zuzunlugu);
		// Lego parçasýnýn arka kýsmý
		glVertex3f(0.0, Yuzunlugu, 0.0);
		glVertex3f(Xuzunlugu, Yuzunlugu, 0.0);
		glVertex3f(Xuzunlugu, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		// Lego parçasýnýn üst kýsmý
		glVertex3f(0.0, Yuzunlugu, 0.0);
		glVertex3f(Xuzunlugu, Yuzunlugu, 0.0);
		glVertex3f(Xuzunlugu, Yuzunlugu, Zuzunlugu);
		glVertex3f(0.0, Yuzunlugu, Zuzunlugu);
		// Lego parçasýnýn sað kýsmý
		glVertex3f(Xuzunlugu, Yuzunlugu, Zuzunlugu);
		glVertex3f(Xuzunlugu, Yuzunlugu, 0.0);
		glVertex3f(Xuzunlugu, 0.0, 0.0);
		glVertex3f(Xuzunlugu, 0.0, Zuzunlugu);
		// Lego parçasýnýn sol kýsmý
		glVertex3f(0.0, Yuzunlugu, Zuzunlugu);
		glVertex3f(0.0, Yuzunlugu, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, Zuzunlugu);
		glEnd();

	}
};

vector <Kutucuk*> kutucuklar;

void yenidenSekillendir(int, int);
bool butunCarpismaKontrolleri();
void kutucukOlustur(double,double,double);
void KlavyeHareketi(int, int, int);
void kisa1x1Olustur(double, double, double);

void isle(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);	// Pencerenin rengini tanýmlamak için	
	glEnable(GL_DEPTH_TEST);	// Derinliði aktif eder.	

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 800, 0, 800);
	kisa1x1Olustur(0, 0, -18.5);
	kisa1x1Olustur(-3, -3, -18.5);
}

void KlavyeHareketi(int anahtar, int x, int y) {

	switch (anahtar) {

	case GLUT_KEY_RIGHT:
		for (int i = 0; i < kutucuklar.size(); i++) {
			if (kutucuklar[i]->cins == 1)
			kutucuklar[i]->xHareket += 0.1;
		}
		break;
	case GLUT_KEY_LEFT:
		for (int i = 0; i < kutucuklar.size(); i++) {
			if (kutucuklar[i]->cins == 1)
			kutucuklar[i]->xHareket -= 0.1;
		}
		break;
	case GLUT_KEY_UP:
		for (int i = 0; i < kutucuklar.size(); i++) {
			if (kutucuklar[i]->cins == 1)
			kutucuklar[i]->yHareket += 0.1;
		}
		break;
	case GLUT_KEY_DOWN:
		for (int i = 0; i < kutucuklar.size(); i++) {
			if (kutucuklar[i]->cins == 1)
			kutucuklar[i]->yHareket -= 0.1;
		}
		break;
	case GLUT_KEY_END:
		if (!kameraBakis) {
			kameraBakis = true;
			
		}
		else {
			kameraBakis = false;
			
		}
		break;
	case GLUT_KEY_PAGE_UP:
		if(kameraBakis)
			phi += 2;
		
		
		break;
	case GLUT_KEY_PAGE_DOWN:
		if(kameraBakis)
			phi -= 2;
		
		
		break;

	case GLUT_KEY_F10:
		if (kameraBakis) {
			phi2 -= 2;
		}
		break;

	case GLUT_KEY_F11:
		if (kameraBakis) {
			phi2 += 2;

		}
		break;
	}

	
	gozX = r * sin(deg2rad(theta)) * sin(deg2rad(phi));
	gozY = r * cos(deg2rad(theta)) * sin(deg2rad(phi2));
	gozZ = r * sin(deg2rad(theta)) * cos(deg2rad(phi));
	glutPostRedisplay();

}
void cizgiSegmenti(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//glTranslatef(0, 0, -8);
	

		for (int i = 0; i < kutucuklar.size(); i++) {
			kutucuklar[i]->isle();
		}
	
	glutSwapBuffers();
	if (butunCarpismaKontrolleri()) {
		for (int i = 0; i < kutucuklar.size(); i++) {
			if (kutucuklar[i]->cins == 1) {
				kutucuklar[i]->xHareket = kutucuklar[i]->xHareketEski;
				kutucuklar[i]->yHareket = kutucuklar[i]->yHareketEski;
				kutucuklar[i]->zHareket = kutucuklar[i]->zHareketEski;
			}
		}
	}
	else {
		for (int i = 0; i < kutucuklar.size(); i++) {
			if (kutucuklar[i]->cins == 1) {
				kutucuklar[i]->xHareketEski = kutucuklar[i]->xHareket;
				kutucuklar[i]->yHareketEski = kutucuklar[i]->yHareket;
				kutucuklar[i]->zHareketEski = kutucuklar[i]->zHareket;
			}
		}
	}
	glutPostRedisplay();
}

int _tmain(int argc, _TCHAR argv[]) {

	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Deneme");
	isle();
	glutDisplayFunc(cizgiSegmenti);
	glutReshapeFunc(yenidenSekillendir);
	glutSpecialFunc(KlavyeHareketi);
	glutMainLoop();
	return 0;

}

void yenidenSekillendir(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(40, 1, 2.0, 50.0);


	glMatrixMode(GL_MODELVIEW);

}

bool butunCarpismaKontrolleri() {






	for (int i = 0; i < kutucuklar.size(); i++) {
		for (int j = 0; j < kutucuklar.size(); j++) {
			if (i == j) { continue; }
			if (kutucuklar[i]->cins == kutucuklar[j]->cins) { continue; }
			


			if (((kutucuklar[i]->xHareket + (kutucuklar[i]->Xuzunlugu / 2)) >= (kutucuklar[j]->xHareket - (kutucuklar[j]->Xuzunlugu / 2))) &&
				((kutucuklar[i]->xHareket + (kutucuklar[i]->Xuzunlugu / 2)) <= (kutucuklar[j]->xHareket + (kutucuklar[j]->Xuzunlugu / 2))) &&
				((kutucuklar[i]->yHareket - kutucuklar[i]->Yuzunlugu / 2) <= (kutucuklar[j]->yHareket + kutucuklar[j]->Yuzunlugu / 2)) &&
				((kutucuklar[i]->yHareket + kutucuklar[i]->Yuzunlugu / 2) >= (kutucuklar[j]->yHareket - kutucuklar[j]->Yuzunlugu / 2)) &&
				((kutucuklar[i]->zHareket + kutucuklar[i]->Zuzunlugu / 2) >= (kutucuklar[j]->zHareket - kutucuklar[j]->Zuzunlugu / 2)) &&
				((kutucuklar[i]->zHareket - kutucuklar[i]->Zuzunlugu / 2) <= (kutucuklar[j]->zHareket + kutucuklar[j]->Zuzunlugu / 2))) {


				return true;

			}
		}

	}

	return false;

}

void kutucukOlustur(double xHareket, double yHareket, double zHareket, int cins) {
	Kutucuk* kutucuk = new Kutucuk(xHareket, yHareket, zHareket, cins);
	kutucuklar.push_back(kutucuk);
	glutPostRedisplay();
}

void kisa1x1Olustur(double xHareket, double yHareket, double zHareket) {
	cins++;
	for (int i = 0; i <= 5; i++) {
		kutucukOlustur(xHareket + double(i) / 4, yHareket, zHareket, cins);
		kutucukOlustur(xHareket, yHareket, zHareket - double(i) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket, zHareket-double(1)/4, cins);
		kutucukOlustur(xHareket+double(1)/4, yHareket, zHareket - double(i) / 4, cins);
		kutucukOlustur(xHareket + double(5) / 4, yHareket, zHareket - double(i) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket, zHareket - (double)(5) / 4, cins);
		kutucukOlustur(xHareket + double(4) / 4, yHareket, zHareket - double(i) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket, zHareket - (double)(4) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket+(double)(1) / 4, zHareket, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket+(double)(1) / 4, zHareket - (double)(1) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket+(double)(1) / 4, zHareket - (double)(2) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket+(double)(1) / 4, zHareket - (double)(3) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket+(double)(1) / 4, zHareket - (double)(4) / 4, cins);
		kutucukOlustur(xHareket + double(i) / 4, yHareket+(double)(1) / 4, zHareket - (double)(5) / 4, cins);

		if ((i > 3) && (i <= 5)) {
			kutucukOlustur(xHareket + double(i - 2) / 4, yHareket+(double)(2) / 4, zHareket - (double)(2) / 4, cins);
			kutucukOlustur(xHareket + double(i - 2) / 4, yHareket+(double)(2) / 4, zHareket - (double)(3) / 4, cins);
		}
	}
}