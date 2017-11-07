/*
 * Author: <name>
 * Date:
 * ECE-131 Programming Fundamentals
 * Project 2
 *
 */ 
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>       //getopt()

/* Function Prototypes */
void print_prime_numbers(int start, int end, char delim);
bool co_primes(int num1,int num2);
float cuboid_volume(float length, float breadth, float height);
void print_design();
int power(int n, int d);
void display_options();
void interactive();
void run_tests();

/**
 * Main function - DO NOT MODIFY
 */
int main(int argc, char **argv)
{
		char opt;

		while((opt = getopt(argc,argv,"t")) != -1){
			switch(opt) {
				case 't':
					/* Automated testing */
					run_tests();
					goto done;
				default:
					break;
			}
		}
		interactive();
done:
		return 0;
}

/**
 * Implement Me!
 * Calculates the volume of a cuboid given length, breadth, and height
 * You should return 0 if any of the inputs are negative
 */
float cuboid_volume(float length, float breadth, float height){
	float volume;
	if(height < 0 || breadth < 0 || length < 0){

        	//printf("No negative values please!\n"); /* If statement to make sure no negatives entered */
       		 return 0.0;
        }
	else
	{
       		 volume= height * breadth * length; /* Algorithm to find volume or output */
	}
	return volume;
}

/**
 * Implement Me!
 * Prints all prime numbers between start and end (excluding start and end)
 * delim is the character to put after every prime number - for example:
 * if delim = ',' the output look like: 3,5,7,11 with a ',' in between each
 * if delim = '\n' the output looks like:
	3
	5
	6
	11
 */
bool checkprime(int p); //function prototype to use to determine if prime
void print_prime_numbers(int start, int end, char delim){
	/* Implement me */
	int n;
	for(n = start + 1; n < end; n++){
                if(checkprime(n) && n!=1){		//algorithm to determine all values
                        printf("%d%c",n,delim);		// to test. prints prime numbers
                }}
        }


bool checkprime(int p){
	int i;
        for(i=2; i <= p/2; i++){
                if (p%i == 0){				//function to determine if prime
                        return false;
                }
        }
        return true;		//will return true or false
}

/**
 * Implement Me!
 * Detemines whether num1(>=0), num2(>=0) are co-primes or not
 * if yes return true, otherwise return false
*/
bool co_primes(int num1,int num2){
	int min;
	int i;

	if(num1<num2){
		min = num1;
	}			//sets smaller number as min
	else{
		min = num2;
	}

	for(i=1; i <= min; i++){
		if(num1%i == 0 && num2%i == 0){
			if(i>1)			//algorithm give to check if coprime
				return false;	//returns false if not and true other wise
		}
	}
	return true;
}


/**
 * Implement Me!
 * Prints a pretty number triangle
 * when rows is 7 you should print:
1
1 2
1 2 3
1 2 3 4
1 2 3
1 2
1
 * when rows is 4 you should print:
1
1 2
1 2
1
 */
void print_design(int N){
	/* code here to print the design but depending on the number of rows */
        int rows;
        int col; /* Variables  */

        for(rows = 1; rows <= N; rows++){

                if(rows <= (((N+1)/2))){

                        for(col=1; col <= rows; col++){	//algorithm for top half of trianle
							//N is total rows, rows is horizontal row
							//Col is number printed
                                printf("%d ",col);
                        }
                }


                else{
                        for(col = 1; col <= N - rows + 1; col++){
							//algorithm for bottom half
							//counts down
                                printf("%d ",col);
                	}
                }
        printf("\n");
        }
        return 0;



}

/**
 * Implement Me!
 * Computes n to the power of d
 */
int power(int base, int exponent)
{
	/* Implement me */
	int value;
	int i;
	value = 1;
	for(i=exponent; i > 0; i--){

                value = value*base;     /*While loop algorithm to calculate power */
                                        /*Starts at exponent and counts down till 1 */
                                        /*Then calculates the first value and continues*/
        }
	//printf("%d to the power of %d is %d.\n",base,exponent,value); /* Output */
	return value;
}

/**
 * Shows input options for interactive mode
 * No changes should be necessary here
 */
