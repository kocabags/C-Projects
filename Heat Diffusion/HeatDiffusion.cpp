#include <iostream>
#include <cstdlib>
#include <iomanip> 

using namespace std;

bool getchoice(string);
int getint(string);
float getfloat(string);
float* createwire(int,float,float,float);
float** createplate(int,float,float,float);
void printwire(float*,int);
void printplate(float**,int);
void reprintwire(float*,float*,int);
void reprintplate(float**,float**,int);
void getstability(bool,float rho,float c,float x,float t,float k);
void evalwire(float*,int,float rho,float c,float x,float t,float k);
void evalplate(float**,int,float rho,float c,float x,float t,float k);
void removeplate(float**,int);

int main() {

   	bool goagain = 1;	

   	while (goagain) {
		bool wire_or_plate = getchoice("Press 1 for Wire or Press 0 for Plate: ");
		int length = getint("How many segments would you like?  ");
		float distance = getfloat("How long do you want it?  ");
		float deltax = (distance/((float)length));
		float time = getfloat("Time: ");
		int intervals = getint("Time intervals: ");
		float deltat = (time/((float)intervals));
		float rho = getfloat("rho: ");
		float capacity = getfloat("specific heat capacity: ");
		float conductivity = getfloat("Thermal Conductivity: ");
		getstability(wire_or_plate,rho,capacity,deltax,deltat,conductivity);
		float tempinit = getfloat("Initial Temperature: ");
	
		if (wire_or_plate) {
			float templeft = getfloat("Left Temp: ");
			float tempright = getfloat("Right Temp: ");
			float* wire = createwire(length,tempinit,templeft,tempright);
			printwire(wire,length);
			for (int i = 0; i < (intervals-1); i++) {
				evalwire(wire,length,rho,capacity,deltax,deltat,conductivity);
				printwire(wire,length);
				cout << endl;
			}
			delete [] wire;
		}
		else {
			float temptopbottom = getfloat("Temp on the top and bottom: ");
			float tempsides = getfloat("Temp on the sides: ");
			float** plate = createplate(length,tempinit,tempsides,temptopbottom);
			printplate(plate,length);
			for (int i = 0; i < (intervals-1); i++) {
				evalplate(plate,length,rho,capacity,deltax,deltat,conductivity);
				printplate(plate,length);
				cout << endl;
			}
			removeplate(plate,length);
		}
		goagain = getchoice("Do you want to go again? 1 for yes, 0 for no: ");
	}

	return 0;
}

/*************************************************************
 * ** Function: getchoice
 * ** Description: In order to pick a choice, this function get 1 or 0 from the user.
 * ** Parameters: Prompt is displayed to the user for input.
 * *************************************************************/
bool getchoice(string prompt) {

   	string choice = "";

	while(1) {
		cout << prompt;
		cin >> choice;

		if (choice == "0")
			return 0;
		else if (choice == "1")
		   	return 1;
		else
		   	cout << "Invalid Input!" << endl;
	}
}

/*************************************************************
 * ** Function: getint
 * ** Description: This function gets an integer from the user.
 * ** Parameters: Prompt is displayed to the user for input.
 * *************************************************************/
int getint(string prompt) {

	string input = "";
	bool reprompt = 1;

	while (reprompt) {
		cout << prompt;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input.at(i) >= '0' && input.at(i) <= '9') {
			   	reprompt = 0;
			}
			else {
			   	cout << "Invalid Input" << endl;
				reprompt = 1;
				break;
			}
		}
	}
	return atoi(input.c_str());
}

/*************************************************************
 * ** Function: getfloat
 * ** Description: This function asks for a float number to the user.
 * ** Parameters: Prompt is displayed to the user for input.
 * *************************************************************/
float getfloat(string prompt) {

	string input = "";
	bool reprompt = 1;
	int dotcheck = 0;
	int dashcheck = 0;

	while (reprompt) {
		cout << prompt;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if ((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) == '.' || input.at(i) == '-') {
			   	if (input.at(i) == '-' && i != 0) {
					cout << "Invalid Input" << endl;
					reprompt = 1;
					break;
				}
			   	if (dotcheck > 1) {
					cout << "Invalid Input" << endl;
					reprompt = 1;
					break;
				}
				if (input.at(i) == '.') {
					dotcheck++;
				}   	
			   	reprompt = 0;
			}
			else {
			   	cout << "Invalid Input" << endl;
				reprompt = 1;
				break;
			}
		}
	}
	return atof(input.c_str());
}

/*************************************************************
 * ** Function: createwire
 * ** Description: This function creates a 1d array for the wire.
 * ** Parameters: Length represents the segments, templeft represents the left side and tempright represent the riht side temperature,
 * ** tempint represents the intial temperature.
 * ** Pre-Conditions: length, tempinit, templeft, tempright 
 * ** Post-Conditions: The wire is created.
 * *************************************************************/
float* createwire(int length,float tempinit,float templeft,float tempright) {

   	float* wire = new float[length];

	wire[0] = templeft;
	wire[length-1] = tempright;
	for (int i = 1; i < (length-1); i++) {
		wire[i] = tempinit;
	}

	return wire;
}

/*************************************************************
 * ** Function: createplate
 * ** Description: This function creates a 2d array for the plate.
 * ** Parameters:Length represents the segments, tempside represents the left side and the riht side temperature,
 * ** temptopbottom represents the top and the bottom temperature. 
 * ** Pre-Conditions: length, tempinit, tempsides, temptopbottom 
 * ** Post-Conditions: The plate is created.
 * *************************************************************/
