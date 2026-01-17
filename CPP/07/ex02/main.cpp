/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:10:12 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/12 15:39:03 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];

		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
    {
        Array<int> arr;
        std::cout << "Test 1: Default constructor (empty array), size: " << arr.size() << std::endl;
    }

    // Test case: Creation of Array with size n (default-initialized elements)
    {
        Array<int> arr(5);
        std::cout << "Test 2: Array with 5 elements, size: " << arr.size() << std::endl;

        // Accessing valid elements
        for (unsigned int i = 0; i < arr.size(); ++i) {
            arr[i] = i + 1;
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }
    }

    // Test case: Checking bounds and exception for invalid index
    {
        
            Array<int> arr(5);
            std::cout << "Test 3: Attempting to access out-of-bounds index..." << std::endl;
            
		try { arr[10] = 100;  // Should throw an exception
        } catch (std::exception& e) {
            std::cout << "Caught exception for out-of-bounds access: " << e.what() << std::endl;
        }
    }

    // Test case: Copy constructor (deep copy check)
    {
        Array<int> arr(3);
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        
        Array<int> arrCopy(arr);
        std::cout << "Test 4: Copy constructor" << std::endl;
        
        std::cout << "arrCopy[0] = " << arrCopy[0] << std::endl;
        std::cout << "arrCopy[1] = " << arrCopy[1] << std::endl;
        std::cout << "arrCopy[2] = " << arrCopy[2] << std::endl;
    }

    // Test case: Assignment operator (deep copy check)
    {
        Array<int> arr(3);
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        
        Array<int> arrAssigned;
        arrAssigned = arr;
        std::cout << "Test 5: Assignment operator" << std::endl;
        
        std::cout << "arrAssigned[0] = " << arrAssigned[0] << std::endl;
        std::cout << "arrAssigned[1] = " << arrAssigned[1] << std::endl;
        std::cout << "arrAssigned[2] = " << arrAssigned[2] << std::endl;
    }
    // Test case: Leaks (check for deletion of previous array before new assignment)
    {
        Array<int> arr1(3);
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;

        Array<int> arr2(3);
        arr2[0] = 100;
        arr2[1] = 200;
        arr2[2] = 300;
        
        Array<int> arrAssigned;
        arrAssigned = arr1;
        std::cout << "Test 6: test for leaks" << std::endl;
        
        std::cout << "arrAssigned[0] = " << arrAssigned[0] << std::endl;
        std::cout << "arrAssigned[1] = " << arrAssigned[1] << std::endl;
        std::cout << "arrAssigned[2] = " << arrAssigned[2] << std::endl;

		arrAssigned = arr2;
        
        std::cout << "arrAssigned[0] = " << arrAssigned[0] << std::endl;
        std::cout << "arrAssigned[1] = " << arrAssigned[1] << std::endl;
        std::cout << "arrAssigned[2] = " << arrAssigned[2] << std::endl;
    }
	return 0;
}
