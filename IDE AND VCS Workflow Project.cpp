#include <iostream>  
#include <iomanip>  

using namespace std;  

int main() {  
	const double sugarCups = 1.5; // cups of sugar per batch  
	const double butterCups = 1.0; // cups of butter per batch  
	const double flourCups = 2.75; // cups of flour per batch  

	const double batchYield = 48; // cookies per batch  

	double cookiesWanted; // Declare the variable cookiesWanted  
	double totalSugarCups;
	double totalButterCups;
	double totalFlourCups;

	cout << "How many cookies do you want to make? ";  
	cin >> cookiesWanted;  

	totalSugarCups = (cookiesWanted / batchYield) * sugarCups;
	totalButterCups = (cookiesWanted / batchYield) * butterCups;
	totalFlourCups = (cookiesWanted / batchYield) * flourCups;
	cout << fixed << setprecision(2); // Set precision for output
	cout << "You will need:\n";
	cout << totalSugarCups << " cups of sugar\n";
	cout << totalButterCups << " cups of butter\n";
	cout << totalFlourCups << " cups of flour\n";
	return 0;

	
}