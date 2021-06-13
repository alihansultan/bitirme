#include "stdafx.h"
#include <iostream>
#include "tanimlayicilar.h"
#include "isiklandirma.h"
#include "sagMenuveYazilar.h"
#include "solMenuveYazilar.h"
#include "Nesneler.h"
#include "Lego.h"
#include "FareHareketi.h"
#include "FareHareketiGeriBildirimiAktif.h"
#include "FareHareketiGeriBildirimiPasif.h"
#include "varsayilanLegoDegerleri.h"
#include "Fonksiyonlar.h"
#include "bagliLegoKontrolu.h"

using namespace std;

void varsayilanLegoDegerleri();
void zamanlayici(int);
bool butunCarpismaKontrolleri();

void isle(void) {
	glClearColor(0.0, 0.0, 0.5, 1.0);	// Pencerenin rengini tanýmlamak için	
	glEnable(GL_DEPTH_TEST);	// Derinliði aktif eder.	
	glMatrixMode(GL_PROJECTION);		
	gluOrtho2D(0, 800, 0, 800);
	
	// BMP resimlerine ait kimliklerinin tanýmý yapýlýyor
	copKutusuResmi.kimlik = copKutusuResmi.BMPYukle("trash3.bmp");
	dondurmeResmi.kimlik = dondurmeResmi.BMPYukle("rotate.bmp");
	cikisResmi.kimlik = cikisResmi.BMPYukle("exit.bmp");
	sifirlaResmi.kimlik = sifirlaResmi.BMPYukle("reset.bmp");
	kameraHareketiResmi.kimlik = kameraHareketiResmi.BMPYukle("camera.bmp");
	kisa1x1Resmi.kimlik = kisa1x1Resmi.BMPYukle("1x1kisa.bmp");
	uzun1x1Resmi.kimlik = uzun1x1Resmi.BMPYukle("1x1uzun.bmp");
	kisa1x2Resmi.kimlik = kisa1x2Resmi.BMPYukle("1x2kisa.bmp");
	uzun1x2Resmi.kimlik = uzun1x2Resmi.BMPYukle("1x2uzun.bmp");
	kisa1x4Resmi.kimlik = kisa1x4Resmi.BMPYukle("1x4kisa.bmp");
	uzun1x4Resmi.kimlik = uzun1x4Resmi.BMPYukle("1x4uzun.bmp");
	kisa2x2Resmi.kimlik = kisa2x2Resmi.BMPYukle("2x2kisa.bmp");
	uzun2x2Resmi.kimlik = uzun2x2Resmi.BMPYukle("2x2uzun.bmp");
	kisa2x4Resmi.kimlik = kisa2x4Resmi.BMPYukle("2x4kisa.bmp");
	uzun2x4Resmi.kimlik = uzun2x4Resmi.BMPYukle("2x4uzun.bmp");
}


void FareHareketi(int button, int durum, int farex, int farey);

void FareHareketiGeriBildirimiPasif(int xPos, int yPos);

void FareHareketiGeriBildirimiAktif(int xPos, int yPos);


