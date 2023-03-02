#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare_jobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

void job_sequencing(vector<Job>& jobs, int max_deadline) {
    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compare_jobs);

    // Allocate a time slot for each job
    vector<int> time_slots(max_deadline, -1);
    int total_profit = 0;
    int num_jobs = 0;

    // Assign jobs to time slots in decreasing order of profit
    for (const Job& job : jobs) {
        for (int i = job.deadline - 1; i >= 0; i--) {
            if (time_slots[i] == -1) {
                time_slots[i] = job.id;
                total_profit += job.profit;
                num_jobs++;
                break;
            }
        }
    }

    // Print the results
    cout << "Jobs selected: ";
    for (int i = 0; i < max_deadline; i++) {
        if (time_slots[i] != -1) {
            cout << time_slots[i] << " ";
        }
    }
    cout << endl;
    cout << "Total profit: " << total_profit << endl;
    cout << "Number of jobs: " << num_jobs << endl;
}

int main() {
    vector<Job> jobs = {
        {1, 4, 70},
        {2, 1, 80},
        {3, 1, 30},
        {4, 1, 100},
        {5, 3, 90},
        {6, 2, 20}
    };
    int max_deadline = 4;

    job_sequencing(jobs, max_deadline);
    cout<<"Robin-23498-DAA-lab-Prime"<<endl;

    return 0;
}
