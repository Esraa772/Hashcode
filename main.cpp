#include <bits/stdc++.h>
using namespace std;

struct greedy {
int id;
int score;
};

void insertionSort (greedy arr[], int n)
{
int i, j;
greedy key;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;

/* Move elements of arr[0..i-1], that are
greater than key, to one position ahead
of their current position */
while (j >= 0 && arr[j].score > key.score)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}


void printArray(greedy arr[], int n)
{
int i;
for (i = 0; i < n; i++)
cout << arr[i].score << " ";
cout << endl;
}



int main() {
// your code goes here
freopen("f_libraries_of_the_world.txt", "r", stdin);
freopen("f.txt", "w", stdout);
int b=0,l=0,d=0,arr[100000];int arr_arg[100000];
int x=0,maxi=0;int arr_sum[100000];



for(int i=0;i<100000;i++){ arr_sum[i]=0; arr[i]=0;arr_arg[i]=0;}
scanf("%d%d%d",&b,&l,&d);
for(int i=0;i<b;i++)
{
scanf("%d",&arr[i]);
maxi+=arr[i];
}
vector <vector <int> > v;
vector<int>::iterator it;
for(int i =0;i<l;i++)
{
vector <int> vtemp;
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
vtemp.push_back(a);
vtemp.push_back(b);
vtemp.push_back(c);
for(int j=0;j<a;j++)
{
scanf("%d",&x);
vtemp.push_back(x);
arr_sum[i]+=arr[x];
}
v.push_back(vtemp);
vtemp.clear();
}


greedy f[100000];
int maxi_2 = 0 ;
for(int i=0;i<l;i++)
{
    int r= (maxi/arr_sum[i]);
    if(r > maxi_2) maxi_2 =r;
}
for(int i=0;i<l;i++)
{
    int r= (maxi/arr_sum[i])*(d/maxi_2);
    int z= r+(v[i][1]/d)+(d/(b/v[i][2]));
    f[i] = greedy{i,z};
}
insertionSort(f,l);
int taken_libraries=0,cnt=0,k=0;
while(cnt<d && taken_libraries<=l)
{
    cnt+=v[f[k].id][2];
    taken_libraries++;
    k++;
}
k=0;
printf("%d\n",--taken_libraries);
for(int i=0;i<taken_libraries;i++)
{
    printf("%d %d\n",f[k].id,v[f[k].id][0]);
    it = v[f[k].id].begin();
    v[f[k].id].erase(it);
    it = v[f[k].id].begin();
    v[f[k].id].erase(it);
    it = v[f[k].id].begin();
    v[f[k].id].erase(it);
    for(int j=0;j<v[f[k].id].size();j++)
    {
        printf("%d ",v[f[k].id][j]);
    }
    cout<<endl;
    k++;
}
v.clear();
return 0;
}
