#include "Payment.h"
#include <iostream>
using namespace std;

Payment::Payment(){// A default constructor will fill fields with nonsense values. 
	Name = new char[16];
	Surname = new char[16];
	Salary = 0;
	EmployementYear = 2000;
	TaxPercent = 13;
	DaysWorked = 0;
	WorkDays = 25;
	Withheld = Tax();
	Income = ClearSalary();
	AllowancePercent = AllowancePercent_();
}
Payment::Payment(const char* surname, const char* name, double salary, short employementyear, short taxpercent, short daysworked, short workdays) { //Sets fields initialization values from user, works with dymamic fields
	Surname = new char[strlen(surname) + 1];
	for (int i = 0; i < strlen(surname); i++)
		Surname[i] = surname[i];
	Surname[strlen(surname)] = '\0';

	Name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
		Name[i] = name[i];
	Name[strlen(name)] = '\0';

	Salary = salary;
	EmployementYear = employementyear;
	AllowancePercent = AllowancePercent_();
	TaxPercent = taxpercent;

	if (workdays > 25 || workdays < 0)
		WorkDays = 25;
	else
		WorkDays = workdays;

	if (daysworked > workdays || daysworked < 0)
		DaysWorked = workdays;
	else
		DaysWorked = daysworked;

	Withheld = Tax();
	Income = ClearSalary();

}
Payment::~Payment()//Clears memory
{
	if (Name != nullptr)delete[]Name;
	if (Surname != nullptr)delete[]Surname;
}
Payment::Payment(const Payment& temp) //Basic copy constructor but with functionality for proper work of dymamic fiedls. 
{
	Surname = new char[strlen(temp.Surname) + 1];
	strcpy_s(Surname, strlen(temp.Surname) + 1, temp.Surname);

	Name = new char[strlen(temp.Name) + 1];
	strcpy_s(Name, strlen(temp.Name) + 1, temp.Name);

	Salary = temp.Salary;
	EmployementYear = temp.EmployementYear;
	AllowancePercent = temp.AllowancePercent;
	TaxPercent = temp.TaxPercent;
	DaysWorked = temp.DaysWorked;
	WorkDays = temp.WorkDays;
	Withheld = temp.Withheld;
	Income = temp.Income;

}


short Payment::AllowancePercent_() const
{
	unsigned int CurrentYear = 2022;
	if (YearsAtWork() < 2) return 0;			//If an employee has worked for less than two years, he will not be paid allowances ...
	else {
		return (YearsAtWork()) * 2;				// If an employee has worked more than two years, he will be paid allowances - Employement Years * 2.
	}
}
short Payment::YearsAtWork() const //Counts the number of years at work, subtracting the year of employment from the current year.
{
	unsigned int CurrentYear = 2022;
	return CurrentYear - EmployementYear;
}
double Payment::ClearSalary() const // Returns clear salary
{
	return Salary * DaysWorked;
}
double Payment::NoTaxSalary() const //Returns clear salary but with allowances.
{
	return ClearSalary() + (ClearSalary() * AllowancePercent)/100;
}
double Payment::Tax() const //Returns sum of taxes that will be excluded from final salary.
{
	return NoTaxSalary()* TaxPercent / 100;
}
double Payment::CompleteSalary() const  //Returns final salary with allowances and taxes and 1% pension.
{
	return (NoTaxSalary() - Tax()) - ((NoTaxSalary() - Tax()) * 1/100); //Salary with allowances - taxes - 1% pension.
}


