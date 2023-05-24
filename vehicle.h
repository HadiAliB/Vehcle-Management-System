#include"info.h"
#include"service.h"

	class Vehicle
{
	int vId;
	int registrationNo;
	float avgMileage;
	char * LicenceType; // License required for driving the vehicle
	bool status; // false for free, true if booked in a service already
	char * fueltype;
	float overallRanking;
	Date manufacturingDate;
	Feature * list;
	int f_size;
	Service ** serviceHistory;
	int s_size;
	//Add services address in the array for tracking complete information of service.
	//you can add more members here if required
	//add member functions
 public:
	Vehicle();
	Vehicle(int,int,float,char*,bool,char*,float,Date,Feature*,Service**);
	Vehicle(const Vehicle &);
	void set_vId(int);
	void set_reg(int);
	void set_f_size(int size)
{
	f_size=size;
}
	void set_s_size(int size)
{
	s_size=size;
}
	int get_f_size()
{
	return f_size;
}
	int get_s_size()
{
	return s_size;
}
	void set_avg(float);
	void set_lics(char*);
	void set_status(bool);
	void set_fuel(char*);
	void set_rank(float);
	void set_date(Date);
	void set_features(Feature*,int);
	void set_service_rec(Service**,int);
	int get_vId();
	int get_reg();
	float get_avg();
	char* get_lics();
	bool get_status();
	char* get_fuel();
	float get_rank();
	Date get_date();
	Feature* get_features();
	Service** get_service_rec();
	void update_vehicle_services(const Service &service)
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
	friend ostream & operator <<(ostream &,const Vehicle &);
	friend istream & operator >>(istream &,Vehicle &);
	friend ofstream & operator <<(ofstream &,const Vehicle &);
	friend ifstream & operator >>(ifstream &,Vehicle &);
	void print();
	void printf(ofstream &out)
{
	out<<*this;
}
	~Vehicle();
};
//add Complete Hierarchy of vehicles based on their types and functions
