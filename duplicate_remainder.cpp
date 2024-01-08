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
std::list<int> calculateRemainder(const std::list<int>& lst, int divisor) {
    // List of remainder
    std::list<int> remainderList;

    // Calculate remainder
    for (int element : lst) {
        int remainderCalc = element % divisor;
        remainderList.push_back(remainderCalc);
    }

    return remainderList;
}

// Function to remove duplicates and find remainder
std::list<int> duplicateRemover(const std::list<int>& lst, int divisor) {
    std::list<int> uniqueElements;

    for (int element : lst) {
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
    while (true) {
        // Create list and declare other variables
        std::list<int> listOfInt;
        std::string listOfStrs;
        std::string divisorStr;
        int divisorInt;

        // Get list and divisor and display message
        std::cout <<
        "This program will remove any duplicates in a list of integers\n";
        std::cout <<
        "then it will find the remainder of the list with\n";
        std::cout << "the divisor from the user.\n";
        std::cout <<
        "Please enter the number you want the list to be divided by: ";
        std::cin >> divisorStr;

        std::cout << "Please enter your list of ints (separated by spaces): ";
        std::getline(std::cin >> std::ws, listOfStrs);

        std::istringstream iss(listOfStrs);
        int listElement;

        try {
            while (iss >> listElement) {
                listOfInt.push_back(listElement);
            }

            divisorInt = std::stoi(divisorStr);

            // Check if the list has something in it
            if (listOfInt.empty()) {
                std::cout << "Please enter integers.\n";
            } else if (divisorInt == 0) {
                // Check if the divisor is 0
                std::cout << "You can't divide by 0.\n";
            } else {
                // Call duplicate remover function
                std::list<int> remainderList =
                duplicateRemover(listOfInt, divisorInt);

                // Display the new list
                std::cout << "The remainder of the list without duplicates is ";
                for (int num : remainderList) {
                    std::cout << num << " ";
                }
                std::cout << "\n";
            }

            // See if the user wants to try again
            std::string userDecision;
            std::cout << "Would you like to continue (y/n): ";
            std::cin >> userDecision;
            std::cout << "\n";

            if (userDecision == "n" || userDecision == "N") {
                break;
            }
        } catch (std::exception) {
            std::cout << divisorStr << " and "
            << listOfStrs << " are not valid.\n";
        }
    }
}
