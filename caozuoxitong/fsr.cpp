#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Process {
public:
    int pid; // 进程ID
    int priority; // 优先级
    int burst_time; // CPU 执行时间
    Process(int pid, int priority, int burst_time) 
        : pid(pid), priority(priority), burst_time(burst_time) {}
};
bool compare(const Process &a, const Process &b) {
    return a.priority > b.priority; // 按优先级降序排序
}
int main() {
    vector<Process> processes = {
        Process(1, 3, 10),
        Process(2, 1, 5),
        Process(3, 4, 8),
        Process(4, 2, 4),
        Process(5, 5, 2)
    };
    sort(processes.begin(), processes.end(), compare); // 按优先级降序排序
    map<int, Process> process_map; // 使用 map 存储进程信息，以避免直接使用负数或冲突
    queue<int> running_queue; // 保存当前正在运行的进程
    queue<int> completed_queue; // 保存已经完成的进程
    int remaining_burst_time = 0; // 记录当前还需要执行的 CPU 时间
    int i = 0;
    while (i < processes.size() || !running_queue.empty()) {
        if (remaining_burst_time == 0) {
            int pid = running_queue.front();
            Process &p = process_map[pid];
            cout << "Process " << p.pid << " is running, burst_time: " << p.burst_time 
                << ", priority: " << p.priority << endl;
            running_queue.pop();
            completed_queue.push(pid);
            remaining_burst_time += p.burst_time;
            i++;
        } else if (remaining_burst_time >= processes[i].burst_time) {
            Process p = processes[i];
            process_map[p.pid] = p;
            cout << "Process " << p.pid << " is running, burst_time: " << p.burst_time 
                << ", priority: " << p.priority << endl;
            running_queue.push(p.pid);
            remaining_burst_time -= p.burst_time;
            i++;
        } else {
            cout << "Process " << processes[i].pid << " is waiting, burst_time: " << processes[i].burst_time 
                << ", priority: " << processes[i].priority << endl;
            i++;
        }
        cout << "Remaining burst time: " << remaining_burst_time << endl;
    }
    // 输出已经完成的进程
    cout << "Completed processes:" << endl;
    while (!completed_queue.empty()) {
        int pid = completed_queue.front();
        Process &p = process_map[pid];
        cout << "Process " << p.pid << ", burst_time: " << p.burst_time 
            << ", priority: " << p.priority << endl;
        completed_queue.pop();
    }
    return 0;
}