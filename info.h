#pragma once
#include<iostream>
#include<fstream>

 using namespace std;

	class Name 
{
	char* fName;
	char* lName;
 public:
	Name()
{
	fName=new char [10];
	lName=new char [10];
}
	Name(char* fN, char* lN)
{
	fName=new char [10];
	strcpy(fName,fN);
	lName=new char [10];
	strcpy(lName,lN);
}
	Name(const Name &name)
{
	fName=new char [10];
	strcpy(fName,name.fName);
	lName=new char [10];
	strcpy(lName,name.lName);
}
	void set_fName(char* fN)
{
	if(fName!=0)
		delete [] fName;
	fName=new char [10];
	strcpy(fName,fN);
}	
	void set_lName(char* lN)
{
	if(lName!=0)
		delete [] lName;
	lName=new char [10];
	strcpy(lName,lN);
}
	char* get_fName()
{
	return fName;
}
	char* get_lName()
{
	return lName;
}
	//add following functions //Getter, Setters
	//Destructor, Default Constructor, Copy Constructor,
	friend ostream & operator <<(ostream &out, const Name &n)
{
	out<<"The First Name is = "<<n.fName<<endl;
	out<<"The Last Name is = "<<n.lName<<endl;
	return out;
}
	friend istream & operator >>(istream &in,Name &n)
{
	in>>n.fName;
	in>>n.lName;
	return in;
}
	friend ofstream & operator <<(ofstream &out, const Name &n)
{
	out<<n.fName<<endl;
	out<<n.lName<<endl;
	return out;
}	
	friend ifstream & operator >>(ifstream &in,Name &n)
{
	in>>n.fName;
	in>>n.lName;
	return in;
}
	Name operator =(const Name &name)
{
	if(fName!=0)
		delete [] fName;
	fName=new char [10];
	strcpy(fName,name.fName);
	if(lName!=0)
		delete [] lName;
	lName=new char [10];
	strcpy(lName,name.lName);
	return *this;
}
	~Name()
{
	if(fName!=0)
		delete [] fName;
	if(lName!=0)
		delete [] lName;
	fName=lName=0;
}
};
	/*ostream& operator<<(ostream& out, const Name& n) 
{
	out << n.fName << " " << n.lName << endl;
	return out;
}*/
	class Date
{
	int day;
	int month;
	int year;

 public:
	Date()
{
	day=month=1;
	year=2010;
}
	Date(int d,int m,int y)
{
	day=d;
	month=m;
	year=y;
}
	Date(const Date &date)
{
	day=date.day;
	month=date.month;
	year=date.year;
}
	void set_day(int d)
{
	day=d;
}
	void set_month(int m)
{
	month=m;
}
	void set_year(int y)
{
	year=y;
}
	int get_day()
{
	return day;
}
	int get_month()
{
	return month;
}
	int get_year()
{
	return year;
}
	friend ostream & operator <<(ostream &out, const Date &n)
{
	out<<"The Date is  = "<<n.day<<"/"<<n.month<<"/"<<n.year;
	return out;
}
	friend istream & operator >>(istream &in,Date &n)
{
	in>>n.day;
	in>>n.month;
	in>>n.year;
	return in;
}
	friend ofstream & operator <<(ofstream &out, const Date &n)
{
	out<<n.day<<endl;
	out<<n.month<<endl;
	out<<n.year<<endl;
	return out;
}	
	friend ifstream & operator >>(ifstream &in,Date &n)
{
	in>>n.day;
	in>>n.month;
	in>>n.year;
	return in;
}
	Date operator =(const Date &date)
{
	day=date.day;
	month=date.month;
	year=date.year;
	return *this;
}
	friend bool operator ==(Date date1,Date date2)
{
	if((date1.day==date2.day)&&(date1.month==date2.month)&&(date1.year==date2.year))
		return true;
	else
		return false;
}
	~Date()
{
	day=month=year=0;
}
	//add constructurs getter setters and stream output function, which output date in 
	//given format day / Mon / Year
};
	class mTime
{
	int hour;
	int min;
	int sec;