// KlavyeHareketi fonksiyonu, klavye ok tuþlarýný dinleyip bunlara göre belirlenen fonksiyonlarý gerçekleþtirmekktedir.
void KlavyeHareketi(int anahtar, int x, int y) {

	switch (anahtar) {
	
	case GLUT_KEY_RIGHT:
		if (kameraHareket == false) {			
				if (onBakis) {
					if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
						legolar[legolar.size() - farkDegeri]->xHareket += 0.01;
					}
					else {
						for (int i = 0; i < legolar.size(); i++) {
							if (legolar[i]->baglilik) {
								legolar[i]->xHareket += 0.5;
							}
						}
					}
				}
				else if (yanBakis) {
					if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
						legolar[legolar.size() - farkDegeri]->zHareket += 0.01;
					}
					else {
						for (int i = 0; i < legolar.size(); i++) {
							if (legolar[i]->baglilik) {
								legolar[i]->zHareket += 0.5;
							}
						}
					}
				}
												
		}
		else {
			merkezX -= 2.0;
			kameraHareketBilgileriniKonsolaYazdir();
		}
		break;
	case GLUT_KEY_LEFT:
		if (kameraHareket == false) {
					
				if (onBakis) {
					if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
						legolar[legolar.size() - farkDegeri]->xHareket -= 0.01;
					}
					else {
						for (int i = 0; i < legolar.size(); i++) {
							if (legolar[i]->baglilik) {
								legolar[i]->xHareket -= 0.5;
							}

						}
					}
				}
				else if (yanBakis) {
					if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
						legolar[legolar.size() - farkDegeri]->zHareket -= 0.01;
					}
					else {
						for (int i = 0; i < legolar.size(); i++) {
							if (legolar[i]->baglilik) {
								legolar[i]->zHareket -= 0.5;
							}

						}
					}
					
				}					
		}
		else {
			merkezX += 2.0;
			kameraHareketBilgileriniKonsolaYazdir();
		}
		break;
	case GLUT_KEY_UP:
		if (kameraHareket == false) {
			if (onBakis||yanBakis) {
				if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
					legolar[legolar.size() - farkDegeri]->yHareket += 0.01;
				}
				else {
					for (int i = 0; i < legolar.size(); i++) {
						if (legolar[i]->baglilik) {
							legolar[i]->yHareket += 0.5;
						}

					}
				}
			}
		}
		else {
			merkezZ -= 2.0;
			kameraHareketBilgileriniKonsolaYazdir();
		}
		break;
	case GLUT_KEY_DOWN:
		if (kameraHareket == false) {
			if (onBakis || yanBakis) {
				if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
					legolar[legolar.size() - farkDegeri]->yHareket -= 0.01;
				}
				else {
					for (int i = 0; i < legolar.size(); i++) {
						if (legolar[i]->baglilik) {
							legolar[i]->yHareket -= 0.5;
						}
					}
				}
			}
		}
		else {
			merkezZ += 2.0;
			kameraHareketBilgileriniKonsolaYazdir();
		}
		break;
	
	}

	// Çarpýþma olmadýðýnda baðlý olmayan legolarýn eski hareket verileri yenileriyle güncellenecektir.
	if (!butunCarpismaKontrolleri() && legolar[legolar.size() - farkDegeri]->baglilik == false) {
		eskiHareketBilgileriniGuncelle();
	}
	// Çarpýþma olduðunda baðlý olmayan legolarýn mevcut hareketleri, çarpýþma olmadýðý (eski hareket)
	// verilerine eþitlenecektir.
	else if (butunCarpismaKontrolleri() && legolar[legolar.size() - farkDegeri]->baglilik == false) {
		mevcutHareketBilgileriniEskiyeDondur();
	}

	// Baðlý legolarýn çarpýþma kontrolü bu fonksiyonla saðlanmaktadýr.
	tumBagliLegoCarpismalariniKontrolEt();
	
	glutPostRedisplay(); // Son yapýlan deðiþiklikler ekrana aktarýlýr.
}

// KlavyeDinleme fonksiyonu, num lock'taki sayý tuþlarýna göre hareketleri saðlayan fonksiyondur.
void KlavyeDinleme(unsigned char k, int x, int y) {
	
	if (k == 'q') {		exit(0);	}
	
	if (k == '6') {
		if (onBakis) {			
			legolar[legolar.size() - farkDegeri]->xHareket += 0.01;	
		}
		if (yanBakis) {
			legolar[legolar.size() - farkDegeri]->zHareket += 0.01;
		}
	}
	if (k == '4') {
		if (onBakis) {
			legolar[legolar.size() - farkDegeri]->xHareket -= 0.01;
		}
		if (yanBakis) {
			legolar[legolar.size() - farkDegeri]->zHareket -= 0.01;
		}
	}
	if (k == '8') {
		if (onBakis || yanBakis) {
			legolar[legolar.size() - farkDegeri]->yHareket += 0.01;
		}
	}
	if (k == '5') {
		if (onBakis || yanBakis) {
			legolar[legolar.size() - farkDegeri]->yHareket -= 0.01;
		}
	}
	
	if (k == 27) {		exit(0);	}
	
	if (k == 'd') {
		dondurmeIsleminiUygula();
	}

	// Çarpýþma olmadýðýnda baðlý olmayan legolarýn eski hareket verileri yenileriyle güncellenecektir.

	if (!butunCarpismaKontrolleri() && legolar[legolar.size() - farkDegeri]->baglilik == false) {
		eskiHareketBilgileriniGuncelle();
	}
	// Çarpýþma olduðunda baðlý olmayan legolarýn mevcut hareketleri, çarpýþma olmadýðý (eski hareket)
	// verilerine eþitlenecektir.
	else if (butunCarpismaKontrolleri() && legolar[legolar.size() - farkDegeri]->baglilik == false) {
		mevcutHareketBilgileriniEskiyeDondur();
	}
	glutPostRedisplay();
}




