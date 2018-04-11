#include <stdio.h>

void foodBill();
void oceanLevels();
void stockTransaction();


int main(){

	foodBill();
	oceanLevels();
	stockTransaction();

	return 0;
}

void foodBill(){

	float mealCost = 88.67f, taxAmount, tipAmount,total;

	taxAmount = mealCost * .0675;
	total = mealCost + taxAmount;
	tipAmount = (total) * .2;
	total += tipAmount;

	printf("Restaurant Bill \n");
	printf("Meal Cost: $%.2f\n", mealCost);
	printf("Tax Amount: $%.2f\n", taxAmount);
	printf("Tip Amount: $%.2f\n", tipAmount);
	printf("Total Bill: $%.2f\n", total);
	printf("=====================\n");

}

void oceanLevels(){

	float oceanRise = 1.5f;

	float oceanFive, oceanSeven, oceanTen;
	oceanFive = 5 * oceanRise;
	oceanSeven = 7 * oceanRise;
	oceanTen = 10 * oceanRise;

	printf("Future Ocean Levels \n");
	printf("The ocean level is rising at a rate of %.2f millimeters per year.\n", oceanRise);
	printf("The ocean's level will be %.2f millimeters higher in 5 years.\n", oceanFive);
	printf("The ocean's level will be %.2f millimeters higher in 7 years.\n", oceanSeven);
	printf("The ocean's level will be %.2f millimeters higher in 10 years.\n", oceanTen);
	printf("=====================\n");

}

void stockTransaction(){
	//Stock Transaction
	int stockNum = 1000;
	float bought = stockNum * 45.50;
	float sold = stockNum * 56.60;
	float commission1 = bought *.02;
	float commission2 = sold *.02;
	float loss = commission1 + commission2 + bought;
	float total = sold - loss;

	printf("Joe's Stock Transaction\n");
	printf("Joe bought %i shares for $%.2f", stockNum, bought);

}

