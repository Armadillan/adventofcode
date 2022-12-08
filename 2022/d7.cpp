#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class FilesystemNode {
    public:
        //if parent is NULL, node is root
        FilesystemNode* parent_ptr;
        std::vector<FilesystemNode*> children;
        int size;
        std::string abspath;
        FilesystemNode(int size_, FilesystemNode* parent_ptr_, std::string abspath_) {
            //directories start with size 0
            size=size_;
            parent_ptr=parent_ptr_;
            abspath=abspath_;
        }
};

using FilesystemNodes = std::unordered_map<std::string, FilesystemNode*>;

void propagateDirSizes(FilesystemNode* root_ptr) {
    for (FilesystemNode* child_ptr : root_ptr->children) {
        propagateDirSizes(child_ptr);
        root_ptr->size += child_ptr->size;
    }
}

FilesystemNodes createFilesystemGraph() {
    FilesystemNodes graph;

    FilesystemNode* cwd_ptr = new FilesystemNode(0, NULL, "/");

    graph["/"] = cwd_ptr;

    int space_index;
    std::string path;

    std::string line;
    //skip first line
    std::getline(std::cin,line);

    //get all nodes
    while (std::getline(std::cin, line)) {
        if (line == "$ ls") {
            continue;
        }
        if (line == "$ cd ..") {
            cwd_ptr = cwd_ptr->parent_ptr;
            continue;
        }
        if (line.substr(0, 4) == "$ cd") {
            path = cwd_ptr->abspath + line.substr(5) + "/";
            cwd_ptr = graph[path];
            continue;
        }
        if (line.substr(0, 3) == "dir") {
            path = cwd_ptr->abspath + line.substr(4) + "/";
            graph[path] = new FilesystemNode(0, cwd_ptr, path);
            cwd_ptr->children.push_back(graph[path]);
            continue;
        }
        //last alternative is that the line describes a file
        space_index = line.find(' ');
        path = cwd_ptr->abspath + line.substr(space_index+1);
        graph[path] = new FilesystemNode(stoi(line.substr(0, space_index)), cwd_ptr, path);
        cwd_ptr->children.push_back(graph[path]);
    }

    //find sizes of directories
    propagateDirSizes(graph["/"]);

    return graph;
}

int solveP1(FilesystemNodes* graph) {
    int sum = 0;
    for (auto& kv: *graph) {
        if (!kv.second->children.empty() && kv.second->size <= 100000) {
            sum += kv.second->size;
        }
    }
    return sum;
}

int solveP2(FilesystemNodes* graph) {
    const int disk_size = 70000000;
    const int required_space = 30000000;
    const int space_to_free = required_space - disk_size + (*graph)["/"]->size;

    int smallest = (*graph)["/"]->size;
        for (auto& kv: *graph) {
        if (!kv.second->children.empty() && kv.second->size >= space_to_free && kv.second->size < smallest) {
            smallest = kv.second->size;
        }
    }
    return smallest;
}

int main() {
    FilesystemNodes nodes = createFilesystemGraph();
    std::cout << solveP1(&nodes) << std::endl;
    std::cout << solveP2(&nodes) << std::endl;
}
