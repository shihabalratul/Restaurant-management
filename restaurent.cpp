#include<bits/stdc++.h>
using namespace std;

class Restaurant 
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];

    int table_num;
	int num_of_items;
	int item_code[12];
	int quantity[12];
	int total_price = 0;
private:
    int total_tax = 0;
    int length;
public:
    void show_menu()
	{
		cout<<setw(28);
		cout<< "MENU"<< endl;
		cout<<setw(31);
		cout<< "----------"<<endl;
		cout<<endl;
		cout<<left<<setfill(' ')<<setw(15)<<"Item Code";
		cout<<left<<setfill(' ')<<setw(33)<<"Item Name";
		cout<<"Item Price"<<endl;
		for(int i = 0; i<length; i++)
		{

			cout<<left<<setfill(' ')<<setw(15)<<food_item_codes[i];
			cout<<left<<setfill(' ')<<setw(33)<<food_item_names[i];
			cout<<food_item_prices[i]<<"/-"<<endl;
		}
		cout<<endl;
	}

	void add_menu()
	{
		cin>> length;

		for(int i = 0; i<length; i++)
		{
			cin>>food_item_codes[i];
			cin.clear();
	    	cin.sync();
			getline(cin, food_item_names[i]);
			cin>> food_item_prices[i];
		}
	}

	void take_order()
	{
		cout<<"Enter Table No :";
		cin>>table_num;
		cout<<"Enter Number of Items :";
		cin>>num_of_items;
		for(int i = 0; i<num_of_items; i++)
		{
			Re_enter:
			cout<<"Enter Item "<<i+1<< " Code :";
			cin>>item_code[i];

			int x = distance(food_item_codes, find(food_item_codes, food_item_codes + length, item_code[i]));
			
			if(x >= length)
			{
				cout<<"Wrong Item Code. Please enter a valid code."<<endl;
				goto Re_enter;
			}
			cout<<"Enter Item "<<i+1<< " Quantity :";
			cin>>quantity[i];
		}
		
	}
	void clean()
	{
		table_num = 0;
		num_of_items = 0;
		item_code[12] = {};
		quantity[12] = {};
		total_price = 0;
	}
	void show_bill()
	{
		cout;
		cout<<right<< setfill(' ')<<setw(57) << "BILL SUMMARY"<< endl;
		cout<<right<<setfill(' ')<<setw(60)<<"------------------"<<endl;
		cout<<endl;
		cout<<"Table No. : "<<table_num<<endl;

		cout<<left<<setfill(' ')<<setw(15)<<"Item Code";
		cout<<left<<setfill(' ')<<setw(33)<<"Item Name";
		//cout<<"Item Price";
		cout<<left<<setfill(' ')<<setw(20)<<"Item Price";
		//cout<<"Item Quantity";
		cout<<left<<setfill(' ')<<setw(20)<<"Item Quantity";
		cout<<"Total Price"<<endl;

		for(int i = 0; i<num_of_items; i++)
		{
			int x = distance(food_item_codes, find(food_item_codes, food_item_codes + length, item_code[i]));
			int total = food_item_prices[x]*quantity[i];
			total_price += total;


			cout<<left<<setfill(' ')<<setw(15)<<food_item_codes[x];
			cout<<left<<setfill(' ')<<setw(
			33)<<food_item_names[x];
			cout<<left<<setfill(' ')<<setw(20)<<food_item_prices[x];
			cout<<left<<setfill(' ')<<setw(20)<<quantity[i];
			cout<<total<<endl;
		}

		float tax = (5.0 * total_price)/100.0;
		total_tax += tax;
		cout<<left<<setfill(' ')<<setw(88)<<"TAX";
		cout<<fixed<<setprecision(2)<<tax<<endl;
		cout<<setfill('_')<<setw(100)<<"_"<<endl;

		cout<<left<<setfill(' ')<<setw(88)<<"NET TOTAL";

		cout<<fixed<<setprecision(2)<<tax+total_price<<" Taka"<<endl;
		cout<<endl;

		clean();
	}
};




int main()
{
	Restaurant *menu = new Restaurant;
	menu->add_menu();
	while(true)
	{
		menu->show_menu();
		menu->take_order();
		menu->show_bill();
	}


		delete menu;
	
	return 0;
}
