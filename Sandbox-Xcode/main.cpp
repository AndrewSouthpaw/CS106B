/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include "gwindow.h"
#include "random.h"
using namespace std;

/* Constants */
const double MIN_AREA = 10000;
const double MIN_EDGE = 20;

/* Function prototypes */
void subdivideCanvas(GWindow &gw, double x, double y,
					 double width, double height);

/* Main program */

int main() {
	GWindow gw;
	subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
	return 0;
}

/*
 * Function: subdivideCanvas
 * Usage: subdivideCanvas(gw, x, y, width, height);
 * ------------------------------------------------
 * Decomposes rectangular region on canvas recursively by splitting randomly
 * along its larger dimension. Recursion continues until area falls below
 * constant MIN_AREA.
 */

void subdivideCanvas(GWindow &gw, double x, double y,
					 double width, double height) {
	if (width * height >= MIN_AREA) {
		if (width > height) {
			double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
			subdivideCanvas(gw, x, y, mid, height);
			subdivideCanvas(gw, x + mid, y, width - mid, height);
			gw.drawLine(x + mid, y, x + mid, y + height);
		} else {
			double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
			subdivideCanvas(gw, x, y, width, mid);
			subdivideCanvas(gw, x, y + mid, width, height - mid);
			gw.drawLine(x, y + mid, x + width, y + mid);
		}
	}
}