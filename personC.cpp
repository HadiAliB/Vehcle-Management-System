#include"person.h"
#include<iostream>
using namespace std;
Person::Person()
{
	 Age=0;
	 Nid=0;
}
Person::Person(Name name, Date date, int age, int nid):pName(name),DOB(date)
{
	Age = age;
	Nid = nid;
}
Person::Person(const Person &person):pName(person.pName),DOB(person.DOB)
{
	Age=person.Age;
	Nid=person.Nid;
}
void Person::set_name(Name name)
{
	pName=name;
}
void Person::set_dob(Date date)
{
	DOB=date;
}
void Person::set_age(int age)
{
	Age = age;
}
void Person::set_nid(int nid)
{
	Nid = nid;
}
Name Person::get_name()
{
	return pName;
}
Date Person::get_dob()
{
	return DOB;
}
int Person::get_age()
{
	return Age;
}
int Person::get_nid()
{
	return Nid;
}
ostream& operator <<(ostream& out, const Person&obj)
{
	out<<" Person Name:"<<obj.pName<<endl;
	out<<" Person DoB:"<<obj.DOB<<endl;
	out << "Person Age:" << obj.Age << endl;
	out << "Person Nid:" << obj.Nid << endl;
	return out;
}
istream& operator >>(istream& in , Person& obj)
{
	in >> obj.pName;
	in >> obj.DOB;
	cout << "Enter Age:" << endl;
	in>>obj.Age;
	in>>obj.Nid;
	return in;
}
ofstream& operator <<(ofstream &out, const Person &person)
{
	out<<person.pName<<endl;
	out<<person.DOB<<endl;
	out<<person.Age<<endl;
	out<<person.Nid<<endl;
	return out;
}
ifstream& operator >>(ifstream &in, Person &person)
{
	in >> person.pName;
	in >> person.DOB;
	in>>person.Age;
	in>>person.Nid;
	return in;
}
Customer::Customer()
{
	cId=0;
	bookingHistory=0;
	s_size=0;
}
Customer::Customer(int id, Service** his, int size, Name name, Date date, int age, int nid):Person(name,date,age,nid)
{
	int index=0;
	cId=id;
	s_size=size;
	bookingHistory=new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		*(bookingHistory+index)=*(his+index);
	}
}
Customer::Customer(Customer &customer):Person(customer.get_name(),customer.get_dob(),customer.get_age(),customer.get_nid())
{
	int index=0;
	cId=customer.cId;
	s_size=customer.s_size;
	bookingHistory=new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		*(bookingHistory+index)=*(customer.bookingHistory+index);
	}
}
void Customer::set_cId(int x)
{
	cId = x;
}
void Customer::set_s_size(int x)
{
	s_size = x;
}
void Customer::set_service(Service**Arr,int size)
{
	int index=0;
	if(bookingHistory!=0)
	{
		for(index=0;index<s_size;index++)
		{
			delete *(bookingHistory+index);
		}
		delete [] bookingHistory;
	}
	s_size=size;
	bookingHistory = new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		bookingHistory[index]=new Service;
		bookingHistory[index]=Arr[index];
	}
}
int Customer::get_cId()
{
	return cId;
}
Service** Customer::get_services()
{
	return bookingHistory;
}
int Customer::get_s_size()
{
	return s_size;
}
ostream& operator <<(ostream& out, const Customer& obj)
{
	out << "Customer Id:" << obj.cId << endl;
	for (int i = 0; i < obj.s_size; i++)
	{
		out << *obj.bookingHistory[i] << endl;
	}
	return out;
}
istream& operator >>(istream& in, Customer& obj)
{
	in >> obj.cId;
	for (int i = 0; i < obj.s_size; i++)
	{
		in >> *obj.bookingHistory[i];
	}
	return in;
}
ofstream& operator <<(ofstream& fout, const Customer& obj)
{
	fout << obj.cId << endl;
	for (int i = 0; i < obj.s_size; i++)
	{
		fout << *obj.bookingHistory[i] << endl;
	}
	return fout;
}
ifstream& operator >>(ifstream& fin, Customer& obj)
{
	fin >> obj.cId;
	for (int i = 0; i < obj.s_size; i++)
	{
		fin >> *obj.bookingHistory[i];
	}
	return fin;
}
void Customer::print()
{
	Person::print();
	cout<<*this;
}
void Customer::printf(ofstream &out)
{
	Person::printf(out);
	out<<*this;
}
Customer::~Customer()
{
	cId=0;
	int index=0;
	if(bookingHistory!=0)
		for(index=0;index<s_size;index++)
		{
			delete *(bookingHistory+index);
		}
	bookingHistory=0;
	s_size=0;
}
	Driver::Driver()
{
	dId=0;
	LicencesList=0;
	noofLicences=1;
	overallRanking=2;
	salary=1000;
	completion.set_day(12);
	completion.set_month(12);
	completion.set_year(2021);
	experience=1;
	status=1; // 1 for free, 2 if booked and 3 if canceled
	serviceHistory=0;
	s_size=0;
}
	Driver::Driver(int id,char** list,int lics,float rank,float sal,int xp,int stat,Service** his,int size,Date date,Name name,Date date1,int age,int nId):Person(name,date1,age,nId)
{
	int index=0;
	dId=id;
	LicencesList=new char* [lics];
	for(index=0;index<lics;index++)
	{
		*(LicencesList+index)=new char [10];
		strcpy(*(LicencesList+index),*(list+index));
	}
	noofLicences=lics;
	overallRanking=rank;
	salary=sal;
	experience=xp;
	status=stat;
	s_size=size;
	for(index=0;index<s_size;index++)
	{
		*(serviceHistory+index)=*(his+index);
	}
	completion=date;
}
	Driver::Driver(const Driver &driver)
{
	int index=0;
	dId=driver.dId;
	noofLicences=driver.noofLicences;
	LicencesList=new char* [noofLicences];
	for(index=0;index<noofLicences;index++)
	{
		*(LicencesList+index)=new char [10];
		strcpy(*(LicencesList+index),*(driver.LicencesList+index));
	}
	overallRanking=driver.overallRanking;
	salary=driver.salary;
	experience=driver.experience;
	status=driver.status;
	s_size=driver.s_size;
	for(index=0;index<s_size;index++)
	{
		*(serviceHistory+index)=*(driver.serviceHistory+index);
	}
	completion=driver.completion;
}
void Driver::set_dId(int x)
{
	dId = x;
}
void Driver::set_licenses( char** arr,int size)
{
	int index=0;
	if(LicencesList!=0)
	{
		for(index=0;index<noofLicences;index++)
			delete [] *(LicencesList+index);
		delete [] LicencesList;
	}
	noofLicences=size;
	LicencesList=new char* [noofLicences];
	for(index=0;index<noofLicences;index++)
	{
		*(LicencesList+index)=new char [10];
		strcpy(*(LicencesList+index),*(arr+index));
	}
}
void Driver::set_lics(int x)
{
	noofLicences = x;
}
void Driver::set_rank(float x)
{
	overallRanking = x;
}
void Driver::set_salary(float x)
{
	salary = x;
}
void Driver::set_xp(int x)
{
	experience = x;
}
void Driver::set_status(int x)
{
	status = x;
}
void Driver::set_services(Service** arr)
{
	serviceHistory = arr;
}
void Driver::set_s_size(int x)
{
	s_size = x;
}
int Driver::get_dId()
{
	return dId;
}
char** Driver::get_licenses()
{
	return  LicencesList;
}
int Driver::get_lics()
{
	return noofLicences;
}
float Driver::get_rank()
{
	return overallRanking;
}
float Driver::get_salary()
{
	return salary;
}
int Driver::get_xp()
{
	return experience;
}
int Driver::get_status()
{
	return status;
}
Service** Driver::get_services()
{
	return serviceHistory;
}
int  Driver::get_s_size()
{
	return s_size;
}
ostream& operator <<(ostream& out, const Driver& obj)
{
	out << "Driver Id:" << obj.dId << endl;
	out << "Ranking:" << obj.overallRanking << endl;
	out << "Salary:" << obj.salary << endl;
	out << "Experience:" << obj.experience << endl;
	out << "Status:" << obj.status << endl;
	out << "No of Licence:" << obj.noofLicences << endl;
	out << "No of Services:" << obj.s_size << endl;
	out << obj.completion << endl;
	for (int i = 0; i < obj.s_size; i++)
	{
		out << *obj.serviceHistory[i] << endl;
	}
	for (int i = 0; i < obj.noofLicences; i++)
	{
		for (int j = 0; j < obj.noofLicences; j++)
		{
			out << (obj.LicencesList+i);
		}
	}
	return out;
}
istream& operator >>(istream& in, Driver& obj)
{
	in >> obj.dId;
	in >> obj.overallRanking;
	in >> obj.salary;
	in >> obj.experience;
	in >> obj.status;
	in >> obj.noofLicences;
	in >> obj.s_size;
	in >> obj.completion;
	for (int i = 0; i < obj.s_size; i++)
	{
		in >> *obj.serviceHistory[i];
	}
	for (int i = 0; i < obj.noofLicences; i++)
	{
		for (int j = 0; j < obj.noofLicences; j++)
		{
			in >> obj.LicencesList[i][j];
		}
	}
	return in;
}
ofstream& operator <<(ofstream& fout, const Driver& obj)
{
	fout << obj.dId << endl;
	fout << obj.overallRanking << endl;
	fout << obj.salary << endl;
	fout << obj.experience << endl;
	fout << obj.status << endl;
	fout << obj.noofLicences << endl;
	fout << obj.s_size << endl;
	fout << obj.completion << endl;
	for (int i = 0; i < obj.s_size; i++)
	{
		fout << *obj.serviceHistory[i] << endl;
	}
	return fout;
}
ifstream& operator >>(ifstream& fin, Driver& obj)
{
	fin >> obj.dId;
	fin >> obj.overallRanking;
	fin >> obj.salary;
	fin >> obj.experience;
	fin >> obj.status;
	fin >> obj.noofLicences;
	fin >> obj.s_size;
	fin >> obj.completion;
	for (int i = 0; i < obj.s_size; i++)
	{
		obj.serviceHistory[i]->fin(fin);
	}
	return fin;
}
void Driver::print()
{
	Person::print();
	cout<<*this;
}
void Driver::printf(ofstream& out)
{
	Person::printf(out);
	out<<*this;
}
Driver::~Driver()
{
	int index=0;
	dId=0;
	LicencesList=0;
	noofLicences=0;
	overallRanking=0;
	salary=0;
	experience=0;
	status=false;
	if(serviceHistory!=0)
	{ 
		for(index=0;index<s_size;index++)
		{
			delete *(serviceHistory+index);
		}
		delete [] serviceHistory;
	}
	s_size=0;
	completion.set_day(0);
	completion.set_month(0);
	completion.set_year(0);
}
void Person::print()
{
	cout<<*this;
}
void Person::printf(ofstream &out)
{
	out<<*this;
}
Person::~Person()
{
	Age=Nid=0;
}