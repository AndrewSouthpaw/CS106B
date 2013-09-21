/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: Andrew Smith
 *
 * Given a set of cities and hospitals that can cover those cities. 
 * Determines if it is possible to cover all the cities for a specified
 * total number of hospitals.
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
#include "simpio.h"

using namespace std;


bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result);


int main() {
    while (true) {
        string s = getLine("Enter a key to quit.");
        if (s != "") break;
        int numHospitals;
        while (true) {
            numHospitals = getInteger("Enter number of hospitals: ");
            if (numHospitals >= 0) break;
            cout << "Invalid number of hospitals. Please try again." << endl;
        }
        Set<string> cities;
        Vector<Set<string> > locations;
        Vector<Set<string> > result;
        
        // Set up test condition
        cities += "A", "B", "C", "D", "E", "F";
        Set<string> hospital;
        hospital += "A", "B", "C";
        locations.add(hospital);
        hospital.clear();
        hospital += "A", "C", "D";
        locations.add(hospital);
        hospital.clear();
        hospital += "B", "F";
        locations.add(hospital);
        hospital.clear();
        hospital += "C", "E", "F";
        locations.add(hospital);
        
        bool b = canOfferUniversalCoverage(cities, locations, numHospitals, result);
        cout << numHospitals << (b ? " can " : " can not ") << "cover the cities." << endl;
        
        
    }
    return 0;
}

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */

bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result) {
    
    /* Base case 1: all cities are covered */
    if (cities.size() == 0) return true;
    
    /* Base case 2: no more hospitals available */
    if (numHospitals == 0) return false;
    
    for (int i = 0; i < locations.size(); i++) {
        Set<string> location = locations[i];
        Set<string> citiesRemaining = cities;
        for (string city : location) {
            citiesRemaining.remove(city);
        }
        Vector<Set<string> > locationsRemaining = locations;
        locationsRemaining.remove(i);
        if (canOfferUniversalCoverage(citiesRemaining, locationsRemaining, numHospitals - 1, result)) {
            result.add(location);
            return true;
        }
    }
    return false;
}










