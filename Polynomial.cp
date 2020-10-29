#include"Polynomial.h"

Polynomial::Polynomial()
{
	start=end=NULL;
	size=0;

}

Polynomial::Polynomial(char* in)
{
	size=0;
	int check=0,count=0,co=0,dg=0,one=0,two=0,l=0;
	char *temp='\0';
	char *temp1='\0';
	char *input=in;
	Term a;
	for(int i=0;in[i]!='\0';i++)
	{
		if(in[i]=='x')
			count++;
	}
	char **temp2=new char*[count];
	for(int i=0;i<count;i++)
		temp2[i]='\0';
	for(int i=0,j=0;in[i]!='\0';i++)
	{
		if((in[i]=='+'||in[i]=='-')&&i!=0)
		{
			one=two;
			two=i;
			temp2[j]=new char[(two-one)+1];
			l=0;
			for(int k=one;k<(two);k++)
				temp2[j][l++]=in[k];
			temp2[j][l]='\0';
			j++;
		}
		if(in[i+1]=='\0')
		{
			one=two;
			two=i;
		}

	}
	temp1=new char[(two-one)+2];
	l=0;
	for(int i=one;i<=two;i++)
		temp1[l++]=in[i];
	temp1[l]='\0';
	for(int j=0;j<count;j++)
	{
		temp=strtok(temp2[j],"x");
		a.coeff=atoi(temp);
		temp=strtok(NULL,"^");
		a.deg=atoi(temp);
		addAtEnd(a);
	}
	a.coeff=atoi(temp1);
	a.deg=0;
	addAtEnd(a);
	delete []temp1;
	for(int i=0;i<count;i++)
		delete []temp2[i];
	delete []temp2;
}
Polynomial::Polynomial(const Polynomial &obj)
{
	size=0;
	Node *temp=NULL;
	Term d;
	temp=obj.start;
	while(temp!=NULL)
	{
		d=temp->t;
		addAtEnd(d);
		temp=temp->next;
	}
	size=obj.size;
	delete []temp;
}

