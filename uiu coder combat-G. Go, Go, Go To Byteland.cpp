#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int> > adj(10000);
map<int, bool> vis;

ll ans[2000+100][2000 + 100] = {0};

void dfs(int sr, int parent)
{

   ans[parent][sr] = 1;
   vis[sr] = true;

   for (int i = 0; i < adj[sr].size(); i++)
   {
      if (!vis[adj[sr][i]])
      {

         dfs(adj[sr][i], parent);
      }
   }
}

int main()
{
   int t;
    scanf("%d",&t);
   while (t--)
   {
      adj.clear();

      for (int i = 0; i <= 10000; i++)
      {
         adj[i].clear();
      }

      for (int i =1; i <=2000+10; i++)
      {
         for (int j =1; j <=2000+10; j++)
         {
            ans[i][j]=0;
         }
         
      }
      

      vis.clear();

      int n;
      scanf("%d",&n);

      for (int i = 1; i <= n; i++)
      {
        
         char s[20000];
          scanf("%s",s);
         for (int j = 1; j <=n; j++)
         {

            if (s[j - 1] == '1')
            {
               adj[i].push_back(j);
              
            }
         }
      }

      for (int i = 1; i <= n; i++)
      {
         vis.clear();
         dfs(i, i);
      }

      for (int i = 1; i <= n; i++)
      {
         char res[20000];
          
         for (int j = 1; j <= n; j++)
         {
           
            if(ans[i][j]==1) res[j-1]='1';
            
            else res[j-1]='0';
            
         }
         res[n]='\0';
         
         printf("%s\n",res);
      }

     
   }
}
