/*
   Mayank Pratap Singh
   MNNIT, 2nd year IT
   AC ho.
*/
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MOD 1000000007

typedef long long ll;
typedef long double ld;

const int INF=(int)(1e9);
const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef vector<list<pair<int,double> > >vld;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

/*************  Ye mera template hai chutiye apna template khud bana  **************  */

/*******************************************************************************
 
               Hey bitch dont copy my template.
               
               Those who are not able to do anything on their own are the ones
               who copy templates from others. 

*****************************************************************************/

/* ********* Compare Function for sorting pair of coordinates ************    */

bool compare(const pair<int,int>&i,const pair<int,int>&j){

    if(i.second==j.second)         // Decreasing order according to first coordinate
      return i.first>j.first;

    return i.second<j.second;   // Increasing order according to second coordinate

}


/******  Modular Multiplication Function for Long integes  ********/

long long mulmod(long long a,long long b,long long c){
 
    long long x=0,y=a%c;
    while(b>0){
 
        if(b%2==1){
 
            x=(x+y)%c;
 
        }
 
        y=(y*2)%c;
        b/=2;
 
    }
    return x%c;
}

/****** Modular Exponentiation Function For Long Integers  ******/

long long modulo(long long a,long long b,long long c){
 
     long long x=1,y=a;
 
     while(b>0){
 
         if(b%2==1){
 
             x=mulmod(x,y,c);
         }
         y=mulmod(y,y,c);
         b/=2;
     }
 
     return x%c;
 
}

/****** Fermat's Primalty Testing *****/
bool Fermat(long long p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        long long a = rand()%(p-1)+1; 
        // modulo is the function we developed above for modular exponentiation.
        if(modulo(a,p-1,p) != 1){ 
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}

/******  Miller Rabin for Prime Check in case Of Large Integers  ********/
 
bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}  

/***** Sieve Of Eratosthenes is a Bitch *******/ 

bool prime[2000005];
 
void sieve(){
 
  memset(prime,true,sizeof(prime));
 
  for(int p=2;p*p<=N;p++){
 
     if(prime[p]==true){
 
        for(int i=p*2;i<=N;i+=p)
          prime[i]=false;
     }
 
  }
}

/****** Its called BFS  **********/
 
vector<list<int> >adjacencyList(vertices+1);

int parent[vertices+1];
int level[vertices+1];

void bfs(){
	
   memset(parent,0,sizeof(parent));
   memset(level,-1,sizeof(level));

   level[start]=0;
    
   list<int>VertexQueue;  // Queue for implementing BFS
   VertexQueue.push_back(s); 
	
   while(!VertexQueue.empty()){
		
     int newvertex=VertexQueue.front();
	    
     // do something......
	
     for(....){
	
	if(....){
	
	   VertexQueue.push_back(somevertex);
	
	}
     } 
     
     VertexQueue.pop_front();
   }
		
	
}

/****** Depth First Search in Directed Graphs ********/

/*
vl adjList(100005);

int parent[100005];
int status[100005];
int n,m;

// Bro Tip :- While using DFS or any other recursive function,iterator should be local 

void dfs_explore(int start){

   status[start]=1; // Goes into recursion stack

   list<int>::iterator it;

   for(it=adjList[start].begin();it!=adjList[start].end();it++){

       if(parent[*it]==-1){

           parent[*it]=start;
           dfs_explore(*it);
       }

       else{

           if(status[*it]==1)
           	   printf("%d ---> %d is a backward edge\n",start,*it);
       }
   }
   status[start]=0;
}

void dfs(){

   for(int i=1;i<=n;++i){
 
      if(parent[i]==-1){

          parent[i]=0;
          dfs_explore(i);

      }
   }

}

*/

/**** DFS in undirected Graphs with option to detect cycle. *****/

/*
   vl adjList(100005);
int n,m;
int parent[100005];
int status[100005];

bool check;

void dfs_explore(int start){

   list<int>::iterator it;

   int flag=0;

   for(it=adjList[start].begin();it!=adjList[start].end();it++){

       if(parent[*it]==-1){

           parent[*it]=start;
           dfs_explore(*it);
       }

       else{

           if(parent[start]!=*it){
           	   
                flag=1;
                break;
           }
       }

   }

   if(flag==1)
       check=true;
 
   //status[start]=0;
}

void dfs(){

  // int ans=0;

   for(int i=1;i<=n;++i){

       if(parent[i]==-1){

           //printf("Hello\n");
           check=false;
           parent[i]=0;
           dfs_explore(i);
           
           if(check==false) // If cycle not found
               printf("Cycle not found in this component\n");
       }
   }

  // printf("%d\n",ans);

}
*/

/****** Nth Fibonacci in logn *******/

long long int fib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0]%1000000007;

}
void power(long long int F[2][2],long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(long long int F[2][2],long long int M[2][2])
{
  long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x%1000000007;
  F[0][1] = y%1000000007;
  F[1][0] = z%1000000007;
  F[1][1] = w%1000000007;
}

// ****** Range Minimum using Segment Trees ******  //

/*
long long seg[400011],a[400011];

long long construct(int node,int start,int end){

    if(start==end){
        seg[node]=a[start];
        return seg[node];
    }
    int mid=(start+end)>>1;

    int left=construct(node*2,start,mid);

    int right=construct(node*2+1,mid+1,end);

    seg[node]=min(left,right);
   
    return seg[node];
   
}

long long range_min(int node,int start,int end,int left,int right){


    if(start>right||end<left)
        return max;

    if(start>=left && end<=right)
         return seg[node];

   int mid=(start+end)>>1;

    return min(range_min(node*2,start,mid,left,right),range_min(node*2+1,mid+1,end,left,right));
}

// To build tree:- construct(1,1,n) 
// To build find minimum value in given range [l,r] :- range_min(1,1,n,l,r)

*/

int main(){
	
     
    



    return 0;
}
