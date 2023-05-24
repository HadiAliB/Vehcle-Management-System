#pragma once
#include"info.h"
#include<fstream>

	class Service 
{
	char* source;
	char* destination;
	float distance; //in km
	Date bookingDate;
	mTime bookingTime;
	bool status; // false for pending, true if complete
	float fuelrate;
	int cId; // Customer Id who booked the ride
	int dId; // Driver Id
	int vId; // vehicle Id
	//you can add more members here if required
	//add member functions
 public:
	Service();
	Service(char*,char*,float,Date,mTime,bool,float,int,int,int);
	Service(const Service &);
	void set_source(char*);
	void set_destination(char*);
	void set_distance(float);
	void set_date(Date);
	void set_time(mTime);
	void set_status(bool);
	void set_rate(float);
	void set_cId(int);
	void set_dId(int);
	void set_vId(int);
	char* get_source();
	char* get_destination();
	float get_distance();
	Date get_date();
	mTime get_time();
	bool get_status();
	float get_rate();
	int get_cId();
	int get_dId();
	int get_vId();
	friend ostream & operator <<(ostream &,const Service &);
	friend ofstream & operator <<(ofstream &,Service &);
	friend istream & operator >>(istream &,Service &);
	friend ifstream & operator >>(ifstream &,Service &);
	void operator =(const Service &);
	virtual void printf(ofstream &);
	virtual void fin(ifstream &);
	virtual void print();
	~Service();
};
	class Ride:public Service 
{
	int noofPassengers; // false for pending, true if complete
	char* rideType; // intercity, intracity
	float DriverRanking; // 0 to 5 scale (worst to best)
	float VehicleRanking; // 0 to 5 scale (worst to best)
	//you can add more members here if required
	//add member functions
 public:
	Ride();
	Ride(int,char*,float,float,char*,char*,float,Date,mTime,bool,float,int,int,int);
	void set_passengers(int);
	void set_type(char*);
	void set_d_rank(float);
	void set_v_rank(float);
	friend ostream& operator <<(ostream &,const Ride &);
	friend ofstream& operator <<(ofstream &,Ride &);
	friend istream& operator >>(istream &,Ride &);
	friend ifstream& operator >>(ifstream &,Ride &);
	Ride operator =(const Ride &);
	void printf(ofstream &);
	void fin(ifstream &);
	void print();
	~Ride();
};
	class Delivery:public Service 
{
	float goodsWeight; // Weight of goods in Kg
	char* goodsType; //type of goods food, furniture, petroleum, chemicals, etc.
	//you can add more members here if required
	//add member functions
 public:
	Delivery();
	Delivery(float,char*,char*,char*,float,Date,mTime,bool,float,int,int,int);
	void set_g_weight(float);
	void set_g_type(char*);
	float get_g_weight();
	char* get_g_type();
	friend ostream & operator <<(ostream &,const Delivery &);
	friend ofstream & operator <<(ofstream &,Delivery &);
	friend istream & operator >>(istream &,Delivery &);
	friend ifstream & operator >>(ifstream &,Delivery &);
	void printf(ofstream &);
	void fin(ifstream &);
	Delivery operator =(const Delivery &);
	void print();
	~Delivery();
};