// Ekrana çizdirme görevleri üstlenen fonksiyonlar buraya yerleþtirilmiþtir.
void cizgiSegmenti(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(8, 8, -40);
	glRotatef(180, 1, 0, 0);

	glLoadIdentity();
	glTranslatef(3.75, -1.28, -10.0);
	

	
	menuCizgileri();
	
	menuYazilari();
	

	kameraYazilari();

	glLoadIdentity();
	glTranslatef(-6.25, -0.78, -10.0);

	menuCizgileri2();
	menuYazilari2();
	
	isiklandirma();
	copKutusuResmi.BMP_Isle(copKutusuResmi.kimlik, 2.0, 22.4, 13.8, -45, copKutusuResmi.renk);
	dondurmeResmi.BMP_Isle(dondurmeResmi.kimlik, 0.055, 1.69, 0.66, -4, dondurmeResmi.renk);
	cikisResmi.BMP_Isle(cikisResmi.kimlik, 0.05, 1.69, -0.38, -4, cikisResmi.renk);
	sifirlaResmi.BMP_Isle(sifirlaResmi.kimlik, 0.05, 1.69, -0.26, -4, sifirlaResmi.renk);
	kameraHareketiResmi.BMP_Isle(kameraHareketiResmi.kimlik, 0.05, 1.69, -0.14, -4, kameraHareketiResmi.renk);
	if(kisa1x1Resmi.aktifMi) 
		kisa1x1Resmi.BMP_Isle(kisa1x1Resmi.kimlik, kisa1x1Resmi.boyut, -0.72, 0.53, -2, kisa1x1Resmi.renk); 
	else if(uzun1x1Resmi.aktifMi) 
		uzun1x1Resmi.BMP_Isle(uzun1x1Resmi.kimlik, uzun1x1Resmi.boyut, -0.72, 0.48, -2, uzun1x1Resmi.renk);
	else if(kisa1x2Resmi.aktifMi)
		kisa1x2Resmi.BMP_Isle(kisa1x2Resmi.kimlik, kisa1x2Resmi.boyut, -0.72, 0.43, -2, kisa1x2Resmi.renk);
	else if(uzun1x2Resmi.aktifMi)
		uzun1x2Resmi.BMP_Isle(uzun1x2Resmi.kimlik, uzun1x2Resmi.boyut, -0.72, 0.38, -2, uzun1x2Resmi.renk);
	else if(kisa1x4Resmi.aktifMi)
		kisa1x4Resmi.BMP_Isle(kisa1x4Resmi.kimlik, kisa1x4Resmi.boyut, -0.72, 0.32, -2, kisa1x4Resmi.renk);
	else if(uzun1x4Resmi.aktifMi)
		uzun1x4Resmi.BMP_Isle(uzun1x4Resmi.kimlik, uzun1x4Resmi.boyut, -0.72, 0.27, -2, uzun1x4Resmi.renk);
	else if(kisa2x2Resmi.aktifMi)
		kisa2x2Resmi.BMP_Isle(kisa2x2Resmi.kimlik, kisa2x2Resmi.boyut, -0.72, 0.22, -2, kisa2x2Resmi.renk);
	else if(uzun2x2Resmi.aktifMi)
		uzun2x2Resmi.BMP_Isle(uzun2x2Resmi.kimlik, uzun2x2Resmi.boyut, -0.72, 0.17, -2, uzun2x2Resmi.renk);
	else if(kisa2x4Resmi.aktifMi)
		kisa2x4Resmi.BMP_Isle(kisa2x4Resmi.kimlik, kisa2x4Resmi.boyut, -0.72, 0.12, -2, kisa2x4Resmi.renk);
	else if(uzun2x4Resmi.aktifMi)
		uzun2x4Resmi.BMP_Isle(uzun2x4Resmi.kimlik, uzun2x4Resmi.boyut, -0.72, 0.07, -2, uzun2x4Resmi.renk);

	Zemin();
	
	
	// Kaç tane mevcut lego varsa o kadar legonun ekranda çizdirilmesinin kontrolü burada sürekli olarak yapýlmaktadýr.
	for (int i = 0; i < legolar.size(); i++) {

		legolar[i]->isle();
	}
				
			
	glutSwapBuffers();
	
	
}

