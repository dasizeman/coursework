/*
 * hash_exp.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: dave
 */

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

#include "OpenHashTable.h"

int main()
{
	vector<string> words;
	// Read in the first 10000 words of input
	const int NUMWORDS = 10000;
	int count = 0;
	string buf;
	while (!cin.eof() && count < NUMWORDS)
	{
		getline(cin, buf, '\n');
		words.push_back(buf);
		count++;
	}
	cout << "LOADING 10,000 WORDS INTO OPEN HASH TABLE AND TIMING INSERTION/DELETION WITH DIFFERENT BUCKET SIZES" << endl;
	// Average insertion times over different bucket amounts
	int intervals = 100; // 5 intervals of 1000
	int interval = 1000;
	double bestbtime = 0;
	int bestb = 0; // The b value that yeilded the shortest overall time
	clock_t start, end;
	OpenHashTable* oht = new OpenHashTable(0);

	for (int i = 1000; i <= (intervals*interval); i+= interval)
	{
		double insert_total = 0;
		double delete_total = 0; // Total times for averaging

		for (int j = 0; j < 10; j++)
		{
			// Add the words to an OHT dictionary
			oht->SETB(i);
			vector<string>::iterator it = words.begin();
			start = clock();
			while (it != words.end())
			{
				oht->INSERT((*it));
				it++;
			}
			end = clock();

			insert_total += ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);

			// Delete the words from the dictionary
			it = words.begin();
			start = clock();
			while (it != words.end())
			{
				oht->DELETE((*it));
				it++;
			}
			end = clock();

			delete_total += ((double)end-(double)start)/(CLOCKS_PER_SEC/1000);
		}
		// Compute averages and best times
		double avg = (insert_total + delete_total) / 10;
		cout << "OVERALL AVG TIME FOR B = " << i << " : " << avg << endl;
		if (bestbtime == 0 || avg < bestbtime)
		{
			bestbtime = avg;
			bestb = i;
		}
	}
	double load = (double)(NUMWORDS)/bestb;
	cout << "DETERMINED OPTIMAL BUCKET SIZE TO BE " << bestb << endl;
	cout << "LOAD FACTOR " << load << endl;


	return 0;
}


