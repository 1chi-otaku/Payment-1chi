#pragma once
class Payment
{
	char* Surname; //Surname of the worker.
	char* Name; //Name of the worker.
	double Salary; //Salary per day.
	short EmployementYear; //The year the employee started working.
	short AllowancePercent; //Per cent of additional allowance.
	short TaxPercent; //Per cent of taxes.
	short DaysWorked; //Number of days the employee was at work.
	short WorkDays; //Number of work days in a month (25 max).
	short Withheld; //Withholds of employee's salary.
	double Income; //A clear salary of the employee including allowances but excluding withelds.
	
public:
	explicit Payment(); //Default constructor will fill the object with N/A values.
	explicit Payment(const char* surname, const char* name, double salary, short employementyear, short taxpercent, short daysworked, short workdays); //Constructor will fill object's data with values from user.
	~Payment(); //Destructor will clear memory for Surname and Name fields.
	Payment(const Payment& temp); //Copy constructor for proper copy of dynanic fields.
	short AllowancePercent_() const; //Calculates allowance per cent of the employees referring to YearsAtWork(); method.
	short YearsAtWork() const; //Returns the number of full years the employee has worked.
	double ClearSalary() const; //Returns clear salary of the employee: meaning default Salary * Worked Days.
	double NoTaxSalary() const; //Returns salary without taxes and witholds: meaning Clear Salary + Allowance Percent.
	double Tax() const; //Returns the summ of money that goes to taxes and witholds. 
	double CompleteSalary() const; //Returns complete salary of the worker: meaning NoTaxSalary - Tax and -1%.

	//Input-Output
	void Input(); //Will fill object's date with keyboard values.
	void Print() const; //Will show object's data in console.

	
	//Setters - will change field's value directly.
	void SetSurname(const char* surname);
	void SetName(const char* name);
	void SetSalary(double salary);
	void SetEmployementYear(short employmentyear);
	void SetAllowancePercent(short allowancepercent);
	void SetTaxPercent(short taxpercent);
	void SetDaysWorked(short daysworked);
	void SetWorkDays(short workdays);
	void SetWithheld(short withheld);
	void SetIncome(double income);

	//Getters - will return field's value.
	const char* GetSurname()const;
	const char* GetName()const;
	double GetSalary()const;
	short GetEmploymentYear()const;
	short GetAllowancePercent()const;
	short GetTaxPercent()const;
	short GetDaysWorked()const;
	short GetWorkDays()const;
	short GetWithheld()const;
	double GetIncome()const;





};

