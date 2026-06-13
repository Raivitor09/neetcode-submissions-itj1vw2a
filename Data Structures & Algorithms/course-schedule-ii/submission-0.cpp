class Solution {
public:
    unordered_set<int> visiting;
    unordered_set<int> finished;

    vector<vector<int>> graph;
    vector<int> order;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        graph.resize(numCourses);

        // montar o grafo
        for(auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);
        }

        // testar todos os cursos
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) {
                return {};
            }
        }

        reverse(order.begin(), order.end());

        return order;
    }

private:

    bool dfs(int course) {

        // PARADAS

        // ciclo encontrado
        if(visiting.count(course)) {
            return false;
        }

        // já processado
        if(finished.count(course)) {
            return true;
        }

        // PROCESSAR

        visiting.insert(course);

        // EXPLORAR

        for(int neighbor : graph[course]) {
            if(!dfs(neighbor)) {
                return false;
            }
        }

        // FINALIZAR

        visiting.erase(course);
        finished.insert(course);

        order.push_back(course);

        return true;
    }
};