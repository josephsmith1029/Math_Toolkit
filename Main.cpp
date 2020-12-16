#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <tgmath.h>

/*This program is a multi tool calculator that can calculate different areas, fractions, the quadratic formula
and the pythagorean theorm. I intend to add more tools in the future, but these four are the only ones so far.
The code is built for expansion, as simple as adding to the arrays, and creating a new menu for that tool.*/


using namespace std;

// Constant Variables =========
const int MAX_TOOLS = 4;
const int MAX_AREAS = 6;
const int MAX_FRACS = 4;
const int MAIN_HEADER_LENGTH = 48;
const int TOOL_HEADER_LENGTH = 48;

const double pi = 3.14159265359;

const string MAIN_TITLE = "\t\tT O O L K I T";
const string AREA_TITLE = "\t A R E A  C A L C U L A T O R";
const string FRAC_TITLE = "\t       F R A C T I O N\n\t     C A L C U L A T O R";
const string QUAD_TITLE = "       Q U A D R A T I C  F O R M U L A\n\t      C A L C U L A T O R";
const string PYTH_TITLE = "     P Y T H A G O R E A N  T H E O R E M\n\t      C A L C U L A T O R";

const char TITLE_DESIGN = '=';
const char TOOL_DESIGN = '-';
// Programmer Details
const string PROGRAMMER_NAME = "Joseph Smith";
const double VERSION = 1.0;
// Variables ==================
string tools[MAX_TOOLS] = {"Area Calculator", "Fraction Calculator", "Quadratic Formula", "Pythagorean Theorem"};
string areas[MAX_AREAS] = { "Square", "Rectangle", "Triangle", "Trapezoid", "Circle", "Ellipse" };
string fracs[MAX_FRACS] = { "Addition", "Subtraction", "Multiplication", "Division" };
// Function Prototypes ========
void menu();
void openMenu(int selection);
void areaTool();
void fracTool();
void quadTool();
void pythTool();
// Function Tool Prototypes ===
void header(int length, string text, char design);
void resetPage(int code);
void errorMessage(int code);
// Function Math Tools ========
int gcd(int num, int dem);

int main() {
	menu();
}

// Functions ========

void menu() {
	//Variables
	int selection = -1;

	//Reset page
	resetPage(0);
	//Welcome message
	cout << "\n\t     Welcome to the Toolkit!\n";
	//Display tools
	for (int i = 0; i < MAX_TOOLS; i++) {
		cout << "\n " << i + 1 << ". " << tools[i];
	}
	cout << "\n 0. Quit program";
	//Select a tool
	cout << "\n\n Select a tool from the menu: ";
	while (selection > MAX_TOOLS || selection < 0) {
		cin >> selection;
		if (selection > MAX_TOOLS || selection < 0) {
			errorMessage(0);
		}
	}
	//Opens a menu based on selection
	if (selection != 0) {
		openMenu(selection);
	}
	else {
		//Displays credits and quits program
		resetPage(0);
		cout << endl << "Made by: " << PROGRAMMER_NAME << endl << "Version " << VERSION;
		cout << endl << "Press enter to quit";
		cin.get();
		cin.sync();
		cin.ignore();
		exit(0);
	}
	
	
}

void openMenu(int selection) {
	//Reset page
	resetPage(0);
	//Cycle through different menus depending on selection integer called
	switch (selection) {
	case 0: menu();
		break;
	case 1: areaTool();
		break;
	case 2: fracTool();
		break;
	case 3: quadTool();
		break;
	case 4: pythTool();
	}
}

