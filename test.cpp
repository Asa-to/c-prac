#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10000;
struct node{
	int l,r,p,s,deg,dep,h;
};
int n,v,l1,r1,tmp,root;
int vis[N]={0};
node tree[N];


int build(int k,int depth){
	if ((tree[k].l==-1)&&(tree[k].r==-1)) {
		tree[k].deg=0;
		tree[k].dep=depth;
		return tree[k].h=0;
	}
	else if ((tree[k].l!=-1)&&(tree[k].r!=-1)){
		tree[tree[k].l].p=k;
       	tree[tree[k].r].p=k;
		tree[tree[k].l].s=tree[k].r;
		tree[tree[k].r].s=tree[k].l;
		tree[k].deg=2;
		tree[k].dep=depth;
		return tree[k].h=max(build(tree[k].l,depth+1),build(tree[k].r,depth+1))+1;
	}
	else if (tree[k].l!=-1){
		tree[tree[k].l].p=k;

		tree[tree[k].l].s=-1;


		tree[k].deg=1;
		tree[k].dep=depth;
		return tree[k].h=build(tree[k].l,depth+1)+1;		
	}
	else if (tree[k].r!=-1){

       	tree[tree[k].r].p=k;

		tree[tree[k].r].s=-1;
		
		tree[k].deg=1;
		tree[k].dep=depth;
		return tree[k].h=build(tree[k].r,depth+1)+1;		
	}
  return -1;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v>>l1>>r1;
		tree[v].l=l1;
		tree[v].r=r1;
		if (tree[v].l!=-1) vis[tree[v].l]=1;
		if (tree[v].r!=-1) vis[tree[v].r]=1;
	}
	for(int i=0;i<n;i++){
		if (vis[i]==0){
			root=i;
			break;
		}
	}
	build(root,0);
	tree[root].p=-1;
	tree[root].s=-1;
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].p,tree[i].s,tree[i].deg,tree[i].dep,tree[i].h);
		if (i==root) printf("root");
		else if(tree[i].l==-1&&tree[i].r==-1) printf("leaf");
		else printf("internal node");
		printf("\n");
	}
	return 0;
}