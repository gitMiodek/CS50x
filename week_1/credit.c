#include <cs50.h>
#include <stdio.h>
//Write a code which checks wether the number is a valid credit card number and if so, print out the name of the card's company
bool checksum(long number);

int calculate_length(long number);

int check_1st_digit(long number);

int check_2_first_digits(long number);

int main(void)
{
    long number = get_long("Number: ");
    //Check if num is valid
    if (checksum(number))
    {
        //Check for 16 digits cards (Visa (13 or 16), MasterCard (16))
        if (calculate_length(number) == 16 && check_1st_digit(number) == 4)
        {
            printf("VISA\n");
        }
        else if (calculate_length(number) == 13 && check_1st_digit(number) == 4)
        {
            printf("VISA\n");
        }
        else if (calculate_length(number) == 16 && (check_2_first_digits(number) == 51 ||
                check_2_first_digits(number) == 52 ||
                check_2_first_digits(number) == 53 || check_2_first_digits(number) == 54 || check_2_first_digits(number) == 55))
        {
            printf("MASTERCARD\n");

        }
        else if (calculate_length(number) == 15 && (check_2_first_digits(number) == 34 ||
                check_2_first_digits(number) == 37))
        {
            printf("AMEX\n");
        }

        else
        {
            printf("INVALID\n");
        }


    }
    else
    {
        printf("INVALID\n");
    }
    // printf(" %i\n",checksum(number));
    // printf(" %i\n",calculate_length(number));
    // printf(" %i\n",check_2_first_digits(number));
    // printf(" %i\n",check_1st_digit(number));




}

int check_1st_digit(long number)
{

    int tmp, res;
    while (number > 0)
    {
        tmp = number % 10;
        number /= 10;
        if (number < 1)
        {
            res = tmp;
            // printf("%i\n", tmp);
        }
    }
    return res;


}

int check_2_first_digits(long number)
{
    int tmp, res;
    while (number > 1)
    {
        tmp = number % 100;
        number /= 10;
        if (number < 10 && number > 1)
        {
            res = tmp;
            // printf("%i\n", tmp);
        }
    }
    return res;
}


int calculate_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

bool checksum(long number)
{
    int n, tmp, x;
    int sum = 0;
    int count = 0;
    bool res = false;
    while (number > 1)
    {
        n = number % 10;
        if (count % 2 == 1)
        {
            if (n * 2 >= 10)
            {
                // printf("%i\n", n*2);
                tmp = n * 2;
                while (tmp > 0)
                {
                    x = tmp % 10;
                    // printf("%i\n", x);
                    sum += x;
                    tmp /= 10;
                }
            }
            else
            {
                sum += (n * 2);
            }
        }
        else
        {
            sum += n;
        }
        number /= 10;
        count++;
    }
    // printf("Sum: %i\n", sum);
    if (sum % 10 == 0)
    {
        res =  true;
    }
    return res;
}
