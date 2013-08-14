/*
 * File: main.cpp
 * --------------
 * Playing with the GWindow library!
 * Created: 2013-08-13
 */

#include "gwindow.h"
#include "gevents.h"
#include "gobjects.h"

using namespace std;

/* Function prototypes */

void drawDiamond(GWindow &gw);
void drawRectangleAndOval(GWindow &gw);

/* Main program */

int main() {
    GWindow gw;
    drawDiamond(gw);
    GLine *line;
    while (true) {
        GEvent e = waitForEvent(MOUSE_EVENT + KEY_EVENT);
        switch (e.getEventClass()) {
            case MOUSE_EVENT:
                if (e.getEventType() == MOUSE_PRESSED) {
                    line = new GLine(e.getX(), e.getY(), e.getX(), e.getY());
                    gw.add(line);
                } else if (e.getEventType() == MOUSE_DRAGGED) {
                    line->setEndPoint(e.getX(), e.getY());
                }
                
                break;
            case KEY_EVENT:
                drawRectangleAndOval(gw);
                break;
        }
    }
    
    
    return 0;
}


/*
 * Function: drawDiamond
 * Usage: drawDiamond(gw);
 * -----------------------
 * Draws a diamond connecting the midpoints of the window's edge.
 */

void drawDiamond(GWindow &gw) {
    double width = gw.getWidth();
    double height = gw.getHeight();
    gw.drawLine(0, height / 2, width / 2, 0);
    gw.drawLine(width / 2, 0, width, height / 2);
    gw.drawLine(width, height / 2, width / 2, height);
    gw.drawLine(width / 2, height, 0, height / 2);
}


/*
 * Function: drawRectangleAndOval
 * Usage: drawRectangleAndOval(gw);
 * --------------------------------
 * Draws a blue rectangle and a gray oval inscribed in the diamond.
 */

void drawRectangleAndOval(GWindow &gw) {
    double width = gw.getWidth();
    double height = gw.getHeight();
    gw.setColor("BLUE");
    gw.fillRect(width / 4, height / 4, width / 2, height / 2);
    gw.setColor("GRAY");
    gw.fillOval(width / 4, height / 4, width / 2, height / 2);
}

