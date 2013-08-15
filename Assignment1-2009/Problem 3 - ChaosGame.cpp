/*
 * File: main.cpp
 * --------------
 * Author: Andrew Smith
 * Created: 2013-08-14
 * 
 * Simulates the "Chaos Game" phenomenon.  User clicks three points within the
 * graphics window, A, B, and C.  A triangle is drawn connecting the points.  The
 * following steps are followed:
 * 1. Randomly choose one vertex as the current point
 * 2. Draw a small filled circle around the current point
 * 3. Randomly choose on vertex and move the current point half the distance
      toward that vertex
 * 4. Repeat steps 2 & 3, stopping on user mouse click
 */

#include <iostream>
#include "console.h"
#include "gwindow.h"
#include "gevents.h"
#include "gtypes.h"
#include "random.h"
#include "gobjects.h"

using namespace std;

/* Constants */

const int CIRCLE_DIAM = 5;

/* Function prototypes */

GPoint getPointFromUser();
void drawTriangle(GPoint a, GPoint b, GPoint c, GWindow gw);
void drawFilledCircle(GPoint currentPt, GWindow gw);
GPoint moveCurrentPoint(GPoint currentPt, GPoint a, GPoint b, GPoint c);

/* Main program */

int main() {
    GWindow gw;
    GPoint a = getPointFromUser();
    GPoint b = getPointFromUser();
    GPoint c = getPointFromUser();    
    int n = randomInteger(1, 3);
    GPoint currentPt;
    switch (n) {
        case 1: currentPt = a; break;
        case 2: currentPt = b; break;
        case 3: currentPt = c; break;
    }
    drawTriangle(a, b, c, gw);
    while (true) {
        GMouseEvent e = getNextEvent();
        if (e.getEventType() == MOUSE_CLICKED) break;
        drawFilledCircle(currentPt, gw);
        currentPt = moveCurrentPoint(currentPt, a, b, c);

    }
    return 0;
}


/*
 * Function: getPointFromUser
 * Usage: GPoint pt = getPointFromUser();
 * ---------------------------------------
 * Waits for a user to select a point on the screen, and returns the point.
 */

GPoint getPointFromUser() {
    while (true) {
        GMouseEvent e = waitForEvent();
        if (e.getEventType() == MOUSE_CLICKED) {
            GPoint *pt = new GPoint(e.getX(), e.getY());
            return *pt;
        }
    }
}


/*
 * Function: drawTriangle
 * Usage: drawTriangle(a, b, c);
 * -----------------------------
 * Draws a triangle from the passed GPoints.
 */

void drawTriangle(GPoint a, GPoint b, GPoint c, GWindow gw) {
    GLine *line = new GLine(a.getX(), a.getY(), b.getX(), b.getY());
    gw.add(line);
    line = new GLine(a.getX(), a.getY(), c.getX(), c.getY());
    gw.add(line);
    line = new GLine(b.getX(), b.getY(), c.getX(), c.getY());
    gw.add(line);
    
}


/*
 * Function: drawFilledCircle
 * Usage: drawFilledCircle(currentPt);
 * -------------------------------------
 * Draws a filled circle at the given GPoint.
 */

void drawFilledCircle(GPoint currentPt, GWindow gw) {
    int x = currentPt.getX();
    int y = currentPt.getY();
    GOval *cir = new GOval(x, y, CIRCLE_DIAM, CIRCLE_DIAM);
    cir->setFillColor("BLACK");
    cir->setFilled(true);
    gw.add(cir);
}


/*
 * Function: moveCurrentPoint
 * Usage: moveCurrentPoint(currentPt, a, b, c);
 * --------------------------------------------
 * Moves current point half the distance to a randomly selected vertex
 * of the triangle (A, B, C).
 */

GPoint moveCurrentPoint(GPoint currentPt, GPoint a, GPoint b, GPoint c) {
    GPoint newPt;
    int n = randomInteger(1, 3);
    switch (n) {
        case 1: newPt = a; break;
        case 2: newPt = b; break;
        case 3: newPt = c; break;
    }
    int x = currentPt.getX() + (newPt.getX() - currentPt.getX()) / 2;
    int y = currentPt.getY() + (newPt.getY() - currentPt.getY()) / 2;
    GPoint result(x, y);
    return result;
}






















