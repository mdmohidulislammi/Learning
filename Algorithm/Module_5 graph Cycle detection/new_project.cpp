#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
bool is_vis[N];
bool ans;
int parent[N];
int sum;
void DFs(int src)
{
    sum += src;
    cout << src << endl;
    is_vis[src] = true;
    for (int child : graph[src])
    {
        if (is_vis[child] && child != parent[src])
        {
            ans = true;
        }
        if (!is_vis[child])
        {
            sum += child;
            parent[child] = src;
            DFs(child);
        }
    }
}
class student
{
public:
    string Name;
    int cls;
    char group;
    int age;
    int roll;
    int marks;
    student(string Name, int cls, char group, int age, int roll, int marks)
    {
        this->Name = Name;
        this->cls = cls;
        this->group = group;
        this->age = age;
        this->roll = roll;
        this->marks = marks;
    }
};
class cmp
{
public:
    bool operator()(student a, student b)
    {
        if (a.cls == b.cls)
        {
            if (a.group > b.group)
            {
                return true;
            }
            else if (a.group == b.group)
            {
                if (a.age < b.age)
                    return true;
                else if (a.age == b.age)
                {
                    if (a.marks < b.marks)
                        return true;
                    else if (a.Name == b.Name)
                        return true;
                }
            }
        }
        else if (a.cls < b.cls)
            return true;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(is_vis, false, sizeof(is_vis));
    memset(parent, -1, sizeof(parent));
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (!is_vis[i])
        {
            DFs(i);
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << sum << endl;
    vector<student> v;
    while(1)
    {
        string name;
        char group;
        int cls, roll, marks, age;
        cin >> name >> cls >> group >> age >> roll >> marks;

        if(name=="ami")
        break;
        v.push_back({name, cls, group, age, roll, marks});
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].Name << " " << v[i].cls << " " << v[i].group << " " << v[i].age << " " << v[i].roll << " " << v[i].marks << endl;
    }
    priority_queue<student, vector<student>, cmp> pq;
    cout<<"Serial"<<"Name"<<"  "<<" Class"<<"   Group"<<"    Age"<<"     Roll"<<"   Marks"<<endl;
     cout<<"__________________________________________________________________________________________________"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i<< " . "<<v[i].Name << "    " << v[i].cls << "       " << v[i].group << "      " << v[i].age << "       " << v[i].roll << "     " << v[i].marks << endl;
    }
    return 0;
}