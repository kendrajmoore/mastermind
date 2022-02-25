// Mastermind is a game composed of 8 pieces of different colors.
// A secret code is then composed of 4 distinct pieces.
// The player has 10 attempts to find the secret code.
// After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.
// Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
// If the player finds the code, he wins, and the game stops.
// A misplaced piece is a piece that is present in the secret code butthat is not in a good position.
// You must read the player's input from the standard input.
// Your program will also receive the following parameters:
// -c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
// -t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUMS 4
#define ATTEMPTS 10
#define MAX 7
#define SIZE 128
int codeArr[NUMS];
int numArr[NUMS];
int attempts;


int getCode(char* inputNum)
{
    int i;
    char buffer [SIZE];
    buffer[1] = '\0';
    for(i=0; i < NUMS; i++)
    {
        if(inputNum[i] < '0' || inputNum[i] > ('0' + MAX))
        {
            printf("This number is invalid\n");
            printf("%c\n", inputNum[i]);
            printf("Please restart again\n");
            return 0;
        } 
        //need to read num from command line to buffer and save in array
        buffer[0] = inputNum[i];
        //int num = atoi(buffer);
        codeArr[i] = atoi(buffer);
    }
    return 1;

}

//make random code
void createCode()
{
    int i;

    srand(time(NULL));
    for(i = 0; i < NUMS; i++)
    {
        codeArr[i] = rand() % (MAX+1);
    }
    
}


//get user guess
int userInput()
{
    int i;
    char buffer [SIZE];
    char singleDigit [2];
    singleDigit[1] = '\0';

    read(STDIN_FILENO, buffer, SIZE);
    for (i=0; i < NUMS; i++)
    {
        //printf("Enter a single digit at the same time: \n");
        //read(STDIN_FILENO, buffer, SIZE);
        if(buffer[i] < '0' || buffer[i] > ('0' + MAX))
        {
            printf("This number is invalid\n");
            printf("%c\n", buffer[i]);
            printf("Please restart again\n");
            return 0;
        } 
        //need to read num from command line to buffer and save in array
        singleDigit[0] = buffer[i];
        numArr[i] = atoi(singleDigit);
    }
    return 1;
}

//check to see if this is the correct number
int compare()
{
    int right = 0;
    int misplaced = 0;
    int i, k;
    for(i = 0; i < NUMS; i++)
    {
        if(codeArr[i] == numArr[i])
        {
            right += 1;
        } 
        else 
        {
            for(k=0; k<NUMS; k++)
            {
                if(codeArr[i] == numArr[k])
                {
                    misplaced ++;
                    break;
                } 
            }
        }
    }

   
    if(right == NUMS)
    {
        printf("You won\n");
        return 1;
     
    } 
    else 
    {
        printf("Numbers you guessed correctly\n");
        printf("%d\n", right);
        printf("Numbers you misplaced\n");
        printf("%d\n", misplaced);
        return 0;
    }
  

}

int startGame(int userAttempts)
{
    //int selection;
    attempts = userAttempts;
    printf("Will you find my secret code?\n");
    printf("Enter four (4) numbers!!!\n");
    while(attempts > 0)
    {

        while( !userInput() );
        int compareResult = compare();
        if(compareResult == 1)
        {
            return 1;
        } 
        else 
        {
            attempts -= 1;
            printf("You have this many attempts left\n");
            printf("%d\n", attempts);
            printf("-----------------\n");
        }
        
    }
    printf("You lost\n");
    return 0;
    
}


int main(int argc, char* argv[]) 
{
    int i;
    attempts = ATTEMPTS;

    if(argc != 1 && argc != 3 && argc != 5)
    {
        printf("You entered your arguments incorrectly\n");
        return 1;
    }

    createCode();
        
 

    for(i=1; i < argc; i++)
    {
        
        if(argv[i][0] == '-' && argv[i][1] == 'c')
        {
           
            if(i != argc - 1)
            {
                if(getCode(argv[i+1]) == 0)
                {
                    return 1;
                } 
            }
            else
            {
                printf("Your input is invalid\n");
                return 1;
            }
        } 
        if(argv[i][0] == '-' && argv[i][1] == 't')
        {
            attempts = atoi(argv[i+1]);
            if(attempts == 0)
            {
                printf("Entered invalid attempts\n");
                return 1;
            }
        } 
        if(argv[i][0] == '-' && argv[i][1] != 't')
        {
                printf("Entered incorrect argument\n");
                return 1;
        } 
    }
    startGame(attempts);

    return 0;
    
}