Polynomial Polynomial:: operator=(const Polynomial &obj)
{
	if(size>0)
	{
		Node *temp=NULL,*temp2=NULL;
	temp2=start->next;
	temp=start;
	while(temp2!=NULL)
	{
		delete temp;
		temp=temp2;
		temp2=temp2->next;
	}
	delete []temp;
	delete []temp2;
	size=0;
	start=end=NULL;
	}
	
	Node *temp3=NULL;
	Term d;
	d.coeff=0;
	d.deg=0;
	temp3=obj.start;
	while(temp3!=NULL)
	{
		d=temp3->t;
		addAtEnd(d);
		temp3=temp3->next;
	}
	size=obj.size;
	delete []temp3;
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial &obj)
{
	Polynomial ans;
	Node *temp=NULL;
	Term d;
	d.coeff=0;
	d.deg=0;
	bool check=false;
	temp=NULL;
	ans.size=0;
	temp=start;
	Node *temp3=NULL;
	temp3=obj.start;
	while(temp!='\0')
	{
		check=true;
	temp3=obj.start;
		while(temp3!='\0')
		{
			if(temp->t.deg==temp3->t.deg)
			{
				d.coeff=(temp->t.coeff)+(temp3->t.coeff);
				d.deg=temp->t.deg;
				check=false;
			    ans.addAtEnd(d);
			}
			temp3=temp3->next;
		}
		if(check)
		{
			d=temp->t;
			ans.addAtEnd(d);
		}
		temp=temp->next;
	}
	temp3=obj.start;
	while(temp3!='\0')
	{
		check=true;
		temp=start;
		while(temp!='\0')
		{
			if(temp->t.deg==temp3->t.deg)
			{
				check=false;
			}
			temp=temp->next;
		}
		if(check)
		{
			d=temp3->t;
			ans.addAtEnd(d);
			cout<<d.deg<<endl;
		}
			temp3=temp3->next;
	}
	temp=temp3=NULL;
	delete temp;
	delete temp3;
	return ans;

}
Polynomial Polynomial::operator+(const int num)
{
	Polynomial ans(*this);
	Node* temp=NULL;
	bool check=true;
	Term d;
	d.coeff-0;d.deg=0;
	temp=ans.start;
	while(temp!='\0')
	{
		if(temp->t.deg==0)
		{
			temp->t.coeff=temp->t.coeff+num;
			check=false;
		}
		temp=temp->next;
	}
	if(check)
	{
		d.coeff=num;
		d.deg=0;
		ans.addAtEnd(d);
	}
	return ans;
}
Polynomial Polynomial::operator-(const int num)
{
	Polynomial ans(*this);
	Node* temp=NULL;
	bool check=true;
	Term d;
	d.coeff-0;d.deg=0;
	temp=ans.start;
	while(temp!='\0')
	{
		if(temp->t.deg==0)
		{
			temp->t.coeff=temp->t.coeff-num;
			check=false;
		}
		temp=temp->next;
	}
	if(check)
	{
		d.coeff=(num)*(-1);
		d.deg=0;
		ans.addAtEnd(d);
	}
	return ans;
}
Polynomial Polynomial::operator-(const Polynomial &obj)
{
	Polynomial ans;
	Node *temp=NULL,*temp2=NULL;
	Term d;
	d.coeff=0;
	d.deg=0;
	bool check=false;
	ans.size=0;
	temp2=start;
	temp=NULL;
	Node *temp3=NULL;
	temp3=obj.start;
	while(temp2!='\0')
	{
		check=true;
	temp3=obj.start;
		while(temp3!='\0')
		{
			if(temp2->t.deg==temp3->t.deg)
			{
				d.coeff=(temp2->t.coeff)-(temp3->t.coeff);
				d.deg=temp2->t.deg;
				check=false;
			    ans.addAtEnd(d);
			}
			temp3=temp3->next;
		}
		if(check)
		{
			d=temp2->t;
			ans.addAtEnd(d);
		}
		temp2=temp2->next;
	}
	temp3=obj.start;
	while(temp3!='\0')
	{
		check=true;
		temp2=start;
		while(temp2!='\0')
		{
			if(temp2->t.deg==temp3->t.deg)
			{
				check=false;
			}
			temp2=temp2->next;
		}
		if(check)
		{

			d=temp3->t;
			d.coeff=d.coeff*(-1);
			ans.addAtEnd(d);
			cout<<d.deg<<endl;
		}
			temp3=temp3->next;
	}
	temp=temp2=temp3=NULL;
	delete temp;
	delete temp2;
	delete temp3;
	return ans;

}
Polynomial Polynomial::operator*(const Polynomial &obj)
{
	Polynomial ans;
	Node *temp=NULL,*temp2=NULL;
	Term d;
	d.coeff=0;d.deg=0;
	temp=start;
	while(temp!='\0')
	{
		temp2=obj.start;
		while(temp2!='\0')
		{
			d.coeff=(temp->t.coeff)*(temp2->t.coeff);
			d.deg=(temp->t.deg)+(temp2->t.deg);
			ans.addAtEnd(d);
			temp2=temp2->next;
		}
		temp=temp->next;
	}
	temp=temp2=NULL;
	delete temp;
	delete temp2;
	return ans;	

}
Polynomial Polynomial::operator*(const int num)
{
	Polynomial ans;
	Node *temp=NULL;
	Term d;
	d.coeff=0;d.deg=0;
	temp=start;
	while(temp!='\0')
	{
		d.coeff=(temp->t.coeff)*num;
		d.deg=temp->t.deg;
		ans.addAtEnd(d);
		temp=temp->next;
	}
	return ans;
	temp=NULL;
	delete []temp;
}
Polynomial operator*(const int num,const Polynomial &obj)
{
	Polynomial ans;
	Polynomial temp;
	Polynomial temp2("1");
	temp2.start->t.coeff=0;
	temp2.start->t.deg=0;
	temp.start=obj.start;
	while(temp.start!='\0')
	{
		temp2.start->t.coeff=(temp.start->t.coeff)*num;
		temp2.start->t.deg=temp.start->t.deg;
		ans.addAtEnd(temp2.start->t);
		temp.start=temp.start->next;
	}
	return ans;
}
Polynomial operator+(const int num, Polynomial &obj)
{
	Polynomial ans;
	ans=obj+num;
	return ans;
}
Polynomial operator-(const int num, Polynomial &obj)
{
	Polynomial ans;
	ans=-obj;
	ans=ans+num;
	return ans;
}
bool Polynomial::operator==(const Polynomial &obj)
{
	bool check=true;
	bool check2=true;
	Node *temp=NULL,*temp2=NULL;
	temp=start;
	while(temp!='\0')
	{
		check2=true;
		temp2=obj.start;
		while(temp2!='\0')
		{
			if((temp->t.coeff==temp2->t.coeff)&&(temp->t.deg==temp2->t.deg))
				check2=false;
			temp2=temp2->next;
		}
		if(check2)
			check=false;
		temp=temp->next;
	}
	return check;
	temp=temp2=NULL;
	delete []temp;
	delete []temp2;
}

