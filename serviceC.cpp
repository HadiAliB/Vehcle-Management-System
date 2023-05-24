#include"service.h"
	
	Service::Service()
{
	source=0;
	destination=0;
	distance=0;
	status=false;
	fuelrate=0;
	cId=0;
	dId=0;
	vId=0;
}
	Service::Service(char* source,char* destination,float distance,Date date,mTime time,bool status,float fuelrate,int cid,int did,int vid)
{
	this->source=new char [10];
	strcpy(this->source,source);
	this->destination=new char [10];
	strcpy(this->destination,destination);
	this->distance=distance;
	this->status=status;
	this->fuelrate=fuelrate;
	bookingDate=date;
	bookingTime=time;
	cId=cid;
	dId=did;
	vId=vid;
}
	Service::Service(const Service &service)
{
	source=new char [10];
	strcpy(source,service.source);
	destination=new char [10];
	strcpy(destination,service.destination);
	distance=service.distance;
	status=service.status;
	fuelrate=service.fuelrate;
	bookingDate=service.bookingDate;
	bookingTime=service.bookingTime;
	cId=service.cId;
	dId=service.dId;
	vId=service.vId;
}
	void Service::set_source(char* source)
{
	if(this->source!=0)
		delete [] this->source;
	this->source=new char [10];
	strcpy(this->source,source);
}
	void Service::set_destination(char* destination)
{
	if(this->destination!=0)
		delete [] this->destination;
	this->destination=new char [10];
	strcpy(this->destination,destination);
}
	void Service::set_distance(float distance)
{
	this->distance=distance;
}
	void Service::set_date(Date date)
{
	bookingDate=date;
}
	void Service::set_time(mTime time)
{
	bookingTime=time;
}
	void Service::set_status(bool status)
{
	this->status=status;
}
	void Service::set_rate(float fuelrate)
{
	this->fuelrate=fuelrate;
}
	void Service::set_cId(int cid)
{
	cId=cid;
}
	void Service::set_dId(int did)
{
	dId=did;
}
	void Service::set_vId(int vid)
{
	vId=vid;
}
	char* Service::get_source()
{
	return source;
}
	char* Service::get_destination()
{
	return destination;
}
	float Service::get_distance()
{
	return distance;
}
	Date Service::get_date()
{
	return bookingDate;
}
	mTime Service::get_time()
{
	return bookingTime;
}
	bool Service::get_status()
{
	return status;
}
	float Service::get_rate()
{
	return fuelrate;
}
	int Service::get_cId()
{
	return cId;
}
	int Service::get_dId()
{
	return dId;
}
	int Service::get_vId()
{
	return vId;
}
	ostream & operator <<(ostream &out,const Service &service)
{
	out<<"The Source of Service is = "<<service.source<<endl;
	out<<"The Dstination of Service is = "<<service.destination<<endl;
	out<<"The Distance of Service is = "<<service.distance<<endl;
	out<<"The Date of Service is = "<<service.bookingDate<<endl;
	out<<"The Time of Service is = "<<service.bookingTime<<endl;
	out<<"The Status of Service is = ";
	if(service.status)
		cout<<"Complete"<<endl;
	else
		cout<<"incomplete"<<endl;
	out<<"The Fuel Rate of Service is = "<<service.fuelrate<<endl;
	out<<"The Customer Id is = "<<service.cId;
	out<<"The Driver Id is = "<<service.dId;
	out<<"The Vehicle Id is = "<<service.vId;
	return out;
}	
	ofstream & operator <<(ofstream &out,Service &service)
{
	out<<service.source<<endl;
	out<<service.destination<<endl;
	out<<service.distance<<endl;
	out<<service.bookingDate<<endl;
	out<<service.bookingTime<<endl;
	out<<service.status<<endl;
	out<<service.fuelrate<<endl;
	out<<service.cId;
	out<<service.dId;
	out<<service.vId;
	return out;
}
	istream & operator >>(istream &in,Service &service)
{
	in>>service.source;
	in>>service.destination;
	in>>service.distance;
	in>>service.bookingDate;
	in>>service.bookingTime;
	in>>service.status;
	in>>service.fuelrate;
	in>>service.cId;
	in>>service.dId;
	in>>service.vId;
	return in;
}	
	ifstream & operator >>(ifstream &in,Service &service)
{
	in>>service.source;
	in>>service.destination;
	in>>service.distance;
	in>>service.bookingDate;
	in>>service.bookingTime;
	in>>service.status;
	in>>service.fuelrate;
	in>>service.cId;
	in>>service.dId;
	in>>service.vId;
	return in;
}
	void Service::operator =(const Service &service1)
{
	if(source!=0)
		delete [] source;
	source=new char [10];
	strcpy(source,service1.source);
	if(destination!=0)
		delete [] destination;
	destination=new char [10];
	strcpy(destination,service1.destination);
	distance=service1.distance;
	status=service1.status;
	fuelrate=service1.fuelrate;
	bookingDate=service1.bookingDate;
	bookingTime=service1.bookingTime;
	cId=service1.cId;
	dId=service1.dId;
	vId=service1.vId;
}
	void Service::printf(ofstream &out)
{
	out<<this;
}
	void Service::fin(ifstream &in)
{
	in>>*this;
}
	void Service::print()
{
	cout<<endl<<"The Service Information is given below "<<endl<<this;
}
	Service::~Service()
{
	if(source!=0)
		delete source;
	source=0;
	if(destination!=0)
		delete destination;
	destination=0;
	distance=0;
	status=false;
	fuelrate=0;
	cId=0;
	dId=0;
	vId=0;
}
	Ride::Ride()
{
	noofPassengers=0;
	rideType=0;
	DriverRanking=0;
	VehicleRanking=0;
}
	Ride::Ride(int no,char* type,float d_rank,float v_rank,char* source,char* destination,float distance,Date date,mTime time,bool status,float fuelrate,int cid,int did,int vid):Service(source,destination,distance,date,time,status,fuelrate,cid,did,vid)
{
	noofPassengers=no;
	rideType=new char [10];
	strcpy(rideType,type);
	DriverRanking=d_rank;
	VehicleRanking=v_rank;
}
	void Ride::set_passengers(int no)
{
	noofPassengers=no;
}
	void Ride::set_type(char* type)
{
	if(rideType!=0)
		delete [] rideType;
	rideType=new char [10];
	strcpy(rideType,type);
}
	void Ride::set_d_rank(float d_rank)
{
	DriverRanking=d_rank;
}
	void Ride::set_v_rank(float v_rank)
{
	VehicleRanking=v_rank;
}
	ostream& operator <<(ostream &out,const Ride &ride)
{
	out<<endl<<"The No of Passengers is = "<<ride.noofPassengers;
	out<<endl<<"The Type of Ride is = "<<ride.rideType;
	out<<endl<<"The Ranking Of Driver is = "<<ride.DriverRanking;
	out<<endl<<"The Ranking of Vehicle is = "<<ride.VehicleRanking;
	return out;
}	
	ofstream& operator <<(ofstream &out,Ride &ride)
{
	out<<endl<<ride.noofPassengers;
	out<<endl<<ride.rideType;
	out<<endl<<ride.DriverRanking;
	out<<endl<<ride.VehicleRanking;
	return out;
}
	istream& operator >>(istream &in,Ride &ride)
{
	in>>ride.noofPassengers;
	in>>ride.rideType;
	in>>ride.DriverRanking;
	in>>ride.VehicleRanking;
	return in;
}	
	ifstream& operator >>(ifstream &in,Ride &ride)
{
	in>>ride.noofPassengers;
	in>>ride.rideType;
	in>>ride.DriverRanking;
	in>>ride.VehicleRanking;
	return in;
}
	Ride Ride::operator =(const Ride &ride)
{
	Service::operator=(ride);
	noofPassengers=ride.noofPassengers;
	if(rideType!=0)
		delete [] rideType;
	rideType=new char [10];
	strcpy(rideType,ride.rideType);
	DriverRanking=ride.DriverRanking;
	VehicleRanking=ride.VehicleRanking;
	return *this;
}
	void Ride::printf(ofstream &out)
{
	Service::printf(out);
	out<<this;
}
	void Ride::fin(ifstream &in)
{
	Service::fin(in);
	in>>*this;
}
	void Ride::print()
{
	Service::print();
	cout<<endl<<"The Ride Information is given below "<<this;
}
	Ride::~Ride()
{
	noofPassengers=0;
	if(rideType!=0)
		delete [] rideType;
	rideType=0;
	DriverRanking=0;
	VehicleRanking=0;
}
	Delivery::Delivery()
{
	goodsWeight=0;
	goodsType=0;
}
	Delivery::Delivery(float weight,char* type,char* source,char* destination,float distance,Date date,mTime time,bool status,float fuelrate,int cid,int did,int vid):Service(source,destination,distance,date,time,status,fuelrate,cid,did,vid)
{
	goodsWeight=weight;
	goodsType=new char [10];
	strcpy(goodsType,type);
}
	void Delivery::set_g_weight(float weight)
{
	goodsWeight=weight;
}
	void Delivery::set_g_type(char* type)
{
	if(goodsType!=0)
		delete [] goodsType;
	goodsType=new char [10];
	strcpy(goodsType,type);
}
	float Delivery::get_g_weight()
{
	return goodsWeight;
}
	char* Delivery::get_g_type()
{
	return goodsType;
}
	ostream & operator <<(ostream &out,const Delivery &delivery)
{
	out<<"The Weight of Goods is = "<<delivery.goodsWeight;
	out<<"The Type of Goods is = "<<delivery.goodsType;
	return out;
}	
	ofstream & operator <<(ofstream &out,Delivery &delivery)
{
	out<<delivery.goodsWeight;
	out<<delivery.goodsType;
	return out;
}
	istream & operator >>(istream &in,Delivery &delivery)
{
	in>>delivery.goodsWeight;
	in>>delivery.goodsType;
	return in;
}
	ifstream & operator >>(ifstream &in,Delivery &delivery)
{
	in>>delivery.goodsWeight;
	in>>delivery.goodsType;
	return in;
}
	void Delivery::printf(ofstream &out)
{
	Service::printf(out);
	out<<this;
}	
	void Delivery::fin(ifstream &in)
{
	Service::fin(in);
	in>>*this;
}
	Delivery Delivery::operator =(const Delivery &delivery)
{
	goodsWeight=delivery.goodsWeight;
	if(goodsType!=0)
		delete [] goodsType;
	goodsType=new char [10];
	strcpy(goodsType,delivery.goodsType);
	return *this;
}
	void Delivery::print()
{
	Service::print();
	cout<<endl<<"The Delivery Information is given below "<<this;
}
	Delivery::~Delivery()
{
	if(goodsType!=0)
		delete [] goodsType;
	goodsWeight=0;
	goodsType=0;
}