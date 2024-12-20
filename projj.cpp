#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctime>
#include<string>
#include<stdlib.h>
#include <cstdlib>
#include <string>
#include<conio.h>
//#include"funcstime"
using namespace std;

void Option();
void GoOption(string option_case);
void MoreOption();

void ChangeToMiladi(int year,int month,int day); //tabdil shamsi be miladi.
void GoNextDay();    //tarikh ros baid.
void BackAgoDay();  //tarikh roz ghabl.
void GoToday();    //tarikh emroz ro az sistem migere.

void ReadEventYM();
void NewTask();
void ReadTask();
void TaskOfFuture();
void TaskDontDone();
void SearchTask(string search_case);
void NewEventToday(string event);
void NewEventWeekly(string event);
void NewEventMonthy(string event);
void NewEventYearly(string event);
void ReadEvent();
void EventOfFuture();
void EventOfFutureY();
void Searchevent(string search_case);
void RemoveEventT(string remove_case, string S);
void RemoveEventY(string remove_case, string S);



int StringToInteger(string number_task);



int year,month,day,daykey,date;


int main(){
  
  GoToday();
  
  ChangeToMiladi(year,month,day);
  ReadEventYM();
  ReadEvent();
  ReadTask();
  Option();
  
  return 0;
}


void GoToday(){
	
	time_t now=time(0);
	
	long int secend_long=now;
	year=1348;
	month=10;
	day=11;
	
	
  
	while(secend_long>31708800){
	
		if(secend_long>=31536000 && year%4!=3){
			year++;
			secend_long-=31536000;
		}
		
		else if(secend_long>=31622400 && year%4==3){
			year++;
			secend_long-=31622400;
		}	
	}
	
	
	while(secend_long>2764800){
		switch (month){
      
      case 1: case 2: case 3:
      case 4: case 5: case 6:
      
        if(secend_long>=2678400){
          secend_long-=2678400;
          month++;
        }
        break;
      
      
      case 7: case 8: case 9:
      case 10: case 11:
      if (secend_long>=2592000){
        secend_long-=2592000;
        month++;
      } 
        break;  
    
      case 12:
        if(secend_long>=2592000 && year%4==3){
        	secend_long-=2592000;
        	month=1;
        	year++;
        }
        
        else if(secend_long>=2505600 && year%4!=3){
        	secend_long-=2505600;
        	month=1;
        	year++;
        	}
    	} 
		 
	}


	while(secend_long>=86400){
		day++;
		secend_long-=86400;
		
		if(day>=29){
			
		switch (month){
			
			case 1: case 2: case 3:
      		case 4: case 5: case 6:
      
        		if(day==32){
          		
          			day=1;
          			month++;
        	}
        		break;
      
      
      		case 7: case 8: case 9:
      		case 10: case 11:
      			if (day==31){
        			day=1;
        			month++;
      	} 
       			 break;  
    
      		case 12:
        		if(day==31 && year%4==3){
        			day=1;
        			month=1;
        			year++;
       		}
        
        		else if(day==30 && year%4!=3){
        			day=1;
        			month=1;
        			year++;
        	}
    	} 
    	
		 
	}
	
   }
}


void Option(){
	
  cout<<endl<<"write a command and press \"Enter\" "<<endl<<endl;
  cout<<"N:\t"<<"Next day."<<endl;
  cout<<"P:\t"<<"Previous day."<<endl;
  cout<<"NW:\t"<<"Go next week."<<endl;
  cout<<"PW:\t"<<"Back ago week."<<endl;
  cout<<"GT:\t"<<"Go Today."<<endl;
  cout<<"NE:\t"<<"New event."<<endl;
  cout<<"NT:\t"<<"New task."<<endl;
  cout<<"EE n:\t"<<"Edit event #n."<<endl;
  cout<<"ET n:\t"<<"Edit task #n."<<endl;
  cout<<"MT n:\t"<<"Mark task #n as done."<<endl;
  cout<<"DE n:\t"<<"Delete event #n."<<endl;
  cout<<"DT n:\t"<<"Delete task #n."<<endl;
  cout<<"M "<<"      More option."<<endl;
  cout<<">>>MT1 "<<endl;
  
  string option_case;
  cin>>option_case;

  GoOption(option_case);
  
}


