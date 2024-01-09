// Copyright (c) 2023 Remy Skelton All rights reserved.
//
// Created by: Remy Skelton
// Date: Jan 4, 2023
// This program will calculate the average of
// nums with user input

#include <iostream>
#include <list>
#include <sstream>
#include <string>

// Function to calculate the remainder of a list of integers
std::list<int> calculateRemainder(std::list<int> listOfInt, int divisor) {
    std::list<int> remainderList;

    // Calculate remainder
    for (int element : listOfInt) {
        int remainderCalc = element % divisor;
        remainderList.push_back(remainderCalc);
    }

    return remainderList;
}

// Function to remove duplicates and find remainder
std::list<int> duplicateRemover(std::list<int> listOfInt, int divisor) {
    std::list<int> uniqueElements;

    for (int element : listOfInt) {
        bool isUnique = true;
        for (int uniqueElement : uniqueElements) {
            if (element == uniqueElement) {
                isUnique = false;
                break;
            }
        }

        if (isUnique == true) {
            uniqueElements.push_back(element);
        }
    }
    std::list<int> remainderList = calculateRemainder(uniqueElements, divisor);
    return remainderList;
}

int main() {
    std::string userDecision;

    do {
        std::list<int> listOfInt;
        std::string listOfStrs;
        std::string divisorStr;
        int divisorInt;
        std::list<int> remainderList;

        std::cout << "This program will remove any duplicates in a list of integers\n";
        std::cout << "then it will find the remainder of the list with\n";
        std::cout << "the divisor from the user.\n";
        std::cout << "Please enter the number you want the list to be divided by: ";
        std::cin >> divisorStr;

        while (true) {
            std::cout << "Please enter an element of the list (if list is done, enter a decimal or str): ";
            std::cin >> listOfStrs;

            try {
                // Convert and add to the list
                listOfInt.push_back(std::stoi(listOfStrs));

            } catch (std::exception) {
                // Error for string
                std::cout << listOfStrs << " is not valid.\n";
                break;
            }
        }

        try {
            divisorInt = std::stoi(divisorStr);

            if (listOfInt.size() == 0) {
                std::cout << "Please enter integers.\n";
            } else if (divisorInt == 0) {
                std::cout << "You can't divide by 0.\n";
            } else {
                remainderList = duplicateRemover(listOfInt, divisorInt);

                std::cout << "The remainder of the list without duplicates is ";
                for (int num : remainderList) {
                    std::cout << num << " ";
                }
                std::cout << "\n";
            }

            // See if the user wants to try again
            std::cout << "Would you like to continue (y/n): ";
            std::cin >> userDecision;
            std::cout << "\n";

        } catch (std::exception) {
            std::cout << divisorStr << " is not valid.\n";
        }
    } while (userDecision != "n" || userDecision != "N");
}
