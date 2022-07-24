#include <iostream>
#include <string>
#include <fstream>
#include "gate.h"

using namespace std;


//--------------------------------------------------------------HELPER FUNCTIONS

int get_num(string str) {
	int i;
	int count=0;
	for(i=0;i<str.length();i++){
		if(str[i]==' ')
			count++;
	}
	return count;
}


string get_partof_string(string str,int part){
	char buffer[15];
	int i,j;
	for(i=0;i<15;i++)
		buffer[i]='\0';
	
	i=0;
	for(j=0;j<part+1;j++) {
		while(str[i]!=' ' && str[i]!='\0')
		i++;

		i++;
	}

	j=0;
	while(str[i]!=' ' && str[i]!='\0'){
		buffer[j]=str[i];
		i++;
		j++;
	}
	string name=buffer;
	//cout<<buffer<<endl;
	return name;



}




int main() {


	/* first file reading part, determining how many elements are going to be included */ 

	ifstream inFile;
	inFile.open("circuit.txt");
	string inputline,outputline;

	getline(inFile, inputline);
	getline(inFile, outputline);

	int inpnum=get_num(inputline);//number of inputs
	int outpnum=get_num(outputline);//number of outputs
	int othergatesnum=0;
	string line;
	while(getline(inFile, line)){
		if(line[0]=='D')//decoder case
			othergatesnum+=4;
		else
			othergatesnum++;
	}


	int totalgates=othergatesnum+inpnum+outpnum;
	Gate** circuit;
	circuit = new Gate*[totalgates];
	/*second file reading part, data is going to be written */
	ifstream inFile2;
	inFile2.open("circuit.txt");
	getline(inFile2, inputline);
	getline(inFile2, outputline);

	int i,j;
	int count=0;
	for(i=0;i<inpnum;i++){
		circuit[count]= new input;
		circuit[count][0].set_name(get_partof_string(inputline,i));
		count++;	
	}

	while(getline(inFile2, line)){

		if(line[0]=='A' &&    line[1]=='N'       && line[2]=='D'){//and case
			circuit[count]= new andgate;
			circuit[count][0].set_name(get_partof_string(line,0));
			string and1=get_partof_string(line,1);
			string and2=get_partof_string(line,2);
	

			for(i=0;i<count;i++){
				if(and1==circuit[i][0].get_name()){
				
					break;
				}
			}

			for(j=0;j<count;j++){
				if(and2==circuit[j][0].get_name()){
				
					break;
				}
			}
			circuit[count][0].set_input_gate(circuit[i],circuit[j]);



		}
			
		else if(line[0]=='O' &&    line[1]=='R'){//or case

			circuit[count]= new orgate;
			circuit[count][0].set_name(get_partof_string(line,0));
			string or1=get_partof_string(line,1);
			string or2=get_partof_string(line,2);

			for(i=0;i<count;i++){
				if(or1==circuit[i][0].get_name()){
					
					break;
				}
			}

			for(j=0;j<count;j++){
				if(or2==circuit[j][0].get_name()){
				
					break;
				}
			}
			circuit[count][0].set_input_gate(circuit[i],circuit[j]);
			
		}

		else if(line[0]=='N' &&    line[1]=='O' && line[2]=='T'){//not case

			circuit[count]= new notgate;
			circuit[count][0].set_name(get_partof_string(line,0));
			string not1=get_partof_string(line,1);

			for(i=0;i<count;i++){
				if(not1==circuit[i][0].get_name()){
					
					break;
				}
			}
			circuit[count][0].set_input_gate(circuit[i],NULL);

			
		}

		else if(line[0]=='F' &&    line[1]=='L' && line[2]=='I'){//flipflop case

			circuit[count]= new flipflop;
			circuit[count][0].set_name(get_partof_string(line,0));
			string fli1=get_partof_string(line,1);

			for(i=0;i<count;i++){
				if(fli1==circuit[i][0].get_name()){
					
					break;
				}
			}
			circuit[count][0].set_input_gate(circuit[i],NULL);

		}

		else if(line[0]=='D' &&    line[1]=='E' && line[2]=='C'){//decoder case
			circuit[count]= new d1;
			circuit[count][0].set_name(get_partof_string(line,0));
			string de_1=get_partof_string(line,4);
			string de_2=get_partof_string(line,5);

			for(i=0;i<count;i++){
				if(de_1==circuit[i][0].get_name()){
				
					break;
				}
			}

			for(j=0;j<count;j++){
				if(de_2==circuit[j][0].get_name()){
				
					break;
				}
			}
			circuit[count][0].set_input_gate(circuit[i],circuit[j]);
			count++;

			circuit[count]= new d2;
			circuit[count][0].set_name(get_partof_string(line,1));
			circuit[count][0].set_input_gate(circuit[i],circuit[j]);
			count++;

			circuit[count]= new d3;
			circuit[count][0].set_name(get_partof_string(line,2));
			circuit[count][0].set_input_gate(circuit[i],circuit[j]);
			count++;

			circuit[count]= new d4;
			circuit[count][0].set_name(get_partof_string(line,3));
			circuit[count][0].set_input_gate(circuit[i],circuit[j]);
			
		}
		count++;
		}

		
	
	for(i=0;i<outpnum;i++){
			circuit[count]= new output;
			circuit[count][0].set_name(get_partof_string(outputline,i));

			string out=circuit[count][0].get_name();
			for(j=0;j<count;j++){
				if(out==circuit[j][0].get_name()){
					break;
				}
			}

			circuit[count][0].set_input_gate(circuit[j],NULL);

			count++;	
			}
		

	ifstream inPuts;
	inPuts.open("input.txt");
	int inputs_placed[inpnum];
	while(getline(inPuts,line)){
		for(i=0;i<inpnum;i++)
			inputs_placed[i]=line[i*2]-48;


		for(i=0;i<inpnum;i++){
		circuit[i][0].set_value(inputs_placed[i]);
	}
	for(i=totalgates-outpnum;i<totalgates;i++){
		cout<<circuit[i][0].eval()<<" ";
	}
	cout<<endl;
	for(i=inpnum;i<totalgates-outpnum;i++){
		circuit[i][0].set_isrunned(false);
	}
		}
		


}


