/*
 * File: InverseGenetics.cpp
 * --------------------------
 * Name: Andrew Smith
 *
 * Lists the possible RNA strands for a protein string provided by user.
 * Assumes all protein strings are valid.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "map.h"
#include "console.h"
#include "simpio.h"
using namespace std;


/* Function prototypes */

void listAllRNAStrandsFor(string protein, Map<char, Set<string> >& codons);
Map<char, Set<string> > loadCodonMap();
void recurAllRNAStrandsFor(string soFar, string protein, Map<char,
                           Set<string> > &codons);

/* Main program */

int main() {
    /* Load the codon map. */
    Map<char, Set<string> > codons = loadCodonMap();

    cout << "This program lists the RNA strands possible for a protein string." << endl;
    while (true) {
        string protein = getLine("Enter a protein string: ");
        if (protein == "") break;
        listAllRNAStrandsFor(protein, codons);
    }
    
    return 0;
}

/* Function: loadCodonMap();
 * Usage: Map<char, Lexicon> codonMap = loadCodonMap();
 * ==================================================================
 * Loads the codon mapping table from a file.
 */

Map<char, Set<string> > loadCodonMap() {
    ifstream input("codons.txt");
    Map<char, Set<string> > result;
    
    /* The current codon / protein combination. */
    string codon;
    char protein;
    
    /* Continuously pull data from the file until all data has been
     * read.
     */
    while (input >> codon >> protein) {
        result[protein] += codon;
    }
    
    return result;
}

/*
 * Function: listAllRNAStrandsFor
 * Usage: listAllRNAStrandsFor("PARTY", codons);
 * ---------------------------------------------
 * Given a protein and a map from amino acid codes to the codons for
 * that code, lists all possible RNA strands that could generate
 * that protein. Assumes all protein letters are valid.
 */

void listAllRNAStrandsFor(string protein, Map<char, Set<string> > &codons) {
    recurAllRNAStrandsFor("", protein, codons);
}

/*
 * Function: recurAllRNAStrandsFor
 * Usage: recurAllRNAStrandsFor("", protein, codons);
 * --------------------------------------------------
 * Recursively lists the RNA strands for a protein.
 */
    
void recurAllRNAStrandsFor(string soFar, string protein, Map<char,
                           Set<string> > &codons) {
    
    /* Base case: empty protein string */
    if (protein.length() == 0) {
        cout << soFar << endl;
        return;
    }
    
    /* Recur step:
     * 1. Take the next letter in the protein.
     * 2. Recur for each RNA sequence
     */
    Set<string> strands = codons.get(protein[0]);
    for (string strand : strands) {
        recurAllRNAStrandsFor(soFar + strand, protein.substr(1), codons);
    }
}









