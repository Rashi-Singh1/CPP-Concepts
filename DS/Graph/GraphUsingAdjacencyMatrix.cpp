#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define type int
class Directed_Graph_Matrix
{
private:
	unordered_map<type,vector<type> > A;	
public :
	Directed_Graph_Matrix()
	{
		A.clear();
	}
	void addEdge(type a, type b)
	{
		if(A.count(a) == 0)
		{
			A[a].push_back(b);
		}
		else{
			bool bpst = false;
			for(int i = 0;i<A[a].size();i++)
			{
				if(A[a][i] == b) bpst = true;
			}
			if(bpst == false) A[a].push_back(b);
		}
		if(A.count(b) == 0){
			vector<type> temp;
			A[b] = temp;
		}
	}
	void bfs(type a)
	{
		if(A.size() == 0) return;
		if(A.count(a) == 0) return;
		unordered_map<type,bool> visited;
		for(auto x : A) visited[x.first] = false;
		queue<type> que;
		que.push(a);
		while(!que.empty())
		{
			type cur = que.front();
			cout<<cur<<" ";
			visited[cur] = false;
			que.pop();
			for(int i = 0;i<A[cur].size();i++)
			{
				if(visited[A[cur][i]] == false) que.push(A[cur][i]);
			}
		}
		cout<<endl;
	}

	void dfs(type a)
	{
		if(A.size() == 0) return;
		if(A.count(a) == 0) return;
		stack<type>sta;
		unordered_map<type,bool> visited;
		for(auto x : A) visited[x.first] = false;
		sta.push(a);
		while(!sta.empty())
		{
			type cur = sta.top();
			cout<<cur<<" ";
			visited[cur] = true;
			sta.pop();
			for(auto x : A[cur]) {
				if(visited[x] == false) sta.push(x);
			}
		}
		cout<<endl;
	}

	void bfs_complete()
	{
		if(A.size() == 0) return;
		unordered_map<type,bool> visited;
		for(auto x : A) visited[x.first] = false;
		queue<type> que;
		for(auto x : A){
			auto a = x.first;
			if(visited[a] == true) continue;
			else{
				que.push(a);
				while(!que.empty())
				{
					type cur = que.front();
					cout<<cur<<" ";
					visited[cur] = false;
					que.pop();
					for(int i = 0;i<A[cur].size();i++)
					{
						if(visited[A[cur][i]] == false) que.push(A[cur][i]);
					}
				}
			}
		}
		cout<<endl;
	}

	void print(){
		for(auto x : A)
		{
			cout<<x.first<<" : ";
			for(auto y : x.second){
				cout<<y<<" ";
			}cout<<endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	Directed_Graph_Matrix graph;
	for (int i = 0; i < 15; ++i)
	{
		graph.addEdge(i,2*i);
	}
	graph.addEdge(1,3);
	graph.print();
	// graph.bfs_complete();
	graph.dfs(1);
	return 0;
}