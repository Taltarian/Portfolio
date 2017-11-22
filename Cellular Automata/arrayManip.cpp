
#include <random>

//Fills array randomly with 1's and 0's
void fillArray(long int length, short array[])
{
    //Generate random seed for PRNG
    std::random_device rd; 
    std::mt19937 rng(rd());

    //Set up distribution so PRNG outputs 0's and 1's
    std::uniform_int_distribution<> distr(0, 1); 

    //iterate through whole array and fill
    for (int iii = 0; iii < length; ++iii)
    {
        array[iii] = distr(rng);
    }
}

//copies original[] into destination[]
void copyArray(short original[], short destination[], long int length)
{
    for (int iii = 0; iii < length; ++iii)
        destination[iii] = original[iii];
}
