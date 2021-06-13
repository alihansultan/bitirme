#pragma once


void onBakisLegoSecmeKontrolu(double x, double y, string islemTipi);
void yanBakisLegoSecmeKontrolu(double x, double y, string islemTipi);

// Fare imleci ekranda sürüklendiði sürece bu fonksiyon çaðrýlacaktýr.
void FareHareketiGeriBildirimiPasif(int xPos, int yPos) {

	x = xPos;
	y = 680 - yPos;
	
	if (!butunCarpismaKontrolleri()) {
		bagliLegoKontrolu();


		if (onBakis) {
			onBakisLegoSecmeKontrolu(x, y, "gezinme");

		}

		else if (yanBakis) {
			yanBakisLegoSecmeKontrolu(x, y, "gezinme");
		}

	}
	cout << "Pikseller: " << xPos << " : " << yPos << endl;

	if ((xPos >= 1118) && (xPos <= 1307)) {
		
		if ((yPos >= 194) && (yPos <= 227)) {
			
			
			butunSagMenuYaziRenkleriVarsayilan();
			resimRenkleriniVarsayilanYap();
			legoDondurYazisiS.beyaz = 0.0;
			dondurmeResmi.renk = 1.0;
		}
		
		 else if ((yPos >= 469) && (yPos <= 498)) {
			butunSagMenuYaziRenkleriVarsayilan();
			resimRenkleriniVarsayilanYap();
			cikisYazisiS.yesil = 0.0;
			cikisResmi.renk = 1.0;
		}
		else if ((yPos >= 435) && (yPos <= 462)) {
			butunSagMenuYaziRenkleriVarsayilan();
			resimRenkleriniVarsayilanYap();
			sifirlaYazisiS.mavi = 0.0;
			sifirlaResmi.renk = 1.0;
		}
		else if ((yPos >= 404) && (yPos <= 430)) {
			butunSagMenuYaziRenkleriVarsayilan();
			resimRenkleriniVarsayilanYap();
			kameraHareketiYazisiS.mavi = 0.0;
			kameraHareketiResmi.renk = 1.0;
		}
		else {
			butunSagMenuYaziRenkleriVarsayilan();
			resimRenkleriniVarsayilanYap();
			if (kameraHareket == false) { kameraHareketiYazisiS.mavi = 5.0; }
			else { kameraHareketiYazisiS.mavi = 2.5; }
		}
	}
	else {
		butunSagMenuYaziRenkleriVarsayilan();
		resimRenkleriniVarsayilanYap();
		if (kameraHareket == false) { kameraHareketiYazisiS.mavi = 5.0; }
		else { kameraHareketiYazisiS.mavi = 2.5; }
	}

	if ((yPos >= 292) && (yPos <= 337)) {
		if ((xPos >= 1135) && (xPos <= 1179)) {
			butunRenkKutucuguRenkleriVarsayilan();
			kirmiziKutucuk.kirmizi = 3.0;
		}

		else if ((xPos >= 1189) && (xPos <= 1234)) {
			butunRenkKutucuguRenkleriVarsayilan();
			yesilKutucuk.yesil = 3.0;
		}

		else if ((xPos >= 1243) && (xPos <= 1288)) {
			butunRenkKutucuguRenkleriVarsayilan();
			maviKutucuk.yesil = 3.0;
			maviKutucuk.mavi = 3.0;
		}

		else { butunRenkKutucuguRenkleriVarsayilan(); }
	}



	else if ((yPos >= 345) && (yPos <= 388)) {
		if ((xPos >= 1135) && (xPos <= 1179)) {
			butunRenkKutucuguRenkleriVarsayilan();
			sariKutucuk.kirmizi = 3.0;
			sariKutucuk.yesil = 3.0;
		}

		else if ((xPos >= 1189) && (xPos <= 1234)) {
			butunRenkKutucuguRenkleriVarsayilan();
			magentaKutucuk.kirmizi = 3.0;
			magentaKutucuk.mavi = 3.0;
		}

		else if ((xPos >= 1243) && (xPos <= 1288)) {
			butunRenkKutucuguRenkleriVarsayilan();
			beyazKutucuk.kirmizi = 4.0;
			beyazKutucuk.yesil = 4.0;
			beyazKutucuk.mavi = 4.0;
		}

		else { butunRenkKutucuguRenkleriVarsayilan(); }
	}
	else { butunRenkKutucuguRenkleriVarsayilan(); }

	
	// SOL BUTONLAR
	
		if ((xPos >= 29) && (xPos <= 184)) {
			if ((yPos >= 56) && (yPos <= 85)) {
				butunButonRenkleriVarsayilan();
				kisa1x1Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();

				kisa1x1YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				kisa1x1Resmi.aktifMi = true;
			}
			else if ((yPos >= 92) && (yPos <= 122)) {
				butunButonRenkleriVarsayilan();
				uzun1x1Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();


				uzun1x1YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				uzun1x1Resmi.aktifMi = true;
			}
			else if ((yPos >= 131) && (yPos <= 160)) {
				butunButonRenkleriVarsayilan();
				kisa1x2Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();

				kisa1x2YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				kisa1x2Resmi.aktifMi = true;
			}
			else if ((yPos >= 168) && (yPos <= 196)) {
				butunButonRenkleriVarsayilan();
				uzun1x2Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				uzun1x2YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				uzun1x2Resmi.aktifMi = true;
			}
			else if ((yPos >= 204) && (yPos <= 234)) {
				butunButonRenkleriVarsayilan();
				kisa1x4Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				kisa1x4YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				kisa1x4Resmi.aktifMi = true;
			}
			else if ((yPos >= 241) && (yPos <= 271)) {
				butunButonRenkleriVarsayilan();
				uzun1x4Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				uzun1x4YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				uzun1x4Resmi.aktifMi = true;
			}
			else if ((yPos >= 278) && (yPos <= 307)) {
				butunButonRenkleriVarsayilan();
				kisa2x2Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				kisa2x2YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				kisa2x2Resmi.aktifMi = true;
			}
			else if ((yPos >= 315) && (yPos <= 345)) {
				butunButonRenkleriVarsayilan();
				uzun2x2Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				uzun2x2YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				uzun2x2Resmi.aktifMi = true;
			}
			else if ((yPos >= 353) && (yPos <= 383)) {
				butunButonRenkleriVarsayilan();
				kisa2x4Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				kisa2x4YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				kisa2x4Resmi.aktifMi = true;
			}
			else if ((yPos >= 390) && (yPos <= 419)) {
				butunButonRenkleriVarsayilan();
				uzun2x4Butonu.cyan = 1.6;
				butunSolMenuYaziRenkleriVarsayilan();
				uzun2x4YazisiS.beyaz = 0.0;
				tumOnizlemeleriKapat();
				uzun2x4Resmi.aktifMi = true;
			}
			else {
				butunButonRenkleriVarsayilan(); butunSolMenuYaziRenkleriVarsayilan(); tumOnizlemeleriKapat();
			}
		}
		else {
			butunButonRenkleriVarsayilan(); butunSolMenuYaziRenkleriVarsayilan(); tumOnizlemeleriKapat();
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
	

	glutPostRedisplay();
}


