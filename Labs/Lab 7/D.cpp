#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    string last, first;
    double gpa;
};


bool cmp(student a, student b)
{
    if (a.gpa == b.gpa)
    {
        if (a.last == b.last)
        {
            return a.first < b.first;
        }
        return a.last < b.last;
    }
    return a.gpa < b.gpa;
}

void merge(student *a, int n, student * b, int m)
{
    vector<student> c;
    int i = 0, j = 0;
    while(i < n || j < m){
        if(i==n){
            c.push_back(b[j++]);
        } else if(j==m){
            c.push_back(a[i++]);
        } else if(cmp(a[i], b[j])){
            c.push_back(a[i++]);
        } else{
            c.push_back(b[j++]);
        }
    }
    for(int i = 0; i < n+m; i++){
        a[i] = c[i];
    }
}

void msort(student *a, int n)
{
    if (n==1)
        return;
    msort(a, n/2);
    msort(a+n/2, n-n/2);
    merge(a, n/2, a+n/2, n-n/2);
}

int main()
{
    map<string, double> grade;
    grade["A+"] = 4.00;
    grade["A"] = 3.75;
    grade["B+"] = 3.50;
    grade["B"] = 3.00;
    grade["C+"] = 2.50;
    grade["C"] = 2.00;
    grade["D+"] = 1.50;
    grade["D"] = 1.0;
    grade["F"] = 0;

    int n;
    cin >> n;
    
    student a[100001];
    int num_subjects, credit;
    string grd;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].last >> a[i].first >> num_subjects;
        double sum = 0, sum_credit = 0;
        for (int j = 0; j < num_subjects; j++)
        {
            cin >> grd >> credit;
            sum += credit * grade[grd];
            sum_credit += credit;
        }
        a[i].gpa = sum/sum_credit;
    }
    msort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].last << " " << a[i].first << " ";
        printf("%.3f\n", a[i].gpa);
    }
}
