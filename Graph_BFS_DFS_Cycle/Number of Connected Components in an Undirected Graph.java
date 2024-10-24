class Solution {
    
    private void dfs(List<List<Integer>>graph, boolean[] vis, int node){
        vis[node] = true;

        for(int neigh : graph.get(node)){
            if(vis[neigh] == false){
                dfs(graph,vis,neigh);
            }
        }
    }

    private void bfs(List<List<Integer>>graph, boolean[] vis, int node){
        Queue<Integer>q = new LinkedList<>();
        q.add(node);
        vis[node] = true;

        while(!q.isEmpty()){
            int current = q.poll();

            for(int neigh : graph.get(current)){
                if(vis[neigh] == false){
                    q.add(neigh);
                    vis[neigh] = true;
                }
            }
        }
    }
    public int countComponents(int n, int[][] edges) {
        //Convert the list of edges into adjacency list

        List<List<Integer>>graph = new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }

        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        int count = 0;
        boolean[] vis = new boolean[n];

        for(int i=0;i<n;i++){
            if(vis[i] == false){
               // bfs(graph,vis,i);
                dfs(graph,vis,i);
                count++;
            }
        }

        return count;

    }
}
