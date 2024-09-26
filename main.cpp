#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

/// @brief populates [fibbSequence] with [n] elements of the fibbonacci sequence. called recursively.
/// @param a the element before the current element in the fibbonacci sequence. always 1 on root call.
/// @param b most recent element of fibbonacci sequence. aways 1 on root call.
/// @param n the number of fibbonacci sequence elements past the first two to be evaluated.
/// @param fibbSequence reference to vector that will hold the fibbonacci sequence elements.
/// @param print whether to print the fibbonacci sequence to the console as it is calculated.
void Fibbonacci(unsigned long a, unsigned long b, unsigned long n, std::vector<unsigned long> &fibbSequence, bool print)
{
    unsigned long next = a + b;
    fibbSequence[fibbSequence.size() - n] = next;

    if(n<2)
    {
        if(print) std::cout << next << std::endl;
        return;
    }

    if(print) std::cout << next << ", ";
    Fibbonacci(b, next, n-1, fibbSequence, print);
}


int main()
{
    // receive input
    std::cout << "Enter how many elements of the Fibbonacci sequence you would like to see: ";
    std::string input;
    std::vector<unsigned long> fibbSequence;
    unsigned long n = 0;
    
    input = std::string();
    std::cin >> input;
            
    // make sure there's enough memory for what the user input
    try
    {
        n = std::stoul(input, nullptr, 10);

        if(n < 2)
        {
            std::cout << std::endl << "Invalid input. Number must be between 2 and [2^32] - 1. Terminating...";
            return -1;
        }
        if(n == 2) // unecessary at this point
        {
            std::cout << "1, 1" << std::endl;
        }

        fibbSequence = std::vector<unsigned long>(n);
    }
    catch(const std::bad_alloc& e)
    {
        std::cout << std::endl << "System does not have enough memory to allocate a vector of size " << n << ". Try a smaller number. Terminating...";
        return -1;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << std::endl << "Invalid input. Number must be between 2 and [2^32] - 1. Terminating...";
        return -1;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << std::endl << "Invalid input. Input must be an integer between 2 and [2^32] - 1. Terminating...";
        return -1;
    }

    // whitespace
    std::cout << std::endl;
    
    fibbSequence[0] = static_cast <unsigned long> (1);
    fibbSequence[1] = static_cast <unsigned long> (1);

    std::cout << "1, 1, ";

    // perform fibbonacci sequence
    Fibbonacci(1, 1, n-2, fibbSequence, true);
    
    return 0;
}