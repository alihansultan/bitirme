#pragma once

#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>



using namespace std;

void gluLookAtFonksiyonu();

class Vertex {
public:
    float x, y, z;
    Vertex() {}
    Vertex(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    
};
class Face {
public:
    Vertex vertex1, vertex2, vertex3, vertexn1, vertexn2, vertexn3, vertext1, vertext2, vertext3;
    Face(Vertex vertex1, Vertex vertex2, Vertex vertex3) {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->vertex3 = vertex3;
    }
    Face(Vertex vertex1, Vertex vertex2, Vertex vertex3, Vertex vertexn1, Vertex vertexn2, Vertex vertexn3, Vertex vertext1, Vertex vertext2, Vertex vertext3) {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->vertex3 = vertex3;
        this->vertexn1 = vertexn1;
        this->vertexn2 = vertexn2;
        this->vertexn3 = vertexn3;
        this->vertext1 = vertext1;
        this->vertext2 = vertext2;
        this->vertext3 = vertext3;
    }
};




string satir, satir2;
stringstream check1(satir);




class Lego { 
    ifstream dosya;

    vector <string> tokens, tokens2;
    int vt_sayac = 0;
    int vn_sayac = 0;
    int v_sayac = 0;
    int f_sayac = 0;
    string intermediate;

    vector <Vertex> vectors;
    vector <Vertex> vNormals;
    vector <Vertex> vTextures;
    vector <Face> Faces;
    double kucultmeMiktari = 0.025;
    
public:
    double hacim = 0;
    string objAdi;
    double kirmizi = 0.0;
    double yesil=5;
    double mavi=3;
    double xHareket= 0.0;
    double yHareket=2.0;
    double zHareket=-18.5;
    double xHareketEski=0.0;
    double yHareketEski=2.0;
    double zHareketEski=-18.5;
    double Xuzunlugu;
    double Yuzunlugu;
    double YuzunluguYedek;
    double YuzunluguSilindirsiz;
    double Zuzunlugu;
    bool aktifMi = false;
    double sinyal = 0;
    double sinyal2 = 0;
    bool dondurmeIslemi = false;
    double dondur = 0;
    bool baglilik = false;
    bool silindirsizMi = false;
    bool silindirsizkenCarpisma = false;
    int bagliLegolarKimligi = 0;

    

    Lego(string objAdi, double kirmizi, double yesil, double mavi, double Xuzunlugu, double Yuzunlugu, double YuzunluguYedek, double YuzunluguSilindirsiz, double Zuzunlugu, double xHareket, double yHareket, double zHareket, double xHareketEski,
        double yHareketEski, double zHareketEski) {
        this->objAdi = objAdi;
        this->kirmizi = kirmizi;
        this->yesil = yesil;
        this->mavi = mavi;
        this->Xuzunlugu = Xuzunlugu;
        this->Yuzunlugu = Yuzunlugu;
        this->YuzunluguYedek = YuzunluguYedek;
        this->YuzunluguSilindirsiz = YuzunluguSilindirsiz;
        this->Zuzunlugu = Zuzunlugu;
        this->xHareket = xHareket;
        this->yHareket = yHareket;
        this->zHareket = zHareket;
        this->xHareketEski = xHareketEski;
        this->yHareketEski = yHareketEski;
        this->zHareketEski = zHareketEski;
    }

    void ekle() {   // dosyadan okuyor
        
        this->objAdi = objAdi;
        double toplam = 0;
        dosya.open(objAdi);
        if (dosya.is_open()) {

            while (getline(dosya, satir))
            {
                stringstream check1(satir);

                string intermediate;
                if (satir.rfind("v ", 0) == 0) {
                    v_sayac++;
                    while (getline(check1, intermediate, ' '))
                    {
                        tokens.push_back(intermediate);
                    }
                    Vertex vertex(stof(tokens[2]), stof(tokens[3]), stof(tokens[4]));
                    vectors.push_back(vertex);
                    tokens.clear();
                }
                else if (satir.rfind("vn ", 0) == 0) {
                    vn_sayac++;
                    while (getline(check1, intermediate, ' '))
                    {
                        tokens.push_back(intermediate);
                    }
                    Vertex vertex(stof(tokens[1]), stof(tokens[2]), stof(tokens[3]));
                    vNormals.push_back(vertex);
                    tokens.clear();
                }



                else if (satir.rfind("vt ", 0) == 0) {
                    vt_sayac++;
                    while (getline(check1, intermediate, ' '))
                    {
                        tokens.push_back(intermediate);
                    }
                    Vertex vertex(stof(tokens[1]), stof(tokens[2]), stof(tokens[3]));
                    vTextures.push_back(vertex);
                    tokens.clear();

                }
                else if (satir.rfind("f ", 0) == 0) {
                    f_sayac++;
                    while (getline(check1, intermediate, ' '))
                    {
                        tokens.push_back(intermediate);
                    }
                    Face face(vectors[stoi(tokens[1]) - 1], vectors[stoi(tokens[2]) - 1], vectors[stoi(tokens[3]) - 1]);
                    Faces.push_back(face);
                    tokens.clear();


                }


            }

            dosya.close();
        }

        

    }

