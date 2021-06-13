#pragma once


vector <Lego*> legolar;

Lego* aktifLego;

Lego* carpisanLego1;

Lego* carpisanLego2;


void nesne1x1KisaOlustur();
void nesne1x1UzunOlustur();
void nesne1x2KisaOlustur();
void nesne1x2UzunOlustur();
void nesne1x4KisaOlustur();
void nesne1x4UzunOlustur();
void nesne2x2KisaOlustur();
void nesne2x2UzunOlustur();
void nesne2x4KisaOlustur();
void nesne2x4UzunOlustur();
void onBakisLegoSecmeKontrolu(double x, double y, string islemTipi);
void yanBakisLegoSecmeKontrolu(double x, double y, string islemTipi);
void renkDegistir(double kirmizi, double yesil, double mavi);
bool butunCarpismaKontrolleri();
void kameraHareketeGecisVerileriniGuncelle();
void tumBagliLegoCarpismalariniKontrolEt();
void bagliLegoKontrolu();
void legoBaglamalariniIptalEt();


// Farenin sað veya sol tuþuna basýlmasýyla gerçekleþen durumlar burada tanýmlanmýþtýr.
void FareHareketi(int button, int durum, int farex, int farey) {

	// Eðer farenin tuþu sað ise ve tuþa basýldýðýnda
	if (button == GLUT_RIGHT_BUTTON && durum == GLUT_DOWN) {

		if (onBakis) {
			xPikselEski = (float)farex / 64;
			yPikselEski = (680 - (float)farey) / 58;

			xPikselEskiInt = farex / 64;
			yPikselEskiInt = (680 - farey) / 58;
		}
		else if (yanBakis) {
			xPikselEski = (float)farex / 52;
			yPikselEski = (680 - (float)farey) / 46;

			xPikselEskiInt = farex / 52;
			yPikselEskiInt = (680 - farey) / 46;

		}
		else if (kameraHareket) {
			xPikselEski = -(float)farex;
			yPikselEski = (680 - (float)farey);
		}
		

		legoBaglamalariniIptalEt();
		kontrol = true;
		x = farex;
		y = 680 - farey;

		if (!butunCarpismaKontrolleri()) {

			if (onBakis) {
				onBakisLegoSecmeKontrolu(x, y, "secme");
			}
			else if (yanBakis) {
				yanBakisLegoSecmeKontrolu(x, y, "secme");
			}
		}
	}

	
	// Eðer farenin tuþu sol ise ve tuþa basýldýðýnda
	if (button == GLUT_LEFT_BUTTON && durum == GLUT_DOWN) {


		if (onBakis) {
			xPikselEski = (float)farex / 64;
			yPikselEski = (680 - (float)farey) / 58;

			xPikselEskiInt = farex / 64;
			yPikselEskiInt = (680 - farey) / 58;
		}
		else if (yanBakis) {
			xPikselEski = (float)farex / 52;
			yPikselEski = (680 - (float)farey) / 46;

			xPikselEskiInt = farex / 52;
			yPikselEskiInt = (680 - farey) / 46;

		}
		else if (kameraHareket) {
			xPikselEski = -(float)farex;
			yPikselEski = (680 - (float)farey);
		}
		
		

		kontrol = true;
		x = farex;
		y = 680 - farey;

		if (!butunCarpismaKontrolleri()) {

			if (onBakis) {
				onBakisLegoSecmeKontrolu(x, y, "secme");
			}
			else if (yanBakis) {
				yanBakisLegoSecmeKontrolu(x, y, "secme");
			}
		}

		cout << "Farenin sol tusuna basildi." << endl;
		cout << "Pikseller: " << farex << " : " << farey << endl;


		if ((farex >= 1118) && (farex <= 1307)) {

			if ((farey >= 194) && (farey <= 227)) {

				if (legolar[legolar.size() - farkDegeri]->baglilik == false) {

					if (legolar[legolar.size() - farkDegeri]->dondurmeIslemi) {
						legolar[legolar.size() - farkDegeri]->dondurmeIslemi = false;
					}
					else {
						legolar[legolar.size() - farkDegeri]->dondurmeIslemi = true;
					}

				}
			
			}

			
			if ((farey >= 469) && (farey <= 498)) {
				
				ExitProcess(0);
			}

			if ((farey >= 435) && (farey <= 462)) {
				degerleriSifirla();

			}

			if ((farey >= 404) && (farey <= 430)) {


				if (onBakis == true) {

					onBakis = false;
					yanBakis = true;
					gozX = -19.7901;
					gozY = 2.44394;
					gozZ = 0.487037;
					merkezX = 0;
					merkezY = 0;
					merkezZ = -18;
					yukariY = 1;
					objLegoHareket = true;
				}
				else if (yanBakis == true) {
					
					objLegoHareket = false;
					yanBakis = false;
					kameraHareket = true;
					merkezX = 0;
					merkezY = 0;
					merkezZ = -20;
					phi = 45;
					phi2 = 45;
					theta = 45;
					kameraHareketeGecisVerileriniGuncelle();
				}
				else if (kameraHareket == true) {

					kameraHareket = false;
					onBakis = true;
					kameraHareketeGecisVerileriniGuncelle();
					objLegoHareket = true;
				}

			}

		}
		if (legolar.size() != 0) {

			if ((farey >= 292) && (farey <= 337)) {
				if ((farex >= 1135) && (farex <= 1179)) {
					renkDegistir(5.0, 0.0, 0.0);						
				}
				else if ((farex >= 1189) && (farex <= 1234)) {
					renkDegistir(0.0, 5.0, 0.0);
					}
				
				else if ((farex >= 1243) && (farex <= 1288)) {
					renkDegistir(0.0, 5.0, 5.0);
					
					}				
			}

			else if ((farey >= 345) && (farey <= 388)) {
				if ((farex >= 1135) && (farex <= 1179)) {
					renkDegistir(5.0, 5.0, 0.0);					
					}
				
				else if ((farex >= 1189) && (farex <= 1234)) {
					renkDegistir(5.0, 0.0, 5.0);					
					}				

				else if ((farex >= 1243) && (farex <= 1288)) {
					renkDegistir(5.0, 5.0, 5.0);
					}
				
			}
		}


		

		if ( !butunCarpismaKontrolleri()) {
			if ((farex >= 29) && (farex <= 184)) {
				if ((farey >= 56) && (farey <= 85)) {
					nesne1x1KisaOlustur();
				}
				if ((farey >= 92) && (farey <= 122)) {
					nesne1x1UzunOlustur();
				}
				if ((farey >= 131) && (farey <= 160)) {
					nesne1x2KisaOlustur();
				}
				if ((farey >= 168) && (farey <= 196)) {
					nesne1x2UzunOlustur();
				}
				if ((farey >= 204) && (farey <= 234)) {
					nesne1x4KisaOlustur();
				}
				if ((farey >= 241) && (farey <= 271)) {
					nesne1x4UzunOlustur();
				}
				if ((farey >= 278) && (farey <= 307)) {
					nesne2x2KisaOlustur();
				}
				if ((farey >= 315) && (farey <= 345)) {
					nesne2x2UzunOlustur();
				}
				if ((farey >= 353) && (farey <= 383)) {
					nesne2x4KisaOlustur();
				}
				if ((farey >= 390) && (farey <= 419)) {
					nesne2x4UzunOlustur();

				}
				if (legolar.size() != 0) {
					cout << "hacim : " << legolar[legolar.size() - farkDegeri]->hacim << endl;
				}
			}
		}			
	}

	// Eðer farenin tuþu sol ise ve bu tuþ býrakýldýðýnda
	if (button == GLUT_LEFT_BUTTON && durum == GLUT_UP) {
		cout << "Farenin sol tusu birakildi." << endl;
		kontrol = false;
		
		tumBagliLegoCarpismalariniKontrolEt();

		if ((farex >= 1170) && (farex <= 1265)) {
			if (((farey >= 11) && (farey <= 108))) {
				if (legolar.size() != 0) {
					int geciciDeger = legolar.size() - farkDegeri;
					legolar.erase(legolar.begin()+geciciDeger);
					farkDegeri = 1;
					farkDegeriIslem = 1;
				}
			}		
		}
	}

	glutPostRedisplay();
}


