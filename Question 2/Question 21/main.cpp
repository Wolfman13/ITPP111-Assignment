#include <iostream>

int numStuds = 0;
int totTickSold = 0;

std::string getStudName(){
  while (true) {
    std::cout << "Please enter your name: ";
    std::string x;
    std::getline(std::cin, x);

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32767, '\n');
    } else {
      return x;
    }
  }
}

int getTickSold(){
  while (true) {
    std::cout << "Please enter the amount of tickets sold: ";
    int x;
    std::cin >> x;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(32767, '\n');
    } else {
      return x;
    }
  }
}

void counter(){
  const int TICKPRICE = 40;
  int aveTickSold;
  int moneyGen;

  std::cout << "Number of students: " << numStuds << std::endl;
  std::cout << "Total number of tickets sold: " << totTickSold << std::endl;
  if(totTickSold == 0 || numStuds == 0){
    std::cout << "The average ticket sold per student: 0" << std::endl;
  }else{
    aveTickSold = totTickSold/numStuds;
    std::cout << "The average ticket sold per student: "<< aveTickSold << std::endl;
  }
  if(totTickSold == 0){
    std::cout << "Money generated: R0" << std::endl;
  }else{
    moneyGen = totTickSold * TICKPRICE;
    std::cout << "Money generated: R" << moneyGen << std::endl;
  }
}

void cleanUp(){
  std::cin.clear();
  std::cin.ignore(32767, '\n');
}

int main(){
  std::string studName;
  int tickSold;

  while(true){
    counter();
    studName = getStudName();
    std::cout << studName << std::endl;
    tickSold = getTickSold();
    std::cout << tickSold << std::endl;

    cleanUp();
    numStuds += 1;
    totTickSold += tickSold;
    std::cout << "\033[2J\033[1;1H"; // Clear the screen after every entry
  }
}
