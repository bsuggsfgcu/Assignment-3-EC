// Programmers: Paul Cimarusti, Raven Suggs, Cesar Fandino
// Date: 29 October 2024
// Sources: None used
// Log: Oct 29 2024: files created, Level One complete, comments added, Level Two complete, comments added, Level Three complete, comments added, and final input validation added

#include <iostream>
#include <cmath>
#include <algorithm>


/////////////////////////////

std::string LevelOne(int input);
std::string LevelTwo(int input);
std::string LevelThree(double input);
bool IsInt(const std::string& input);
bool IsNumber(const std::string& input);

bool IsInt(const std::string& input)
{
    return std::ranges::all_of(input, [](char eachChar) { return (isdigit((eachChar)) || eachChar == '-');});
}

bool IsNumber(const std::string& input)
{
    int decimals = 0;
    for (char eachChar : input)
    {
        if (!isdigit(eachChar))
        {
            if (eachChar == '.')
                decimals++;
            else
                return false;
        }
    }
    if (decimals <= 1)
        return true;
    return false;
}


//Complexity Level One Code
void LevelOneInput()
{
    std::cout << "Complexity Level One" << std::endl;
    int input1;
    bool L1InputInvalid = true; // Input validation variable
    while (L1InputInvalid)
    {
        // Input validation
        std::cout << "Enter a number:\n";
        std::cin >> input1;
        if (input1 <= 255 && input1 >= 0 && IsInt(std::to_string(input1)))
            L1InputInvalid = false;
        else
            std::cout << "Only integers between 0 and 255 are allowed!\nPlease try again... \n";
    }
    std::cout << input1 << " is " << LevelOne(input1) << " in binary!\n";
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

/////////////////////////////

//Complexity Level Two Code
void LevelTwoInput()
{
    std::cout << "Complexity Level Two" << std::endl;
    int input2;
    bool L2InputInvalid = true; // Input validation variable
    while (L2InputInvalid)
    {
        // Input validation
        std::cout << "Enter a number between -127 and 128:\n";
        std::cin >> input2;
        if (input2 <= 128 && input2 >= -127 && IsNumber(std::to_string(input2)))
            L2InputInvalid = false;
        else
            std::cout << "Only numbers between -127 and 128 are allowed!\nPlease try again... \n";
    }
    std::cout << input2 << " is " << LevelTwo(input2) << " in binary!";

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

/////////////////////////////

//Complexity Level Three Code
void LevelThreeInput()
{
    std::cout << "Complexity Level Three" << std::endl;
    double input3;
    bool L3InputInvalid = true; // Input validation variable
    while (L3InputInvalid)
    {
        // Input Validation
        std::cout << "Enter a number:\n";
        std::cin >> input3;
        if (input3 <= 128 && input3 >= 0 && IsNumber(std::to_string(input3)))
            L3InputInvalid = false;
        else
            std::cout << "Only numbers between 0 and 128 are allowed!\nPlease try again... \n";
    }
    std::cout << input3 << " is " << LevelThree(input3) << " in binary!";
}

std::string LevelThree(double input)
{
    // Declares returnable string
    std::string binaryInput;

    std::string inputStr = std::to_string(input);
    std::string afterDecimalStr = "0.";

    // Finds integer after decimal (this has more precision than (static_cast<int>(number) - number)
    bool afterDecimal = false;
    for (char eachChar : inputStr)
    {
        if (eachChar == '.')
            afterDecimal = true;

        if (afterDecimal)
            if (eachChar != '.')
                afterDecimalStr += eachChar;
    }

    int intInput = static_cast<int>(std::stof(inputStr));
    double doubleInput = std::stof(afterDecimalStr);
    binaryInput += LevelOne(intInput);
    binaryInput += '.';

    for (int digit = 1; digit <=4; digit++)
    {
        if (doubleInput >= pow(2, -digit))
        {
            doubleInput -= pow(2, -digit);
            binaryInput += '1';
        }
        else
            binaryInput += '0';
    }
    return binaryInput;
}

/////////////////////////////

int main() {
    std::cout << "Choose a complexity level for the program (1, 2 , 3):" << std::endl;
    int complexity;
    std::cin >> complexity;
    if(complexity == 1)
    {
        LevelOneInput();
    }
    else if(complexity == 2)
    {
        LevelTwoInput();
    }
    else if(complexity == 3)
    {
        LevelThreeInput();
    }
    else
    {
       std::cout << "Invalid input, ending program." << std::endl;
    }
    return 0;
}