void Payment::Input()
{
	char buff[80];
	double temp;
	short shortTemp;
	if (Surname != nullptr) delete[] Surname;
	cout << "Enter Name: " << endl;
	cin >> buff;
	Surname = new char[strlen(buff) + 1];
	strcpy_s(Surname, strlen(buff)+1, buff);

	if (Name!= nullptr) delete[] Name;
	cout << "Enter Name: " << endl;
	cin >> buff;
	Name = new char[strlen(buff) + 1];
	strcpy_s(Name, strlen(buff)+1, buff);

	cout << "Enter Salary: " << endl;
	cin >> temp;
	Salary = temp;

	cout << "Enter Employement Year: " << endl;
	cin >> shortTemp;
	if (shortTemp < 0 || shortTemp > 3000)
		EmployementYear = 2022;
	else
		EmployementYear = shortTemp;

	

	cout << "Enter Tax Percantage: " << endl;
	cin >> shortTemp;
	TaxPercent = shortTemp;

	cout << "Enter Current Work Days In This Month: " << endl;
	cin >> shortTemp;
	if (shortTemp > 25 || shortTemp < 0)
		WorkDays = 25;
	else
		WorkDays = shortTemp;
	AllowancePercent = AllowancePercent_();
	

	cout << "Enter Days Worked In This Month: " << endl;
	cin >> shortTemp;
	if (shortTemp > WorkDays || shortTemp < 0)
		DaysWorked = WorkDays;
	else
		DaysWorked = shortTemp;

	Income = ClearSalary();
	
	
}
void Payment::Print() const
{
	cout << "Full name - " << Surname << " " << Name << endl;
	cout << "Salary - " << Salary << endl;
	cout << "Employment year - " << EmployementYear << endl;
	cout << "Experience - " << YearsAtWork() << " year(s)" << endl;
	cout << "Allowance percent - " << AllowancePercent_() << "%" << endl;
	cout << "Tax Percent - " << TaxPercent << "%" << endl;
	cout << "Current work days in this month - " << WorkDays << endl;
	cout << "Days worked in this month - " << DaysWorked << endl;
	cout << "Withheld - " << Tax() << endl;
	cout << "Clear salary - " << ClearSalary() << endl;
	cout << "Salary with allowance - " << NoTaxSalary() << endl;
	cout << "Complete salary - " << CompleteSalary() << endl << endl;
} 


//Setters - will change field's value directly.
void Payment::SetSurname(const char* surname)
{
	if (Surname != nullptr)delete[]Surname;
	Surname = new char[strlen(surname) + 1];
	strcpy_s(Surname, strlen(surname)+ 1, surname);
}
void Payment::SetName(const char* name)
{
	if (Name != nullptr)delete[]Name;
	Name = new char[strlen(name) + 1];
	strcpy_s(Name, strlen(name)+1 , name);
	
}
void Payment::SetSalary(double salary)
{
	Salary = salary;
}
void Payment::SetEmployementYear(short employmentyear) //Checks if the user wrote a correct value, otherwise sets EmployementYear to 0.
{
	if (employmentyear < 0 || employmentyear > 3000)
		EmployementYear = 2022;
	else
		EmployementYear = employmentyear;
}
void Payment::SetAllowancePercent(short allowancepercent)
{
	AllowancePercent = allowancepercent;
}
void Payment::SetTaxPercent(short taxpercent)
{
	TaxPercent = taxpercent;
}
void Payment::SetDaysWorked(short daysworked) //Checks if workdays isn't > than 25 and < than 1. If it is, sets a WorkDays value.
{
	if (daysworked > WorkDays || daysworked < 1)
		DaysWorked = WorkDays;
	else
		DaysWorked = daysworked;
}
void Payment::SetWorkDays(short workdays) //Checks if workdays isn't > than 25 and < than 1. If it is, sets a default value - 25.
{
	if (workdays > 25 || workdays < 1)
		WorkDays = 25;
	else
		WorkDays = workdays;
}
void Payment::SetWithheld(short withheld)
{
	Withheld = withheld;
}
void Payment::SetIncome(double income)
{
	Income = income;
}

//Getters - will return field's value.
const char* Payment::GetSurname() const
{
	return Surname;
}
const char* Payment::GetName() const
{
	return Name;
}
double Payment::GetSalary() const
{
	return Salary;
}
short Payment::GetEmploymentYear() const
{
	return EmployementYear;
}
short Payment::GetAllowancePercent() const
{
	return AllowancePercent;
}
short Payment::GetTaxPercent() const
{
	return TaxPercent;
}
short Payment::GetDaysWorked() const
{
	return DaysWorked;
}
short Payment::GetWorkDays() const {
	return WorkDays;
}
short Payment::GetWithheld() const
{
	return Withheld;
}
double Payment::GetIncome() const
{
	return Income;
}
