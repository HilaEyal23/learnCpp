#include <iostream>
#include <random>
#include <limits>

bool checkGuess(int tryNumber, int choosenNumber);
bool playAgain();
void handleExtraText();
bool validInput();

#define MAX_NUMBER_OF_GUESSES 7
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main()
{
  std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
  bool playMode{true};
  std::random_device rd;
  std::seed_seq seq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  std::mt19937 mt{ seq };
  std::uniform_int_distribution<int> die{MIN_NUMBER, MAX_NUMBER};
  while(playMode)
  {
    int choosenNumber{die(mt)};

    for(int i{1}; i <= MAX_NUMBER_OF_GUESSES; ++i)
    {
      if(checkGuess(i,choosenNumber))
      {
        std::cout << "Good guess, You won!\n";
        break;
      }
      else if(i == MAX_NUMBER_OF_GUESSES)
        std::cout << "Sorry, you lose. The correct number was " << choosenNumber << '\n';
    }
    playMode = playAgain();
  }
  std::cout << "Thank you for playing.\n";
  return 0;
}


//funtions

bool checkGuess(int tryNumber, int choosenNumber)
{
  std::cout << "Guess #" << tryNumber << ":";
  int guessedNumber{};
  std::cin >> guessedNumber;

  while(!validInput()) //the used will be asked to enter a valid input (until he does)
    std::cin >> guessedNumber;

  std::cout << "number you guessed: " << guessedNumber << '\n';
  if(guessedNumber == choosenNumber)
    return true;
  else if(guessedNumber < choosenNumber)
  {
    std::cout << "Your guess is too low\n";
  }
  else
    std::cout << "Your guess is too high\n";
  return false;
}

bool playAgain()
{
    while(true)
    {  
      std::cout << "Would you like to play again (y/n)? ";
      char ans{};
      std::cin >> ans;
      if(ans == 'y')
        return true;
      if(ans == 'n')
        return false;
      handleExtraText(); // any other input from y\n will be deleted and the user will be asked to answer again
    }
}

//validation funtions

void handleExtraText()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validInput()
{
  if(!std::cin) //equal to if(std::cin.fail())
  {
    std::cin.clear(); // gets back to 'normal' mode from 'failure' mode
    handleExtraText(); // removes the previous invalid input
    std::cerr << "Invalid input. Please try again\n";
    return false;
  }
  handleExtraText(); // removes any extraneous text
  return true;
}


