struct graph
{
    int v;
    struct lnode  **array;
};

void bfs(struct graph *g,int start);
