// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)
#define REPORT_GENDER showMeGenderSizes(vectorOfWomen,vectorOfMen,mapOfGender)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);
void showMeGenderSizes(vector<Slav *>,vector<Slav *>,map<int,Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);
void genderOfSlavs(Slav *,int,int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;
	int sex=atoi(argv[2]);
	containers(slavs, n);
	adapters(slavs, n);
	genderOfSlavs(slavs,n,sex);


	delete [] slavs;
}
void genderOfSlavs(Slav * slavs,int n,int sex)
{
	
	vector <Slav *> vectorOfMen;
	vector <Slav *> vectorOfWomen;
	map <int,Slav *>mapOfGender;
	
	printf("Gender\n");
	srand(time(NULL));
	int random_place,i=0;
	int *numbers=new int[n];
	do{
	 random_place=rand()%n;
	 if(numbers[random_place]!=1){	
		numbers[random_place]=1;
		if( (slavs+i)->specify()==sex)  vectorOfMen.push_back(slavs+random_place);
		else vectorOfWomen.push_back(slavs+random_place);
		i++;
	 }
	}while(i<n);
	printf("# vector\n");
	REPORT_GENDER;

	for (int i=0;i<2;i++){
		mapOfGender[gender(m)]=*vectorOfMen.begin();
		mapOfGender[gender(f)]=*vectorOfWomen.begin();
	}
	printf("## map\n");
	REPORT_GENDER;

	delete [] numbers;
	numbers=NULL;
	
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	//vector <Slav *> vectorOfGender;
	//map <int,vector<Slav *> *>mapOfGender;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");
	// Umieść Słowian w losowej kolejności w wektorze.

	srand(time(NULL));
	int random_place,i=0;
	int *numbers=new int[n];

	/*vectorOfSlavs.push_back(0); 
	for(int i=0;i<n;i++){
		int position=rand()%vectorOfSlavs.size();
		vectorOfSlavs.insert(vectorOfSlavs.begin()+position,slavs+i);
	}vectorOfSlavs.pop_back();*/

	do{
	 random_place=rand()%n;
	 if(numbers[random_place]!=1){	
		numbers[random_place]=1;
		vectorOfSlavs.push_back(slavs+random_place);
		i++;
	 }
	}while(i<n);
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	for(vector<Slav *>::iterator j =vectorOfSlavs.begin(); j!=vectorOfSlavs.end(); j++)
        cout<<(**j).description();
	cout<<endl;
	delete [] numbers;
	numbers=NULL;

	REPORT_CONTAINERS;
	printf("## set\n");
	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for (int i=0;i<n;i++){
		setOfSlavs.insert(vectorOfSlavs[i]); 
	}


	REPORT_CONTAINERS;
	printf("## map\n");
	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór

	set<Slav*>::iterator it_set=setOfSlavs.begin();
	set<Slav*>::iterator it=setOfSlavs.end();
	it--;
	int j=1;
	while(it_set!=   setOfSlavs.end()   ){
		
		mapOfSlavs[*it_set]= (*it );

		setOfSlavs.erase(*it_set);
		setOfSlavs.erase(*it);
		
		it_set=setOfSlavs.begin();
		it=setOfSlavs.begin();
		
		for(int i=0;i<(n-1-j-j)  ;i++){it++;}
		j++;
		REPORT_CONTAINERS;
	}	
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	int p=0;
	map<Slav *,Slav *>::iterator it_map=mapOfSlavs.begin();
	while(it_map!=mapOfSlavs.end()){
		cout<<(*it_map).first->description()<<" oraz "<<(*it_map).second->description()<<endl;
		it_map++;
	}

	REPORT_CONTAINERS;
	//	for(vector<Slav *>::iterator it_gen=vectorOfSlavs.begin();it_gen!=vectorOfSlavs.end();it_gen++){
	//		if((**it_gen).vectorOfSlavs->specify()==sex){
	//			vectorOfGender.push_back((**it_gen).vectorOfSlavs);
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.

	for(int i=0;i<n;i++){
		queueOfSlavs.push(slavs+i);				//dlaczego slavs[i] nie działa?
	}

	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.

	while(!queueOfSlavs.empty()){
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}  
  /*	for(int i=0;i<n;i++){
		stackOfSlavs.push(queueOfSlavs.front()-i);  // czy nie moznadostac sie do n-tego 
	}*/												// el-tu kolejki bez usuwania?

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.
	cout<<"Wyswietlanie zweglonych cial: "<<endl;
	while(!stackOfSlavs.empty()){
		cout<<stackOfSlavs.top()->description()<<" ";
		stackOfSlavs.pop();
	}cout<<endl;

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}

void showMeGenderSizes(vector<Slav *>vector_f,vector<Slav *>vector_m, map < int, Slav *> map)
{
	printf("[vector_f_size = %lu,vector_m_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector_f.size(),
		vector_m.size(),
		map.size(),
		Slav::counter());
}