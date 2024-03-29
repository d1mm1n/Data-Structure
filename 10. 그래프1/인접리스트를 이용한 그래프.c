//인접리스트를 이용한 그래프 
//교재 프로그램 10.2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n; //정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

//그래프 초기화
void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}
}

//정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선 삽입, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL) {
			printf("->%d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 3, 2);

	print_adj_list(g);
	free(g);
	return 0;
}