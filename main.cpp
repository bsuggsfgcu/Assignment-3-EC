// Programmers: Paul Cimarusti, Raven Suggs, Cesar Fandino
// Date: 29 October 2024
// Sources:
// Log: Oct 29 2024: files created, Level One complete, comments added, Level Two complete, comments added

#include <iostream>
std::string LevelOne(int input);
std::string LevelTwo(int input);
std::string LevelThree(int input);

int main() {
    int input1;
    bool L1InputInvalid = true; // Input validation variable
    std::cout << "LEVEL ONE\n";
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



    int input2;
    bool L2InputInvalid = true; // Input validation variable
    std::cout << "LEVEL TWO\n";
    while (L2InputInvalid)
    {
        // Input validation
        std::cout << "Enter a number:\n";
        std::cin >> input2;
        if (input1 < 128 && input1 > -127)
            L2InputInvalid = false;
        else
            std::cout << "Only numbers between -127 and 128 are allowed!\nPlease try again... \n";
    }
    std::cout << input2 << " is " << LevelTwo(input2) << " in binary!";

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