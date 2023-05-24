#include"vehicle.h"

	Vehicle::Vehicle()
{
	vId=0;
	registrationNo=0;
	avgMileage=0;
	LicenceType=0;
	status=0;
	fueltype=0;
	overallRanking=0;
	list=0;
	serviceHistory=0;
}
	Vehicle::Vehicle(int vid,int no,float avg,char* lics,bool status,char* fuel,float rank,Date date,Feature* list,Service** rec)
{
	vId=vid;
	registrationNo=no;
	avgMileage=avg;
	LicenceType=new char [10];
	strcpy(LicenceType,lics);
	this->status=status;
	fueltype=new char [10];
	strcpy(fueltype,fuel);
	overallRanking=rank;
	manufacturingDate=date;
	this->list=list;
	serviceHistory=rec;
}
	Vehicle::Vehicle(const Vehicle &vehicle)
{
	vId=vehicle.vId;
	registrationNo=vehicle.registrationNo;
	avgMileage=vehicle.avgMileage;
	LicenceType=new char [10];
	strcpy(LicenceType,vehicle.LicenceType);
	status=vehicle.status;
	fueltype=new char [10];
	strcpy(fueltype,vehicle.fueltype);
	overallRanking=vehicle.overallRanking;
	manufacturingDate=vehicle.manufacturingDate;
	list=vehicle.list;
	serviceHistory=vehicle.serviceHistory;
}
	void Vehicle::set_vId(int vid)
{
	vId=vid;
}
	void Vehicle::set_reg(int no)
{
	registrationNo=no;
}
	void Vehicle::set_avg(float avg)
{
	avgMileage=avg;
}
	void Vehicle::set_lics(char* lics)
{
	if(LicenceType!=0)
		delete [] LicenceType;
	LicenceType=new char [10];
	strcpy(LicenceType,lics);
}
	void Vehicle::set_status(bool status)
{
	this->status=status;
}
	void Vehicle::set_fuel(char* fuel)
{
	if(fueltype!=0)
		delete [] fueltype;
	fueltype=new char [10];
	strcpy(fueltype,fuel);
}
	void Vehicle::set_rank(float rank)
{
	overallRanking=rank;
}
	void Vehicle::set_date(Date date)
{
	manufacturingDate=date;
}
	void Vehicle::set_features(Feature* list,int size)
{
	int index=0;
	if(this->list!=0)
		delete [] this->list;
	f_size=size;
	this->list=new Feature [f_size];
	for(index=0;index<f_size;index++)
	{
		*(this->list+index)=*(list+index);
	}
}
	void Vehicle::set_service_rec(Service** rec,int size)
{
	int index=0;
	if(serviceHistory!=0)
	{ 
		for(index=0;index<s_size;index++)
			delete [] *(serviceHistory+index);
		delete serviceHistory;
	}
	s_size=size;
	serviceHistory=new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		*(serviceHistory+index)=*(rec+index);
	}
}
	int Vehicle::get_vId()
{
	return vId;
}
	int Vehicle::get_reg()
{
	return registrationNo;
}
	float Vehicle::get_avg()
{
	return avgMileage;
}
	char* Vehicle::get_lics()
{
	return LicenceType;
}
	bool Vehicle::get_status()
{
	return status;
}
	char* Vehicle::get_fuel()
{
	return fueltype;
}
	float Vehicle::get_rank()
{
	return overallRanking;
}
	Date Vehicle::get_date()
{
	return manufacturingDate;
}
	Feature* Vehicle::get_features()
{
	return list;
}
	Service** Vehicle::get_service_rec()
{
	return serviceHistory;
}
	ostream& operator <<(ostream &out, const Vehicle &vehicle)
{
	int index=0;
	out<<endl<<"The Id of Vehicle is = "<<vehicle.vId;
	out<<endl<<"The Registration No. of Vehicle is = "<<vehicle.registrationNo;
	out<<endl<<"The Average Mileage of Vehicle is = "<<vehicle.avgMileage;
	out<<endl<<"The The License Type of Vehicle is = "<<vehicle.LicenceType;
	out<<endl<<"The Status of Vehicle is = ";
	if(vehicle.status)
		out<<"Complete Ride";
	else
		out<<"Incomplete Ride";
	out<<endl<<"The Fuel Type of Vehicle is = "<<vehicle.fueltype;
	out<<endl<<"The Overall Ranking of Vehicle is = "<<vehicle.overallRanking;
	out<<endl<<"The Features of Vehicle are = ";
	for(index=0;index<vehicle.f_size;index++)
	{
		cout<<*(vehicle.list+index);
	}
	out<<endl<<"The Service Record of Vehicle is = ";
	for(index=0;index<vehicle.s_size;index++)
	{
		cout<<**(vehicle.serviceHistory+index);
	}
	return out;
}
	istream & operator >>(istream &in, Vehicle &vehicle)
{
	int index=0;
	in>>vehicle.vId;
	in>>vehicle.registrationNo;
	in>>vehicle.avgMileage;
	in>>vehicle.LicenceType;
	in>>vehicle.status;
	in>>vehicle.fueltype;
	in>>vehicle.overallRanking;
	for(index=0;index<vehicle.f_size;index++)
	{
		in>>*(vehicle.list+index);
	}
	for(index=0;index<vehicle.s_size;index++)
	{
		in>>**(vehicle.serviceHistory+index);
	}
	return in;
}
	ofstream & operator <<(ofstream &out, const Vehicle &vehicle)
{
	int index=0;
	out<<vehicle.vId;
	out<<vehicle.registrationNo;
	out<<vehicle.avgMileage;
	out<<vehicle.LicenceType;
	out<<vehicle.status;
	out<<vehicle.fueltype;
	out<<vehicle.overallRanking;
	for(index=0;index<vehicle.f_size;index++)
	{
		out<<*(vehicle.list+index);
	}
	for(index=0;index<vehicle.s_size;index++)
	{
		out<<**(vehicle.serviceHistory+index);
	}
	return out;
}
	ifstream & operator >>(ifstream &in, Vehicle &vehicle)
{
	int index=0;
	in>>vehicle.vId;
	in>>vehicle.registrationNo;
	in>>vehicle.avgMileage;
	in>>vehicle.LicenceType;
	in>>vehicle.status;
	in>>vehicle.fueltype;
	in>>vehicle.overallRanking;
	for(index=0;index<vehicle.f_size;index++)
	{
		in>>*(vehicle.list+index);
	}
	for(index=0;index<vehicle.s_size;index++)
	{
		in>>**(vehicle.serviceHistory+index);
	}
	return in;
}
	void Vehicle::print()
{
	cout<<*this;
}
	Vehicle::~Vehicle()
{
	vId=0;
	registrationNo=0;
	avgMileage=0;
	if(LicenceType!=0)
		delete [] LicenceType;
	LicenceType=0;
	status=0;
	if(fueltype!=0)
		delete [] fueltype;
	fueltype=0;
	overallRanking=0;
	list=0;
	serviceHistory=0;
}