float** createplate(int length,float tempinit,float tempsides,float temptopbottom) {

   	float** plate = new float*[length];

	for (int i = 0; i < length; i++) {
		plate[i] = new float[length];
		if (i == 0 || i == (length-1)) {
			for (int j = 0; j < length; j++) {
				plate[i][j] = temptopbottom;
			   	if (j == 0 || j == (length-1)) {
					plate[i][j] = 0;
				}
			}
		}
		else {
			for (int j = 0; j < length; j++) {
				if (j == 0 || j == (length-1)) {
					plate[i][j] = tempsides;
				}
				else {
					plate[i][j] = tempinit;
				}
			}
		}
	}

	return plate;
}

/*************************************************************
 * ** Function: printwire
 * ** Description: This function prints out a 1d array of the wire.
 * ** Parameters: Length is the number of segments
 * ** Pre-Conditions: Length has a value
 * ** Post-Conditions: Print out the wire.
 * *************************************************************/
void printwire(float* wire,int length) {

	for(int i = 0; i < length; i++) {
		cout << setw(8) << wire[i];
	}
	cout << endl;
}

/*************************************************************
 * ** Function: printplate
 * ** Description: This function prints out a 2d array of the plate.
 * ** Parameters: Length is the heigth and the lenght.
 * ** Pre-Conditions: Both values are initialized.
 * ** Post-Conditions: Print out the plate.
 * *************************************************************/
void printplate(float** plate,int length) {

	for(int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << setw(8) << plate[i][j];
		}
		cout << endl;
	}
}

/*************************************************************
 * ** Function: reprintwire
 * ** Description: Copies the 1d array to another one.
 * ** Parameters: Wire 1 and Wire 2 are the 1d arrays.
 * ** Pre-Conditions: Both values ara initialized.
 * ** Post-Conditions: Prints out the other 1d array.
 * *************************************************************/
void reprintwire(float* wire1,float* wire2,int length) {

	for (int i = 1; i < (length-1); i++) {
		wire2[i] = wire1[i];
	}

}

/*************************************************************
 * ** Function: reprintplate
 * ** Description: Copies the 2d array to another one.
 * ** Parameters: Plate1 and plate 2 are the 2d arrays.
 * ** Pre-Conditions: Both values are initialized.
 * ** Post-Conditions: Prints out the next 2d array.
 * *************************************************************/
void reprintplate(float** plate1,float** plate2,int length) {
	
	for (int i = 1; i < (length-1); i++) {
		for (int j = 1; j < (length-1); j++) {
			plate2[i][j] = plate1[i][j];
		}
	}

}

/*************************************************************
 * ** Function: getstability
 * ** Description: This function determines whether or not the simulation will be stable.
 * ** Parameters: wire_or_plate is whether its a wire or plate, rho is density, c is the specific 
 * ** heat capacity, x is the distance between segments, t is the time step for each interval, and k is the conductivity.
 * ** Pre-Conditions: All the values are initialized
 * ** Post-Conditions: Prints out if it's stable or not
 * *************************************************************/
void getstability(bool wire_or_plate,float rho,float c,float x,float t,float k) {

	if (wire_or_plate) {
		if ((t*k)/(x*x*c*rho) < 0.5 && (t*k)/(x*x*c*rho) > -0.5) {
			cout << "This simulation is stable" << endl;
		}
		else {
			cout << "This simulation is unstable" << endl;
			exit(0);
		}
	}
	else {
	   	if (t < ((x*x*rho*c)/(4*k))) {
			cout << "This simulation is stable" << endl;
		}
		else {
			cout << "This simulation is unstable" << endl;
			exit(0);
		}
	}

}

/*************************************************************
 * ** Function: evalwire
 * ** Description: This function calculates the new temp of the wire after one interval.
 * ** Parameters: Wire is the wire, length is the length of the wire, rho is density, c is the specific
 * ** Pre-Conditions: All the values are initialized. 
 * ** Post-Conditions: The temp changes.
 * *************************************************************/
void evalwire(float* wire,int length,float rho,float c,float x,float t,float k) {
	
   	float* copywire = new float[length];
	for (int i = 1; i < (length-1); i++) {
		copywire[i] = (t*k*((wire[i+1]-(2*wire[i])+wire[i-1])/(x*x*c*rho))+wire[i]);
	}
	reprintwire(copywire,wire,length);
	delete [] copywire;
}

/*************************************************************
 * ** Function: evalplate
 * ** Description: This function calculates the new temp of the plate after one interval.
 * ** Parameters: plate is the plate, length is the width/height of the plate, rho is density, c is the specific
 * ** Pre-Conditions: All the values are initialized.
 * ** Post-Conditions: The temp changes.
 * *************************************************************/
void evalplate(float** plate,int length,float rho,float c,float x,float t,float k) {

   	float constant = ((k*t)/(c*rho*x*x));
	float** copyplate = new float*[length];
	for (int i = 0; i < length; i++) {
		copyplate[i] = new float[length];
	}	
	
	for (int i = 1; i < (length-1); i++) {
		for (int j = 1; j < (length-1); j++) {
			copyplate[i][j] = (constant*(plate[i+1][j]-2*plate[i][j]+plate[i-1][j]+plate[i][j+1]-2*plate[i][j]+plate[i][j-1])+plate[i][j]);
		}	
	}
	reprintplate(copyplate,plate,length);
	for (int i = 0; i < length; i++) {
		delete [] copyplate[i];
	}
	delete [] copyplate;
}

/*************************************************************
 * ** Function: removeplate
 * ** Description: This function deletes the rows and than the plate.
 * ** Parameters: Plate is the plate
 * ** Pre-Conditions: Values are initialized.
 * ** Post-Conditions: The plate is deleted.
 * *************************************************************/
void removeplate(float** plate,int length) {

	for (int i = 0; i < length; i++) {
		delete [] plate[i];
	}
	delete [] plate;

}


