#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream infile;
    infile.open("e_shiny_selfies.txt");
    int n;
	infile>>n;
	char *ch=new char[n];
        int *M=new int[n];
        multimap<int, int> M_tagh;
        multimap<int, int> M_tagv;
        string** tag = new string*[n];
    int counth=0,countv=0;
	for(int i=0;i<n;i++){
        infile>>ch[i];
        if(ch[i]=='V') countv++;
        else counth++;
        infile>>M[i];
        if(ch[i]!='V')
            M_tagh.insert(pair<int, int>(M[i], i));
        else
            M_tagv.insert(pair<int, int>(M[i], i));
        tag[i] = new string[M[i]];
        for(int j=0; j<M[i]; j++){
            infile>>tag[i][j];
        }
    }
    infile.close();
    ofstream outfile;
    outfile.open("shiny_selfie_output.txt");
    int slides=(countv/2)+counth;
    outfile<<slides<<endl;

    vector<int> indexv ;
    vector<int> indexh ;

    int h_count=0, v_count=0 ;

    map<int, int>::iterator itr;
    for (itr = M_tagh.begin(); itr != M_tagh.end(); ++itr) {
             indexh.push_back(itr->second) ;
            h_count++ ;
    }
    for (itr = M_tagv.begin(); itr != M_tagv.end(); ++itr) {
             indexv.push_back(itr->second) ;
            v_count++ ;
    }

    int i, j, k;
    int n1 = h_count;
    int n2 = v_count;

    i = 0;
    j = 0;
    while (i < n1 && j+1 < n2)
    {
        if (indexh[i] <= indexv[j])
        {
            outfile<<indexh[i]<<endl ;
            i++;
        }
        else if(j+1<n2)
        {
            outfile<<indexv[j]<<" "<<indexv[j+1]<<endl ;
            j+=2;
        }
    }
    while (i < n1)
    {
        outfile<<indexh[i]<<endl ;
        i++;
    }
    while (j+1 < n2)
    {
        outfile<<indexv[j]<<" "<<indexv[j+1]<<endl ;
        j+=2 ;
    }

    /*int n2=n;
    int ind=0;
    int vind1=0;
    int vind2=0;
    int vx=0;

    while(n2>0){
        if(ch[ind]=='H'){
            outfile<<ind<<endl;
        }
        else{
            if(vx==0){
                vind1=ind;
                vx++;
            }
            else if(vx==1){
                vind2=ind;
                vx++;
            }
            if(vx==2){
                outfile<<vind1<<" "<<vind2<<endl;
                vind1=0;
                vind2=0;
                vx=0;
            }

        }
        ind++;
        n2--;
    }*/
    outfile.close();
	return 0;
}



