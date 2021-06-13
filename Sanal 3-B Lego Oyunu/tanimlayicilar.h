#pragma once

#pragma once
#include <math.h>
#include <iostream>
#include <string>
#include <string.h>

#define PI 3.14

using namespace std;

GLsizei xPiksely = 0, yPiksely = 0, zPiksely = 1.0;
GLubyte renklerYazisi[] = { 'R','e','n','k','l','e','r',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte cizgi[] = { '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte cikisYazisi[] = { 'C','i','k','i','s',' ','y','a','p',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte sifirlaYazisi[] = { 'S','i','f','i','r','l','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte kameraHareketiYazisi[] = { 'K','a','m','e','r','a',' ','h','a','r','e','k','e','t','i',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte onBakisYazisi[] = { 'Ö','n',' ','B','a','k','i','s',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte yanBakisYazisi[] = { 'Y','a','n',' ','B','a','k','i','s',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte serbestKameraYazisi[] = { 'S','e','r','b','e','s','t',' ','k','a','m','e','r','a',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte carpismaTespitiYazisi[] = { 'C','a','r','p','i','s','m','a',' ','t','e','s','p','i','t',' ','e','d','i','l','d','i','!','!','!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte solMenuYazisi[] = { 'H','a','z','i','r',' ','l','e','g','o','l','a','r',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte kisa1x1Yazisi[] = { ' ',' ',' ',' ',' ',' ','1','x','1',' ','k','i','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte uzun1x1Yazisi[] = { ' ',' ',' ',' ',' ',' ','1','x','1',' ','u','z','u','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte kisa1x2Yazisi[] = { ' ',' ',' ',' ',' ',' ','1','x','2',' ','k','i','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte uzun1x2Yazisi[] = { ' ',' ',' ',' ',' ',' ','1','x','2',' ','u','z','u','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte kisa1x4Yazisi[] = { ' ',' ',' ',' ',' ',' ','1','x','4',' ','k','i','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte uzun1x4Yazisi[] = { ' ',' ',' ',' ',' ',' ','1','x','4',' ','u','z','u','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte kisa2x2Yazisi[] = { ' ',' ',' ',' ',' ',' ','2','x','2',' ','k','i','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte uzun2x2Yazisi[] = { ' ',' ',' ',' ',' ',' ','2','x','2',' ','u','z','u','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte kisa2x4Yazisi[] = { ' ',' ',' ',' ',' ',' ','2','x','4',' ','k','i','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte uzun2x4Yazisi[] = { ' ',' ',' ',' ',' ',' ','2','x','4',' ','u','z','u','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte dusukGrafikModuYazisi[] = { 'Y','ü','k','s','e','k',' ','g','r','a','f','i','k',' ','m','o','d','u',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte silindirOturtmaKontroluYazisi[] = { 'S','i','l','i','n','d','i','r',' ','o','t','u','r','t','m','a','y','a',' ','u','y','g','u','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte legoSecYazisi[] = { 'L','e','g','o',' ','s','e','c',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte legoDondurYazisi[] = { 'L','e','g','o',' ','d','o','n','d','u','r',' ','(','d',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte serbestKameraHareketBilgisi[] = { 'F','a','r','e','y','i',' ','s','ü','r','ü','k','l','e','y','e','r','e','k',' ','e','k','r','a','n','d','a',' ','g','e','z','i','n','m','e',' ','y','a','p','a',' ',' ',' ',' ' };
GLubyte serbestKameraHareketBilgisi2[] = { 'b','i','l','i','r','s','i','n','i','z','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte hassasHareketBilgisi[] = { 'O','k',' ','t','u','s','l','a','r','i','y','l','a',' ','d','a','h','a',' ','i','n','c','e',' ','h','a','r','e','k','e','t','l','e','r',' ','y','a','p','a', };
GLubyte hassasHareketBilgisi2[] = { 'b','i','l','i','r','s','i','n','i','z','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
GLubyte legoSilYazisi[] = { 'L','e','g','o',' ','s','i','l',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };

GLint veriDegeri[] = { 0 };

bool kontrol = false;
float x, y, z;

double xPiksel;
double yPiksel;
double xPikselEski;
double yPikselEski;

double xPikselInt;
double yPikselInt;
double xPikselEskiInt;
double yPikselEskiInt;

double FullScreen = 0.74;

void yenidenSekillendir(int, int);
void zamanlayici(int);
void varsayilanLegoDegerleri();

double xDondurme = 0.0;
double yDondurme = 0.0;

bool objLegoHareket = false;


bool yanBakis = false;
bool onBakis = true;
bool kameraHareket = false;

double upx = 0.0;
double sayi = 0.5;
double teta = sayi * (3.142 / 180);





bool dusukGrafikModu = true;



bool carpismaTespiti = false;
int carpismaTespitiSayaci = 0;
int carpismaTespitiSayaci2 = 0;


double rad2deg(double radyan) {
	return radyan * 180 / PI;
}

double deg2rad(double derece) {
	return derece * PI / 180;
}


double yukariY = 1.0;
double phi, phi2 = 45;
double theta = 45;
int r = 28;
double gozX = r * sin(deg2rad(theta)) * sin(deg2rad(phi));
double gozY = r * cos(deg2rad(theta)) * sin(deg2rad(phi));
double gozZ = r * sin(deg2rad(theta)) * cos(deg2rad(phi));
double merkezX = 0, merkezY = 0, merkezZ = -20;
double tempX, tempY;







int pencereGenisligi = 1366;
int pencereUzunlugu = 768;




void degerleriSifirla() {

	varsayilanLegoDegerleri();
	
	phi = 45;
	phi2 = 45;
	merkezX = 0;
	merkezY = 0;
	merkezZ = -20;
	gozX = r * sin(deg2rad(theta)) * sin(deg2rad(phi));
	gozY = r * cos(deg2rad(theta)) * sin(deg2rad(phi));
	gozZ = r * sin(deg2rad(theta)) * cos(deg2rad(phi));


	
	kameraHareket = false;
	
	onBakis = true;
	yanBakis = false;
	kameraHareket = false;
	dusukGrafikModu = true;
}


// OBJ LEGOLARIN SÝLÝNDÝRLÝ BOYUTLARI
// SADECE SÝLÝNDÝRÝN YÜKSEKLÝÐÝ 121 PÝKSELDÝR (Y=121)
double carpimKatsayisi = 10;
double objUzunlukKatsayisi = 0.001345;

double genisletilmisObjUzunlukKatsayisi = 0.001360; // Bu silindir çarpýþma kontrolünde kullanýlacaktýr.
double genisletilmisObj1Xuzunlugu = 554 * genisletilmisObjUzunlukKatsayisi;


double silindirGenisligi = 328 * objUzunlukKatsayisi;

double obj1Xuzunlugu = 554 * objUzunlukKatsayisi;
double obj1Yuzunlugu = 349 * objUzunlukKatsayisi;
double obj1YuzunluguSilindirsiz = 228 * objUzunlukKatsayisi;
double obj1Zuzunlugu = 554 * objUzunlukKatsayisi;

double obj2Xuzunlugu = 554 * objUzunlukKatsayisi;
double obj2Yuzunlugu = 805 * objUzunlukKatsayisi;
double obj2YuzunluguSilindirsiz = 684 * objUzunlukKatsayisi;
double obj2Zuzunlugu = 554 * objUzunlukKatsayisi;

double obj3Xuzunlugu = 1108 * objUzunlukKatsayisi; // bunlar hazýr legolarýn ölçülen piksel uzunluklarý.
double obj3Yuzunlugu = 349 * objUzunlukKatsayisi;
double obj3YuzunluguSilindirsiz = 228 * objUzunlukKatsayisi;
double obj3Zuzunlugu = 554 * objUzunlukKatsayisi;

double obj4Xuzunlugu = 1108 * objUzunlukKatsayisi;
double obj4Yuzunlugu = 805 * objUzunlukKatsayisi;
double obj4YuzunluguSilindirsiz = 684 * objUzunlukKatsayisi;
double obj4Zuzunlugu = 554 * objUzunlukKatsayisi;

double obj5Xuzunlugu = 2216 * objUzunlukKatsayisi;
double obj5Yuzunlugu = 349 * objUzunlukKatsayisi;
double obj5YuzunluguSilindirsiz = 228 * objUzunlukKatsayisi;
double obj5Zuzunlugu = 554 * objUzunlukKatsayisi;

double obj6Xuzunlugu = 2216 * objUzunlukKatsayisi;
double obj6Yuzunlugu = 805 * objUzunlukKatsayisi;
double obj6YuzunluguSilindirsiz = 684 * objUzunlukKatsayisi;
double obj6Zuzunlugu = 554 * objUzunlukKatsayisi;

double obj7Xuzunlugu = 1108 * objUzunlukKatsayisi;
double obj7Yuzunlugu = 349 * objUzunlukKatsayisi;
double obj7YuzunluguSilindirsiz = 228 * objUzunlukKatsayisi;
double obj7Zuzunlugu = 1108 * objUzunlukKatsayisi;

double obj8Xuzunlugu = 1108 * objUzunlukKatsayisi;
double obj8Yuzunlugu = 805 * objUzunlukKatsayisi;
double obj8YuzunluguSilindirsiz = 684 * objUzunlukKatsayisi;
double obj8Zuzunlugu = 1108 * objUzunlukKatsayisi;

double obj9Xuzunlugu = 2216 * objUzunlukKatsayisi;
double obj9Yuzunlugu = 349 * objUzunlukKatsayisi;
double obj9YuzunluguSilindirsiz = 228 * objUzunlukKatsayisi;
double obj9Zuzunlugu = 1108 * objUzunlukKatsayisi;

double obj10Xuzunlugu = 2216 * objUzunlukKatsayisi;
double obj10Yuzunlugu = 805 * objUzunlukKatsayisi;
double obj10YuzunluguSilindirsiz = 684 * objUzunlukKatsayisi;
double obj10Zuzunlugu = 1108 * objUzunlukKatsayisi;


bool silindirOturtmaKontrolu = false;
int silindirOturtmaSayaci = 0;

int farkDegeri = 1;
int farkDegeriIslem = 1;
int silindirsizCarpismaSayaci = 0;

