#pragma once
#include"info.h"
#include"service.h"

	class Person 
{
	Name pName;
	Date DOB;
	int Age;
	int Nid;
 public:
	Person();
	Person(Name,Date,int,int);
	Person(const Person &);
	void set_name(Name);
	void set_dob(Date);
	void set_age(int);
	void set_nid(int);
	Name get_name();
	Date get_dob();
	int get_age();
	int get_nid();
	friend ostream & operator <<(ostream &,const Person &);
	friend istream & operator >>(istream &,Person &);
	friend ofstream & operator <<(ofstream &,const Person &);
	friend ifstream & operator >>(ifstream &,Person &);
	virtual void print();
	virtual void printf(ofstream &);
	~Person();
	//add following functions in this class //Getter, Setters
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output 
	//operator (print information of person)
};
	class Customer:public Person 
{
	int cId;
	// Unique and assigned first time when customer makes first service request
	Service** bookingHistory;
	int s_size;
	//Maintain and Update history of customer for each service (ride or goods 
	//transportation order) by adding address of service in dynamic array.
	//you can add more members here if required
 public:
	Customer();
	Customer(int,Service**,int,Name,Date,int,int);
	Customer(Customer &);
	void set_cId(int);
	void set_s_size(int);
	void set_service(Service**,int);
	int get_cId();
	void update_customer_services(const Service &service)
{
	if(bookingHistory!=0)
	{ 
		int index=0;
		Service** temp=new Service* [s_size];
		for(index=0;index<s_size;index++)
		{
			*(temp+index)=new Service;
			(*(temp+index))->operator=(**(bookingHistory+index));
		}
		for(index=0;index<s_size;index++)
		{
			delete *(bookingHistory+index);
		}
		delete [] bookingHistory;
		s_size++;
		bookingHistory=new Service* [s_size];
		for(index=0;index<(s_size-1);index++)
		{
			*(bookingHistory+index)=new Service;
			(*(bookingHistory+index))->operator=(**(temp+index));
		}
		**(bookingHistory+index)=service;
		for(index=0;index<(s_size-1);index++)
		{
			delete *(temp+index);
		}
		delete [] temp;
	}
	else
	{
		s_size=1;
		bookingHistory=new Service*;
		*(bookingHistory)=new Service;
		(*(bookingHistory))->operator=(service);
	}
}
	Service** get_services();
	int get_s_size();
	friend ostream & operator <<(ostream &,const Customer &);
	friend istream & operator >>(istream &,Customer &);
	friend ofstream & operator <<(ofstream &,const Customer &);
	friend ifstream & operator >>(ifstream &,Customer &);
	void print();
	void printf(ofstream &);
	~Customer();
	//add following functions in this class //Getter, Setters
	//Destructor, Default and Parametrized Constructor, Copy Constructor, Output 
	//operator (print complete information of customer including history if any)
};
	class Driver:public Person 
{
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	Date completion;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled
	Service** serviceHistory;
	int s_size;
	//Add services address in the array for tracking complete information of service.
 public:
	Driver();
	Driver(int,char**,int,float,float,int,int,Service**,int,Date,Name,Date,int,int);
	Driver(const Driver &);
	void set_dId(int);
	void set_licenses(char**,int);
	void set_lics(int);
	void set_rank(float);
	void set_completion_date(Date &date)
{
	completion.set_day(date.get_day());
	completion.set_month(date.get_month());
	completion.set_year(date.get_year());
}
	Date get_completion_date()
{
	return completion;
}
	void set_salary(float);
	void update_driver_services(const Service &service)
{
	if(serviceHistory!=0)
	{ 
		int index=0;
		Service** temp=new Service* [s_size];
		for(index=0;index<s_size;index++)
		{
			*(temp+index)=new Service;
			**(temp+index)=**(serviceHistory+index);
		}
		for(index=0;index<s_size;index++)
		{
			delete *(serviceHistory+index);
		}
		delete [] serviceHistory;
		s_size++;
		serviceHistory=new Service* [s_size];
		for(index=0;index<(s_size-1);index++)
		{
			*(serviceHistory+index)=new Service;
			**(serviceHistory+index)=**(temp+index);
		}
		*(serviceHistory+index)=new Service;
		**(serviceHistory+index)=service;
		for(index=0;index<(s_size-1);index++)
		{
			delete *(temp+index);
		}
		delete [] temp;
	}
	else
	{
		s_size=1;
		serviceHistory=new Service*;
		*(serviceHistory)=new Service;
		**(serviceHistory)=service;
	}
}
	void set_xp(int);
	void set_status(int);
	void set_services(Service**);
	void set_s_size(int);
	int get_dId();
	char** get_licenses();
	int get_lics();
	float get_rank();
	float get_salary();
	int get_xp();
	int get_status();
	Service** get_services();
	int get_s_size();
	friend ostream & operator <<(ostream &,const Driver &);
	friend istream & operator >>(istream &,Driver &);
	friend ofstream & operator <<(ofstream &,const Driver &);
	friend ifstream & operator >>(ifstream &,Driver &);
	void print();
	void printf(ofstream &);
	~Driver();
	//add following functions in this class
	//Getter, Setters
	//Destructor, Default and Parameterized Constructor, Copy Constructor, Output 
	//operator (prints complete information of Driver)
};