void MoreOption(){
	
	system("CLS");
	cout<<'\t'<<' '<<year<<'/'<<month<<'/'<<day<<endl;
	cout<<"   -----------------------"<<endl;
	cout<<endl<<"GD\t"<<"Go to desired date:"<<endl;
	cout<<"TF:\t"<<"Show Tasks of future."<<endl;
	cout<<"EF:\t"<<"Show Event of future (daily and weekly)."<<endl;
	cout<<"EYF:\t"<<"Show Event of future (yearly and monthy)."<<endl;
	cout<<"TD:\t"<<"Show Tasks dont Done."<<endl;
	cout<<"SE:\t"<<"Search event."<<endl;
	cout<<"ST:\t"<<"Search task."<<endl;
	
	
	
	
	string more_option_case;
	cin>>more_option_case;
	
	if(more_option_case=="GD"){
		
		cout<<endl<<"Enter your date:(year,month,day) :"<<endl;
		cin>>year>>month>>day;
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
	
	else if(more_option_case=="TF"){
		system("CLS");
		cout<<endl<<"         Task of future:"<<endl<<endl;
		
		TaskOfFuture();
		cout<<endl;
		for(int i=0;i<65;i++) cout<<'*';
		cout<<endl<<endl<<"Press key to back calender."<<endl;
		getch();
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
	
	else if(more_option_case=="TD"){
		
		system("CLS");
		cout<<endl<<"         Task dont Done:"<<endl<<endl;
		
		TaskDontDone();
		cout<<endl;
		for(int i=0;i<65;i++) cout<<'*';
		cout<<endl<<endl<<"Press key to back calender."<<endl;
		getch();
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
	else if(more_option_case=="ST"){
		
		string search_case;
		cout<<"Enter your key word:"<<endl;
		cin>>search_case;
		system("CLS");
		SearchTask(search_case);
		for(int i=0;i<65;i++) cout<<'*';
		cout<<endl<<endl<<"Press key to back calender."<<endl;
		getch();
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
		else if(more_option_case=="EF"){
		system("CLS");
		cout<<endl<<"         Event of future:"<<endl<<endl;

		EventOfFuture();
		cout<<endl;
		for(int i=0;i<65;i++) cout<<'*';
		cout<<endl<<endl<<"Press key to back calender."<<endl;
		getch();
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
	
	else if(more_option_case=="EYF"){
		system("CLS");
		cout<<endl<<"         Event of future:"<<endl<<endl;

		EventOfFutureY();
		cout<<endl;
		for(int i=0;i<65;i++) cout<<'*';
		cout<<endl<<endl<<"Press key to back calender."<<endl;
		getch();
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
	
	else if(more_option_case=="SE"){
		
		string search_case;
		cout<<"Enter your key word:"<<endl;
		cin>>search_case;
		system("CLS");
		Searchevent(search_case);
		
		system("CLS");
		ChangeToMiladi(year,month,day);
		ReadEventYM();
		ReadEvent();
		ReadTask();
		Option();
	}
	
	 else  {
	 	
 		MoreOption();
  } 
  
}


void RemoveEventY(string remove_case, string S){
	

	
	fstream file,tem;
    file.open("EventYM.txt", ios::in);
    tem.open("Temp.txt",ios::out);
    string event_read;
    string number_event;
    string tarikh;
    string check;
    string St;
   
    
    
    while(!file.eof()){
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    
  			
  			if(remove_case!=event_read ){
  					
  					
  					tem<<number_event<<'$'<<event_read<<'$'<<tarikh<<'$'<<St<<'$';
			  }

				
		}
		
		
		file.close();
		tem.close();
	
		
	fstream te;
    te.open("Temp.txt", ios::in);
    ofstream fil("EventYM.txt",ios::out);
    
    while(!te.eof()){
    	getline(te, number_event, '$');
    	getline(te, event_read, '$'); 
        getline(te, tarikh, '$');
    	getline(te, St, '$');
		
		fil<<number_event<<'$'<<event_read<<'$'<<tarikh<<'$'<<St<<'$';
	}
	
	fil.close();
	te.close();
}


void RemoveEventT(string remove_case, string S){
	
	fstream file,tem;
    file.open("Event.txt", ios::in);
    tem.open("Temp.txt",ios::out);
    string event_read;
    string number_event;
    string tarikh;
    string check;
    string St;
   
    
    
    while(!file.eof()){
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    
  			
  			if(remove_case!=event_read ){
  					
  					
  					tem<<number_event<<'$'<<event_read<<'$'<<tarikh<<'$'<<St<<'$';
			  }

				
		}
		
		
		file.close();
		tem.close();
	
		
	fstream te;
    te.open("Temp.txt", ios::in);
    ofstream fil("Event.txt",ios::out);
    
    while(!te.eof()){
    	getline(te, number_event, '$');
    	getline(te, event_read, '$'); 
        getline(te, tarikh, '$');
    	getline(te, St, '$');
		
		fil<<number_event<<'$'<<event_read<<'$'<<tarikh<<'$'<<St<<'$';
	}
	
	fil.close();
	te.close();
}


void Searchevent(string search_case){
	
	cout<<endl<<"Searching ("<<search_case<<") in Yearly or Monthy Event:"<<endl<<endl;
	fstream file;
    file.open("EventYm.txt", ios::in);
    string event_read;
    string number_event;
    string St;
    string tarikh;
    string check="@@";
    
    int z=1;
    int s=0;
    string forremoveY[40];
    string forremoveT[40];
    
    while(!file.eof()){
    	
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    	
    	if (event_read.find(search_case) != std::string::npos) {	
			
			if(check!=event_read){
				check=event_read;
				cout<<z<<':'<<' '<<St<<'-'<<tarikh<<event_read<<endl;
    			cout<<endl;
    			s=1;		
    			forremoveY[z]=event_read;
    			z++;
    			
			}
    		
		}
    
	}
	
	file.close();
	if(s==1)for(int i=0;i<65;i++)cout<<'*';cout<<endl;
	
	z=1;
    check="@@";	
    fstream fil;
    fil.open("Event.txt", ios::in);
    while(!fil.eof()){
    	
    	getline(fil, number_event, '$');
    	getline(fil, event_read, '$'); 
        getline(fil, tarikh, '$');
    	getline(fil, St, '$');
    	
    	if (event_read.find(search_case) != std::string::npos) {	
			
			if(check!=event_read){
				check=event_read;
				forremoveT[z]=event_read;
				cout<<z<<':'<<' '<<St<<'-';
				if(St=="W"){
					int d=StringToInteger(tarikh);
    		 		switch (d){
    					case 0: cout<<"Saturday"; break;
    					case 1: cout<<"Sunday";   break;
    					case 2: cout<<"Monday";   break;  
    					case 3: cout<<"Tuesday";  break;
    					case 4: cout<<"Wednesday";break;
    					case 5: cout<<"Thursday"; break;
   						case 6: cout<<"Friday";   break;
  					}
				}
				else{
					cout<<tarikh;
				}
				cout<<event_read<<endl;
    			cout<<endl;
    			s=1;		
    			z++;
			}
    		
		}
    
	}
	fil.close();
	
	
	if(s==0){
		cout<<"Not found!"<<endl;
		for(int i=0;i<65;i++) cout<<'*';
		cout<<endl<<"Press key to back calender.";
		getch();
		
	} 
	
	
	
	
	if(s==1){
		
		for(int i=0;i<65;i++) cout<<'*';
		
		cout<<endl<<endl<<"Chose from option:"<<endl;
		cout<<"EE  n  type event:"<<"\tTo edit event."<<endl;
		cout<<"RE  n  type event:"<<"\tTo remove event."<<endl;
		cout<<"B:              "<<"\t To back calender."<<endl;
		string c,type;
		int num;
		cin>>c;
		
		if(c=="EE"){
			cin>>num>>type;
			if(type=="Y"  ||  type=="M"){
				
				
				RemoveEventY(forremoveY[num],type);
				
				if(type=="Y"){
					cout<<endl<<"Enter your event:"<<endl;
					string event;
					getline(cin,event,'.');	
					NewEventYearly(event);
					cout<<endl<<"Process is copelete!"<<endl<<"Press key to back calender."<<endl;
					getch();	
				}
				
				else if(type=="M"){
					cout<<endl<<"Enter your event:"<<endl;
					string event;
					getline(cin,event,'.');	
					NewEventMonthy(event);
					cout<<endl<<"Process is copelete!"<<endl<<"Press key to back calender."<<endl;
					getch();	
				}
					
				
			}
			
			else if(type=="W"  ||  type=="T")	
			
				RemoveEventT(forremoveY[num],type);
				
				if(type=="T"){
					cout<<endl<<"Enter your event:"<<endl;
					string event;
					getline(cin,event,'.');	
					NewEventToday(event);
					cout<<endl<<"Process is copelete!"<<endl<<"Press key to back calender."<<endl;
					getch();
				}
				
				else if(type=="W"){
					cout<<endl<<"Enter your event:"<<endl;
					string event;
					getline(cin,event,'.');	
					NewEventWeekly(event);
					cout<<endl<<"Process is copelete!"<<endl<<"Press key to back calender."<<endl;
					getch();	
				}
		}
		
		
		
		else if(c=="RE"){
			cin>>num>>type;
			if(type=="Y"  ||  type=="M"){
				RemoveEventY(forremoveY[num],type);
				cout<<endl<<"Process is copelete!"<<endl<<"Press key to back calender."<<endl;
				getch();
			}
			else if(type=="W"  ||  type=="T"){
				RemoveEventT(forremoveT[num],type);
				cout<<endl<<"Process is copelete!"<<endl<<"Press key to back calender."<<endl;
				getch();
			}
					
		}
		else {
		
		}	
	}
		
	}
	

void GoOption(string option_case){
  
  if(option_case=="N"){
    system("CLS");
    day++;
    GoNextDay();
    ChangeToMiladi(year,month,day);
    ReadEventYM();
    ReadEvent();
    ReadTask();
    Option();  
  }
  
  
  else if(option_case=="P"){
     system("CLS");
     day--;
     BackAgoDay();
     ChangeToMiladi(year,month,day);
     ReadEventYM();
     ReadEvent();
     ReadTask();
     Option();
   }
  
  
  else if(option_case=="NW"){
  	system("CLS");
  	int z=7-date;
  	for(int i=0;i<z;i++){
  		day++;
  		GoNextDay();
	  }
	ChangeToMiladi(year,month,day);
	ReadEventYM();
	ReadEvent();
	ReadTask();
    Option();
  }
  
  
  else if(option_case=="PW"){
  	system("CLS");
  	int z=date+7;
  	for(int i=0;i<z;i++){
  		day--;
  		BackAgoDay();
	  }
	ChangeToMiladi(year,month,day);
	ReadEventYM();
	ReadEvent();
	ReadTask();
    Option();
  }
  
  else if(option_case=="GT"){
  	system("CLS");
  	
  	GoToday();
	ChangeToMiladi(year,month,day);
	ReadEventYM();
	ReadEvent();
	ReadTask();
    Option();
  }
  
  
  else if(option_case=="NE"){
  	
  	char s;
	string event;
    cout<<"Enter your Event:"<<endl;
    getline(cin,event,'.');
    cout<<endl<<"Enter type of your event:"<<endl;
    cout<<"(T to today)-(W to weekly)-(M to monthy)-(Y to yearly)"<<endl;
    cin>>s;
    if(s=='T'){
    	NewEventToday(event);
    	system("CLS");
    	ChangeToMiladi(year,month,day);
    	ReadEventYM();
    	ReadEvent();
    	ReadTask();
    	Option();
    	
	}
	
	else if(s=='W'){
	    NewEventWeekly(event);
		system("CLS");
    	ChangeToMiladi(year,month,day);
    	ReadEventYM();
    	ReadEvent();
    	ReadTask();
    	Option();
	}
	
	else if(s=='M'){
		NewEventMonthy(event);
		system("CLS");
    	ChangeToMiladi(year,month,day);
    	ReadEventYM();
    	ReadEvent();
    	ReadTask();
    	Option();
	}
	
	else if(s=='Y'){
		NewEventYearly(event);
		system("CLS");
    	ChangeToMiladi(year,month,day);
    	ReadEventYM();
    	ReadEvent();
    	ReadTask();
    	Option();
	}
	
	else{
		
	}
    
  }
  
  
  else if(option_case=="NT"){
  	
    NewTask();
    system("CLS");
    ChangeToMiladi(year,month,day);
    ReadEventYM();
    ReadEvent();
    ReadTask();
    Option();
  }
  
  
  else if(option_case=="EE"){
    int line;
    cin >> line;
  }
  
  
  else if(option_case=="ET"){
    int line;
    cin >> line;
  }
  
  
  else if(option_case=="MT"){
    int line;
    cin >> line;
  }
  
  
  else if(option_case=="DE"){
    int line;
    cin >> line;
  }
  
  
  else if(option_case=="DT"){
    int line;
    cin >> line;
  
  }
  
  
  else if(option_case=="M")
  	MoreOption();
  
  else  {
  	
  		cout<<"Chose from option please! (Error)"<<endl;
   		string option_case;
  		cin>>option_case;

 		 GoOption(option_case);
  } 
  
  
}


void EventOfFutureY(){
	
	int s=0;
	fstream file;
    file.open("EventYM.txt", ios::in);
    string event_read;
    string number_event;
    string tarikh;
    string check;
    string St;
    
    int z=1;
    
    while(!file.eof()){
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10>daykey  &&  St== "Y"  &&  check!=event_read ){
  			
  			check=event_read;
  		
    		cout<<z<<':'<<"(Y)"<<' '<<tarikh<<event_read<<endl<<endl;
    		z++;
    		s=1;
			}	
		}
		file.close();
		cout<<endl;if(s==1)cout<<endl;
	z=1;
	check="@";
	fstream fil;
    fil.open("EventYM.txt", ios::in);	
    
	while(!fil.eof()){
    	getline(fil, number_event, '$');
    	getline(fil, event_read, '$'); 
        getline(fil, tarikh, '$');
    	getline(fil, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10>daykey  &&  St== "M"  &&  check!=event_read ){
  			
  			check=event_read;
  			
    		cout<<z<<':'<<"(M)"<<' '<<tarikh<<event_read<<endl<<endl;
    		z++;
    		s=1;
			}	
		}
		
		fil.close();
		
		if(s==0){
		cout<<"Not exiest event!"<<endl;
		
		
		
		
	}
}


void TaskOfFuture(){
	int s=0;
	fstream file;
    file.open("Task.txt", ios::in);
    string task_read;
    string number_task;
    string statos;
    string tarikh;
    int z=1;
    
    while(!file.eof()){
    	getline(file, number_task, '$');
    	getline(file, task_read, '$'); 
    	getline(file, statos, '$');
        getline(file, tarikh, '$');
    
    	int count=StringToInteger(number_task);
    	
  		if(count/10>daykey){
  			
    		cout<<z<<':'<<' '<<tarikh<<task_read;
    		
    		if(statos=="0") cout<<'\t'<<"Dont Do it!"<<endl;
    		else cout<<"Done!";
    		cout<<endl;
    		z++;
    		s=1;
		}
    
	}
	
	file.close();
	if(s==0) cout<<"Not exiest task!"<<endl;
}


void EventOfFuture(){
	int s=0;
	fstream file;
    file.open("Event.txt", ios::in);
    string event_read;
    string number_event;
    string tarikh;
    string St;
    string check;
    int z=1;
    
    while(!file.eof()){
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10>daykey  &&  St=="W"  &&  check!=event_read ) {
  			check=event_read;
  			
    		cout<<z<<':';
    		int d=StringToInteger(tarikh);
    		 switch (d){
    			case 0: cout<<"Saturday"; break;
    			case 1: cout<<"Sunday";   break;
    			case 2: cout<<"Monday";   break;  
    			case 3: cout<<"Tuesday";  break;
    			case 4: cout<<"Wednesday";break;
    			case 5: cout<<"Thursday"; break;
   				case 6: cout<<"Friday";   break;
  			}
  			cout<<event_read<<endl;
    		z++;
    		s=1;
		}	
	}
	if(s==1) for(int i=0;i<65;i++)  cout<<'*';
	cout<<endl;
	file.close();
	z=1;
	fstream fil;
    fil.open("Event.txt", ios::in);
	 while(!fil.eof()){
    	getline(fil, number_event, '$');
    	getline(fil, event_read, '$'); 
        getline(fil, tarikh, '$');
    	getline(fil, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10>daykey  &&  St=="T" ) {
  		
    		cout<<z<<':'<<' '<<'T'<<event_read<<endl;
  			z++;
    		s=1;
		}	
	}
	
	fil.close();
	if(s==0){
		cout<<"Not exiest event!"<<endl;
	} 
}


void TaskDontDone(){
	int s=0;
	fstream file;
    file.open("Task.txt", ios::in);
    string task_read;
    string number_task;
    string statos;
    string tarikh;
    int z=1;
    
    while(!file.eof()){
    	getline(file, number_task, '$');
    	getline(file, task_read, '$'); 
    	getline(file, statos, '$');
        getline(file, tarikh, '$');
    	int count= StringToInteger(number_task);
    	
  		if(statos=="0"  && count/10 <= daykey){
  			
    		cout<<z<<':'<<' '<<tarikh<<task_read<<endl<<endl;
    		z++;
    		s=1;
		}
	}
	if(s==0) cout<<"Not exiest task!"<<endl;
	file.close();
}


void SearchTask(string search_case){
	cout<<endl<<"Searching ("<<search_case<<") in Task:"<<endl<<endl;
	fstream file;
    file.open("Task.txt", ios::in);
    string task_read;
    string number_task;
    string statos;
    string tarikh;
    int z=1;
    int s=0;
    while(!file.eof()){
    	getline(file, number_task, '$');
    	getline(file, task_read, '$'); 
    	getline(file, statos, '$');
        getline(file, tarikh, '$');
    	
    	
    	if (task_read.find(search_case) != std::string::npos) {	
			
			if(z%2==1){
				
    			cout<<(z+1)/2<<':'<<' '<<tarikh<<task_read;
    			if(statos=="0") cout<<'\t'<<"Dont Do it!"<<endl;
    			else cout<<"Done!";
    			cout<<endl;
    			s=1;
			}			
    		z++;
		}
    
	}
	
	file.close();
	
	if(s==0) cout<<"Not found!"<<endl;
}


void NewEventToday(string event){
	
	string number_event , event_read , tarikh , St;
	int z=0;
	ifstream file("Event.txt",ios::app);
	while(!file.eof()){
		
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
     	getline(file, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10==daykey){
  			if(z<count%10){
  				z=count%10;
			  }
		}
	}
	file.close();
	
	int n=z+1;
	ofstream fil("Event.txt",ios::app);
	
	fil<<daykey*10+n<<'$'<<event<<'$'<<year<<'/'<<month<<'/'<<day<<'$'<<'T'<<'$'<<endl;
	
	fil.close();
	
}


void NewEventYearly(string event){
	
	
	for(long int i=1340;i<1425;i++){
		
		ifstream fil("EventYM.txt",ios::app);
		int z=0;
		while(!fil.eof()){
			string number_event , event_read , tarikh , St;
    		getline(fil, number_event, '$');
    		getline(fil, event_read, '$'); 
        	getline(fil, tarikh, '$');
    		getline(fil, St, '$');
    		int count=StringToInteger(number_event);
    	
  			if(count/10==i*10000+month*100+day){
  				if(z<count%10){
  					z=count%10;
				  }
			}
		}
		fil.close();
	
		int n=z+1;
		ofstream file("EventYM.txt",ios::app);
		
	
		file<<i*100000+month*1000+day*10+n<<'$'<<event<<'$'<<month<<'/'<<day<<'$'<<'Y'<<'$'<<endl;
	
	    file.close();
    }
	
		ofstream filz("EventYM.txt",ios::app);
		filz<<"!!!"<<'$'<<endl<<"!!!"<<'$'<<"!!!"<<'$'<<"!!!"<<'$';
		filz.close();
	
}


void NewEventMonthy(string event){
	
	for(long int i=1340;i<1425;i++){
		
		for(int j=1;j<=12;j++){
			
			int z=0;
			ifstream fil("EventYM.txt",ios::app);
			while(!fil.eof()){
				
				string number_event , event_read , tarikh , St;
    			getline(fil, number_event, '$');
    			getline(fil, event_read, '$'); 
        		getline(fil, tarikh, '$');
    			getline(fil, St, '$');
    			int count=StringToInteger(number_event);
    	
  				if(count/10==i*10000+j*100+day){
  					if(z<count%10){
  						z=count%10;
				  		}
					}
				}
				
			fil.close();
	
			int n=z+1;
			ofstream file("EventYM.txt",ios::app);
			
			file<<i*100000+j*1000+day*10+n<<'$'<<event<<'$'<<day<<'$'<<'M'<<'$'<<endl;
	
	    	file.close();
    	}
			
	}
	
		ofstream filz("EventYM.txt",ios::app);
		filz<<"!!!"<<'$'<<endl<<"!!!"<<'$'<<"!!!"<<'$'<<"!!!"<<'$';
		filz.close();
	
}


void NewTask(){
	
	
	int z=0;
	ifstream fil("Task.txt",ios::app);
	while(!fil.eof()){
		string number_task , task_read , statos, tarikh;
    	getline(fil, number_task, '$');
    	getline(fil, task_read, '$'); 
    	getline(fil, statos, '$');
        getline(fil, tarikh, '$');
    
    	int count=StringToInteger(number_task);
    	
  		if(count/10==daykey){
  			if(z<count%10){
  				z=count%10;
			  }
		}
	}
	fil.close();
	
	int n=z+1;
	ofstream file("Task.txt",ios::app);
	cout<<"Press Your Task :";
	string task;
    getline(cin,task,'.');
	
	file<<daykey*10+n<<'$'<<task<<'$'<<false<<'$'<<year<<'/'<<month<<'/'<<day<<'$'<<endl;
	
	file.close();
}


void NewEventWeekly(string event){
	
	for(int i=date;i<25000;i+=7){
	
		int z=0;
		ifstream fil("Event.txt",ios::app);
		while(!fil.eof()){
			string number_event , event_read , tarikh , St;
    		getline(fil, number_event, '$');
    		getline(fil, event_read, '$'); 
        	getline(fil, tarikh, '$');
    		getline(fil, St, '$');
    		int count=StringToInteger(number_event);
    	
  			if(count/10==i){
  				if(z<count%10){
  					z=count%10;
				  }
			}
		}
		fil.close();
	
		int n=z+1;
		ofstream file("Event.txt",ios::app);
		
	
		file<<i*10+n<<'$'<<event<<'$'<<date<<'$'<<'W'<<'$'<<endl;
	
	    file.close();
    }
	
	
	
}


void ReadEvent(){
	
	fstream file;
    file.open("Event.txt", ios::in);
    string event_read;
    string number_event;
    string tarikh;
    string St;
    int z=1;
    while(!file.eof()){
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10==daykey){
    		cout<<z<<':'<<event_read<<'\t'<<St<<endl<<endl;
    		z++;
		}

	}
	file.close();
	cout<<endl;
}


void ReadEventYM(){
	
	fstream file;
    file.open("EventYM.txt", ios::in);
    string event_read;
    string number_event;
    string tarikh;
    string St;
    int z=1;
    int s=0;
    cout<<"< Event >"<<endl<<endl;
    
    
    while(!file.eof()){
    	getline(file, number_event, '$');
    	getline(file, event_read, '$'); 
        getline(file, tarikh, '$');
    	getline(file, St, '$');
    	int count=StringToInteger(number_event);
    	
  		if(count/10==year*10000+month*100+day){
    		cout<<z<<':'<<event_read<<'\t'<<St<<endl<<endl;
    		z++;
    		s=1;
		}

	}
	file.close();
	if(s==1) for(int i=0;i<20;i++) cout<<'-';
	cout<<endl;
	
}


void ReadTask(){

	fstream file;
    file.open("Task.txt", ios::in);
    string task_read;
    string number_task;
    string statos;
    string tarikh;
    
    cout<<"< Task >"<<endl;
    
    
    while(!file.eof()){
    	getline(file, number_task, '$');
    	getline(file, task_read, '$'); 
    	getline(file, statos, '$');
        getline(file, tarikh, '$');
    
    	int count=StringToInteger(number_task);
    	
  		if(count/10==daykey){
  			
    		cout<<count%10<<':'<<task_read;
    		
    		if(statos=="0") cout<<'\t'<<"Dont Do it!"<<endl;
    		else cout<<"Done!";
    		cout<<endl;
		}
    
	}
	cout<<endl;
	file.close();
	for(int i=0;i<65;i++){
		cout<<'*';
	}
	cout<<endl;
	
}
    
   
int StringToInteger(string number_task){
   	
	int number=0;
	
	for(int i=0;number_task[i]!='\0';i++){
		
		number*=10;
		switch (number_task[i]){
			case '0':
				number+=0;break;
			case '1':
				number+=1;break;			
			case '2':
				number+=2;break;
			case '3':
				number+=3;break;
			case '4':
				number+=4;break;
			case '5':
				number+=5;break;
			case '6':
				number+=6;break;
			case '7':
				number+=7;break;
			case '8':
				number+=8;break;
			case '9':
				number+=9;break;
		}
	}
	
	return number;
   }


void GoNextDay(){
	
  switch(month){
    case 1: case 2: case 3:
    case 4:  case 5: case 6:
      if(day==32){
        day=1;
        month++;
        break;
      }
      
      
    case 7: case 8: case 9:
    case 10:case 11:
      if(day==31){
        day=1;
        month++;
        break;
      }
        
    case 12:
      if(day==30 && year%4!=3){
        day=1;
        month=1;
        year++;
      }
      if(day==31 && year%4==3){
        day=1;
        month=1;
        year++;
      }  
	  break;    
  }
}


void BackAgoDay(){
	
  switch(month){
    case 2: case 3:case 4:
    case 5: case 6:case 7:
      if(day==0){
        day=31;
        month--;
        break;
      }
      
      
    case 8: case 9: case 10:
    case 11:case 12:
      if(day==0){
        day=30;
        month--;
        break;
      }
        
    case 1:
      if(day==0 && (year-1)%4!=3){
        day=29;
        month=12;
        year--;
      }
      if(day==0 &&( year-1)%4==3){
        day=29;
        month=12;
        year--;
      }      
  }
}


void ChangeToMiladi(int year,int month,int day){
  
  
  ofstream p("Task.txt",ios::app); //baraye baz kardan file baraye avalin ejra.
  p.close();
   ofstream p3("Temp.txt",ios::app); //baraye baz kardan file baraye avalin ejra.
  p3.close();
  ofstream p1("Event.txt",ios::app); //baraye baz kardan file baraye avalin ejra.
  p1.close();
  ofstream p2("EventYM.txt",ios::app); //baraye baz kardan file baraye avalin ejra.
  p2.close();
    
  int daylong=0;
  
  for(int i=1340;i<year;i++){
    daylong+=365;
    if(i%4==3){
      daylong++;
    }
  }
  
  for(int i=1;i<month;i++){
    if(i<=6){
      daylong+=31;
    }
    
    else if(i<=11){
      daylong+=30;
      
    }
  }
  
  daylong+=day-1;
  
  date=(daylong+4+6)%7;
  daykey=daylong+3;
  
  int year_miladi=1961;
  int month_miladi=3;
  int day_miladi=21;
  
  while(daylong>366){
    year_miladi++;
    daylong-=365;
    if(year_miladi%4==0){
      daylong--;
    }  
  }
  
  
  while(daylong>32){
  
    switch (month_miladi){
      
      case 1: case 3: case 5:
      case 7: case 8: case 10:
      case 12:
        if(daylong-31>0){
          daylong-=31;
          month_miladi++;
        }
        break;
      
        
        
      case 4: case 6:
      case 9: case 11:
      if (daylong-30>0){
        daylong-=30;
        month_miladi++;
      } 
        break;  
    
      case 2:
        if(daylong-28>0){
        daylong-=28;
        }
        if(year_miladi%4==0){
          daylong--;
        }
        month_miladi++;
        break;
      default:
        break;
    }  
    
  if(month_miladi>12){
    month_miladi-=12;
    year_miladi++;
  }
  }
  day_miladi+=daylong;
  
  if(month_miladi>12){
    month_miladi-=12;
    year_miladi++;
  }
  
  if(day_miladi>28){
      switch (month_miladi){
      
      case 1: case 3: case 5:
      case 7: case 8: case 10:
      case 12:
        if(day_miladi-31>0){
          day_miladi-=31;
          month_miladi++;
        }
        break;
      
      case 4: case 6:
      case 9: case 11:
        if (day_miladi-30>0){
          day_miladi-=30;
          month_miladi++;
        }
        break;   
      
      case 2:
        if(day_miladi-28>0){
        day_miladi-=28;
        }
        if(year_miladi%4==0){
          day_miladi--;
        }
        month_miladi++;
      
  }
        
  }
  
  if(month_miladi>12){
    month_miladi-=12;
    year_miladi++;
  }

  if(day_miladi==0){
    month_miladi--;
    day_miladi+=29;
  }
  
  

  daylong=daykey-3;
  int year_gamari=1380;
  int month_gamari=10;
  int day_gamari=4;
  
  while(daylong>356){
  	
    year_gamari++;
    daylong-=354;
    
    if( year_gamari%30==2  || year_gamari%30==5  || year_gamari%30==7 
	 || year_gamari%30==10 || year_gamari%30==13 || year_gamari%30==15
	 || year_gamari%30==18 ||year_gamari%30==21  || year_gamari%30==24
	 ||year_gamari%30==26  ||year_gamari%30==29){
	 	
      daylong--;
    }  
  }
  
  
  while(daylong>32){
  
    switch (month_gamari){
      
      case 1: case 3: case 5:
      case 7: case 9: case 11:
     
        if(daylong-30>0){
          daylong-=30;
          month_gamari++;
        }
        break;
      
        
        
      case 2: case 4:
      case 6: case 8:
      case 10:
	  	
      if (daylong-29>0){
        daylong-=29;
        month_gamari++;
      } 
        break;  
    
      case 12:
      	
        if(daylong-30>0 && ((year_gamari-3)%30==2  || (year_gamari-3)%30==5  || (year_gamari-3)%30==7 
	 || (year_gamari-3)%30==10 || (year_gamari-3)%30==13   || (year_gamari-3)%30==16
	 || (year_gamari-3)%30==18 ||(year_gamari-3)%30==21    || (year_gamari-3)%30==24
	 ||(year_gamari-3)%30==26  ||(year_gamari-3)%30==29)){
        daylong-=30;
        month_gamari++;
        }
        else if(daylong>29){
        	daylong-=29;
        	month_gamari++;
		}
       
         
         
      default:
        break;
    }  
    
  if(month_gamari>12){
    month_gamari-=12;
    year_gamari++;
   }
   
  }
  day_gamari+=daylong;
  
  if(year>=1391 &&year<=1418){
  	day_gamari--;
  }
   if(year>=1420){
  	day_gamari--;
  }
 
  if(day_gamari>28){
      switch (month_gamari){
      
      case 1: case 3: case 5:
      case 7: case 9: case 11:
      
        if(day_gamari-30>0){
          day_gamari-=30;
          month_gamari++;
        }
        break;
      
      case 2:
      case 4: case 6:
      case 8: case 10:
      	
        if (day_gamari-29>0){
          day_gamari-=29;
          month_gamari++;
        }
        break;   
        
      case 12:
      	
		if(daylong-30>0 && ((year_gamari-3)%30==2  || (year_gamari-3)%30==5  || (year_gamari-3)%30==7 
	 || (year_gamari-3)%30==10 || (year_gamari-3)%30==13   || (year_gamari-3)%30==16
	 || (year_gamari-3)%30==18 ||(year_gamari-3)%30==21    || (year_gamari-3)%30==24
	 ||(year_gamari-3)%30==26  ||(year_gamari-3)%30==29)){
		 	day_gamari-=30;
		 	month_gamari++;
		 }
		 else if(day_gamari>29){
		 	day_gamari-=29;
		 	month_gamari++;
		 }
  }
  if(month_gamari>12){
    month_gamari-=12;
    year_gamari++;
  }
        
  }
  

  
  cout<<endl;
  switch (date){
    case 0: cout<<"Saturday"<<endl; break;
    case 1: cout<<"Sunday"<<endl;   break;
    case 2: cout<<"Monday"<<endl;   break;  
    case 3: cout<<"Tuesday"<<endl;  break;
    case 4: cout<<"Wednesday"<<endl;break;
    case 5: cout<<"Thursday"<<endl; break;
    case 6: cout<<"Friday"<<endl;   break;
  }
  
  cout<<"Shamsi:    "<<year<<'-'<<month<<'-'<<day<<endl;
  cout<<"Gregorian: "<<year_miladi<<'-'<<month_miladi<<'-'<<day_miladi<<endl;
   cout<<"Hejri:     "<<year_gamari<<'-'<<month_gamari<<'-'<<day_gamari<<endl;
  
  for(int i=0;i<65;i++){
    cout<<'*';
  }
  cout<<endl;
  
}