    void isle() {   

        if (dondurmeIslemi) {
            dondur = 90;
        }
        else {
            dondur = 0;
        }
        
        double xKaydirma = 0;
        double yKaydirma = 0;
        double zKaydirma = 0;
        double dondurmeAcisi = 0;
        double kDondurmeX = 0;
        double kDondurmeY = 0;
        double kDondurmeZ = 0;
        
        // ÖNEMLÝ:
        // Hazýr legolarýn bulunduklarý konumlarý sebebiyle döndürme iþlemlerdinde tam merkezden dönmeme sorunu vardý.
        // Bu sorun döndürme iþlemi yapýldýktan sonra birkaç oynamalar yapýlarak giderilebilmiþtir.
        // Ayný zamanda çarpýþma kontrollerinin düzgün çalýþabilmesi adýna legolarýn baþlangýçta bulunduklarý konumlar
        // legolarýn merkez noktasý ayný olacak þekilde konumlarýnda oynamalar yapýldý.

        if (objAdi == "1x1kisa.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.25;
                kDondurmeX = -0.03;
                Xuzunlugu = obj1Zuzunlugu;
                Zuzunlugu = obj1Xuzunlugu;
            }
            else {
                Xuzunlugu = obj1Xuzunlugu;
                Zuzunlugu = obj1Zuzunlugu;
            }
        }