const Polynomial& Polynomial::operator++()
{
	*this=*this+1;
	return *this;
}
Polynomial Polynomial::operator++(int)
{
	Polynomial temp=*this;
	*this=*this+1;
	return temp;
}

const Polynomial& Polynomial::operator-()
{
	Node* temp=NULL;
	temp=start;
	while(temp!='\0')
	{
		temp->t.coeff=temp->t.coeff*(-1);
		temp=temp->next;
	}
	temp=NULL;
	delete []temp;
	return *this;
}
double Polynomial::evaluate(int x)
{
	double sum=0,power=0;
	Node *temp=NULL;
	temp=start;
	while(temp!='\0')
	{
		power=pow(x,temp->t.deg);
		sum=sum+(power*temp->t.coeff);
		temp=temp->next;
	}
	delete []temp;
	return sum;
}
int Polynomial::whichX(int num)
{
	int high=0;
	int n=num,x=0;
	int curr=0,diff=0;
	bool check=true;
	Node *temp=NULL;

	temp=start;
	high=temp->t.deg;
	while(temp!='\0')
	{
		
		high=temp->t.deg+high;
		temp=temp->next;
	}
	if(high>0)
	{
	n=n/high;
	int n2=n;
	if(n>0)
		n=n*(-1);
	else if(n<0)
		n2=n2*(-1);
	for(int i=n;i<=n2;i++)
	{
		if(evaluate(i)==num)
		{
			x=i;
			check=false;
		}
	}
	if(check)
	{
		x=n;
		if(evaluate(x)>num)
			diff=evaluate(x)-num;
		else if(evaluate(x)<num)
			diff=num-evaluate(x);
		for(int i=n;i<=n2;i++)
	{
		curr=evaluate(i);
		if(curr<num)
		{
		if((num-curr)<diff)
		{
			x=i;
			diff=num-curr;
		}
		}
		else if(curr>num)
		{
			if((curr-num)>diff)
			{
				x=i;
				diff=curr-num;
			}
		}
	}
	}
	return x;
	}
	else 
		return 0;
	temp=NULL;
	delete []temp;
}
void Polynomial::clear()
{
	Node *temp=NULL,*temp2=NULL;
	temp2=start->next;
	temp=start;
	while(temp2!=NULL)
	{
		delete temp;
		temp=temp2;
		temp2=temp2->next;
	}
	delete []temp;
	delete []temp2;
	size=0;
	start=end=NULL;
}

Polynomial Polynomial::derivate()
{
	Polynomial ans;
	Node *temp=NULL;
	Term d;
	d.coeff=0;d.deg=0;
	temp=start;
	while(temp!='\0')
	{
		if(temp->t.deg==0)
		{
			d.coeff=0;
			d.deg=0;
			ans.addAtEnd(d);
			temp=temp->next;
		}
		else
		{
			d.coeff=(temp->t.coeff)*temp->t.deg;
			d.deg=temp->t.deg-1;
			ans.addAtEnd(d);
			temp=temp->next;
		}
	}
	temp=NULL;
	delete []temp;
	return ans;
}

