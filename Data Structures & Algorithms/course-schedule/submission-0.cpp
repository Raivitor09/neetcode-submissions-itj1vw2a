class Solution {
public:
    unordered_set<int> finished;
    unordered_set<int> visiting;
    vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);

        // montar o grafo
        for(auto& p: prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);
        }

        // testar todos os cursos
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) {
                return false;
            } 
        }

        return true;
    }

    bool dfs(int course) {
        // Parada
        if(visiting.count(course)) {
            return false;
        }

        if(finished.count(course)) {
            return true;
        }

        // Processar
        visiting.insert(course);

        // Explorar
        for(int neighbor : graph[course]) {
            if(!dfs(neighbor)) {
                return false;
            }
        }

        // Finalizar
        visiting.erase(course);
        finished.insert(course);

        return true;
    }
};