int _tmain(int argc, _TCHAR argv[]) {



	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(pencereGenisligi, pencereUzunlugu);
	glutCreateWindow("Sanal 3-B Lego Oyunu");

	
	
	isle();
	
	// Uygulamanýn açýlýþta sahip olacaðý legolar burada tanýmlanýr.
	nesne1x1KisaOlustur();
	nesne1x1UzunOlustur();
	nesne1x2KisaOlustur();

	
	glutDisplayFunc(cizgiSegmenti);
	
	glutTimerFunc(0, zamanlayici, 0);
	glutMouseFunc(FareHareketi);
	glutMotionFunc(FareHareketiGeriBildirimiAktif);
	glutPassiveMotionFunc(FareHareketiGeriBildirimiPasif);
	glutReshapeFunc(yenidenSekillendir);
	
	glutKeyboardFunc(KlavyeDinleme);
	glutSpecialFunc(KlavyeHareketi);
	
	
	glutMainLoop();
	return 0;
}

void yenidenSekillendir(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(40, 1 + FullScreen, 2.0, 50.0);
	

	glMatrixMode(GL_MODELVIEW);

}



// Legolar arasýndaki tüm çarpýþmalarý kontrol eden fonksiyonlar burada tanýmlanmýþtýr.
bool butunCarpismaKontrolleri() {
	


		for (int i = 0; i < legolar.size(); i++) {
			for (int j = 0; j < legolar.size(); j++) {
				if (i == j) { continue; }
				
				
				
		

				bool durumlarX[13] = { (((int)((legolar[i]->xHareket) * carpimKatsayisi)) == ((int)((legolar[j]->xHareket) * carpimKatsayisi))),
					((int)(abs)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->xHareket) + genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)) ,
					((int)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->xHareket) - genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->xHareket) + genisletilmisObj1Xuzunlugu)) * carpimKatsayisi)),
					((int)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->xHareket) - genisletilmisObj1Xuzunlugu)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->xHareket) + genisletilmisObj1Xuzunlugu * 2)) * carpimKatsayisi)),
					((int)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->xHareket) - genisletilmisObj1Xuzunlugu * 2)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->xHareket + genisletilmisObj1Xuzunlugu) + genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->xHareket - genisletilmisObj1Xuzunlugu) - genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->xHareket) + genisletilmisObj1Xuzunlugu * 3)) * carpimKatsayisi)),
					((int)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->xHareket) - genisletilmisObj1Xuzunlugu * 3)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->xHareket + genisletilmisObj1Xuzunlugu*2) + genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)((((legolar[i]->xHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->xHareket - genisletilmisObj1Xuzunlugu*2) - genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
				};

				bool durumlarZ[13] = { (((int)((legolar[i]->zHareket) * carpimKatsayisi)) == ((int)((legolar[j]->zHareket) * carpimKatsayisi))),
					((int)(abs)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->zHareket) + genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)) ,
					((int)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->zHareket) - genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->zHareket) + genisletilmisObj1Xuzunlugu)) * carpimKatsayisi)),
					((int)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->zHareket) - genisletilmisObj1Xuzunlugu)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->zHareket) + genisletilmisObj1Xuzunlugu * 2)) * carpimKatsayisi)),
					((int)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->zHareket) - genisletilmisObj1Xuzunlugu * 2)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->zHareket + genisletilmisObj1Xuzunlugu) + genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->zHareket - genisletilmisObj1Xuzunlugu) - genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->zHareket) + genisletilmisObj1Xuzunlugu * 3)) * carpimKatsayisi)),
					((int)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->zHareket) - genisletilmisObj1Xuzunlugu * 3)) * carpimKatsayisi)),
					((int)(abs)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)(abs)((((legolar[j]->zHareket + genisletilmisObj1Xuzunlugu*2) + genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
					((int)((((legolar[i]->zHareket))) * carpimKatsayisi)) == ((int)((((legolar[j]->zHareket - genisletilmisObj1Xuzunlugu*2) - genisletilmisObj1Xuzunlugu / 2)) * carpimKatsayisi)),
				};

				
				bool durum = 0;
				bool durum2 = 0;
				bool durum3 = 0;
				bool durum4 = 0;
				bool durum5 = 0;
				bool durum6 = 0;
				int uzaklikDegeri = 2.3;
				
				bool bagliDurumlar1X = durumlarX[0] || durumlarX[3] || durumlarX[4] || durumlarX[5] || durumlarX[6] || durumlarX[9] || durumlarX[10];
				bool bagliDurumlar1Z = durumlarZ[0] || durumlarZ[3] || durumlarZ[4] || durumlarZ[5] || durumlarZ[6] || durumlarZ[9] || durumlarZ[10];
				bool bagliDurumlar2X = durumlarX[1] || durumlarX[2] || durumlarX[7] || durumlarX[8];
				bool bagliDurumlar2Z = durumlarZ[1] || durumlarZ[2] || durumlarZ[7] || durumlarZ[8];
				

				if (((legolar[i]->Xuzunlugu == legolar[j]->Xuzunlugu) && (legolar[i]->Zuzunlugu == legolar[j]->Zuzunlugu)) && (legolar[i]->dondurmeIslemi == false && legolar[j]->dondurmeIslemi== false)) {
					durum = ((bagliDurumlar1X) && (bagliDurumlar1Z));
				}

				else if (((legolar[i]->Zuzunlugu == legolar[j]->Zuzunlugu) && (legolar[i]->Xuzunlugu == legolar[j]->Xuzunlugu)) && (legolar[i]->dondurmeIslemi == true && legolar[j]->dondurmeIslemi == true)) {
					durum = ((bagliDurumlar1X) && (bagliDurumlar1Z));
				}			
				else if (((legolar[i]->Xuzunlugu == obj1Xuzunlugu) && ((legolar[j]->Xuzunlugu == obj3Xuzunlugu) || legolar[j]->Xuzunlugu == obj5Xuzunlugu) && (legolar[i]->Zuzunlugu == legolar[j]->Zuzunlugu)) && (legolar[j]->dondurmeIslemi== false) ) {
					
					durum2 = ((bagliDurumlar2X) && (durumlarZ[0]));
				}
				else if (((legolar[i]->Xuzunlugu == obj1Xuzunlugu) && ((legolar[j]->Xuzunlugu == obj3Zuzunlugu) || legolar[j]->Xuzunlugu == obj5Zuzunlugu) && (legolar[i]->Zuzunlugu == legolar[j]->Xuzunlugu)) && (legolar[j]->dondurmeIslemi == true)) {

					durum2 = ((bagliDurumlar2Z) && (durumlarX[0]));
				}
				else if (((((legolar[i]->Xuzunlugu == obj3Xuzunlugu) || (legolar[i]->Xuzunlugu == obj5Xuzunlugu)) && ((legolar[j]->Xuzunlugu == obj3Xuzunlugu) || (legolar[j]->Xuzunlugu == obj5Xuzunlugu))) && (legolar[i]->Zuzunlugu == legolar[j]->Zuzunlugu)) && legolar[j]->dondurmeIslemi == false) {
					durum3 = ((bagliDurumlar1X || durumlarX[11] || durumlarX[12]) && (bagliDurumlar1Z || durumlarZ[11] || durumlarZ[12]));
				}
				else if (((((legolar[i]->Xuzunlugu == obj3Xuzunlugu) || (legolar[i]->Xuzunlugu == obj5Xuzunlugu)) && ((legolar[j]->Xuzunlugu == obj3Zuzunlugu) || (legolar[j]->Xuzunlugu == obj5Zuzunlugu))) && (legolar[i]->Zuzunlugu == legolar[j]->Xuzunlugu)) && legolar[j]->dondurmeIslemi == true) {
					durum3 = ((bagliDurumlar1Z || durumlarZ[11] || durumlarZ[12]) && (bagliDurumlar1X || durumlarX[11] || durumlarX[12] ));
				}
				else if (((legolar[i]->Xuzunlugu == obj1Xuzunlugu) && ((legolar[j]->Xuzunlugu == obj7Xuzunlugu) || (legolar[j]->Xuzunlugu == obj9Xuzunlugu))) && legolar[j]->dondurmeIslemi == false) {
					durum4 = ((bagliDurumlar2X) && (durumlarZ[1] || durumlarZ[2]));
				}
				else if (((legolar[i]->Xuzunlugu == obj1Xuzunlugu) && ((legolar[j]->Xuzunlugu == obj7Zuzunlugu) || (legolar[j]->Xuzunlugu == obj9Zuzunlugu))) && legolar[j]->dondurmeIslemi == true) {
					durum4 = ((bagliDurumlar2Z) && (durumlarX[1] || durumlarX[2]));
				}
				else if ((((legolar[i]->Xuzunlugu == obj3Xuzunlugu) || (legolar[i]->Xuzunlugu == obj5Xuzunlugu)) && ((legolar[j]->Xuzunlugu == obj7Xuzunlugu) || (legolar[j]->Xuzunlugu == obj9Xuzunlugu))) && legolar[j]->dondurmeIslemi == false) {
					durum5 = ((bagliDurumlar1X) && (bagliDurumlar2Z));
				}
				else if ((((legolar[i]->Xuzunlugu == obj3Xuzunlugu) || (legolar[i]->Xuzunlugu == obj5Xuzunlugu)) && ((legolar[j]->Xuzunlugu == obj7Zuzunlugu) || (legolar[j]->Xuzunlugu == obj9Zuzunlugu))) && legolar[j]->dondurmeIslemi == true) {
					durum5 = ((bagliDurumlar1Z) && (bagliDurumlar2X));
				}

				if ((durum || durum2 || durum3 || durum4 || durum5) &&
					((((legolar[j]->xHareket + uzaklikDegeri >= legolar[i]->xHareket) && (legolar[j]->xHareket - uzaklikDegeri  <= legolar[i]->xHareket)) &&
						((legolar[j]->yHareket + uzaklikDegeri  >= legolar[i]->yHareket) && (legolar[j]->yHareket - uzaklikDegeri  <= legolar[i]->yHareket)) &&
						((legolar[j]->zHareket + uzaklikDegeri  >= legolar[i]->zHareket) && (legolar[j]->zHareket - uzaklikDegeri  <= legolar[i]->zHareket)))) )
				{

					legolar[i]->Yuzunlugu = legolar[i]->YuzunluguSilindirsiz; // bu durumlarda silindirsiz y uzunluðuna eþit-
					//leniyor.
					legolar[i]->silindirsizMi = true;
					legolar[j]->Yuzunlugu = legolar[j]->YuzunluguSilindirsiz;
					legolar[j]->silindirsizMi = true;

					if ((i == legolar.size() - farkDegeri) || (j == legolar.size() - farkDegeri)) {
						silindirOturtmaKontrolu = true;
					}
					
				}
				else {
					legolar[i]->Yuzunlugu = legolar[i]->YuzunluguYedek;
					
					legolar[j]->Yuzunlugu = legolar[j]->YuzunluguYedek;
					

					
				}
			
				if (((legolar[i]->xHareket + (legolar[i]->Xuzunlugu / 2)) >= (legolar[j]->xHareket - (legolar[j]->Xuzunlugu / 2))) &&
					((legolar[i]->xHareket + (legolar[i]->Xuzunlugu / 2)) <= (legolar[j]->xHareket + (legolar[j]->Xuzunlugu / 2))) &&
					((legolar[i]->yHareket - legolar[i]->Yuzunlugu / 2) <= (legolar[j]->yHareket + legolar[j]->Yuzunlugu / 2)) &&
					((legolar[i]->yHareket + legolar[i]->Yuzunlugu / 2) >= (legolar[j]->yHareket - legolar[j]->Yuzunlugu / 2)) &&
					((legolar[i]->zHareket + legolar[i]->Zuzunlugu / 2) >= (legolar[j]->zHareket - legolar[j]->Zuzunlugu / 2)) &&
					((legolar[i]->zHareket - legolar[i]->Zuzunlugu / 2) <= (legolar[j]->zHareket + legolar[j]->Zuzunlugu / 2))) {

					carpisanLego1 = legolar[i];
					carpisanLego2 = legolar[j];

					return true;

				}
				
			}
			
		}
	
	return false;	
}
	
