#include <iostream>

void ComplexityLevelOne()
{
    std::cout << "Complexity Level One" << std::endl;
}

void ComplexityLevelTwo()
{
    std::cout << "Complexity Level Two" << std::endl;
}

void ComplexityLevelThree()
{
    std::cout << "Complexity Level Three" << std::endl;
}

int main()
{
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
