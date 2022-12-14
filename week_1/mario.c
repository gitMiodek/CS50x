#include <cs50.h>
#include <stdio.h>
// Write a code which will ask user for a height and then prints out a tower which looks like an example:
// height: 5
//     #  #
//    ##  ##
//   ###  ###
//  ####  ####
// #####  #####
int main(void)
{
    int height;
    do
    {
        height = get_int("Whats the tower height?: \n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        
        for (int k = 0; k < (2 * height) + 2; k++)
        {
            if (k == height || k == height + 1)
            {
                printf(" ");
            }
            else if (k < height)
            {
                if (k >= height - i - 1)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {

                
                if (k > height  && k <= (height + 2 + i))
                {
                    printf("#");
                }

            }
        }
        printf("\n");
    }


}
