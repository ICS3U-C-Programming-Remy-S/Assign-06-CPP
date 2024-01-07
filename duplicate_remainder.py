#!/usr/bin/env python3
# Created by: Remy Skelton
# Created on: Jan 1st, 2024
# This program will remove any duplicates in a list of integers
# then it will find the remainder of the list with
# the divisor from the user


def duplicate_remover(lst, divisor):
    # list that will be returned
    unique_elements = []
    # find unique elements
    for element in lst:
        if element not in unique_elements:
            unique_elements.append(element)

    remainder = calculate_remainder(divisor, unique_elements)
    return remainder


def calculate_remainder(divisor, lst):
    # list of remainder
    list_of_remainder = []
    # find remainder
    for counter in range(len(lst)):
        remainder_calc = lst[counter] % divisor
        list_of_remainder.append(remainder_calc)
    return list_of_remainder


def main():
    while True:
        # create list
        list_of_int = []

        # get list and divisor and display message
        print("This program will remove any duplicates in a list of integers")
        print("then it will find the remainder of the list with")
        print("the divisor from the user.")
        divisor_str = input(
            "Please enter the number you want the list to be divided by: "
        )
        list_of_strs = input("Please enter your list of ints (separated by a space): ")

        try:
            list_of_int = [
                int(x) for x in list_of_strs.split()
            ]
            divisor_int = int(divisor_str)

            # check if the list has something in it
            if len(list_of_int) == 0:
                print("Please enter integers.\n")

            # check if the divisor is 0
            elif divisor_int == 0:
                print("You can't divide by 0.\n")

            else:
                # call duplicate remover function
                remainder_list = duplicate_remover(list_of_int, divisor_int)

                # display the new list
                print(
                    f"The remainder of the list without duplicates is {remainder_list}\n"
                )

            # see if user wants to try again
            user_decision = input("Would you like to continue (y/n): ")
            print("")

            if user_decision.lower() == "n":
                break

        except Exception:
            print(f"{divisor_str} and {list_of_strs} are not valid.\n")


if __name__ == "__main__":
    main()
