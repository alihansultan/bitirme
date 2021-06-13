#pragma once

void bagliLegoKontrolu() {

	double uzaklikDegeri = 1.8;
	legoBaglamalariniIptalEt();

	for (int i = 0; i < legolar.size(); i++) {

		if (legolar[legolar.size() - farkDegeriIslem] == legolar[i]) { continue; }
		
		if ((((legolar[legolar.size() - farkDegeriIslem]->xHareket + uzaklikDegeri + 0.5 >= legolar[i]->xHareket) && (legolar[legolar.size() - farkDegeriIslem]->xHareket - uzaklikDegeri - 0.5 <= legolar[i]->xHareket)) &&
			((legolar[legolar.size() - farkDegeriIslem]->yHareket + uzaklikDegeri >= legolar[i]->yHareket) && (legolar[legolar.size() - farkDegeriIslem]->yHareket - uzaklikDegeri <= legolar[i]->yHareket)) &&
			((legolar[legolar.size() - farkDegeriIslem]->zHareket + uzaklikDegeri - 0.5 >= legolar[i]->zHareket) && (legolar[legolar.size() - farkDegeriIslem]->zHareket - uzaklikDegeri - 0.5 <= legolar[i]->zHareket)))
			&& legolar[i]->silindirsizMi == true && legolar[legolar.size() - farkDegeriIslem]->silindirsizMi == true && legolar[i]->silindirsizkenCarpisma == true &&
			legolar[legolar.size() - farkDegeriIslem]->silindirsizkenCarpisma == true) {

			legolar[legolar.size() - farkDegeriIslem]->baglilik = true;
			legolar[i]->baglilik = true;

			legolar[legolar.size() - farkDegeriIslem]->sinyal2 = -4.2;
			legolar[i]->sinyal2 = -4.2;
			if (legolar[i]->baglilik) {

				for (int j = 0; j < legolar.size(); j++) {
					if (legolar[i] == legolar[j]) { continue; }
					if ((((legolar[j]->xHareket + uzaklikDegeri + 0.5 >= legolar[i]->xHareket) && (legolar[j]->xHareket - uzaklikDegeri - 0.5 <= legolar[i]->xHareket)) &&
						((legolar[j]->yHareket + uzaklikDegeri >= legolar[i]->yHareket) && (legolar[j]->yHareket - uzaklikDegeri <= legolar[i]->yHareket)) &&
						((legolar[j]->zHareket + uzaklikDegeri + 0.5 >= legolar[i]->zHareket) && (legolar[j]->zHareket - uzaklikDegeri - 0.5 <= legolar[i]->zHareket)))
						&& legolar[i]->silindirsizMi == true && legolar[j]->silindirsizMi == true && legolar[i]->silindirsizkenCarpisma == true
						&& legolar[j]->silindirsizkenCarpisma == true) {


						legolar[j]->baglilik = true;
						legolar[j]->sinyal2 = -4.2;


					}
				}
			}
		

	}
	}
	glutPostRedisplay();

	
	
}


void legoBaglamalariniIptalEt() {

	for (int i = 0; i < legolar.size(); i++) {

		if (legolar[i]->baglilik) {
			legolar[i]->xHareketEski = legolar[i]->xHareket;
			legolar[i]->yHareketEski = legolar[i]->yHareket;
			legolar[i]->zHareketEski = legolar[i]->zHareket;
			legolar[i]->baglilik = false;
			legolar[i]->sinyal2 = 0.0;
		}
	}

}


void tumBagliLegoCarpismalariniKontrolEt() {
	if (!butunCarpismaKontrolleri() && legolar.size() != 0) {
		if (legolar[legolar.size() - farkDegeriIslem]->baglilik) {
			for (int i = 0; i < legolar.size(); i++) {
				if (legolar[i]->baglilik) {
					legolar[i]->xHareketEski = legolar[i]->xHareket;
					legolar[i]->yHareketEski = legolar[i]->yHareket;
					legolar[i]->zHareketEski = legolar[i]->zHareket;
				}
			}
		}
	}
}