/************
Ryan Biette
Drinks.cpp
************/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
   This program is a rudimentary search for different types of drinks
   The program uses a data file containing each drink recipe and name
   This will be read in and put into an array of structs that can then
   be searched.
*/  

//Ice can be added to drinks. Not part of recipe unless noted.
//Simple drinks included, advanced not so much...


//Place to save favorites/ratings? (put it in the struct?)

//Declare struct for drinks
struct drink {
	string name;	
	string ing_1;
	string ing_2;
	string ing_3;
	string ing_4;
	string garnish;
	string glass;
};

//Declare sentinel value
const string SENTINEL = "-1";

//prototype functions
//void count_drinks(string filename);

int main()
{
	
	string filename = "drinks.txt";
	
	
	//count number of drinks
	ifstream inf;
	inf.open(filename.c_str());
	if ( !inf.is_open())
		cout << "error opening data file!" << endl;	
	
	//count the number of drink recipes
	int count = 0;
	string x;
	while (x != SENTINEL)
	{
		inf >> x;
		if (x == "~")
			count++;	
	}		
	
	inf.close();	//close file


//reading info in
	//pointer to a array of drinks
	drink* recipe_array;
	//declare dynamic array
	recipe_array = new drink[count];	

	ifstream fin;
	fin.open(filename.c_str());
	if( !fin.is_open())
		cout << "error reopening file!" << endl;

	string tilda, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
	//placeholder var's
	for(int i = 0; i < count; i++) {
		getline(fin, tilda); 
		getline(fin, temp1); //needs to get 75 characters
		recipe_array[i].name = temp1;	//set name	
		getline(fin, temp2);
		recipe_array[i].ing_1 = temp2;	//set ingredient 1
		getline(fin, temp3);
		recipe_array[i].ing_2 = temp3;	//set ingredient 2
		getline(fin, temp4);
		recipe_array[i].ing_3 = temp4;	//set ingredient 3
		getline(fin, temp5);
		recipe_array[i].ing_4 = temp5;	//set ingredient 4
		getline(fin, temp6);
		recipe_array[i].garnish = temp6;	//set garnish
		getline(fin, temp7);
		recipe_array[i].glass = temp7;	//set glass
	}
	
	fin.close();

//search for drink name (make conditional with options from here i.e. "1" -> search)
	string search;	
	cout << "What drink would you like to search for?" << endl;
	cin >> search;

	int j = 0;
	bool match = false;
	while( (match == false) && (j < count)) {
		if(recipe_array[j].name == search) {
			cout << "Found! Here is the recipe:" << endl;
			cout << recipe_array[j].name << endl
			  << "You'll need:" << endl
			  << recipe_array[j].ing_1 << endl
			  << recipe_array[j].ing_2 << endl  
			  << recipe_array[j].ing_3 << endl  
			  << recipe_array[j].ing_4 << endl; 
			cout << "Garnish: " << recipe_array[j].garnish << endl;
			cout << "Glass: " << recipe_array[j].glass << endl;
			match = true;
		}
		else j++;
	}
	if(match == false){
		cout << "Drink not found. Please try again. Capitalize" << 
			" each word. (i.e. Gin Fizz)" << endl;
	}
//Browse
	char choice;
	cout << endl << "Would you like to browse? (y or n)" << endl;
	cin >> choice;
		if(choice == 'n')
			cout << "Okay" << endl;
		if(choice == 'y') {
			cout << "We have these drink recipes: " << endl;
			for(int i = 0; i < count; i++) 
				cout << recipe_array[i].name << endl;
		}

cout << "done\n";
return 0;
}

