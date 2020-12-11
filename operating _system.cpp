#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Process
{
	public:
	int no;
	int burstTime;
	int arrivalTime;
	int priority;
	Process(int no,int burstTime,int arrivalTime,int priority)
	{
		this->no=no;
		this->burstTime=burstTime;
		this->arrivalTime=arrivalTime;
		this->priority=priority;	
	}
};
class minheap
{
	public:
	int heap_size;
	int capacity;
	vector<Process >v2;
	vector<Process >v3;
	vector<Process >v4;
	minheap(int cap)
	{
		capacity=cap;
		heap_size=0;	
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return 2*i+1;
	}
	int right(int i)
	{
		return 2*i+2;
	}
	int insertkey(Process ,int);
	void minheapify(int );
	//Process extractmin();
	void display();
	void display3();
	void emptyV();
	void emptyV3();
};
void minheap::emptyV3()
{
	cout<<"Round Robin Scheduling (Queue 2):\n";
	cout<<"-----------------------------------------------------------------------------\n";
	int quantumTime=2;
	for (int i=0;i<v3.size();i++)
	{
		cout<<"   "<<"P"<<v3[i].no<<"   ";
	}
	while(!v3.empty())
	{
		
		if(v3[0].burstTime<2)
		{
			v3[0].burstTime=0;
			cout<<"   "<<"P"<<v3[0].no<<"   ";
			v3.erase(v3.begin());
		}
		else
		{
			v3[0].burstTime-=2;
			cout<<"   "<<"P"<<v3[0].no<<"   ";
			v3.push_back(v3[0]);
			v3.erase(v3.begin());
		}
	}
	cout<<"\n-----------------------------------------------------------------------------\n";
}
void minheap::emptyV()
{
	while(!v2.empty())
	{
		for(int i=0;i<v2.size();i++)
		{
			heap_size--;
			v2[0].burstTime=0;
			v4.push_back(v2[0]);
			v2.erase(v2.begin());
			minheapify(0);
		}
	}
}
void minheap::display3()
{
	cout<<"Fixed Priority Premmitive Scheduling (Queue 1):\n";
	cout<<"-----------------------------------------------------------------------------\n";
	for(int i=0;i<v4.size();i++)
	{
		cout<<"   "<<"P"<<v4[i].no<<"   ";
	}
	cout<<endl<<"-----------------------------------------------------------------------------\n";
}

void minheap::display()
{
	cout<<"display";
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i].priority<<ends<<v2[i].arrivalTime<<ends<<v2[i].burstTime;
	}
}
void swap(Process *p1,Process *p2)
{
	Process c=*p1;
	*p1=*p2;
	*p2=c;
}
/*Process minheap::extractmin()
{
	if(heap_size<=0)
	{
		cout<<"no elements\n";
	}
	if(heap_size==1)
	{
		heap_size--;
		return v2[0];
	}
	Process *min=v2[0];
	v2[0]=v2[heap_size-1];
	heap_size--;
	minheapify(0);
	return min;
}*/
void minheap::minheapify(int i)
{
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<heap_size&&v2[l].priority<v2[i].priority)
	{
		smallest=l;
	}
	if(r<heap_size&&v2[r].priority<v2[smallest].priority)
	{
		smallest=r;
	}
	if(smallest!=i)
	{
		swap(v2[i],v2[smallest]);
		minheapify(smallest);
	}
}
int minheap::insertkey(Process p,int k)
{
	if(heap_size==capacity||p.burstTime==0)
	{
		return 0;
	}
	if(heap_size!=0)
	{
		
		v2[0].burstTime=v2[0].burstTime+v2[0].arrivalTime-p.arrivalTime;
		if(v2[0].priority>p.priority||v2[0].burstTime==0)
		{
			heap_size--;
			if(v2[0].burstTime<=0)
			v4.push_back(v2[0]);
			else
			v3.push_back(v2[0]);
			v2.erase(v2.begin());
			minheapify(0);
			
		}
	}
	//cout<<"y2";
	heap_size++;
	int i=heap_size-1;
	//cout<<"p5"<<p.priority;
	v2.push_back(p);
	while(i!=0&&v2[parent(i)].priority>v2[i].priority)
	{
		swap(v2[parent(i)],v2[i]);
		i=parent(i);
	}
}
bool compareArrival(Process p1,Process p2)
{
	return (p1.arrivalTime<p2.arrivalTime);
}
int main()
{
	int count=0;
	int n=0;
	int flag1=1;
	int totalArrival=INT_MIN;
	vector<Process > v;
	cout<<"enter Process Details:\n";
	while(flag1!=0)
	{
		count++;
		int bt,at,p;
		cout<<"Process "<<count<<endl;
		cout<<"Bursttime:";
		cin>>bt;cout<<endl;
		cout<<"ArrivalTime:";
		cin>>at;cout<<endl;
		cout<<"Priority:";
		cin>>p;cout<<endl;
		if(totalArrival<at)
		totalArrival=at;
		Process *r=new Process(count,bt,at,p);
		v.push_back(*r);
		int y;
		cout<<"add new process enter 1 else 0\n";
		cin>>y;
		if(y==0)
		{
			flag1=0;
		}
	}
	sort(v.begin(),v.end(),compareArrival);
	minheap h(v.size());
	int j=0;
	cout<<"totalArrival"<<totalArrival<<endl;
	for(int i=0;i<=totalArrival;i++)
	{
		//cout<<"i"<<i<<ends<<v[j].arrivalTime;
		if(v.empty())
		break;
		if(i==v[j].arrivalTime)
		{
			h.insertkey(v[j],i);
			j++;
		}
	}
	h.emptyV();
	h.display3();
	h.emptyV3();
	
}