 public:
	mTime()
{
	hour=min=sec=0;
}
	mTime(int h,int m,int s)
{
	hour=h;
	min=m;
	sec=s;
}
	mTime(const mTime &time)
{
	hour=time.hour;
	min=time.min;
	sec=time.sec;
}
	void set_hour(int h)
{
	if((h<1)||(h>24))
		hour=1;
	else
		hour=h;
}	
	void set_min(int m)
{
	if((m<0)||(m>59))
		min=0;
	else
		min=m;
}	
	void set_sec(int s)
{
	if((s<0)||(s>59))
		sec=0;
	else
		sec=s;
}
	int get_hour()
{
	return hour;
}
	int get_min()
{
	return min;
}
	int get_sec()
{
	return sec;
}
	friend ostream & operator <<(ostream &out, const mTime &n)
{
	out<<"The Date is  = "<<n.hour<<":"<<n.min<<":"<<n.sec;
	return out;
}
	friend istream & operator >>(istream &in,mTime &n)
{
	in>>n.hour;
	in>>n.min;
	in>>n.sec;
	return in;
}
	friend ofstream & operator <<(ofstream &out, const mTime &n)
{
	out<<n.hour<<endl;
	out<<n.min<<endl;
	out<<n.sec<<endl;
	return out;
}	
	friend ifstream & operator >>(ifstream &in,mTime &n)
{
	in>>n.hour;
	in>>n.min;
	in>>n.sec;
	return in;
}
	mTime operator =(const mTime &time)
{
	hour=time.hour;
	min=time.min;
	sec=time.sec;
	return *this;
}
	~mTime()
{
	hour=min=sec=0;
}
	//add constructurs getter setters and stream output function, which output time in 
	//given format Hr : Min: Sec
};
	class Feature
{
	int fId;
	char * description;
	float cost;

 public:
	Feature()
{
	fId=0;
	description=0;
	cost=0;
}
	Feature(int id,char* descrp,float c)
{
	fId=id;
	description=new char [20];
	strcpy(description,descrp);
	cost=c;
}
	Feature(const Feature &feature)
{
	fId=feature.fId;
	description=new char [20];
	strcpy(description,feature.description);
	cost=feature.cost;
}
	void set_fId(int id)
{
	fId=id;
}
	void set_description(char* descrp)
{
	if(description!=0)
		delete [] description;
	description=new char [20];
	strcpy(description,descrp);
}
	void set_cost(float c)
{
	cost=c;
}
	int get_fId()
{
	return cost;
}
	char* get_description()
{
	return description;
}
	float get_cost()
{
	return cost;
}
	friend ostream & operator <<(ostream &out,const Feature &feature)
{
	out<<"The Feature Id is = "<<feature.fId<<endl;
	out<<"The Feature Description is = "<<feature.description<<endl;
	out<<"The Feature Cost is = "<<feature.cost<<endl;
	return out;
}
	friend istream & operator >>(istream &in,Feature &feature)
{
	in>>feature.fId;
	in>>feature.description;
	in>>feature.cost;
	return in;
}
	friend ofstream & operator <<(ofstream &out,const Feature &feature)
{
	out<<feature.fId<<endl;
	out<<feature.description<<endl;
	out<<feature.cost<<endl;
	return out;
}
	friend ifstream & operator >>(ifstream &in,Feature &feature)
{
	in>>feature.fId;
	in>>feature.description;
	in>>feature.cost;
	return in;
}
	Feature operator =(const Feature &feature)
{
	fId=feature.fId;
	if(description!=0)
		delete [] description;
	description=new char [20];
	strcpy(description,feature.description);
	cost=feature.cost;
	return *this;
}
	~Feature()
{
	fId=0;
	if(description!=0)
		delete [] description;
	description=0;
	cost=0;
}
	//you can add more members here if required
	//add member functions
};
	