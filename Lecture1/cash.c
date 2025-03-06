#include <stdio.h>
#include <cs50.h>

int calc_quarters(int cents);
int calc_dimes(int cents);
int calc_nickels(int cents);
int calc_pennies(int cents);
int calc_coins(int cents);

int main(void)
{
//Prompt user to enter the change
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

//calculate how many coins you should give customer
    int coins = calc_coins(cents);
    printf ("%i coins\n", coins);
}


//calculate how many quarters you should give customers
int calc_quarters(int cents)
{
    int coin = 0;
    coin = cents / 25;
    return coin;
}

//Calculate how many dimes you should give customer
int calc_dimes(int cents)
{
    int coin = 0;
    coin = cents / 10;
    return coin;
}
//Calculate how many nickels you should give customer
int calc_nickels(int cents)
{
    int coin = 0;
    coin = cents / 5;
    return coin;
}
//Calculate how many pennies you should give customer
int calc_pennies(int cents)
{
    int coin = 0;
    coin = cents / 1;
    return coin;
}
//Sum the number of quarters, dimes, nickels, and pennies used

int calc_coins(int cents)
{
    //calculate remainer cents after quarters
    int quarters = calc_quarters(cents);
    cents = cents - (quarters * 25);
    //calculate remainer cents after dimes
    int dimes = calc_dimes(cents);
    cents = cents - (dimes * 10);
    //calculate remainer cents after nickels
    int nickels = calc_nickels(cents);
    cents = cents - (nickels * 5);
    //calculate remainer cents after pennies
    int pennies = calc_pennies (cents);
    //calculate total number of coins
    int coins = quarters + dimes + nickels + pennies;
    return coins;
}
