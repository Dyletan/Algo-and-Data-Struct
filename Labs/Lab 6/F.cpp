#include <iostream>
#include <map>
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

int partition(student *a, int l, int r)
{
    int p = rand() % (r - l + 1) + l;
    swap(a[r], a[p]);
    int j = l;
    for (int i = l; i < r; i++)
    {
        if (cmp(a[i], a[r]))
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[r], a[j]);
    return j;
}

void qsort(student *a, int l, int r)
{
    if (l >= r)
        return;
    int piv = partition(a, l, r);
    qsort(a, l, piv - 1);
    qsort(a, piv + 1, r);
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
    
    student a[1000001];
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
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].last << " " << a[i].first << " ";
        printf("%.3f\n", a[i].gpa);
    }
}
