#line 72 "Graduation.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,vector<int> > pp;

class Graduation {
	public:
	vector<int> req_Lst[127];
	vector<int> classes;
	int B_A[127]={0}, A_B[127]={0};
	
	string play(int source)
	{
		int parent[127] = {0}, current_req, current_class, req_to_class;
		for(int i=0; i<=126; i++)
			parent[i] = -1;
		parent[source] = source;

		queue<int> q;
		q.push(source);
		int flag = 0;
		while(!flag and !q.empty())
		{
			current_class = q.front();
			q.pop();
			
			for(int i=0; i<req_Lst[current_class].size();i++)
			{
				current_req = req_Lst[current_class][i];
				req_to_class = B_A[current_req];
				if(req_to_class == -1)
				{
					flag = 1;
					break;
				}
				if(parent[req_to_class] != -1)
				{
					parent[req_to_class] = source;
					q.push(req_to_class);
				}
			}
		}
		if(!flag)
			return "";

		while(parent[current_class] != current_class)
		{
			int class_to_req = A_B[current_class];
			A_B[current_class] = current_req;
			B_A[current_req] = current_class;

			current_req = class_to_req;
			current_class = parent[current_class];
		}

		A_B[current_class] = current_req;
		B_A[current_req] = current_class;

		string ss;
		ss.push_back((char)source);
		return ss;
	}
	string moreClasses(string classesTaken, vector <string> requirements) 
	{
		
		int a[127] = {0};
		vector<pp> vpp;
		
		memset(A_B, -1, sizeof(A_B));
		memset(B_A, -1, sizeof(B_A));
		for(int i=0; i< requirements.size() ;i++)
		{
			const char *s = requirements[i].c_str();
			int x = 0;
			vector<int> v;
			for(int j=0; j<strlen(s); j++)
			{
				if('0'<=s[j] and s[j]<='9')
					x = x*10 + s[j]-'0';
				else
				{
					v.push_back(s[j]);
					a[s[j]] = 1;
				}
			}
			vpp.push_back(pp(x,v));
		}
		
		for(int i=0;i<classesTaken.size(); i++)
			a[classesTaken[i]]=0;
	
		for(int i=0; i<=126; i++)
			if(a[i] == 1)
				classes.push_back(i);
									
		sort(classes.begin(), classes.end());
		//creating of vector of classes is done set A
		
		
		int co = 0;
		for(int i=0; i<vpp.size(); i++)
		{
			pp f = vpp[i];
			vector<int> req;
			for(int j=0; j<f.first; j++)
				req.push_back(co++);
			vector<int> v = f.second;
			for(int j=0; j<v.size(); j++)
				req_Lst[v[j]].insert(req_Lst[v[j]].end(), req.begin(), req.end());
		}	
		
		/*
		testing of the required list created for the classes
		for(int i = 0; i< 127;i++)
		{
			if(req_Lst[i].size()==0)
				continue;
				
			cout << (char)i << " :";
			for(int j=0; j<req_Lst[i].size(); j++)
				cout << req_Lst[i][j] << " ";
			cout << "\n";
		}
		*/
		
		for(int i=0;i<classesTaken.size();i++)
		{	
			play(classesTaken[i]);
		}
		
		string ac = "";
		for(int i=0;i<classes.size();i++)
		{
			ac += play(classes[i]);
		}
		return ac;
	}
};