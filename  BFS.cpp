#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > adj;
int N;

void BFS(int init){
	queue<int> q;
	vector<bool> visited(N);
	vector<int> dist(N);
	
	q.push(init);
	visited[init] = true;
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = 0; i < adj[v].size();i++){
			int u = ajd[v][i];
			if (!visited[u]){
				q.push(u);
				dist[u] = dist[v] + 1;
			}
		}
	}
}

int main(){
		
}
