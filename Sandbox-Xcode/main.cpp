/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include "queue.h"
#include "filelib.h"
#include "lexicon.h"
#include "random.h"


using namespace std;

/* Constants */



/* Function prototypes */



/* Main program */

//--- Point class interface ---
/*
 * File: point.h
 * -------------
 * This interface exports the Point class, which represents a point on
 * a two-dimensional integer grid.
 * (c) Eric Roberts, "Programming Abstractions in C++", 2013, p.269
 */
 
 #ifndef _point_h
 #define _point_h
 
 #include <string>
 
 class point {
 public:
 
 /*
 * Constructor: Point
 * Usage: Point origin;
 *        Point pt(xc, yc);
 * ------------------------
 * Creates a Point object. Default constructor sets coordinates to 0,
 * the second form sets the coordinates to xc and yc.
 */
Point();
Point (int xc, int yc);

/*
 * Methods: getX, getY
 * Usage: int x = pt.getX();
 *        int y = pt.getY();
 * -------------------------
 * These methods return the x and y coordinates of the point.
 */

int getX();
int getY();

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string expression of the Point in the form "(x,y)".
 */

std::string toString();

private:
int x;		/* The x-coordinate */
int y;		/* The y-coordinate */
};

#endif




//--- Point class implementation ---
/*
 * File: point.cpp
 * ----------------
 * This file implements the point.h interface.
 * Taken from "Programming Abstractions in C++", Eric Roberts, 2013, p.270
 */

#include <string>
#include "point.h"
#include "strlib.h"
using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variables x and y. In the
 * second form of the constructor, the parameter names are xc and yc to
 * avoid problem of shadowing the ivars.
 */

Point::Point() {
	
	Point::Point() {
		x = 0;
		y = 0;
	}
	Point::Point (int xc, int yc) {
		x = xc;
		y = yc;
	}
	
	/*
	 * Implementation notes: Getters
	 * -----------------------------
	 * The getters return the value of the corresponding instance variable.
	 * No setters provided to ensure Point objects are immutable.
	 */
	
	int Point::getX() {
		return x;
	}
	int Point::getY() {
		return y;
	}
	
	/*
	 * Implementation notes: toString
	 * ------------------------------
	 * The implementation of the toString uses the integerToString function
	 * from the strlib.h interface.
	 */
	string Point::toString() {
		return "(" + integerToString(x) + ","
		+ integerToString(y) + ")";
	}
