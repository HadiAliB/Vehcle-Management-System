#pragma once
#include"person.h"
#include"vehicle.h"

	class TMS
{
	Driver** drivers;
	int d_size;
	Customer** customers;
	int c_size;
	Vehicle** vehicles;
	int v_size;
	Service** services;
	int s_size;
	Service** c_services;
	int cs_size;

 public:
	TMS();
	TMS(Driver**,int,Customer**,int,Vehicle**,int,Service**,int);
	TMS(const TMS &);
	void set_drivers(const Driver**,int);
	void set_customers(const Customer**,int);
	void set_vehicles(const Vehicle**,int);
	void set_services(const Service**,int);
	void set_d_size(int);
	void set_c_size(int);
	void set_v_size(int);
	int get_d_size();
	int get_c_size();
	int get_v_size();
	Driver** get_drivers();
	Customer** get_customers();
	Vehicle** get_vehicles();
	Service** get_services();
	bool set_records(string);
	bool update_customer();
	bool update_driver();
	bool update_vehicle();
	bool update_customer_service();
	bool update_driver_service();
	bool update_vehicle_service();
	bool read_customer();
	bool read_driver();
	bool read_vehicle();
	bool read_customer_service();
	bool read_driver_service();
	bool read_vehicle_service();	
	bool add_customer(Customer &);
	bool add_driver(Driver &);
	bool remove_driver(Driver &);
	void print_d_ranked();
	void print_v_ranked();
	bool add_vehicle(Vehicle &);
	bool remove_vehicle(Vehicle &);
	void print_customers();
	void print_drivers();
	void print_vehicles();
	void print_vehicle(Vehicle &);
	void print_customer(int);
	void print_driver(int);
	void print_high_ranked_drivers();
	void print_licensed_drivers();
	void print_updated_salary();
	bool service_request(Customer &);
	void cancel_book(Service &,Customer &);
	bool remove_service(Service& service,Service** &services,int &size)
{
	if(services!=0)
	{ 
		int index=0;
		bool cond_a=0;
		bool cond_b=0;
		bool cond_c=0;
		int count=0;
		for(index=0;index<size;index++)
		{
			cond_a=(*(services+index))->get_cId()==service.get_cId();
			cond_b=(*(services+index))->get_dId()==service.get_dId();
			cond_c=(*(services+index))->get_vId()==service.get_vId();
			if(cond_a&&cond_b&&cond_c)
			{
				int index1=0;
				int index2=0;
				Service** temp;
				for(index1=0;index1<size;index1++)
				{
					**(temp+index)=**(services+index);
				}
				for(index1=0;index1<size;index1++)
				{
					delete *(services+index);
				}
				delete [] services;
				size--;
				for(index1=0,index2=0;index1<size;index2++)
				{
					if(((*(temp+index2))->get_cId()!=service.get_cId())&&((*(temp+index2))->get_dId()!=service.get_dId())&&((*(temp+index2))->get_vId()!=service.get_vId()))
					{
						**(services+index1)=**(temp+index2);
						index1++;
					}
				}
				for(index1=0;index1<(size+1);index1++)
				{
					delete *(temp+index1);
				}
				delete [] temp;
				return true;
			}
		}
	}
	else
		return false;
	return false;
}
	void update_services(Service &service)
{
	if(services!=0)
	{ 
		int index=0;
		Service** temp=new Service* [s_size];
		for(index=0;index<s_size;index++)
		{
			*(temp+index)=new Service;
			**(temp+index)=**(services+index);
		}
		for(index=0;index<s_size;index++)
		{
			delete *(services+index);
		}
		delete [] services;
		s_size++;
		services=new Service* [s_size];
		for(index=0;index<(s_size-1);index++)
		{
			*(services+index)=new Service;
			**(services+index)=**(temp+index);
		}
		*(services+index)=new Service;
		**(services+index)=service;
		for(index=0;index<(s_size-1);index++)
		{
			delete *(temp+index);
		}
		delete [] temp;
	}
	else
	{
		s_size=1;
		services =new Service*;
		*(services)=new Service;
		**(services)=service;
	}
}
	void complete_ride(Service &);
	void print_same_vehicle_customers();
	void print_same_date_drivers();
	void print_date_pending_services(Date &);
	void print_driver_pending_services(int);
	void print_cancelled_services(int);
	void menu();
	~TMS();
};