        else if (objAdi == "1x1uzun.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.375;
                kDondurmeX = -0.15;
                Xuzunlugu = obj2Zuzunlugu;
                Zuzunlugu = obj2Xuzunlugu;
            }
            else {
                Xuzunlugu = obj2Xuzunlugu;
                Zuzunlugu = obj2Zuzunlugu;
            }
                zKaydirma = -0.135;
                xKaydirma = -0.01;   
                yKaydirma = -0.42;
            
            
        }
        else if (objAdi == "1x2kisa.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.745;
                kDondurmeX = 0.25;
                Xuzunlugu = obj3Zuzunlugu;
                Zuzunlugu = obj3Xuzunlugu;               
            }
            else {
                Xuzunlugu = obj3Xuzunlugu;
                Zuzunlugu = obj3Zuzunlugu;
            }
            zKaydirma = -0.10;
            xKaydirma = -0.39;
            yKaydirma = -0.22;
           
        }
        else if (objAdi == "1x2uzun.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.490;
                kDondurmeX = 0.07;
                Xuzunlugu = obj4Zuzunlugu;
                Zuzunlugu = obj4Xuzunlugu;
            }
            else {
                Xuzunlugu = obj4Xuzunlugu;
                Zuzunlugu = obj4Zuzunlugu;
            }
            zKaydirma = -0.085;
            xKaydirma = -0.17;
            yKaydirma = -0.22;     
        }

        else if (objAdi == "1x4kisa.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.990;
                kDondurmeX = 1.10;
                Xuzunlugu = obj5Zuzunlugu;
                Zuzunlugu = obj5Xuzunlugu;
            }
            else {
                Xuzunlugu = obj5Xuzunlugu;
                Zuzunlugu = obj5Zuzunlugu;
            }
            zKaydirma = +0.205;
            xKaydirma = -0.89;
            yKaydirma = +0.11;
        }
        else if(objAdi == "1x4uzun.obj"){
            if (dondurmeIslemi) {
                kDondurmeZ = 2.910;
                kDondurmeX = 3.07;
                Xuzunlugu = obj6Zuzunlugu;
                Zuzunlugu = obj6Xuzunlugu;
            }
            else {
                Xuzunlugu = obj6Xuzunlugu;
                Zuzunlugu = obj6Zuzunlugu;
            }
            dondurmeAcisi = 44;
            zKaydirma = +0.716;
            xKaydirma = -2.35;
            yKaydirma = -0.803;         
        }
        else if (objAdi == "2x2kisa.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.910;
                kDondurmeX = -0.04;
                Xuzunlugu = obj7Zuzunlugu;
                Zuzunlugu = obj7Xuzunlugu;
            }
            else {
                Xuzunlugu = obj7Xuzunlugu;
                Zuzunlugu = obj7Zuzunlugu;
            }
            zKaydirma = -0.353;
            xKaydirma = -0.30;
            yKaydirma = -0.152;
        }
        else if (objAdi == "2x2uzun.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 1.890;
                kDondurmeX = +0.06;
                Xuzunlugu = obj8Zuzunlugu;
                Zuzunlugu = obj8Xuzunlugu;
            }
            else {
                Xuzunlugu = obj8Xuzunlugu;
                Zuzunlugu = obj8Zuzunlugu;
            }
            zKaydirma = -0.268;
            xKaydirma = -0.34;
            yKaydirma = -0.268;
        }
        
        else if (objAdi == "2x4kisa.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 0.990;
                kDondurmeX = +2.68;
                Xuzunlugu = obj9Zuzunlugu;
                Zuzunlugu = obj9Xuzunlugu;
            }
            else {
                Xuzunlugu = obj9Xuzunlugu;
                Zuzunlugu = obj9Zuzunlugu;
            }
            dondurmeAcisi = 90;
            zKaydirma = 1.468;
            yKaydirma = +0.01;
            xKaydirma = -1.217;

        }
        else if (objAdi == "2x4uzun.obj") {
            if (dondurmeIslemi) {
                kDondurmeZ = 0.712;
                kDondurmeX = +2.81;
                Xuzunlugu = obj10Zuzunlugu;
                Zuzunlugu = obj10Xuzunlugu;
            }
            else {
                Xuzunlugu = obj10Xuzunlugu;
                Zuzunlugu = obj10Zuzunlugu;
            }
            dondurmeAcisi = 90;
            
            zKaydirma = 1.715;
            yKaydirma = -0.35;
            xKaydirma = -1.12;

        }


        glLoadIdentity();
        if (kameraHareket == 1) {
            gluLookAtFonksiyonu();
        }
        if (yanBakis) {
            gluLookAtFonksiyonu();
        }
        
        glTranslatef(xHareket+xKaydirma+kDondurmeX, yHareket+yKaydirma+kDondurmeY, zHareket+zKaydirma+kDondurmeZ);
        glRotatef(dondur+dondurmeAcisi, 0, 1, 0);
        glScalef(kucultmeMiktari, kucultmeMiktari, kucultmeMiktari); // Legolarýn boyut sorunu bu fonksiyonla düzeltildi.
        glBegin(GL_TRIANGLES);

        

        for (int i = 0; i < f_sayac; i++) {

            glNormal3f(Faces[i].vertexn1.x, Faces[i].vertexn1.y, Faces[i].vertexn1.z);
            glColor3f((Faces[i].vertext1.x), (Faces[i].vertext1.y), (Faces[i].vertext1.z));
            glVertex3f(Faces[i].vertex1.x, Faces[i].vertex1.y, Faces[i].vertex1.z);
            glNormal3f(Faces[i].vertexn2.x, Faces[i].vertexn2.y, Faces[i].vertexn2.z);
            glColor3f((Faces[i].vertext2.x), (Faces[i].vertext2.y), (Faces[i].vertext2.z));
            glColor3f(kirmizi+sinyal+sinyal2, yesil + sinyal+sinyal2, mavi + sinyal + sinyal2);
            glVertex3f(Faces[i].vertex2.x, Faces[i].vertex2.y, Faces[i].vertex2.z);
            glNormal3f(Faces[i].vertexn3.x, Faces[i].vertexn3.y, Faces[i].vertexn3.z);
            glColor3f((Faces[i].vertext3.x), (Faces[i].vertext3.y), (Faces[i].vertext3.z));
            glColor3f(kirmizi + sinyal + sinyal2, yesil + sinyal + sinyal2, mavi + sinyal + sinyal2);
            glVertex3f(Faces[i].vertex3.x, Faces[i].vertex3.y, Faces[i].vertex3.z);

            

           
        }
        
        glEnd();
       
    }

    // Lego sýnýfýnda bulunan uzaklýk hesaplayan algoritmalar
    float onBakisUzaklikBul(int farex, int farey, double xHareket, double yHareket) {
        return sqrtf(pow((((farex-683)/58) - xHareket), 2) + pow((((farey-344)/55) - yHareket), 2));
    }
    float yanBakisUzaklikBul(int farex, int farey, double zHareket, double yHareket) {
        return sqrtf(pow((((farex-683 ) / 58) - (zHareket)), 2) + pow((((farey-344 ) / 55) - yHareket), 2));
    }
        
   

    
};

