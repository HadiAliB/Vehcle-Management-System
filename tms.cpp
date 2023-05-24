#include"TMS.h"
#include<iostream>
#include<string>

 using namespace std;

	TMS::TMS()
{
	drivers=0;
	customers=0;
	vehicles=0;
	services=0;
	d_size=0;
	c_size=0;
	v_size=0;
	s_size=0;
}
	TMS::TMS(Driver** driver,int size1,Customer** customer,int size2,Vehicle** vehicle,int size3,Service** service,int size4)
{
	int index=0;
	d_size=size1;
	drivers=new Driver* [d_size];
	for(index=0;index<d_size;index++)
	{
		*(drivers+index)=new Driver;
		**(drivers+index)=**(driver+index);
	}
	c_size=size2;
	customers=new Customer* [c_size];
	for(index=0;index<c_size;index++)
	{
		*(customers+index)=new Customer;
		**(customers+index)=**(customer+index);
	}
	v_size=size3;
	vehicles=new Vehicle* [v_size];
	for(index=0;index<v_size;index++)
	{
		*(vehicles+index)=new Vehicle;
		**(vehicles+index)=**(vehicle+index);
	}
	s_size=size4;
	services=new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		*(services+index)=new Service;
		**(services+index)=**(service+index);
	}
}
	TMS::TMS(const TMS &tms)
{
	int index=0;
	d_size=tms.d_size;
	drivers=new Driver* [d_size];
	for(index=0;index<d_size;index++)
	{
		*(drivers+index)=new Driver;
	}
	c_size=tms.c_size;
	customers=new Customer* [c_size];
	for(index=0;index<c_size;index++)
	{
		*(customers+index)=new Customer;
	}
	v_size=tms.v_size;
	vehicles=new Vehicle* [v_size];
	for(index=0;index<v_size;index++)
	{
		*(vehicles+index)=new Vehicle;
	}
	s_size=tms.s_size;
	services=new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		*(services+index)=new Service;
		**(services+index)=**(tms.services+index);
	}
}
	void TMS::set_drivers(const Driver**,int size)
{
	int index=0;
	d_size=size;
	drivers=new Driver* [d_size];
	for(index=0;index<d_size;index++)
	{
		*(drivers+index)=new Driver;
	}
}
	void TMS::set_customers(const Customer**,int size)
{
	int index=0;
	c_size=size;
	customers=new Customer* [c_size];
	for(index=0;index<c_size;index++)
	{
		*(customers+index)=new Customer;
	}
}
	void TMS::set_vehicles(const Vehicle**,int size)
{
	int index=0;
	v_size=size;
	vehicles=new Vehicle* [v_size];
	for(index=0;index<v_size;index++)
	{
		*(vehicles+index)=new Vehicle;
	}
}
	void TMS::set_services(const Service**service,int size)
{
	int index=0;
	s_size=size;
	services=new Service* [s_size];
	for(index=0;index<s_size;index++)
	{
		*(services+index)=new Service;
		**(services+index)=**(service+index);
	}
}
	void TMS::set_d_size(int size)
{
	d_size=size;
}
	void TMS::set_c_size(int size)
{
	c_size=size;
}
	void TMS::set_v_size(int size)
{
	v_size=size;
}
	int TMS::get_d_size()
{
	return d_size;
}
	int TMS::get_c_size()
{
	return c_size;
}
	int TMS::get_v_size()
{
	return v_size;
}
	Driver** TMS::get_drivers()
{
	return drivers;
}
	Customer** TMS::get_customers()
{
	return customers;
}
	Vehicle** TMS::get_vehicles()
{
	return vehicles;
}
	Service** TMS::get_services()
{
	return services;
}
	bool TMS::set_records(string str)
{
	string path="Data/Customers/";
	path=path+str;
	path=path+".txt";
	ofstream out;
	out.open(path,ios::app);
	if(out.is_open())
		return true;
	else
		return false;
}
	bool TMS::update_customer()
{
	string path="Data/Customers/Customer";
	ofstream out;
	out.open("Data/Customers/Size.txt");
	out<<c_size;
	out.close();
	int index=0;
	for(index=0;index<c_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		out.open(path);
		(*(customers+index))->printf(out);
		out.close();
	}
	return true;
}
	bool TMS::update_driver()
{
	string path="Data/Drivers/Driver";
	ofstream out;
	out.open("Data/Drivers/Size.txt");
	out<<d_size;
	out.close();
	int index=0;
	for(index=0;index<d_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		out.open(path);
		(*(drivers+index))->printf(out);
		out.close();
	}
	return true;
}
	bool TMS::update_vehicle()
{
	string path="Data/Vehicles/Vehicle";
	ofstream out;
	out.open("Data/Vehicles/Size.txt");
	out<<v_size;
	out.close();
	int index=0;
	for(index=0;index<v_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		out.open(path);
		(*(vehicles+index))->printf(out);
		out.close();
	}
	return true;
}
	bool TMS::update_customer_service()
{
	string path="Records/Customers/Customer";
	ofstream out;
	out.open("Records/Customers/Size.txt");
	out<<c_size;
	out.close();
	int index=0;
	int index1=0;
	for(index=0;index<c_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		out.open(path);
		for(index1=0;index1<(*(customers+index))->get_s_size();index1++)
		{
			(*((*(customers+index))->get_services()+index1))->printf(out);
		}
		out.close();
	}
	return true;
}
	bool TMS::update_driver_service()
{
	string path="Records/Drivers/Driver";
	ofstream out;
	out.open("Records/Drivers/Size.txt");
	out<<d_size;
	out.close();
	int index=0;
	int index1=0;
	for(index=0;index<d_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		out.open(path);
		for(index1=0;index1<(*(drivers+index))->get_s_size();index1++)
		{
			(*((*(drivers+index))->get_services()+index1))->printf(out);
		}
		out.close();
	}
	return true;
}
	bool TMS::update_vehicle_service()
{
	string path="Records/Vehicles/Vehicle";
	ofstream out;
	out.open("Records/Vehicles/Size.txt");
	out<<v_size;
	out.close();
	int index=0;
	int index1=0;
	for(index=0;index<v_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		out.open(path);
		for(index1=0;index1<(*(vehicles+index))->get_s_size();index1++)
		{
			(*((*(vehicles+index))->get_service_rec()+index1))->printf(out);
		}
		out.close();
	}
	return true;
}
	bool TMS::read_customer()
{
	string path="Data/Customers/Customer";
	ifstream in;
	in.open("Data/Customers/Size.txt");
	in>>c_size;
	in.close();
	int index=0;
	customers=new Customer* [c_size];
	for(index=0;index<c_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		in.open(path);
		*(customers+index)=new Customer;
		in>>*(*(customers+index));
		in.close();
	}
	return true;
}
	bool TMS::read_driver()
{
	string path="Data/Drivers/Driver";
	ifstream in;
	in.open("Data/Drivers/Size.txt");
	in>>d_size;
	in.close();
	int index=0;
	drivers=new Driver* [d_size];
	for(index=0;index<d_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		in.open(path);
		*(drivers+index)=new Driver;
		in>>*(*(drivers+index));
		in.close();
	}
	return true;
}
	bool TMS::read_vehicle()
{
	string path="Data/Vehicles/Vehicle";
	ifstream in;
	in.open("Data/Vehicles/Size.txt");
	in>>v_size;
	in.close();
	int index=0;
	vehicles=new Vehicle* [v_size];
	for(index=0;index<v_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		in.open(path);
		*(vehicles+index)=new Vehicle;
		in>>*(*(vehicles+index));
		in.close();
	}
	return true;
}
	bool TMS::read_customer_service()
{
	string path="Records/Customers/Customer";
	ifstream in;
	in.open("Records/Customers/Size.txt");
	in>>c_size;
	in.close();
	int index=0;
	int index1=0;
	for(index=0;index<c_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		in.open(path);
		for(index1=0;index1<(*(customers+index))->get_s_size();index1++)
		{
			in>>*(*((*(customers+index))->get_services()+index1));
		}
		in.close();
	}
	return true;
}
	bool TMS::read_driver_service()
{
	string path="Records/Drivers/Driver";
	ifstream in;
	in.open("Records/Drivers/Size.txt");
	in>>d_size;
	in.close();
	int index=0;
	int index1=0;
	for(index=0;index<d_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		in.open(path);
		for(index1=0;index1<(*(drivers+index))->get_s_size();index1++)
		{
			in>>*(*((*(drivers+index))->get_services()+index1));
		}
		in.close();
	}
	return true;
}
	bool TMS::read_vehicle_service()
{
	string path="Records/Vehicles/Vehicle";
	ifstream in;
	in.open("Records/Vehicles/Size.txt");
	in>>v_size;
	in.close();
	int index=0;
	int index1=0;
	for(index=0;index<v_size;index++)
	{
		path=path+to_string(index+1)+".txt";
		in.open(path);
		for(index1=0;index1<(*(vehicles+index))->get_s_size();index1++)
		{
			in>>*(*((*(vehicles+index))->get_service_rec()+index1));
		}
		in.close();
	}
	return true;
}
	bool TMS::add_customer(Customer &customer)
{
	if(c_size<15)
	{ 
		int index=0;
		if(c_size>0)
		{ 
			for(index=0;index<c_size;index++)
			{
				if((*(customers+index))->get_cId()==customer.get_cId())
				{
					cout<<endl<<"Customer Already added.";
					return false;
				}
			}
			Customer** temp;
			temp=new Customer* [c_size];
			for(index=0;index<c_size;index++)
			{
				*(temp+index)=new Customer;
				**(temp+index)=**(customers+index);
			}
			for(index=0;index<c_size;index++)
			{
				delete *(customers+index);
			}
			delete [] customers;
			c_size++;
			this->customers=new Customer* [c_size];
			for(index=0;index<(c_size-1);index++)
			{
				*(customers+index)=new Customer;
				*(*(customers+index))=*(*(temp+index));
			}
			*(*(customers+index))=customer;
		}
		else
		{ 
			c_size++;
			customers=new Customer* [c_size];
			*customers=new Customer;
			**customers=customer;
		}
		return true;
	}
	else 
		return false;
}
	bool TMS::add_driver(Driver &driver)
{
	if(d_size<10)
	{ 
		int index=0;
		if(d_size>0)
		{ 
			for(index=0;index<d_size;index++)
			{
				if((*(drivers+index))->get_dId()==driver.get_dId())
				{
					cout<<endl<<"Driver Already added.";
					return false;
				}
			}
			Driver** temp;
			temp=new Driver* [d_size];
			for(index=0;index<d_size;index++)
			{
				*(temp+index)=new Driver;
				(*(temp+index))->set_lics((*(drivers+index))->get_lics());
				(*(temp+index))->set_licenses((*(drivers+index))->get_licenses(),(*(temp+index))->get_lics());
				*(*(temp+index))=*(*(drivers+index));
			}
			for(index=0;index<d_size;index++)
			{
				delete *(drivers+index);
			}
			delete [] drivers;
			d_size++;
			drivers=new Driver* [d_size];
			for(index=0;index<(d_size-1);index++)
			{
				*(drivers+index)=new Driver;
				*(*(drivers+index))=*(*(temp+index));
			}
			*(*(drivers+index))=driver;
		}
		else
		{
			d_size++;
			drivers=new Driver* [d_size];
			*drivers=new Driver;
			**drivers=driver;
		}
	}
	else 
		return false;
}
	bool TMS::remove_driver(Driver &driver)
{
	if(d_size>0)
	{ 
		int index=0;
		int index1=0;
		Driver** temp;
		temp=new Driver* [d_size];
		for(index=0;index<d_size;index++)
		{
			*(temp+index)=new Driver;
			*(*(temp+index))=*(*(drivers+index));
		}
		for(index=0;index<d_size;index++)
		{
			delete *(drivers+index);
		}
		delete [] drivers;
		d_size--;
		drivers=new Driver* [d_size];
		for(index=0,index1=0;index<d_size;index1++)
		{
			if((*(temp+index))->get_dId()!=driver.get_dId())
			{
				*(*(drivers+index))=*(*(temp+index1));
				index++;
			}
		}
	}
	return false;
}
	bool TMS::add_vehicle(Vehicle &vehicle)
{
	if(v_size<20)
	{ 
		int index=0;
		if(v_size>0)
		{ 
			for(index=0;index<v_size;index++)
			{
				if((*(vehicles+index))->get_vId()==vehicle.get_vId())
				{
					cout<<endl<<"Vehicle Already added.";
					return false;
				}
			}
			Vehicle** temp;
			temp=new Vehicle* [v_size];
			for(index=0;index<v_size;index++)
			{
				*(temp+index)=new Vehicle;
				*(*(temp+index))=*(*(vehicles+index));
			}
			for(index=0;index<v_size;index++)
			{
				delete* (vehicles+index);
			}
			delete [] vehicles;
			v_size++;
			vehicles=new Vehicle* [v_size];
			for(index=0;index<(v_size-1);index++)
			{
				*(vehicles+index)=new Vehicle;
				*(*(vehicles+index))=*(*(temp+index));
			}
			*(*(vehicles+index))=vehicle;
		}
		else
		{
			v_size++;
			vehicles=new Vehicle* [v_size];
			*vehicles=new Vehicle;
			**vehicles=vehicle;
		}
	}
	else 
		return false;
}
	bool TMS::remove_vehicle(Vehicle &vehicle)
{
	if(v_size>0)
	{ 
		int index=0;
		int index1=0;
		Vehicle** temp;
		temp=new Vehicle* [v_size];
		for(index=0;index<v_size;index++)
		{
			*(temp+index)=new Vehicle;
			*(*(temp+index))=*(*(vehicles+index));
		}
		for(index=0;index<v_size;index++)
		{
			delete *(vehicles+index);
		}
		delete [] vehicles;
		v_size--;
		vehicles=new Vehicle* [v_size];
		for(index=0,index1=0;index<v_size;index1++)
		{
			if((*(temp+index))->get_vId()!=vehicle.get_vId())
			{
				*(*(vehicles+index))=*(*(temp+index1));
				index++;
			}
		}
	}
	return false;
}
	void TMS::print_customers()
{
	int index=0;
	cout<<endl<<"The Customers Registered are = ";
	for(index=0;index<c_size;index++)
	{
		(*(customers+index))->print();
		cout<<endl;
	}
}
	void TMS::print_drivers()
{
	int index=0;
	cout<<endl<<"The Drivers Registered are = ";
	for(index=0;index<d_size;index++)
	{
		(*(drivers+index))->print();
		cout<<endl;
	}
}
	void TMS::print_vehicles()
{
	int index=0;
	cout<<endl<<"The Vehicles Registered are = ";
	for(index=0;index<v_size;index++)
	{
		(*(vehicles+index))->print();
		cout<<endl;
	}
}
	void TMS::print_vehicle(Vehicle &vehicle)
{
	int index=0;
	for(index=0;index<v_size;index++)
	{
		if((*(vehicles+index))->get_vId()==vehicle.get_vId())
		{
			(*(vehicles+index))->print();
			cout<<endl;
		}
	}
}
	void TMS::print_customer(int id)
{
	int index=0;
	for(index=0;index<c_size;index++)
	{
		if((*(customers+index))->get_cId()==id)
		{
			(*(customers+index))->print();
			cout<<endl;
		}
	}
}
	void TMS::print_driver(int id)
{
	int index=0;
	for(index=0;index<d_size;index++)
	{
		if((*(drivers+index))->get_dId()==id)
		{
			(*(drivers+index))->print();
			cout<<endl;
		}
	}
}
	void TMS::print_high_ranked_drivers()
{
	int index=0;
	cout<<endl<<"Drivers above Rank 4.5 are ";
	for(index=0;index<d_size;index++)
	{
		if((*(drivers+index))->get_rank()>=4.5)
		{
			(*(drivers+index))->print();
		}
	}
}
	void TMS::print_licensed_drivers()
{
	int index=0;
	cout<<endl<<"Drivers having Multiple Licenses are ";
	for(index=0;index<d_size;index++)
	{
		if((*(drivers+index))->get_lics()>=2)
		{
			(*(drivers+index))->print();
		}
	}
}
	void TMS::print_updated_salary()
{
	int index=0;
	cout<<endl<<"Updated Salaries of Drivers are ";
	for(index=0;index<d_size;index++)
	{
		cout<<endl<<"Driver Id is"<<(*(drivers+index))->get_dId();
		cout<<endl<<"Driver Name is = "<<(*(drivers+index))->get_name();
		cout<<endl<<"Driver's Salary is = "<<(*(drivers+index))->get_salary()<<endl;
	}
}
	bool TMS::service_request(Customer &customer)
{
	int index=0;
	int count=0;
	Date date(3,4,2021);
	mTime time(3,23,10);
	for(index=0;index<c_size;index++)
	{
		if((*(customers+index))->get_cId()==customer.get_cId())
		{
			count++;
			break;
		}
	}
	if(count>0)
	{ 
		int choice=0;
		int dId=0;
		int vId=0;
		char s[10];
		char d[10];
		cout<<endl<<"1.Choose Any one of the following Drivers = "<<endl;
		for(index=0;index<d_size;index++)
		{
			print_d_ranked();
		}
		cin>>dId;
		cout<<endl<<"2.Choose Any one of the following Vehicles = "<<endl;
		for(index=0;index<v_size;index++)
		{
			print_v_ranked();
		}
		cin>>vId;
		cout<<endl<<"Choose The following from now onwards ";
		cout<<endl<<"3.Service Type (!=0 for Ride and 0 for Delivery)";
		cin>>choice;
		cin.ignore();
		cout<<endl<<"4.Source of Service ";
		cin.getline(s,10);
		cout<<endl<<"5.Destination of Service ";
		cin.getline(d,10);
		if(choice)
		{ 
			cout<<endl<<"13.No of passengers ";
			cout<<endl<<"14.Ride Type(intercity or intracity)";
			cout<<endl<<"15.Driver Ranking";
			cout<<endl<<"16.Vehicle Ranking";
			char* type=new char [10];
			strcpy(type,"intercity");
			Ride temp(1,type,4,4,s,d,10,date,time,false,100,customer.get_cId(),dId,vId);
			customer.update_customer_services(temp);
		}
		else
		{
			cout<<endl<<"13.Weight of Goods ";
			cout<<endl<<"14.Type of Goods";
			char* type1=new char [10];
			strcpy(type1,"furniture");
			Delivery temp1(10,type1,s,d,10,date,time,false,100,customer.get_cId(),dId,vId);
			customer.update_customer_services(temp1);
		}
		return true;
	}
	else
	{
		cout<<endl<<"No Such Customer Found.";
		return false;
	}
}
	void TMS::cancel_book(Service &service,Customer &customer)
{
	int index=0;
	int count=0;
	int count1=0;
	for(index=0;index<c_size;index++)
	{
		if((*(customers+index))->get_cId()==customer.get_cId())
		{
			count++;
			break;
		}
	}
	if(count>0)
	{
		for(index=0;index<d_size;index++)
		{
			if((*(drivers+index))->get_dId()==service.get_dId())
			{
				(*(drivers+index))->set_status(1);
			}
		}
		service.set_rate(service.get_rate()*1.5);
		cout<<endl<<"You have to pay some extra charges for cancellation ";
		cout<<endl<<"The charges are = "<<service.get_rate();
	}
}
	void TMS::complete_ride(Service &service)
{
	int index=0;
	int index1=0;
	int count=0;
	for(index=0;index<c_size;index++)
	{
		if(service.get_cId()==(*(*(customers+index))->get_services())->get_cId())
		{
			(*(*(customers+index))->get_services())->set_status(true);
			(*(vehicles+index))->update_vehicle_services(service);
			(*(drivers+index))->update_driver_services(service);
			update_services(service);
			for(index1=0;index1<d_size;index1++)
			{	
				if((*(drivers+index))->get_dId()==service.get_dId())
				{
					(*(drivers+index))->set_status(1);
				}
			}
			count++;
		}
	}

	if(count==0)
		cout<<endl<<"No Such Service Found";
	else
		service.set_status(true);
}
	void TMS::print_same_vehicle_customers()
{
	int index=0;
	int index1=0;
	for(index=0;index<v_size;index++)
	{
		cout<<endl<<"The Customers having Vehicle no. "<<(*(vehicles+index))->get_vId()<<" are "<<endl;
		for(index1=0;index1<s_size;index++)
		{
			if((*(services+index))->get_vId()==(*(vehicles+index))->get_vId())
			{
				print_customer((*(services+index))->get_cId());
			}
		}
	}
}
	void TMS::print_same_date_drivers()
{
	int index=0;
	int index1=0;
	for(index=0;index<d_size;index++)
	{
		cout<<endl<<"The Drivers having completed services on "<<(*(drivers+index))->get_completion_date();
		for(index1=0;index1<d_size;index1++)
		{
			if((*(drivers+index))->get_completion_date()==(*(drivers+index1))->get_completion_date())
			{
				cout<<endl;
				(*(drivers+index))->print();
			}
		}
	}
}
	void TMS::print_date_pending_services(Date &date)
{
	int index=0;
	for(index=0;index<s_size;index++)
	{
		if(((*(services+index))->get_date()==date)&&((*(services+index))->get_status()==false))
		{
			(*(services+index))->print();
		}
	}
}
	void TMS::print_d_ranked()
{
	int index=0;
	int index1=0;
	float* rank=new float [d_size];
	for(index=0;index<d_size;index++)
	{
		rank[index]=(*(drivers+index))->get_rank();
	}
	float temp=0;
	for(index=0;index<d_size;index++)
	{
		for(index1=index;index1<d_size;index1++)
		{
			if(rank[index]<rank[index1])
			{
				temp=rank[index];
				rank[index]=rank[index1];
				rank[index1]=temp;
			}
		}
	}
	for(index=0;index<d_size;index++)
	{
		for(index1=0;index1<d_size;index1++)
		{
			if((rank[index]==(*(drivers+index1))->get_rank())&&((*(drivers+index))->get_status()==1))
			{
				(*(drivers+index))->print();
			}
		}
	}
	delete [] rank;
}
	void TMS::print_v_ranked()
{
	int index=0;
	int index1=0;
	float* rank=new float [v_size];
	for(index=0;index<v_size;index++)
	{
		rank[index]=(*(vehicles+index))->get_rank();
	}
	float temp=0;
	for(index=0;index<v_size;index++)
	{
		for(index1=index;index1<v_size;index1++)
		{
			if(rank[index]<rank[index1])
			{
				temp=rank[index];
				rank[index]=rank[index1];
				rank[index1]=temp;
			}
		}
	}
	for(index=0;index<v_size;index++)
	{
		for(index1=0;index1<v_size;index1++)
		{
			if((rank[index]==(*(vehicles+index1))->get_rank())&&((*(vehicles+index))->get_status()==false))
			{
				(*(drivers+index))->print();
			}
		}
	}
	delete [] rank;
}
	void TMS::print_driver_pending_services(int id)
{
	int index=0;
	for(index=0;index<s_size;index++)
	{
		if(((*(services+index))->get_dId()==id)&&((*(services+index))->get_status()==false))
		{
			(*(services+index))->print();
		}
	}
}
	void TMS::print_cancelled_services(int id)
{
	int index=0;
	for(index=0;index<cs_size;index++)
	{
		if((*(c_services+index))->get_cId()==id)
		{
			(*(c_services+index))->print();
		}
	}
}
	void TMS::menu()
{
	cout<<endl<<"\t\t\t=====================================";
	cout<<endl<<"\t\t\t\"    Transport Management System     \"";
	cout<<endl<<"\t\t\t====================================="<<endl;
	cout<<"1. Add a new Customer "<<endl;
	cout<<"2. Add a Driver"<<endl;
	cout<<"3. Remove a Driver "<<endl;
	cout<<"4. Add a Vehicle "<<endl;
	cout<<"5. Remove a Vehicle "<<endl;
	cout<<"6. Print List of All Customers"<<endl;
	cout<<"7. Print List of All drivers"<<endl;
	cout<<"8. Print complete list of vehicles with details by their category."<<endl;
	cout<<"9. Print complete details and service history of a particular vehicle, (Provide vehicle ID)"<<endl;
	cout<<"10. Print complete history of a particular customer, (Provide customer ID)"<<endl;
	cout<<"11. Print complete history of a driver including services. (Provide driver ID)"<<endl;
	cout<<"12. Print list of all drivers who have ranking above 4.5."<<endl;
	cout<<"13. Print list of all drivers who have multiple licenses and their license information too."<<endl;
	cout<<"14. Print updated salary of all drivers based on their updated ranking."<<endl;
	cout<<"15. Add a Service request (ride or delivery) for a customer. Customer will be provided with a list"; 
	cout<<"of free vehicles and drivers to choose based on their ranking in descending order. The fair for ";
	cout<<"the service should be calculated and displayed to the user."<<endl;
	cout<<"16. When the customer cancels a booking, he will be charged 5% of service fair cost on"; 
	cout<<"cancelation. (Provide service and customer ID). The driver and vehicle status should be ";
	cout<<"updated after cancelation and no record of service should be added in driver and vehicle, but"; 
	cout<<"customer bookings list should be updated."<<endl;
	cout<<"17. Complete a service (Provide service ID). Update Customer, Driver’s, and vehicles service";
	cout<<"record once a service status is completed, and keep that service in Services list too. Customer";	 
	cout<<"should add ranking of a driver and vehicle for a service after completion."<<endl;
	cout<<"18. Print details of all Customers, who used the same vehicle in a ride service on a different date."<<endl;
	cout<<"19. Print the List of all Drivers who completed delivery services on same days."<<endl;
	cout<<"20. Print details of all pending services on a particular date."<<endl;
	cout<<"21. Print details of all pending services of a particular driver."<<endl;
	cout<<"22. Print details of all canceled services by a customer."<<endl;
}
	TMS::~TMS()
{
	if(drivers!=0)
	{
		int index=0;
		for(index=0;index<d_size;index++)
			delete *(drivers+index);
		delete [] drivers;
	}
	drivers=0;
	if(customers!=0)
	{
		int index=0;
		for(index=0;index<c_size;index++)
			delete *(customers+index);
		delete [] customers;
	}
	customers=0;
	if(vehicles!=0)
	{
		int index=0;
		for(index=0;index<v_size;index++)
			delete *(vehicles+index);
		delete [] vehicles;
	}
	vehicles=0;
	if(services!=0)
	{
		int index=0;
		for(index=0;index<s_size;index++)
			delete *(services+index);
		delete [] services;
	}
	services=0;
	if(c_services!=0)
	{
		int index=0;
		for(index=0;index<cs_size;index++)
			delete *(c_services+index);
		delete [] c_services;
	}
	d_size=0;
	c_size=0;
	v_size=0;
	s_size=0;
	cs_size=0;
}