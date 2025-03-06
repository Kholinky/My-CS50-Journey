#include <stdio.h>
#include <cs50.h>
#include <math.h>
//4003600000000014
int check_sum(long card_num);
int mul_digit(int last_digit);
int num_card_digit(long card_num);
int amex(long card_num, int num_card_digit);
int master(long card_num, int num_card_digit);
int visa(long card_num, int num_card_digit);

int main(void)
{
//prompt user to input a credit card number
    long card_num;
do
{
    card_num = get_long("Enter card number: ");
}
    while (card_num < 0);
    int sum = check_sum(card_num);
    int digit = num_card_digit(card_num);
    bool amex1 = amex(card_num, digit);
    bool master1 = master(card_num, digit);
    bool visa1 = visa(card_num, digit);
    if (sum % 10 != 0)
    {
        printf ("INVALID CARD\n");
        return 0;
    }
    else if (amex1 == true)
    {
        printf ("AMEX\n");
    }
    else if (master1 == true)
    {
        printf ("MASTERCARD\n");
    }
    else if (visa1 == true)
    {
        printf ("VISA\n");
    }
    else
    {
        printf ("INVALID CARD\n");
        return 0;
    }
}



//calculate checksum to get the sum of digit
int check_sum(long card_num)
{
    int check = 0;
    bool track = false;
while (card_num > 0)
   {
    if (track == true)
    {
    int last_digit = card_num % 10;
    int product = mul_digit(last_digit);
    check = check + product;
    }
    else
    {
    int last_digit = card_num % 10;
    check = check + last_digit;
    }
    track = !track;
    card_num = card_num / 10;
   }
    return check;
}


//multiply the alt digit by 2
int mul_digit(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_mul = multiply % 10;
        sum = sum + last_digit_mul;
        multiply = multiply / 10;
    }
    return sum;
}


//check for card lenth and starting numbers
int num_card_digit(long card_num)
{
    int count = 0;
    while (card_num > 0)
    {
        count = count + 1;
        card_num = card_num / 10;
    }
    return count;
}

//check amex
int amex(long card_num, int num_card_digit)
{
    int first_two_digits = card_num / pow(10, 13);
    if ((num_card_digit ==15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check master
int master(long card_num, int num_card_digit)
{
    int first_two_digits = card_num / pow(10, 14);
    if ((num_card_digit ==16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check visa
int visa(long card_num, int num_card_digit)
{
    if (num_card_digit == 13)
    {
        int first_one_digits = card_num / pow(10, 12);
        if (first_one_digits == 4)
        {
            return true;
        }
    }
    else if (num_card_digit == 16)
    {
        int first_one_digits = card_num / pow(10, 15);
        if (first_one_digits == 4)
        {
            return true;
        }
    }
    return false;
}
