#include <iostream>

// Gets the student code from the user
char getStudCode(){
  while (true) {
    std::cout << "Please enter your student code(P/F): ";
    char x;
    std::cin >> x;

    // Checks to see if previous extraction has failed
    if (std::cin.fail()) {
      // It failed so now it needs to handle the failure
      // Puts the cin back in normal operating mode
      std::cin.clear();
      // Remove the bad input
      std::cin.ignore(32767, '\n');
      // Checks to see if studCode mathces the required fields
    } else if (toupper(x) != 'P' && toupper(x) != 'F') {
      // studCode doesn't match either of the required fields
      // Puts cin back in normal operating mode
      std::cin.clear();
      // Removes the bad input
      std::cin.ignore(32767, '\n');
    } else {
      // Cin was successful
      std::cin.ignore(32767, '\n');
      return x;
    }
  }
}

// Used to get any input from the user that is an integer
int getNum(std::string textField) {
  while (true) {
    std::cout << textField;
    int x;
    std::cin >> x;

    // Checks to see if previous extraction has failed
    if (std::cin.fail()) {
      // It failed so now it needs to handle the failure
      // Puts the cin back in normal operating mode
      std::cin.clear();
      // Remove the bad input
      std::cin.ignore(32767, '\n');
    } else {
      // Cin was successful
      std::cin.ignore(32767, '\n');
      return x;
    }
  }
}

int main(){
    // Named constants
    const int PREGSTFEES = 800; // Registration fee for part-time students
    const int PBASICFEES = 4000; // Basic student service fee for part-time students
    const int PMODCOST = 1600; // Cost per module for part-time students
    const int FREGSTFEES = 1500; // Registration fee for full time students
    const int FBASICFEES = 4000; // Basic student service fee for full time students
    const int FBASICFEESEX = 1000; // Basic student service fee for extra student services
    const int FMODCOST = 7000; // Cost per module for full time students

    // Variables that can't be constants
    int studNum; // Student number
    char studCode; // Student code
    int modNum; // Number of modules
    int numServ; // Number of extra services
    int modFees; // Total modules fees
    int billAmount; // The billing amount
    int basicFee; // The total cost of the extra services

    // Gets the required information from the user
    studNum = getNum("Please enter your student number: "); // Student number
    studCode = toupper(getStudCode()); // Student code
    modNum = getNum("Please enter the number of modules you have: "); // Number of modules

    // Switch statement because billing amount is dependant on whether the student is full or part-time
    switch(studCode) {
    case 'P':
      modFees = modNum * PMODCOST; // Calculates the total cost for the modules
      billAmount = PREGSTFEES + PBASICFEES + modFees; // Calculates the billing amount

      // Prints statement
      std::cout << studNum << ": R" << billAmount << std::endl;
    case 'F':
      numServ = getNum("Please enter the number of basic student services you have: "); // Gets the number of extra services
      basicFee = FBASICFEES + (numServ * FBASICFEESEX); // Calculates the cost of the basic student service fee
      modFees = modNum * FMODCOST; // Calculates the total cost for the modules
      billAmount = FREGSTFEES + basicFee + modFees; // Calculates the billing amount

      // Prints statement
      std::cout << studNum << ": R" << billAmount << std::endl;
    }

    return 0;
}
