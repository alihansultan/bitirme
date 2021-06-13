#pragma once

void legoBaglamalariniIptalEt();


void nesne1x1KisaOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("1x1kisa.obj", 0, 5, 3, obj1Xuzunlugu, obj1Yuzunlugu, obj1Yuzunlugu, obj1YuzunluguSilindirsiz, obj1Zuzunlugu,
		0, 2, -18.5, 0, 2, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
	
}

void nesne1x1UzunOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("1x1uzun.obj", 5, 5, 0, obj2Xuzunlugu, obj2Yuzunlugu, obj2Yuzunlugu, obj2YuzunluguSilindirsiz, obj2Zuzunlugu,
		-2, 0, -18.5, -2, 0, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne1x2KisaOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("1x2kisa.obj", 0, 5, 5, obj3Xuzunlugu, obj3Yuzunlugu, obj3Yuzunlugu, obj3YuzunluguSilindirsiz, obj3Zuzunlugu,
		-4, -1, -18.5, -4, -1, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne1x2UzunOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("1x2uzun.obj", 5, 0, 0, obj4Xuzunlugu, obj4Yuzunlugu, obj4Yuzunlugu, obj4YuzunluguSilindirsiz, obj4Zuzunlugu,
		2, -3.5, -18.5, 2, -3.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne1x4KisaOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("1x4kisa.obj", 5, 5, 5, obj5Xuzunlugu, obj5Yuzunlugu, obj5Yuzunlugu, obj5YuzunluguSilindirsiz, obj5Zuzunlugu,
		0, -3.5, -18.5, 0, -3.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne1x4UzunOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("1x4uzun.obj", 0, 5, 5, obj6Xuzunlugu, obj6Yuzunlugu, obj6Yuzunlugu, obj6YuzunluguSilindirsiz, obj6Zuzunlugu,
		-2, -3.5, -18.5, -2, -3.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();  
}

void nesne2x2KisaOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("2x2kisa.obj", 0, 0, 5, obj7Xuzunlugu, obj7Yuzunlugu, obj7Yuzunlugu, obj7YuzunluguSilindirsiz, obj7Zuzunlugu,
		-1, -5.5, -18.5, -1, -4.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne2x2UzunOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("2x2uzun.obj", 5, 5, 0, obj8Xuzunlugu, obj8Yuzunlugu, obj8Yuzunlugu, obj8YuzunluguSilindirsiz, obj8Zuzunlugu,
		2, -5.5, -18.5, 2, -4.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne2x4KisaOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("2x4kisa.obj", 5, 0, 5, obj9Xuzunlugu, obj9Yuzunlugu, obj9Yuzunlugu, obj9YuzunluguSilindirsiz, obj9Zuzunlugu,
		4, -5.5, -18.5, 4, -4.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}

void nesne2x4UzunOlustur() {
	farkDegeri = 1;
	Lego* lego = new Lego("2x4uzun.obj", 5, 0, 5, obj10Xuzunlugu, obj10Yuzunlugu, obj10Yuzunlugu, obj10YuzunluguSilindirsiz, obj10Zuzunlugu,
		-3, -3.5, -18.5, -3, -3.5, -18.5);
	legolar.push_back(lego);
	legolar[legolar.size() - 1]->ekle();
}




void onBakisLegoSecmeKontrolu(double x, double y, string islemTipi) { // ekrandan lego seçme algoritmasý

	Lego* t_aktifLego = legolar[0];
	aktifLego = t_aktifLego;

	

	for (int i = 0; i < legolar.size(); i++) {
		
		
		if (aktifLego->onBakisUzaklikBul(x, y, legolar[i]->xHareket, legolar[i]->yHareket) < legolar[i]->onBakisUzaklikBul(x, y, legolar[i]->xHareket, legolar[i]->yHareket)) {
			t_aktifLego = legolar[i];
		}

		if (t_aktifLego->onBakisUzaklikBul(x, y, legolar[i]->xHareket, legolar[i]->yHareket) <= 1.25) {
			
			aktifLego = t_aktifLego;
			aktifLego->aktifMi = true;
			legoSecYazisiS.aktifMi = true;
			if (islemTipi == "secme") {
				objLegoHareket = true;	
				farkDegeri = legolar.size() - i; // fareHareketi için
				farkDegeriIslem = legolar.size() - i;

				
			}
			else if (islemTipi == "gezinme") {
				farkDegeriIslem = legolar.size() - i;
				legolar[i]->sinyal = -4.0; // geriBildirimiPasif için
			}
			break;

		}
		else {
			legoSecYazisiS.aktifMi = false;
			if (islemTipi == "gezinme") {
				legolar[i]->sinyal = 0; // geriBildirimiPasif için
			}
		}

	}

}


void yanBakisLegoSecmeKontrolu(double x, double y, string islemTipi) {

	Lego* t_aktifLego = legolar[0];
	aktifLego = t_aktifLego;



	for (int i = 0; i < legolar.size(); i++) {


		if (aktifLego->yanBakisUzaklikBul(x, y, legolar[i]->zHareket+18, legolar[i]->yHareket) < legolar[i]->yanBakisUzaklikBul(x, y, legolar[i]->zHareket +18, legolar[i]->yHareket)) {
			t_aktifLego = legolar[i];
		}

		if (t_aktifLego->yanBakisUzaklikBul(x, y, legolar[i]->zHareket +18, legolar[i]->yHareket) <= 1.25) {
			
			aktifLego = t_aktifLego;
			aktifLego->aktifMi = true;
			legoSecYazisiS.aktifMi = true;
			if (islemTipi == "secme") {
				objLegoHareket = true;	
				farkDegeri = legolar.size() - i; // fareHareketi için
				farkDegeriIslem = legolar.size() - i;

			}
			else if (islemTipi == "gezinme") {
				farkDegeriIslem = legolar.size() - i;
				legolar[i]->sinyal = -4.0; // geriBildirimiPasif için
			}
			break;

		}
		else {
			legoSecYazisiS.aktifMi = false;
			if (islemTipi == "gezinme") {
				legolar[i]->sinyal = 0; // geriBildirimiPasif için
			}
		}



	}

}





void renkDegistir(double kirmizi, double yesil, double mavi) {
	legolar[legolar.size() - farkDegeri]->kirmizi = kirmizi;
	legolar[legolar.size() - farkDegeri]->yesil = yesil;
	legolar[legolar.size() - farkDegeri]->mavi = mavi;

}


void eskiHareketBilgileriniGuncelle() {

	legolar[legolar.size() - farkDegeri]->xHareketEski = legolar[legolar.size() - farkDegeri]->xHareket;
	legolar[legolar.size() - farkDegeri]->yHareketEski = legolar[legolar.size() - farkDegeri]->yHareket;
	legolar[legolar.size() - farkDegeri]->zHareketEski = legolar[legolar.size() - farkDegeri]->zHareket;
}

void mevcutHareketBilgileriniEskiyeDondur() {
	carpismaTespiti = true;
	legolar[legolar.size() - farkDegeri]->xHareket = legolar[legolar.size() - farkDegeri]->xHareketEski;
	legolar[legolar.size() - farkDegeri]->yHareket = legolar[legolar.size() - farkDegeri]->yHareketEski;
	legolar[legolar.size() - farkDegeri]->zHareket = legolar[legolar.size() - farkDegeri]->zHareketEski;
}

void dondurmeIsleminiUygula() {
	if (legolar[legolar.size() - farkDegeri]->dondurmeIslemi) {
		legolar[legolar.size() - farkDegeri]->dondurmeIslemi = false;
	}
	else {
		legolar[legolar.size() - farkDegeri]->dondurmeIslemi = true;
	}
}

void kameraHareketeGecisVerileriniGuncelle() {
	gozX = r * sin(deg2rad(theta)) * sin(deg2rad(phi));
	gozY = r * cos(deg2rad(theta)) * sin(deg2rad(phi));
	gozZ = r * sin(deg2rad(theta)) * cos(deg2rad(phi));

}

void kameraHareketSuruklemeIcýnVerileriniGuncelle() {
	gozX = r * sin(deg2rad(theta)) * sin(deg2rad(phi));
	gozY = r * cos(deg2rad(theta)) * sin(deg2rad(phi2));
	gozZ = r * sin(deg2rad(theta)) * cos(deg2rad(phi));
}

void kameraHareketBilgileriniKonsolaYazdir() {
	cout << "gozX: " << gozX << " merkezX: " << merkezX << " gozY: " << gozY << " merkezY: " << merkezY << " gozZ: " << gozZ << " merkezZ: " << merkezZ << " upY: " << yukariY << endl;
}

void gluLookAtFonksiyonu() {
	gluLookAt(gozX + merkezX, gozY + merkezY, gozZ + merkezZ, merkezX, merkezY, merkezZ, 0, yukariY, 0);
}
