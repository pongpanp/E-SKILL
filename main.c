#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int isSuccess = signIn();
	int isExit;
	if (isSuccess) {
		do{
			isExit = mainMenu();
		} while (isExit != 0);
	}
	printf("<< Bye Bye >>");
	return 0;
}

int signIn() {
	int pwMaster = 12345;
	int pwInput;
	int loopCheck = 1;
	
	do {
		printf("Input Password ==> ");
		scanf("%d", &pwInput);
		
		if(pwInput == pwMaster) {
		return 1;
		}
		
		if (loopCheck != 4)  printf("Input password at %d no correct\n", loopCheck); 
	
		printf("...............................\n");
				
		loopCheck++;
	} while (loopCheck <= 4);
	return 0;
}

int mainMenu() {
	int choice;
	
	printf("...............................\n");
	printf("           Main Menu\n");
	printf("...............................\n");
	printf(" 1. +\n 2. -\n 3. x\n 4. div\n 5. mod\n 6. Exit\n");
	printf("...............................\n");
	printf("Select to choice ==> ");
	scanf("%d", &choice);
	printf("...............................\n");
	
	if (choice < 1 || choice > 6) {
		printf("<< Incorrect Please Select Menu 1 - 6 >>\n");
		return 1;
	}
	
	if (choice > 0 && choice != 6) {
		calculator(choice);
		return 1;
	} 
	
	return 0;
}

int calculator(int choice) {
	int inputNumber;
	int number1;
	int number2;
		
	do {
	printf("Input Number 1 [1-10] ==> ");
	scanf("%d/n", &inputNumber);
	} while (inputNumber < 0 || inputNumber > 10);
	
	number1 = inputNumber;
	
	do {
	printf("Input Number 2 [1-10] ==> ");
	scanf("%d/n", &inputNumber);
	} while (inputNumber < 0 || inputNumber > 10);
	
	if (choice != 1 && choice != 3  && inputNumber > number1)  {
		number2 = number1;
		number1 = inputNumber;	
	} else {
		number2 = inputNumber; 
	}
	printf("...............................\n");
	
	switch (choice) {
		case 1: printf("%d + %d = %d \n", number1,  number2 , number1 + number2); break;
		case 2: printf("%d - %d = %d \n", number1,  number2 , number1 - number2); break;
		case 3: printf("%d x %d = %d \n", number1,  number2 , number1 * number2); break;
		case 4: printf("%d div %d = %d \n", number1,  number2 , number1 / number2); break;
		case 5: printf("%d mod %d = %d \n", number1,  number2 , number1 % number2); break;
		default: printf("Not A Menu"); break;
	}
	return 1;
}