void zamanlayici(int) {


	glutReshapeWindow(pencereGenisligi, pencereUzunlugu); // Pencere uzunluðu ve geniþliði sabit kalacaktýr.
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, zamanlayici, 0);
	
	for (int i = 0; i < legolar.size(); i++) {
		legolar[i]->silindirsizMi = false;
	}


	if (legolar.size() != 0) {

		if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
			if (legolar[legolar.size() - farkDegeri]->yHareket <= -4.8) {
				legolar[legolar.size() - farkDegeri]->yHareket = -4.8;
			}
		}

		else {
			double enAlcaktaDuranLegoYHareketi = 0;
			for (int i = 0; i < legolar.size(); i++) {
				if (legolar[i]->baglilik == true) {

					if (legolar[i]->yHareket < enAlcaktaDuranLegoYHareketi) {
						enAlcaktaDuranLegoYHareketi = legolar[i]->yHareket;
					}
				}

			}
			if (enAlcaktaDuranLegoYHareketi < -4.8) {
				double aradakiFark = abs(-4.8 - (enAlcaktaDuranLegoYHareketi));
				for (int i = 0; i < legolar.size(); i++) {
					if (legolar[i]->baglilik == true) {
						legolar[i]->yHareket += aradakiFark;
					}

				}
			}
		}
	}

	if (butunCarpismaKontrolleri()) {

		if (legolar[legolar.size() - farkDegeri]->baglilik == false ) {
			mevcutHareketBilgileriniEskiyeDondur();
		}
		
		carpismaTespitiSayaci2++;

		if (carpismaTespitiSayaci2 >= 5) {
			
			if (legolar[legolar.size() - farkDegeri]->baglilik == false ) {
				
				legolar[legolar.size() - farkDegeri]->xHareketEski += 0.5;
				
				
			}
			else {
				for (int i = 0; i < legolar.size(); i++) {
					if (legolar[i]->baglilik) {
						carpismaTespiti = true;
							legolar[i]->xHareket = legolar[i]->xHareketEski;
							legolar[i]->yHareket = legolar[i]->yHareketEski;
							legolar[i]->zHareket = legolar[i]->zHareketEski;
						
					}
				}
			}
								
		}
		
	}

	if ( !butunCarpismaKontrolleri() ) {
		carpismaTespitiSayaci2 = 0;
		
	}
	
	if (carpismaTespiti == true) {
		carpismaTespitiSayaci++;
		if (abs(carpismaTespitiSayaci) >= 20) {
			carpismaTespiti = false;
			carpismaTespitiSayaci = 0;
		}
	}

	
	if (silindirOturtmaKontrolu == true) {
		silindirOturtmaSayaci++;
		if (abs(silindirOturtmaSayaci) >= 20) {
			silindirOturtmaKontrolu = false;
			silindirOturtmaSayaci = 0;
		}
	}

	
	




}



