#include <iostream>
#include "Payment.h"
using namespace std;
int main() {
	Payment worker("Smith", "John", 100, 2000, 13, 21, 25);
	worker.Print(); //Shows all the information about an object using initialization above.
	Payment worker2;
	worker2.SetSurname("Clington");
	worker2.SetName("Bill");
	worker2.SetSalary(75);
	worker2.SetEmployementYear(1991);
	worker2.SetTaxPercent(15);
	worker2.SetWorkDays(20);
	worker2.SetDaysWorked(15);
	//Showing worker2 data using setters
	worker2.Print();
	//Copy worker2 in worker3 and showing it.
	Payment worker3(worker2);
	worker3.Print();
	cout << endl;
	return 0;
}