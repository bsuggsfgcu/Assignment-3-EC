// Programmers: Paul Cimarusti, Raven Suggs, Cesar Fandino
// Date: 29 October 2024
// Sources:
// Log: Oct 29 2024: files created, Level One complete, comments added, Level Two complete, comments added

#include <iostream>
#include <cmath>
std::string LevelOne(int input);
std::string LevelTwo(int input);
std::string LevelThree(double input);


void ComplexityLevelOne()
{
    std::cout << "Complexity Level One" << std::endl;
    int input1;
    bool L1InputInvalid = true; // Input validation variable
    while (L1InputInvalid)
    {
        // Input validation
        std::cout << "Enter a number:\n";
        std::cin >> input1;
        if (input1 < 255 && input1 > 0)
           L1InputInvalid = false;
        else
            std::cout << "Only numbers between 0 and 255 are allowed!\nPlease try again... \n";
    }
    std::cout << input1 << " is " << LevelOne(input1) << " in binary!'\n";
}

void ComplexityLevelTwo()
{
    std::cout << "Complexity Level Two" << std::endl;
    int input2;
    bool L2InputInvalid = true; // Input validation variable
    while (L2InputInvalid)
    {
        // Input validation
        std::cout << "Enter a number between -127 and 128:\n";
        std::cin >> input2;
        if (input2 < 128 && input2 > -127)
            L2InputInvalid = false;
        else
            std::cout << "Only numbers between -127 and 128 are allowed!\nPlease try again... \n";
    }
    std::cout << input2 << " is " << LevelTwo(input2) << " in binary!";

}

void ComplexityLevelThree()
{
    std::cout << "Complexity Level Three" << std::endl;
}

int main() {

//

  
  std::cout << "Choose a complexity level for the program (1, 2 , 3):" << std::endl;
    int complexity;
    std::cin >> complexity;
    if(complexity == 1)
    {
        ComplexityLevelOne();
    }
    else if(complexity == 2)
    {
        ComplexityLevelTwo();
    }
    else if(complexity == 3)
    {
        ComplexityLevelThree();
    }
    else
    {
       std::cout << "Invalid input, ending program." << std::endl;
    }
    return 0;
}

std::string LevelOne(int input)
{
    // Declares returnable string
    std::string binaryInput;

    // Writes binary representation of input (left to right)
    for (int digit = 7; digit >= 0; digit--)
    {
        if (input >= pow(2, digit))
        {
            input -= static_cast<int>(pow(2, digit)); // The input is now what is left to convert to binary
            binaryInput += '1';
        }
        else
            binaryInput += '0';
    }

    return binaryInput;
}

std::string LevelTwo(int input)
{
    // Declares returnable string
    std::string binaryInput;

    // Adds signed digit
    if (input < 0)
    {
        binaryInput += '1';
        input = -1 * input; // Makes sure the rest of the number is written in normal binary (the negative was already accounted for)
    }


    // Writes remaining binary representation
    for (int digit = 6; digit >= 0; digit--)
    {
        if (input >= pow(2, digit))
        {
            input -= static_cast<int>(pow(2, digit));
            binaryInput += '1';
        }
        else
            binaryInput += '0';
    }

    return binaryInput;
}

std::string LevelThree(double input)
{
    std::string inputStr = std::to_string(input);

    int intInput = static_cast<int>(std::stof(inputStr));
    std::string intInputAfterDecimalStr;

    bool afterDecimal = false;
    for (char eachChar : inputStr)
    {
        if (eachChar == '.')
            afterDecimal = true;

        if (afterDecimal)
            if (eachChar != '.')
                intInputAfterDecimalStr += eachChar;
    }

    // Declares returnable string
    std::string binaryInput;


    std::cout << intInputAfterDecimalStr;
}