/*
 * File: Sierpinski.cpp
 * --------------------------
 * Name: Andrew Smith
 *
 * Recursively draws a Sierpinski triangle based on a user input
 * edge length and fractal order.
 */

#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
#include "simpio.h"
#include "math.h"
using namespace std;


/* Function prototypes */
void drawSierpinskiTriangle(double length, int order, GPoint start, GWindow gw);
void drawTriangle(double length, GPoint start, GWindow gw);

/* Main program */

int main() {
    cout << "This program draws a Sierpinski triangle." << endl;
    double length = getReal("Enter an edge length: ");
    int order = getInteger("Enter a fractal order: ");
    
    GWindow gw;
    
    // of equilateral triangle: http://mathworld.wolfram.com/EquilateralTriangle.html
    double height = 1 / 2.0 * sqrt(3) * length;
    
    // starting point: bottom-left corner of triangle
    double x = gw.getWidth() / 2 - length / 2;
    double y = gw.getHeight() / 2 + height / 2;
    GPoint start(x, y);
    
    drawSierpinskiTriangle(length, order, start, gw);
    return 0;
}

/*
 * Function: drawSierpinskiTriangle
 * Usage: drawSierpinskiTriangle(length, order, width, height);
 * ------------------------------------------------------------
 * Draws a Sierpinski triangle of specified order and length in the center
 * of a graphics window.
 */

void drawSierpinskiTriangle(double length, int order, GPoint start, GWindow gw) {
    
    drawTriangle(length, start, gw);
    
    // Base case: order 0 reached
    if (order == 0) return;
    
    // Starting point for bottom right triangle
    GPoint startRight(start.getX() + length / 2, start.getY());
    
    // Starting point for top triangle
    GPoint startTop(start.getX() + length / 4, start.getY() - length / 4 * sqrt(3));
    
    // Recur step: draw 3 smaller triangles of edge length / 2
    drawSierpinskiTriangle(length / 2, order - 1, start, gw);
    drawSierpinskiTriangle(length / 2, order - 1, startRight, gw);
    drawSierpinskiTriangle(length / 2, order - 1, startTop, gw);
    
    
    
}


/*
 * Function: drawTriangle
 * Usage: drawTriangle(length, start);
 * -----------------------------------
 * Draws an equilateral triangle of edge length from the bottom left corner.
 */

void drawTriangle(double length, GPoint start, GWindow gw) {
    GPoint pt = start;
    for (int i = 0; i < 3; i++) {
        pt = gw.drawPolarLine(pt, length, 60 + (240 * i));
    }
}