void areaTool() {
	//Variables
	int selection = -1;
	double s, a, b, h, r;
	double answer;
	//Header
	cout << endl;
	header(TOOL_HEADER_LENGTH, AREA_TITLE, TOOL_DESIGN);
	for (int i = 0; i < MAX_AREAS; i++) {
		cout << "\n " << i + 1 << ". " << areas[i];
	}
	cout << "\n 0. Return to menu";
	//Choose shape
	cout << "\n\n Choose a shape to find area of: ";
	while (selection > 7 || selection < 0) {
		cin >> selection;
		if (selection > 7 || selection < 0)
			errorMessage(0);
	}
	//Each shape formula. 0 is back, 1 is square, 2 is rect, etc.
	switch (selection) {
	case 0: openMenu(0);
		break;
	case 1: cout << "\n Area of square chosen.\n Enter length of side: ";
			cin >> s;
			answer = s * s;
			cout << "\n The area of the square is " << fixed << setprecision(2) << answer << ". ";
		break;
	case 2: cout << "\n Area of rectangle chosen.\n Enter length of base: ";
			cin >> b;
			cout << "\n Enter length of height: ";
			cin >> h;
			answer = b * h;
			cout << "\n The area of the rectangle is " << fixed << setprecision(2) << answer << ". ";
		break;
	case 3: cout << "\n Area of triangle chosen.\n Enter length of base: ";
			cin >> b;
			cout << "\n Enter length of height: ";
			cin >> h;
			answer = ((b*h)/2);
			cout << "\n The area of the triangle is " << fixed << setprecision(2) << answer << ". ";
		break;
	case 4: cout << "\n Area of trapezoid chosen.\n Enter length of base 1: ";
			cin >> b;
			cout << "\n Enter length of base 2: ";
			cin >> a;
			cout << "\n Enter length of height: ";
			cin >> h;
			answer = (((a + b) / 2) * h);
			cout << "\n The area of the trapezoid is " << fixed << setprecision(2) << answer << ". ";
		break;
	case 5: cout << "\n Area of circle chosen.\n Enter radius: ";
			cin >> r;
			answer = ((r * r) * pi);
			cout << "\n The area of the circle is " << fixed << setprecision(2) << answer << ". ";
		break;
	case 6: cout << "\n Area of an ellipse chosen\n Enter length of b: ";
			cin >> b;
			cout << "\n Enter length of a: ";
			cin >> a;
			answer = (pi * a * b);
			cout << "\n The area of the ellipse " << fixed << setprecision(2) << answer << ". ";
		break;
	}
	//Return to beginning of function
	cout << "\n Press enter to return.";
	cin.get();
	cin.sync();
	cin.ignore();
	openMenu(1);
}

void fracTool() {
	//Variables
	int selection = -1;
	int num1, den1, num2, den2, num3, den3;
	int common_factor = 0;
	cout << endl;
	// Draw header and options
	header(TOOL_HEADER_LENGTH, FRAC_TITLE, TOOL_DESIGN);
	for (int i = 0; i < MAX_FRACS; i++)
		cout << "\n " << i + 1 << ". " << fracs[i];
	cout << "\n 0. Return to menu";
	cout << "\n Please choose an operator: ";
	// Make sure selection is within bounds
	while (selection > MAX_FRACS || selection < 0) {
		cin >> selection;
		if (selection > MAX_FRACS || selection < 0) {
			errorMessage(0);
		}
	}
	// Preform operations depending on user selection
	switch (selection) {
	case 0: openMenu(0);
		break;
	case 1: cout << "\n -FIRST FRACTION-";
			cout << "\n Enter numerator: ";
			cin >> num1;
			cout << " Enter denominator: ";
			cin >> den1;
			cout << " -SECOND FRACTION- ";
			cout << "\n Enter numerator: ";
			cin >> num2;
			cout << " Enter denominator: ";
			cin >> den2;
			den3 = gcd(den1, den2);
			den3 = (den1 * den2) / den3;
			num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);
			common_factor = gcd(num3, den3);
			den3 = den3 / common_factor;
			num3 = num3 / common_factor;
			cout << "\n " << num1 << "/" << den1 << " added to " << num2 << "/" << den2 << " is equal to " << num3 << "/" << den3;
		break;
	case 2: cout << "\n -FIRST FRACTION-";
			cout << "\n Enter numerator: ";
			cin >> num1;
			cout << " Enter denominator: ";
			cin >> den1;
			cout << " -SECOND FRACTION- ";
			cout << "\n Enter numerator: ";
			cin >> num2;
			cout << " Enter denominator: ";
			cin >> den2;
			den3 = gcd(den1, den2);
			den3 = (den1 * den2) / den3;
			num3 = (num1) * (den3 / den1) - (num2) * (den3 / den2);
			common_factor = gcd(num3, den3);
			den3 = den3 / common_factor;
			num3 = num3 / common_factor;
			cout << "\n " << num1 << "/" << den1 << " subtracted by " << num2 << "/" << den2 << " is equal to " << num3 << "/" << den3;
		break;
	case 3: cout << "\n -FIRST FRACTION-";
			cout << "\n Enter numerator: ";
			cin >> num1;
			cout << " Enter denominator: ";
			cin >> den1;
			cout << " -SECOND FRACTION- ";
			cout << "\n Enter numerator: ";
			cin >> num2;
			cout << " Enter denominator: ";
			cin >> den2;
			num3 = num1 * num2;
			den3 = den1 * den2;
			common_factor = gcd(num3, den3);
			den3 = den3 / common_factor;
			num3 = num3 / common_factor;
			cout << "\n " << num1 << "/" << den1 << " multiplied by " << num2 << "/" << den2 << " is equal to " << num3 << "/" << den3;
		break;
	case 4: cout << "\n -FIRST FRACTION-";
			cout << "\n Enter numerator: ";
			cin >> num1;
			cout << " Enter denominator: ";
			cin >> den1;
			cout << " -SECOND FRACTION- ";
			cout << "\n Enter numerator: ";
			cin >> num2;
			cout << " Enter denominator: ";
			cin >> den2;
			num3 = num1 * den2;
			den3 = num2 * den1;
			common_factor = gcd(num3, den3);
			den3 = den3 / common_factor;
			num3 = num3 / common_factor;
			cout << "\n " << num1 << "/" << den1 << " divided by " << num2 << "/" << den2 << " is equal to " << num3 << "/" << den3;
		break;
	}
	//Return to beginning of function
	cout << "\n Press enter to return";
	cin.get();
	cin.sync();
	cin.ignore();
	openMenu(2);

}

