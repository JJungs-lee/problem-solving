#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
Graph�� ��������Ʈ�� ���Ѵ�. G[i] �� i�� ������ ����� ������ ����(pair�� first)�� ����ġ(pair�� second)�� ��� �ִ�.
start�� �������� �ǹ��Ѵ�.

����� vector�� ��ȯ�Ǹ�, vector�� i��° ���Ҵ� start���� i�� ���� ������ �ִ� �Ÿ��� ���Ѵ�.
*/
const int inf = 987654321;

int vertexNum;			// ��������
int edgeNum;			// ��������
int startNum;			// ��������

vector<int> dijkstra(const vector< vector< pair<int, int> > >& graph, const int start){

	vector<int> dist(vertexNum + 1, inf);			//��ȯ�� ������ ����
	dist[start] = 0;

	set< pair<int, int> > pq;

	pq.insert(make_pair(0, start));
	while(!pq.empty()){
		auto top = *pq.begin();
		pq.erase(top);

		int current = top.second;
		const vector< pair<int, int> > &edges = graph[current];

		for(int i = 0; i < edges.size(); ++i){
			int next = edges[i].first;
			//	������ �������ִ� ����ġ > ���� �������ִ� ����ġ+ �������� ���� ����ġ
			if(dist[next] > dist[current] + edges[i].second){
				pq.erase(make_pair(dist[next], next));
				pq.insert(make_pair(dist[current] + edges[i].second, next));
				dist[next] = dist[current] + edges[i].second;
			}
		}
	}
	return dist;
}

int main(){

	int startV;			// �������
	int endV;			// ��������
	int weight;			// ����ġ

	cin >> vertexNum >> edgeNum >> startNum;

	vector< vector< pair<int, int> > > graph(vertexNum + 1);

	for(int i = 0; i < edgeNum; ++i){
		cin >> startV >> endV >> weight;
		graph[startV].push_back(make_pair(endV, weight));
	}
	vector<int> ret = dijkstra(graph, startNum);

	for(int i = 1; i <= vertexNum; ++i){
		ret[i] == inf ? cout << "INF" << endl :
			cout << ret[i] << endl;
	}


	return 0;
}