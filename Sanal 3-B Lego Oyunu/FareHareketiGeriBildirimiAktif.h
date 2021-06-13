#pragma once



class BMP {
public:
	unsigned int kimlik;
	double boyut = 0.18;
	double xKaydirma;
	double yKaydirma;
	double zKaydirma;
	double renk = 5.0f;
	bool aktifMi = false;
	

	unsigned int BMPYukle(const char* dosyaAdi) {
		SDL_Surface* _BMP;
		_BMP = SDL_LoadBMP(dosyaAdi);
		glGenTextures(1, &kimlik);
		glBindTexture(GL_TEXTURE_2D, kimlik);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _BMP->w, _BMP->h, 0, GL_RGB, GL_UNSIGNED_BYTE_2_3_3_REV, _BMP->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		SDL_FreeSurface(_BMP);
		return kimlik;
	}

	void BMP_Isle(int kimlik, double boyut, double xKaydirma, double yKaydirma, double zKaydirma, double renk) {
		this->kimlik = kimlik;
		this->boyut = boyut;
		this->xKaydirma = xKaydirma;
		this->yKaydirma = yKaydirma;
		this->zKaydirma = zKaydirma;
		this->renk = renk;

		glLoadIdentity();
		glTranslatef(xKaydirma, yKaydirma, zKaydirma);
		glRotatef(180, 1, 0, 0);
		glColor3f(renk, renk, renk);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, kimlik);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-boyut, boyut, 0.0);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-boyut, -boyut, 0.0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(boyut, -boyut, 0.0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(boyut, boyut, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

	}

};

BMP copKutusuResmi;
BMP dondurmeResmi;
BMP cikisResmi;
BMP sifirlaResmi;
BMP kameraHareketiResmi;
BMP kisa1x1Resmi;
BMP uzun1x1Resmi;
BMP kisa1x2Resmi;
BMP uzun1x2Resmi;
BMP kisa1x4Resmi;
BMP uzun1x4Resmi;
BMP kisa2x2Resmi;
BMP uzun2x2Resmi;
BMP kisa2x4Resmi;
BMP uzun2x4Resmi;

bool butunCarpismaKontrolleri();
void kameraHareketSuruklemeIcýnVerileriniGuncelle();
void kameraHareketBilgileriniKonsolaYazdir();