void quadTool() {
	//Variables
	double x1, x2, a, b, c;
	int selection = -1;
	cout << endl;
	//Display header and options
	header(TOOL_HEADER_LENGTH, QUAD_TITLE, TOOL_DESIGN);
	cout << "\n 1. Enter numbers\n 0. Return to menu\n";
	//Set bounds of selection
	while (selection > 1 || selection < 0) {
		cin >> selection;
		if (selection > 1 || selection < 0) {
			errorMessage(0);
		}
	}
	//Enter numbers if user selected to enter numbers, if not go back to menu
	switch (selection) {
	case 0: openMenu(0);
		break;
	case 1: cout << "\n Enter a: ";
			cin >> a;
			cout << "\n Enter b: ";
			cin >> b;
			cout << "\n Enter c: ";
			cin >> c;
			double bd = (b * b) - (4 * a * c);
			if (bd >= 0) {
				x1 = (-b + sqrt(bd)) / (2 * a);
				x2 = (-b - sqrt(bd)) / (2 * a);
				cout << "\n The first solution for x is " << x1 << ".";
				cout << "\n The second solution for x is " << x2 << ".";
			}
			else {
				cout << "Complex roots, try again.";
			};
		break;
	}
	
	
	//Return to beginning of function
	cout << "\n Press enter to return.";
	cin.get();
	cin.sync();
	cin.ignore();
	openMenu(3);
}

void pythTool() {
	//Variables
	double a, b, c;
	int selection = -1;
	//Display header and options
	cout << endl;
	header(TOOL_HEADER_LENGTH, PYTH_TITLE, TOOL_DESIGN);
	cout << "\n 1. Enter numbers\n 0. Return to menu\n";
	//Set bounds of selection
	while (selection > 1 || selection < 0) {
		cin >> selection;
		if (selection > 1 || selection < 0) {
			errorMessage(0);
		}
	}
	//Enter numbers if user chose to enter numbers, go back to menu if not
	switch (selection) {
	case 0: openMenu(0);
		break;
	case 1: cout << "\n Enter a: ";
		cin >> a;
		cout << "\n Enter b: ";
		cin >> b;
		c = sqrt((a * a) + (b * b));
		cout << "\n c = " << c;
		break;
	}
	//Return to beginning of function
	cout << "\n Press enter to return.";
	cin.get();
	cin.sync();
	cin.ignore();
	openMenu(4);
}

// Function Tools ===

void header(int length, string text, char design) {
	for (int i = 0; i < length; i++)
		cout << design;
	cout << endl << text << endl;
	for (int i = 0; i < length; i++)
		cout << design;
}

void resetPage(int code) {
	switch (code) {
	case 0:	system("CLS");
		header(MAIN_HEADER_LENGTH, MAIN_TITLE, TITLE_DESIGN);
	}
}

void errorMessage(int code) {
	switch (code) {
	case 0: cout << "\n Invalid selection! Please try again.\n";
	}
}

// Math tools

int gcd(int num, int den) {
	if (num == 0)
		return den;
	return gcd(den % num, num);
}