void display_options(){

	printf("Please choose one of the tasks\n");
	printf("1. Print the prime numbers from start to end\n");
	printf("2. Checks if the values are co-primes\n");
	printf("3. Volume of a cuboid\n");
	printf("4. print the design with a given number of rows\n");
	printf("5. Calculates n to the power of d\n");
	printf("6. Quit the program\n");
}

/**
 * Implement Me!
 * Main handler for interactive mode
 */
void interactive()
{
	/*
	 * Give user the options of selecting one of the tasks to perform(print_design,cuboid volume,co_primes,print_primenumbers, quit the program).
	 * After selecting an option, take the required function arguments from the user and perform that task. Continue giving the selection option for the user untill user enters quit option
	 * You have to use switch statement to call the respective functions
	 */
	int num1;
	int num2;
	float height;
	float breadth;
	float length;
	int N;		//all variables needed for inputs and functions
	int base;
	int exponent;
	int start;
	int end;
	char delim;
	int opt;
	printf("Starting interactive mode!\n");
	while(true){//infinite loop
		display_options();
		scanf("%d",&opt); //takes input for option of function
		switch(opt){
			case 1 :
				printf("What is the start of the range and the end and");
       			 	printf("the character you want between each number? ");
        			scanf("%d %d%c", &start, &end, &delim);
				scanf("%c",&delim);			//takes input
				print_prime_numbers(start,end,delim); //runs function
				break;//breaks out of case
			case 2 :
				printf("Please enter the two numbers you wish to check if co-primes ");
				scanf("%d %d",&num1,&num2);	//input
				if(co_primes(num1, num2))
					printf("True\n");
				else 				//check function for true or false
					printf("False\n");
				break;//breaks out of case
			case 3 :
				printf("Please list the length, breadth, and height of your cuboid: ");
				scanf("%f %f %f",&height,&breadth,&length); //input
				cuboid_volume(length, breadth, height); //runs function
				printf("The volume of your cuboid is %f\n",cuboid_volume(length,breadth,height));//prints output
				break;//breaks out of case
			case 4 :
				printf("Please enter how many rows you would like the triangle to display: ");
				scanf("%d",&N);//takes input
				print_design(N);//runs function
				break;//breaks out of case
			case 5 :
				printf("Enter Base:\n");
       				scanf("%d",&base);
                                /* Input of Function */
       				printf("Enter Exponent:\n");
       				scanf("%d",&exponent);
				power(base,exponent);// runs function
				printf("The value is %d\n",power(base,exponent));//prints output
				break;//breaks out of case



}
	if(opt == 6){
		printf("Closing Program\n");//if option 6 this closes out loop and stop program
		break;
	}
}
}
/**
 * For automated testing - DO NOT MODIFY
 */
void run_tests()
{
	printf("Test0:Primes:0,13: :"); print_prime_numbers(0, 13, ' '); printf("\n");
	printf("Test1:Primes:10,55:,:"); print_prime_numbers(10, 55, ','); printf("\n");
	printf("Test2:Primes:2,100:-:"); print_prime_numbers(2, 100, '-');	printf("\n");

	printf("Test3:CoPrimes:10,20:%s\n", co_primes(10, 20) ? "true":"false");
	printf("Test4:CoPrimes:5,11:%s\n", co_primes(5, 11) ? "true":"false");
	printf("Test5:CoPrimes:12,35:%s\n", co_primes(12, 35) ? "true":"false");

	printf("Test6:Cuboid:3,4,5:%f\n", cuboid_volume(3, 4, 5));
	printf("Test7:Cuboid:10.4,14.2,15.6:%f\n", cuboid_volume(10.4, 14.2, 15.6));
	printf("Test8:Cuboid:0,1,2:%f\n", cuboid_volume(0, 1, 2));
	printf("Test9:Cuboid:-1,1,2:%f\n", cuboid_volume(-1, 1, 2));

	printf("Test10:Design:7\n"); print_design(7);
	printf("Test11:Design:4\n"); print_design(4);
	printf("Test12:Design:1\n"); print_design(1);

	printf("Test13:Power:2,8:%d\n", power(2,8));
	printf("Test14:Power:3,4:%d\n", power(3,4));
	printf("Test15:Power:4,2:%d\n", power(4,2));
}
