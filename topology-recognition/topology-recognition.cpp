
/*
Name:		John Hunsaker
Project: 	Topology Recognition Problem
Problem: 	You are given a weight matrix W[0..n −1, 0..n −1], where n > 3, which is the weight matrix of a weighted, connected,
undirected graph modeling a network with one of these topologies, if any, the matrix represents. Assume the weights to be
positive integer values. Instead of infinity, the elements if the matrix will have the value 100. Design a brute-force algorithm
(express it in pseudocode) for this problem and indicate its time efficiency class.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <fstream>

using namespace std;


int main() {
	int n, i, j, center;
	int W[100][100];
	int zeroCountingArray[100];
	int weightCountingArray[100];
	bool cond;

	//Display the header.                                                        
	cout << "\nTopology Recognition Algorithm" << endl;
	cout << "\nEnter the number of nodes in the topology, then press enter (must be a number larger than 3): " << endl;
	cin >> n;

	while (n <= 3) {
		cout << "You did not enter a number larger than 3. Please enter a correct number: " << endl;
		cin >> n;
	}

	//Read in the weight matrix.                                                     
	cout << "\nEnter the positive weights, 100 for infinity, and 0 if a node connects to itself. Press enter after every line." << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> W[i][j];
		}
	}

	//Confirm the weight matrix is symmetrical (i.e. it truly represents a graph, with no input errors.)
	int y = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (W[i][j] != W[j][i]) {
				cout << "The matrix that was entered is not symmetrical. Please correct the errors, and try again later." << endl;
				cout << "Enter any key, then press enter to close window." << endl;
				cin >> y;
				return EXIT_SUCCESS;
			}
		}
	}

	//Zero out helper arrays from zero to n nodes.
	for (int a = 0; a < n; a++) {
		zeroCountingArray[a] = 0;
		weightCountingArray[a] = 0;
	}

	//Open an output file.
	ofstream myfile("TopologyOutput.txt");

	//Start the chronograph to time the execution of the algorithm.               
	auto start = chrono::high_resolution_clock::now();

	cout << "\nThe topology is:" << endl;




	/* ------------- MAP THE MATRIX COUNTS TO HELPER ARRAYS ------------- */

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//Put every found zero into helper array "zeroTrackerArray".
			if (W[i][j] == 0) {
				zeroCountingArray[i] += 1;
			}

			//Put every found non zero or 100 integer into helper array "connectionCountingArray".
			if (W[i][j] > 0 && W[i][j] < 100) {
				weightCountingArray[i] += 1;
			}
		}
	}




	/* ------------- RING TEST -------------*/

	cond = true;
	//Loop to check whether the topology is a ring.       
	for (int a = 0; a < n; a++) {
		if (zeroCountingArray[a] != 1) {
			cond = false;
		}

		if (weightCountingArray[a] != 2) {
			cond = false;
		}
	}

	if (cond) {
		//Print Results to Screen
		cout << "RING" << endl;
		auto end = chrono::high_resolution_clock::now();
		int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
		double seconds = microseconds / 1E6;
		cout << "\nElapsed time: " << seconds << " seconds" << endl;

		//Print Results to OutputFile
		if (myfile.is_open())
		{
			myfile << "\nCPSC 335" << endl;
			myfile << "Topology Recognition Algorithm" << endl;
			myfile << "Written by: John Hunsaker\n" << endl;
			myfile << "Number of nodes in the topology:\n" << n << endl;
			myfile << "\nThis matrix was entered:" << endl;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					myfile << W[i][j] << " ";
				}
				myfile << endl;
			}
			myfile << "\nThe topology is:" << endl;
			myfile << "RING" << endl;
			myfile << endl;
			myfile << "Elapsed time: " << seconds << " seconds" << endl;
			myfile.close();
		}

		//Close Program
		cout << "\nResults have been written to a file titled TopologyOutput.txt in the same directory as this program." << endl;
		char c;
		cout << "\nEnter any key, then press enter to close window." << endl;
		cin >> c;
		return EXIT_SUCCESS;
	}




	/* ------------- STAR TEST -------------*/

	cond = true;
	center = 0;
	//Loop to check whether the topology is a star.                               
	for (int a = 0; a < n; a++) {
		if (zeroCountingArray[a] != 1) {
			cond = false;
		}

		if (weightCountingArray[a] == (n - 1)) {
			center++;
		}

		else if (weightCountingArray[a] != 1) {
			cond = false;
		}
	}

	if (cond && (center == 1)) {
		//Print Results to Screen
		cout << "STAR" << endl;
		auto end = chrono::high_resolution_clock::now();
		int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
		double seconds = microseconds / 1E6;
		cout << "\nElapsed time: " << seconds << " seconds" << endl;

		//Print Results to OutputFile
		if (myfile.is_open())
		{
			myfile << "\nCPSC 335" << endl;
			myfile << "Topology Recognition Algorithm" << endl;
			myfile << "Written by: John Hunsaker\n" << endl;
			myfile << "Number of nodes in the topology:\n" << n << endl;
			myfile << "\nThis matrix was entered:" << endl;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					myfile << W[i][j] << " ";
				}
				myfile << endl;
			}
			myfile << "\nThe topology is:" << endl;
			myfile << "STAR" << endl;
			myfile << endl;
			myfile << "Elapsed time: " << seconds << " seconds" << endl;
			myfile.close();
		}

		//Close Program
		cout << "\nResults have been written to a file titled TopologyOutput.txt in the same directory as this program." << endl;
		char c;
		cout << "\nEnter any key, then press enter to close window." << endl;
		cin >> c;
		return EXIT_SUCCESS;
	}




	/* ------------- MESH TEST -------------*/

	cond = true;
	//Loop to check whether the topology is a fully connected mesh.               
	for (int a = 0; a < n; a++) {
		if (zeroCountingArray[a] != 1) {
			cond = false;
		}

		if (weightCountingArray[a] != (n - 1)) {
			cond = false;
		}
	}

	if (cond) {
		//Print Results to Screen
		cout << "FULLY CONNECTED MESH" << endl;
		auto end = chrono::high_resolution_clock::now();
		int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
		double seconds = microseconds / 1E6;
		cout << "\nElapsed time: " << seconds << " seconds" << endl;

		//Print Results to OutputFile
		if (myfile.is_open())
		{
			myfile << "\nCPSC 335" << endl;
			myfile << "Topology Recognition Algorithm" << endl;
			myfile << "Written by: John Hunsaker\n" << endl;
			myfile << "Number of nodes in the topology:\n" << n << endl;
			myfile << "\nThis matrix was entered:" << endl;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					myfile << W[i][j] << " ";
				}
				myfile << endl;
			}
			myfile << "\nThe topology is:" << endl;
			myfile << "FULLY CONNECTED MESH" << endl;
			myfile << endl;
			myfile << "Elapsed time: " << seconds << " seconds" << endl;
			myfile.close();
		}

		//Close Program
		cout << "\nResults have been written to a file titled TopologyOutput.txt in the same directory as this program." << endl;
		char c;
		cout << "\nEnter any key, then press enter to close window." << endl;
		cin >> c;
		return EXIT_SUCCESS;
	}




	/* ------------- NEITHER -------------*/

	else {
		//Print Results to Screen
		cout << "NEITHER" << endl;
		auto end = chrono::high_resolution_clock::now();
		int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
		double seconds = microseconds / 1E6;
		cout << "\nElapsed time: " << seconds << " seconds" << endl;

		//Print Results to OutputFile
		if (myfile.is_open())
		{
			myfile << "\nCPSC 335" << endl;
			myfile << "Topology Recognition Algorithm" << endl;
			myfile << "Written by: John Hunsaker\n" << endl;
			myfile << "Number of nodes in the topology:\n" << n << endl;
			myfile << "\nThis matrix was entered:" << endl;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					myfile << W[i][j] << " ";
				}
				myfile << endl;
			}
			myfile << "\nThe topology is:" << endl;
			myfile << "NEITHER" << endl;
			myfile << endl;
			myfile << "Elapsed time: " << seconds << " seconds" << endl;
			myfile.close();
		}

		//Close Program
		cout << "\nResults have been written to a file titled TopologyOutput.txt in the same directory as this program." << endl;
		char c;
		cout << "\nEnter any key, then press enter to close window." << endl;
		cin >> c;
		return EXIT_SUCCESS;
	}
}