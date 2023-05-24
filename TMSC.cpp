#include"TMS.h"
#include<Windows.h>
#include<Wingdi.h>

	bool menu_choice(TMS &);
	void font(int);

	int main()
{
	system("Color AF");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	font(52);
	cout<<"Transport Management System"<<endl;
	font(24);
	TMS tms;
	tms.read_customer();
	tms.read_driver();
	tms.read_vehicle();
	tms.read_customer_service();
	tms.read_driver_service();
	tms.read_vehicle_service();
	while(1)
	{ 
		if(!menu_choice(tms))
		{ 
			system("pause");
			return 0;
		}
	}
}
	bool menu_choice(TMS &tms)
{
	system("cls");
	tms.menu();
	//Service** v_history;
	//Service** history;
	int size=1;
	Customer customer1;
	Driver driver1;
	Vehicle vehicle;
	Date m_date(20,6,2021);
	int choice=0;
	while((choice<1)||(choice>23))
	{
		cin>>choice;
	}
	system("cls");
	if(choice==1)
	{
		Name name;
		char* str=new char [10];
		strcpy(str,"hashim");
		name.set_fName(str);
		strcpy(str,"bilal");
		name.set_lName(str);
		Date dob(10,8,2002);
		//Customer customer1;
		customer1.set_cId(1);
		customer1.set_name(name);
		customer1.set_dob(dob);
		if(!tms.add_customer(customer1))
		{
			cout<<endl<<"Customer Could not be Added.";
		}
		system("pause");
		return true;
	}
	else if(choice==2)
	{
		//Driver driver1;
		driver1.set_dId(1);
		char** licenses=new char* [3];
		*(licenses)=new char [10];
		strcpy(*(licenses),"light");
		*(licenses+1)=new char [10];
		strcpy(*(licenses),"Heavy");
		*(licenses+2)=new char [10];
		strcpy(*(licenses),"Both");
		char* str = new char[10];
		strcpy(str,"hashim");
		Name name;
		name.set_fName(str);
		strcpy(str,"bilal");
		name.set_lName(str);
		Date dob(10,8,2002);
		driver1.set_licenses(licenses,3);
		driver1.set_lics(3);
		driver1.set_rank(4.6);
		driver1.set_salary(1000);
		driver1.set_xp(1000);
		driver1.set_status(1);
		driver1.set_name(name);
		driver1.set_dob(dob);
		driver1.set_s_size(0);
		if(!tms.add_driver(driver1))
		{
			cout<<endl<<"Driver Could not be Added.";
		}
		system("pause");
		return true;
	}
	else if(choice==3)
	{
		tms.remove_driver(driver1);
		system("pause");
		return true;
	}
	else if(choice==4)
	{
		char* descrp=new char [10] ;
		descrp="Turbo";
		Feature* features=new Feature [2];
		features->set_fId(1);
		features->set_description(descrp);
		features->set_cost(2000);
		(features+1)->set_fId(2);
		(features+1)->set_description(descrp);
		(features+1)->set_cost(4000);
		char* license=new char [10] ;
		license="intracity";
		char* fueltype=new char [10] ;
		fueltype="Petrol";
		vehicle.set_vId(1);
		vehicle.set_reg(0001);
		vehicle.set_avg(10);
		vehicle.set_lics(license);
		vehicle.set_status(0);
		vehicle.set_fuel(fueltype);
		vehicle.set_rank(4);
		vehicle.set_date(m_date);
		vehicle.set_features(features,2);
		//vehicle.set_service_rec(v_history,1);
		if(!tms.add_vehicle(vehicle))
		{
			cout<<endl<<"Vehicle Could not be Added.";
		}
		system("pause");
		return true;
	}
	else if(choice==5)
	{
		tms.remove_vehicle(vehicle);
		system("pause");
		return true;
	}
	else if(choice==6)
	{
		tms.print_customers();
		system("pause");
		return true;
	}
	
	else if(choice==7)
	{
		tms.print_drivers();
		system("pause");
		return true;
	}
	else if(choice==8)
	{
		tms.print_vehicles();
		system("pause");
		return true;
	}
	else if(choice==9)
	{
		tms.print_customer(1);
		system("pause");
		return true;
	}
	else if(choice==10)
	{
		tms.print_driver(1);
		system("pause");
		return true;
	}
	else if(choice==11)
	{
		tms.print_vehicle(vehicle);
		system("pause");
		return true;
	}
	else if(choice==12)
	{
		tms.print_high_ranked_drivers();
		system("pause");
		return true;
	}
	else if(choice==13)
	{
		tms.print_licensed_drivers();
		system("pause");
		return true;
	}
	else if(choice==14)
	{
		tms.print_updated_salary();
		system("pause");
		return true;
	}
	else if(choice==15)
	{
		tms.service_request(**tms.get_customers());
		return true;
	}
	else if(choice==16)
	{
		tms.cancel_book(**(*tms.get_customers())->get_services(),customer1);
		return true;
	}
	else if(choice==17)
	{
		tms.complete_ride(**(*tms.get_customers())->get_services());
		return true;
	}
	else if(choice==18)
	{
		tms.print_same_vehicle_customers();
		system("pause");
		return true;
	}
	else if(choice==19)
	{
		tms.print_same_date_drivers();
		system("pause");
		return true;
	}
	else if(choice==20)
	{
		tms.print_date_pending_services(m_date);
		system("pause");
		return true;
	}
	else if(choice==21)
	{
		tms.print_driver_pending_services(1);
		system("pause");
		return true;
	}
	else if(choice==22)
	{
		tms.print_cancelled_services(1);
		system("pause");
		return true;
	}
	else
	{
		tms.update_customer();
		tms.update_driver();
		tms.update_vehicle();
		tms.update_customer_service();
		tms.update_driver_service();
		system("pause");
		return false;
	}
}
	void font(int size)
{
	system("Color 4A");
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Lucida Console"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//std::cout << "Font: Consolas, Size: 24\n";
}