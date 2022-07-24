#ifndef GATE_H
#define GATE_H

#include <iostream>

#include <string>

using namespace std;

//--------------------BASE CLASS: GATE-------------------
class Gate{
	public:
		virtual int eval(){}
		virtual void set_value(int value){}
		virtual void set_input_gate(Gate *Ninput1,Gate *Ninput2){}
		virtual void set_name(string Nname){}
		virtual string get_name(){}
		virtual void set_isrunned(bool state){ }
};


//-------------------------INPUT CLASS-------------------

class input : public Gate{
	public:
		int eval();
		void set_value(int value);
		void set_name(string Nname);
		string get_name();
	private:
		string name;
		int out_value;
};



//-----------------------OUTPUT CLASS-------------------

class output : public Gate{
	public:
		int eval();
		void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		void set_name(string Nname);
		string get_name();
	private:
		string name;
		Gate *input;
		int out_value;
};

//-----------------------AND CLASS-------------------

class andgate : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input1;
		Gate *input2;
		int out_value;
		bool is_runned=false;
};

//-----------------------OR CLASS-------------------


class orgate : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input1;
		Gate *input2;
		int out_value;
		bool is_runned=false;
};

//-----------------------NOT CLASS-------------------

class notgate : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input;
		int out_value;
		bool is_runned=false;
};

//-----------------------FLIPFLOP CLASS-------------------

class flipflop : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input;
		int mem=0;
		int out_value;
		bool is_runned=false;
};

//-----------------------DECODER CLASSES-------------------

class d1 : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input1;
		Gate *input2;
		int out_value;
		bool is_runned=false;
};



class d2 : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input1;
		Gate *input2;
		int out_value;
		bool is_runned=false;
};


class d3 : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input1;
		Gate *input2;
		int out_value;
		bool is_runned=false;
};


class d4 : public Gate{
	public:	
		 int eval();
		 void set_input_gate(Gate *Ninput1,Gate *Ninput2);
		 void set_name(string Nname);
		 string get_name();
		 void set_isrunned(bool state);
	private:
		string name;
		Gate *input1;
		Gate *input2;
		int out_value;
		bool is_runned=false;
}; 


#endif