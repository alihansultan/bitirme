#pragma once


void isiklandirma() {

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.1 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.00 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat light1_ambient[] = { 0.4, 0.4, 0.4, 2.0 };
	GLfloat light1_diffuse[] = { 2.0, 2.0, 2.0, 2.0 };
	GLfloat light1_specular[] = { 2.0, 2.0, 2.0, 2.0 };
	GLfloat light1_position[] = { -4.0, 4.0, 2.0, 2.0 };
	GLfloat spot_direction[] = { -2.0, -2.0, 0.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

	glEnable(GL_LIGHT1);

}