int Polynomial::maxima(int f,int l)
{
	int sum=0,max=0;
	max=f;
	sum=evaluate(max);
	for(int i=f;i<=l;i++)
	{
		if(evaluate(i)>sum)
		{
			max=i;
		}

	}
	return max;
}

int Polynomial::minima(int f,int l)
{
	int sum=0,min=0;
	min=f;
	sum=evaluate(min);
	for(int i=f;i<=l;i++)
	{
		if(evaluate(i)<sum)
		{
			min=i;
		}

	}
	return min;
}
void Polynomial::deleteNegativeTerms(int x)
{
	Node *temp=NULL,*temp2=NULL,*temp3=NULL;
	double power=0,sum=0;
	power=pow(x,start->t.deg);
	sum=(power*start->t.coeff);
	while(sum<0&&start->next!='\0')
	{
		temp=start->next;
		delete start;
		start=temp;
		size--;
		power=pow(x,start->t.deg);
	sum=(power*start->t.coeff);
	}
	temp2=start->next;
	temp=start;
	temp3=temp2->next;
	while(temp3!='\0')
	{
		power=pow(x,temp2->t.deg);
		sum=(power*temp2->t.coeff);
		if(sum<0)
		{
			delete temp2;
			temp->next=temp3;
			temp2=temp3;
			temp3=temp2->next;
			size--;
		}
		else
		{
			temp=temp2;
			temp2=temp2->next;
			temp3=temp2->next;
		}
	}
	power=pow(x,end->t.deg);
	sum=(power*end->t.coeff);
	if(sum<0)
	{
		delete end;
		end=temp;
		end->next=NULL;
		size--;
	}
	temp=temp2=temp3=NULL;
	delete []temp;
	delete []temp2;
	delete []temp3;
}
void Polynomial::addAtStart(const Term &d)
{
	if(size==0)
	{
		start=end=createNode(d);
		size++;
	}
	else
	{
		Node *temp=createNode(d);
		temp->next=start;
		start=temp;
		size++;
	}
}
void Polynomial::addAtEnd(const Term &d)
{
	if(size==0)
	{
		start=end=createNode(d);
		size++;
	}
	else if(size>0)
	{
		Node *temp=createNode(d);
		end->next=temp;
		end=temp;
		size++;
	}
}

Polynomial::~Polynomial()
{
	if(size>0)
	{
	Node *temp=NULL,*temp2=NULL;
	temp2=start->next;
	temp=start;
	while(temp2!=NULL)
	{
		delete temp;
		temp=temp2;
		temp2=temp2->next;
	}
	delete []temp;
	delete []temp2;
	}
	else
	{
		delete []start;
		delete []end;
	}
}

ostream& operator<<(ostream &out,const Polynomial &obj)
{
	if(obj.start!='\0')
	{
	Polynomial a;
	a.start=obj.start;
	out<<"Polynomial: ";
	out<<a.start->t.coeff<<"x^"<<a.start->t.deg;
	a.start=a.start->next;
	while(a.start!='\0')
	{
		if((a.start->t.coeff)>=0)
			out<<"+";
		if(a.start->t.deg>0)
		{
		out<<a.start->t.coeff<<"x^"<<a.start->t.deg;
		a.start=a.start->next;
		}
		else if(a.start->t.deg==0)
		{
			out<<a.start->t.coeff;
			a.start=a.start->next;
		}
	}
	out<<endl;
	a.start=NULL;
	}
	else
		out<<"0"<<endl;
	return out;
}

void operator>>(istream &in,Polynomial &obj)
{
	char *arr="\0";
	arr=new char[100];
	in>>arr;
	char *arr2=new char[strlen(arr)+1];
	for(int i=0;i<strlen(arr)+1;i++)
		arr2[i]=arr[i];
	Polynomial temp(arr2);
	obj=temp;
	delete []arr;
	delete []arr2;
}