void FareHareketiGeriBildirimiAktif(int xPos, int yPos) {

	double xPikselFarkDegeri = 0;
	double yPikselFarkDegeri = 0;
	double xPikselFarkDegeriInt = 0;
	double yPikselFarkDegeriInt = 0;

	if (legolar.size() != 0 && carpisanLego1 != nullptr && carpisanLego2 != nullptr) {
		
			if (legolar[legolar.size() - farkDegeri]->baglilik == false &&
				carpisanLego1->silindirsizMi == true && carpisanLego2->silindirsizMi == true) {
				if (butunCarpismaKontrolleri()) {
					carpisanLego1->silindirsizkenCarpisma = true;
					carpisanLego2->silindirsizkenCarpisma = true;
					silindirsizCarpismaSayaci = 0;
				}

			}
			else {
				silindirsizCarpismaSayaci++;
				if (silindirsizCarpismaSayaci >= 5) {
					if ((carpisanLego1->silindirsizMi == false || carpisanLego2->silindirsizMi == false) && 
						legolar[legolar.size()-farkDegeri]->baglilik == false) {
						if (carpisanLego1 == legolar[legolar.size() - farkDegeri]) {
							carpisanLego1->silindirsizkenCarpisma = false;
						}
						else {
							carpisanLego2->silindirsizkenCarpisma = false;
						}
					}
				}
			}
		
	}

	if (objLegoHareket && legolar.size() != 0) {

		if (onBakis) {
			xPiksel = (float)xPos / 64;
			yPiksel = (680 - (float)yPos) / 58;

			xPikselInt = xPos / 64;
			yPikselInt = (680 - yPos) / 58;

			xPikselFarkDegeri = xPiksel - xPikselEski;
			yPikselFarkDegeri = yPiksel - yPikselEski;

			xPikselFarkDegeriInt = xPikselInt - xPikselEskiInt;
			yPikselFarkDegeriInt = yPikselInt - yPikselEskiInt;


			if (!butunCarpismaKontrolleri()) {
				if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
					legolar[legolar.size() - farkDegeri]->xHareketEski = legolar[legolar.size() - farkDegeri]->xHareket;
					legolar[legolar.size() - farkDegeri]->yHareketEski = legolar[legolar.size() - farkDegeri]->yHareket;
					legolar[legolar.size() - farkDegeri]->xHareket += xPikselFarkDegeri;
					legolar[legolar.size() - farkDegeri]->yHareket += yPikselFarkDegeri;
				}

				else {
					
					for (int i = 0; i < legolar.size(); i++) {
						if (legolar[i]->baglilik) {
							
								legolar[i]->xHareketEski = legolar[i]->xHareket;
								legolar[i]->yHareketEski = legolar[i]->yHareket;
								legolar[i]->zHareketEski = legolar[i]->zHareket;
							
							legolar[i]->xHareket += xPikselFarkDegeriInt;
							legolar[i]->yHareket += yPikselFarkDegeriInt;
							cout << xPikselFarkDegeriInt;
						}

					}
					

				}


			}


			if (carpismaTespiti == true) {
				if (!butunCarpismaKontrolleri()) {
					carpismaTespitiSayaci++;
				}
				if (carpismaTespitiSayaci >= 20) {
					carpismaTespiti = false;
					carpismaTespitiSayaci = 0;
				}
			}
			cout << "Hareketler: " << "x: " << legolar[legolar.size() - farkDegeri]->xHareket << " y: " << legolar[legolar.size() - farkDegeri]->yHareket << endl;

			
		}
		if (yanBakis) {
			xPiksel = (float)xPos / 52;
			yPiksel = (680 - (float)yPos) / 46;

			xPikselInt = xPos / 52;
			yPikselInt = (680 - yPos) / 46;

			xPikselFarkDegeri = xPiksel - xPikselEski;
			yPikselFarkDegeri = yPiksel - yPikselEski;

			xPikselFarkDegeriInt = xPikselInt - xPikselEskiInt;
			yPikselFarkDegeriInt = yPikselInt - yPikselEskiInt;

			if (!butunCarpismaKontrolleri()) {
				if (legolar[legolar.size() - farkDegeri]->baglilik == false) {
					legolar[legolar.size() - farkDegeri]->zHareketEski = legolar[legolar.size() - farkDegeri]->zHareket;
					legolar[legolar.size() - farkDegeri]->yHareketEski = legolar[legolar.size() - farkDegeri]->yHareket;
					legolar[legolar.size() - farkDegeri]->zHareket += xPikselFarkDegeri;
					legolar[legolar.size() - farkDegeri]->yHareket += yPikselFarkDegeri;
				}

				else {
					for (int i = 0; i < legolar.size(); i++) {
						if (legolar[i]->baglilik) {
							
								legolar[i]->xHareketEski = legolar[i]->xHareket;
								legolar[i]->yHareketEski = legolar[i]->yHareket;
								legolar[i]->zHareketEski = legolar[i]->zHareket;
							
							legolar[i]->zHareket += xPikselFarkDegeriInt;
							legolar[i]->yHareket += yPikselFarkDegeriInt;
						}

					}

				}
			}


			if (carpismaTespiti == true) {
				if (!butunCarpismaKontrolleri()) {
					carpismaTespitiSayaci++;
				}
				if (carpismaTespitiSayaci >= 20) {
					carpismaTespiti = false;
					carpismaTespitiSayaci = 0;
				}
			}

			cout << "Hareketler: " << "z: " << legolar[legolar.size() - farkDegeri]->zHareket << " y: " << legolar[legolar.size() - farkDegeri]->yHareket << endl;

			
		}

	}

	if (kameraHareket) {
		xPiksel = -(float)xPos;
		yPiksel = (680 - (float)yPos);

		xPikselFarkDegeri = xPiksel - xPikselEski;
		yPikselFarkDegeri = yPiksel - yPikselEski;

		phi += xPikselFarkDegeri;
		phi2 += yPikselFarkDegeri;
		kameraHareketSuruklemeIcýnVerileriniGuncelle();
		kameraHareketBilgileriniKonsolaYazdir();

	}




	if ((xPos >= 1170) && (xPos <= 1265)) {
		if (((yPos >= 11) && (yPos <= 108))) {
			copKutusuResmi.renk = 1.0;
			legoSilYazisiS.aktifMi = true;
		}
		else
		{
			copKutusuResmi.renk = 5.0;
			legoSilYazisiS.aktifMi = false;
		}

	}
	else
	{
		copKutusuResmi.renk = 5.0;
		legoSilYazisiS.aktifMi = false;
	}

	if (onBakis) {
		xPikselEski = (float)xPos / 64;
		yPikselEski = (680 - (float)yPos) / 58;

		xPikselEskiInt = xPos / 64;
		yPikselEskiInt = (680 - yPos) / 58;
	}
	else if (yanBakis) {
		xPikselEski = (float)xPos / 52;
		yPikselEski = (680 - (float)yPos) / 46;

		xPikselEskiInt = xPos / 52;
		yPikselEskiInt = (680 - yPos) / 46;
	}
	else if (kameraHareket) {
		xPikselEski = -(float)xPos;
		yPikselEski = (680 - (float)yPos);
	}


	
	tumBagliLegoCarpismalariniKontrolEt();
	glutPostRedisplay();
}


void resimRenkleriniVarsayilanYap() {
	dondurmeResmi.renk = 5.0;
	cikisResmi.renk = 5.0;
	sifirlaResmi.renk = 5.0;
	kameraHareketiResmi.renk = 5.0;
}

void tumOnizlemeleriKapat() {
	kisa1x1Resmi.aktifMi = false;
	uzun1x1Resmi.aktifMi = false;
	kisa1x2Resmi.aktifMi = false;
	uzun1x2Resmi.aktifMi = false;
	kisa1x4Resmi.aktifMi = false;
	uzun1x4Resmi.aktifMi = false;
	kisa2x2Resmi.aktifMi = false;
	uzun2x2Resmi.aktifMi = false;
	kisa2x4Resmi.aktifMi = false;
	uzun2x4Resmi.aktifMi = false;
}