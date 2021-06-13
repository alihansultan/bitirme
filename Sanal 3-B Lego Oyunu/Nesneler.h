#pragma once

void gluLookAtFonksiyonu();

void Zemin() {
	// ZEM�N AYARLAMA
	float k = -23.0;
	if (!dusukGrafikModu) {
		while (k < -13.64) {
			for (float i = 0.0; i <= 27.44; i += 0.755) {
				glLoadIdentity();

				if (kameraHareket == 1) {
					gluLookAtFonksiyonu();
				}
				if (yanBakis) {
					gluLookAtFonksiyonu();
				}

				GLUquadricObj* quadratic;
				quadratic = gluNewQuadric();
				glTranslatef(-13.6 + i, -5.05, k - 0.25);
				glRotatef(90, 1.0, 0.0, 0.0);
				glRotatef(xDondurme, 0.0, 1.0, 0.0);
				glRotatef(yDondurme, 1.0, 0.0, 0.0);
				glColor3f(0.0, 0.7, 0.0);
				gluCylinder(quadratic, 0.23f, 0.23f, 0.15f, 10, 10);	// Silindir olu�turma
			}
			k += 0.755;
		}
	}
	
	

	glLoadIdentity();
	if (kameraHareket == 1) {
		gluLookAtFonksiyonu();
	}
	if (yanBakis) {
		gluLookAtFonksiyonu();
	}
	glTranslatef(-20.0, -5.75, -28.25);





	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0, -1.0);
	glColor3f(0.0, 0.6, 0.0);

	// Zeminin �n k�sm�
	glVertex3f(0.0, 0.5, 20);
	glVertex3f(40, 0.5, 20);
	glVertex3f(40, 0.0, 20);
	glVertex3f(0.0, 0.0, 20);
	// Zeminin arka k�sm�
	glNormal3f(0.0, 0.0, -1.0);
	glColor3f(0.0, 0.6, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(40, 0.5, 0.0);
	glVertex3f(40, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	// Zeminin �st k�sm�
	glNormal3f(1.0, 0.0, 0.0);
	glColor3f(0.0, 0.7, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(40.0, 0.5, 0.0);
	glVertex3f(40.0, 0.5, 20.0);
	glVertex3f(0.0, 0.5, 20.0);
	// Zeminin alt k�sm�
	glNormal3f(1.0, 0.0, 0.0);
	glColor3f(0.0, 0.7, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(40, 0.0, 0.0);
	glVertex3f(40, 0.0, 20);
	glVertex3f(0.0, 0.0, 20);
	// Zeminin sa� k�sm�
	glNormal3f(0.0, 1.0, 0.0);
	glColor3f(0.0, 0.8, 0.0);
	glVertex3f(40, 0.5, 20);
	glVertex3f(40, 0.5, 0.0);
	glVertex3f(40, 0.0, 0.0);
	glVertex3f(40, 0.0, 20);
	// Zeminin sol k�sm�
	glNormal3f(0.0, 1.0, 0.0);
	glColor3f(0.0, 0.8, 0.0);
	glVertex3f(0.0, 0.5, 20);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 20);

	glEnd();

	
	// Ekran men� sorununu ��zmek i�in �ok uza�a �izilen (g�r�nmeyen) bir y�zey

	
	glLoadIdentity();
	glTranslatef(0, 0, -100);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	
	glVertex3f(0.0, 1, 1);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(1, 1, 1);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(1, 0.0, 1);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 1);
	glNormal3f(0.0, -1.0, 0.0);
	glEnd();
	glBegin(GL_POINT);
	glEnd();
}

