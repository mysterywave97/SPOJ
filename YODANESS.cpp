#include<bits/stdc++.h>
using namespace std;
long long int count1;
void merge(int a[],int low,int mid,int high){
/*	cout<<low<<" "<<mid<<" "<<high<<"\n";
	cout<<"arrayb- ";
	for(int i=low;i<=high;i++)
	cout<<a[i]<<" ";
	cout<<"\n";*/
	vector<int> b,c;
	//int b[20000],c[20000];
	int m=0,n=0;
	for(int i=low;i<=mid;i++){
	//b[m]=a[i];
	b.push_back(a[i]);
	m++;
}
	for(int i=mid+1;i<=high;i++){
	//c[n]=a[i];
	c.push_back(a[i]);
	n++;
}
/*	for(int i=0;i<m;i++)
	    cout<<b[i]<<" ";
	    cout<<"\n";
	for(int i=0;i<n;i++)
	    cout<<c[i]<<" ";
	    cout<<"\n";*/
	int i=0,j=0,k=low;
	while((i<m) && (j<n)){
		if(b[i]<=c[j]){
			a[k]=b[i];
			k++;
			i++;
		}
		else if(c[j]<b[i]){
			count1=count1+(m-i);
			a[k]=c[j];
			k++;
			j++;
		}
	}
	while(i<m){
		a[k++]=b[i++];
	}
	while(j<n){
		a[k++]=c[j++];
	}
	/*cout<<"array-";
	for(int i=0;i<k;i++)
	cout<<a[i]<<" ";
	cout<<"\n";*/
}
void merge_sort(int a[],int low,int high){
//	cout<<low<<" "<<high<<"\n";
	if(low>=high)
	return;
	int mid=(low+high)/2;
	merge_sort(a,low,mid);
	merge_sort(a,mid+1,high);
	merge(a,low,mid,high);
}
int main(){
	int t;
	cin>>t;
	for(int e=0;e<t;e++){
		count1=0;
		int n;
		cin>>n;
		vector<string> words;
		int aux[30005];
		map<string,int> dictionary;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			words.push_back(s);
		}
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			dictionary.insert(pair<string,int>(s,i));
		}
		for(int i=0;i<n;i++){
			aux[i]=dictionary[words[i]];
		}
	//	for(int i=0;i<n;i++)
	//	cout<<aux[i]<<" ";
		/*map<string,int>::iterator iter;
		iter=words.begin();
		for(;iter!=words.end();++iter){
			cout<<iter->first<<" "<<iter->second<<"\n";
		}*/
		merge_sort(aux,0,n-1);
	   // for(int i=0;i<n;i++)
	    //cout<<a[i]<<" ";
	    cout<<count1<<"\n";
	}
	return 0;
}
