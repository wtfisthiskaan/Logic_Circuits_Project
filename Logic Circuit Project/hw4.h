//--------------------BASE CLASS: GATE-------------------
/*class Gate{
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
		int out_value;

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




//--------------------BASE CLASS: GATE-------------------

//gate has no members

//-------------------------INPUT CLASS-------------------


int input::eval() {
	return out_value;

}

void input::set_value(int value) {
	out_value=value;
}

void input::set_name(string Nname){
	this->name=Nname;
}
string input::get_name(){
	return this->name;
}


//-----------------------OUTPUT CLASS-------------------


int output::eval(){
	int temp;
	temp=input->eval();
	this->out_value=temp;
	return out_value;
}

void output::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input=Ninput1;
}

void output::set_name(string Nname){
	this->name=Nname;
}
string output::get_name(){
	return this->name;
}

//-----------------------AND CLASS-------------------

int andgate::eval(){
	if(is_runned)
		return this->out_value;


	int temp1,temp2;
	temp1=input1->eval();
	temp2=input2->eval();
	if(temp1 && temp2)
		this->out_value=1;
	else
		this->out_value=0;

	is_runned=true;

	return this->out_value;
}

void andgate::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input1=Ninput1;
	this->input2=Ninput2;
}

void andgate::set_name(string Nname){
	this->name=Nname;
}

string andgate::get_name(){
	return this->name;
}

void andgate::set_isrunned(bool state){
	this->is_runned=state;
}


//-----------------------OR CLASS-------------------


int orgate::eval(){
	if(is_runned)
		return this->out_value;


	int temp1,temp2;
	temp1=input1->eval();
	temp2=input2->eval();
	if(temp1 || temp2)
		this->out_value=1;
	else
		this->out_value=0;

	is_runned=true;

	return this->out_value;
}
void orgate::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input1=Ninput1;
	this->input2=Ninput2;
}

void orgate::set_name(string Nname){
	this->name=Nname;
}

string orgate::get_name(){
	return this->name;
}

void orgate::set_isrunned(bool state){
	this->is_runned=state;
}

//-----------------------NOT CLASS-------------------


int notgate::eval(){
	if(is_runned)
		return this->out_value;


	int temp;
	temp=input->eval();
	if(temp)
		this->out_value=0;
	else
		this->out_value=1;

	is_runned=true;

	return this->out_value;
}
void notgate::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input=Ninput1;
}

void notgate::set_name(string Nname){
	this->name=Nname;
}

string notgate::get_name(){
	return this->name;
}
void notgate::set_isrunned(bool state){
	this->is_runned=state;
}

//-----------------------FLIPFLOP CLASS-------------------

int flipflop::eval(){
	if(is_runned)
		return this->out_value;


	int temp;
	temp=input->eval();
	if(temp==0 && mem==0){
		this->out_value=0;
	}
	else if(temp==0 && mem==1){
		this->out_value=1;
	}
	else if(temp==1 && mem==0){
		this->out_value=1;
		mem=1;
	}
	else if(temp==1 && mem==1){
		this->out_value=0;
		mem=0;
	}


	is_runned=true;

	return this->out_value;
}
void flipflop::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input=Ninput1;
}

void flipflop::set_name(string Nname){
	this->name=Nname;
}

string flipflop::get_name(){
	return this->name;
}
void flipflop::set_isrunned(bool state){
	this->is_runned=state;
}

//-----------------------DECODER CLASSES-------------------

int d1::eval() {
	if(is_runned)
		return this->out_value;

	int temp1,temp2;
	temp1=input1->eval();
	temp2=input2->eval();
	//cout<<endl<<endl<<"boru1"<<temp1<<temp2<<endl;
	if(temp1==0 && temp2==0){
		
		this->out_value=1;
	}
	else{
		
		this->out_value=0;
	}


	is_runned=true;

	return this->out_value;
}
void d1::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input1=Ninput1;
	this->input2=Ninput2;
}

void d1::set_name(string Nname){
	this->name=Nname;
}
string d1::get_name(){
	return this->name;
}
void d1::set_isrunned(bool state){
	this->is_runned=state;
}


int d2::eval() {
	if(is_runned)
		return this->out_value;

	int temp1,temp2;
	temp1=input1->eval();
	temp2=input2->eval();
	//cout<<endl<<endl<<"boru2"<<temp1<<temp2<<endl;
	if(temp1==0 && temp2==1){
		
		this->out_value=1;
	}
	else{
		
		this->out_value=0;
	}


	is_runned=true;

	return this->out_value;
}
void d2::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input1=Ninput1;
	this->input2=Ninput2;
}

void d2::set_name(string Nname){
	this->name=Nname;
}
string d2::get_name(){
	return this->name;
}
void d2::set_isrunned(bool state){
	this->is_runned=state;
}

int d3::eval() {
	if(is_runned)
		return this->out_value;

	int temp1,temp2;
	temp1=input1->eval();
	temp2=input2->eval();
	//cout<<endl<<endl<<"boru3"<<temp1<<temp2<<endl;
	if(temp1==1 && temp2==0){
		
		this->out_value=1;
	}
	else{
	
		this->out_value=0;
	}


	is_runned=true;

	return this->out_value;
}
void d3::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input1=Ninput1;
	this->input2=Ninput2;
}

void d3::set_name(string Nname){
	this->name=Nname;
}
string d3::get_name(){
	return this->name;
}
void d3::set_isrunned(bool state){
	this->is_runned=state;
}

int d4::eval() {
	if(is_runned)
		return this->out_value;

	int temp1,temp2;
	temp1=input1->eval();
	temp2=input2->eval();
	//cout<<endl<<endl<<"boru4"<<temp1<<temp2<<endl;
	if(temp1==1 && temp2==1){
		
		this->out_value=1;
	}
	else{
		
		this->out_value=0;
	}


	is_runned=true;

	return this->out_value;
}
void d4::set_input_gate(Gate *Ninput1,Gate *Ninput2){
	this->input1=Ninput1;
	this->input2=Ninput2;
}

void d4::set_name(string Nname){
	this->name=Nname;
}

string d4::get_name(){
	return this->name;
}
void d4::set_isrunned(bool state){
	this->is_runned=state;
}
*/
//--------------------------------------------------------------HELPER FUNCTIONS