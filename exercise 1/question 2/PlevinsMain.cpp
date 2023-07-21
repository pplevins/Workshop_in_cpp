/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 1 Question 2
The program inputs employees and searching the one with the highest salary and the one that brought the lowest income.*/

#include "Employee.h"
#include <iostream>
using namespace std;

int main()
{
	Employee highestSalaryEmplo, minimumCollectedEmplo;
	int idInput;
	char nameInput[21];
	float salaryInput;
	int hoursInput;
	float incomeInput;
	
	cout << "enter details, to end enter 0:\n";
	cin >> idInput >> nameInput >> salaryInput >> hoursInput >> incomeInput; //inputting the first employee
	while (idInput < 1 || salaryInput < 0 || hoursInput < 0 || incomeInput < 0) //integrity check
	{
		cout << "ERROR\n";
		cin >> idInput >> nameInput >> salaryInput >> hoursInput >> incomeInput;
	}
	//putting the inputs to both 2 Employee's.
	highestSalaryEmplo.setId(idInput);
	highestSalaryEmplo.setName(nameInput);
	highestSalaryEmplo.setSalaryPerHour(salaryInput);
	highestSalaryEmplo.setHours(hoursInput);
	highestSalaryEmplo.setOrganizationIncome(incomeInput);
	float totalSalaryHighest = highestSalaryEmplo.salary(); //summing the total salary.

	minimumCollectedEmplo.setId(idInput);
	minimumCollectedEmplo.setName(nameInput);
	minimumCollectedEmplo.setSalaryPerHour(salaryInput);
	minimumCollectedEmplo.setHours(hoursInput);
	minimumCollectedEmplo.setOrganizationIncome(incomeInput);
	
	Employee emploInput; //new Employee for the input.
	float totalSalaryInput;
	bool flag = false;
	cin >> idInput;
	while (idInput != 0)
	{
		cin >> nameInput >> salaryInput >> hoursInput >> incomeInput;
		while (idInput < 1 || salaryInput < 0 || hoursInput < 0 || incomeInput < 0) //integrity check
		{
			cout << "ERROR\n";
			cin >> idInput;
			if (idInput == 0) //if the user wants to stop (ID == 0)
			{
				flag = true;
				break;
			}
			cin >> nameInput >> salaryInput >> hoursInput >> incomeInput;
		}
		if (flag)
			break; //stopping the progress of the loop.
		emploInput.setId(idInput); //putting the inputs in the employee.
		emploInput.setName(nameInput);
		emploInput.setSalaryPerHour(salaryInput);
		emploInput.setHours(hoursInput);
		emploInput.setOrganizationIncome(incomeInput);
		totalSalaryInput = emploInput.salary();
		
		if (totalSalaryHighest < totalSalaryInput) //checking the highest salary.
		{
			highestSalaryEmplo.setId(idInput);
			highestSalaryEmplo.setName(nameInput);
			highestSalaryEmplo.setSalaryPerHour(salaryInput);
			highestSalaryEmplo.setHours(hoursInput);
			highestSalaryEmplo.setOrganizationIncome(incomeInput);
			totalSalaryHighest = totalSalaryInput;
		}
		if (minimumCollectedEmplo.getOrganizationIncome() > emploInput.getOrganizationIncome()) //checking the lowest income.
		{
			minimumCollectedEmplo.setId(idInput);
			minimumCollectedEmplo.setName(nameInput);
			minimumCollectedEmplo.setSalaryPerHour(salaryInput);
			minimumCollectedEmplo.setHours(hoursInput);
			minimumCollectedEmplo.setOrganizationIncome(incomeInput);
		}
		cin >> idInput; //inputting the next ID.
	}
	
	cout << "minimum collected: " << minimumCollectedEmplo.getId() << " " << minimumCollectedEmplo.getName() << " " << minimumCollectedEmplo.getOrganizationIncome() << endl;
	cout << "highest salary: " << highestSalaryEmplo.getId() << " " << highestSalaryEmplo.getName() << " " << totalSalaryHighest << endl;
	return 0;
}

/*Run sample:
A.
enter details, to end enter 0:
123456789
moshe
50
40
2000
135792468
rivka
120
55
3450
97531246
sara
35
100
5632
0
minimum collected: 123456789 moshe 2000
highest salary: 135792468 rivka 7140

B.
enter details, to end enter 0:
111111111
doron
35
120
6000
222222222
tal
50
55
1400
444444444
levi
45
-4
100
ERROR
333333333
naomi
30
120
800
0
minimum collected: 333333333 naomi 800
highest salary: 111111111 doron 5550*/