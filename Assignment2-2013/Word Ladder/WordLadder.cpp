/*
 * File: WordLadder.cpp
 * ----------------------
 * Name: Andrew Smith
 *
 * The Word Ladder searches for the shortest word ladders between two inputted words.
 * A word ladder is a connection between two words by changing one letter
 * at a time.
 *
 * Using starter files of Assignment 2 of Stanford CS106B Spring 2013 class.
 *
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "vector.h"
#include "queue.h"
#include "simpio.h"
using namespace std;


/* Constants */

const string LEXICON_FILE_NAME = "EnglishWords.dat";


/* Function prototypes */

Vector<string> findShortestLadder(Lexicon &words, string start, string end);
Lexicon findWordsOffByOneLetter(Lexicon &words, string word);

/* Main program */

int main() {
	
	Lexicon words(LEXICON_FILE_NAME);
	
	cout << "This program finds the shortest word ladder between "
	<< "two words." << endl;
	
	while (true) {
		
		/* Input words */
		cout << "Enter first word (or RETURN to quit): ";
		string start = getLine();
		if (start == "") break;
		cout << "Enter second word: ";
		string end = getLine();
		
		/* Check if word lengths match */
		if (start.length() != end.length()) {
			cout << "Word lengths do not match! Please try again." << endl;
			
		/* Search for word ladder */
		} else {
			cout << "Searching..." << endl;
			
			Vector<string> shortest = findShortestLadder(words, start, end);
			
			/* Check if a ladder was found */
			if (shortest.size() == 0) {
				cout << "No ladder found!" << endl;
				
				/* Print out the ladder */
			} else {
				string result = "Ladder found: ";
				for (int i = 0; i < shortest.size(); i++) {
					if (i != 0) result += " -> ";
					result += shortest[i];
				}
				cout << result << endl;
			}
		}
	}
	cout << "Goodbye!" << endl;
	return 0;
}



/*
 * Function: findShortestLadder
 * Usage: Vector<string> ladder = findShortestLadder(words, start, end);
 * ---------------------------------------------------------------------
 * Returns the shortest word ladder between two words. Words must be of equal
 * length. If no ladder is found, an empty vector is returned. A lexicon of
 * words is used.
 */

Vector<string> findShortestLadder(Lexicon &words, string start, string end) {

	/* Create an empty queue, ladder, and Lexicon of used words */
	Queue<Vector<string> > ladders;
	Vector<string> ladder;
	Lexicon usedWords;
	
	/* Add the start word to the queue and the list of used words */
	ladder.add(start);
	ladders.enqueue(ladder);
	usedWords.add(start);
	
	/* While the queue is not empty */
	while (!ladders.isEmpty()) {
		
		ladder = ladders.dequeue();
		string lastWord = ladder[ (ladder.size() - 1) ];
		
		/* Return the ladder if the final word is the end word */
		if (lastWord == end) {
			return ladder;
		}
		
		/* Find words off by one letter from last word of ladder */
		Lexicon wordsOffByOneLetter = findWordsOffByOneLetter(words, lastWord);
		
		/* For each word off by one letter, if it hasn't been used in a ladder,
		 * create a copy of the current ladder and add the word to it, then
		 * add it to the queue.
		 */
		for (string word : wordsOffByOneLetter) {
			if (!usedWords.contains(word)) {
				Vector<string> newLadder = ladder;
				newLadder.add(word);
				usedWords.add(word);
				ladders.enqueue(newLadder);
			}
		}
	}
	
	/* If the queue empties and a ladder has not successfully been returned,
	 * no ladder exists; returns an empty vector.
	 */
	ladder.clear();
	return ladder;
}



/*
 * Function: findWordsOffByOneLetter
 * Usage: Lexicon words = findWordsOffByOneLetter(words, lastWord);
 * -----------------------------------------------------------------
 * Returns a Lexicon of words that are off by one letter from the given word,
 * based on a given Lexicon.
 */
 
Lexicon findWordsOffByOneLetter(Lexicon &words, string word) {

	Lexicon result;
	for (int i = 0; i < word.length(); i++) {
		
		/* Try replacing that letter with all 26 alphabet letters. If it forms
		 * a new word, add it to the result.
		 */
		for (char ch = 'a'; ch <= 'z'; ch++) {
			string str = word.substr(0, i) + ch + word.substr(i + 1, word.length());
			if (words.contains(str)) {
				result.add(str);
			}
		}
	}
	return result;
}















