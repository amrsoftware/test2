#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iterator>

using namespace std;

char grid[100][100];

//int number of 1`s
//(i,j) start point of region
int out_img(int i,int j,int n,const int &t){

	//Stop Case
    if(n==1 && grid[i][j]=='1')
        return 1;
    if(n==1 && grid[i][j]=='0')
        return 0;

    //get 4 region number of 1
    int Hn = n/2;
    int ur=out_img( i    ,j+Hn ,Hn ,t );	//upper-right
    int ul=out_img( i    ,j    ,Hn ,t );	//upper-left
    int ll=out_img( i+Hn ,j    ,Hn ,t );	//lower-left
    int lr=out_img( i+Hn ,j+Hn ,Hn ,t );	//lower-right

    //count 1
    int sum1 = 0;
    sum1 += ur;
    sum1 += ul;
    sum1 += ll;
    sum1 += lr;

    //count 0
    int sum0 = 0;
    sum0 += n*n;
    sum0 -= sum1;

    //check counter
    char   all  = 'x';
    float  nn   = n*n;
    int    zero = sum0/nn *100;
    int    one  = sum1/nn *100;

    if(zero>=t)
        all='0';
    if(one>=t)
        all='1';

    //Change Grid
    if(all!='x')
    for(int k=0; k<n; k++)
    for(int o=0; o<n; o++)
        grid[i+k][j+o]=all;

    //Return Sum of 1`s
    return sum1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ( "input.txt","rt",stdin );	//Read Input From File
    freopen ("output.txt","wt",stdout);	//Put Output In File
#endif


    //INPUT
    int n,t;
    char x;
    int icase = 1;	//Case Number
    scanf("%d %d\n", &n , &t);
    

    while(n!=0){
        
        //Input Grid Color
        //White 0
        //Black 1
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%c",&x);
            grid[i][j]=x;
        }scanf("%c",&x);	//To get \n
        }

        //Call Function
        out_img(0,0,n,t);

        //Output Case Number
        printf("Image %d:\n",icase);
		
		//Output Grid Color
        //White 0
        //Black 1
        for(int i=0 ; i<n; i++){
        for(int j=0 ; j<n; j++){
            x=grid[i][j];
            printf("%c",x);
        }printf("\n");
        }

        //Input New n,t
        scanf("%d %d\n",&n,&t);
        icase++;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);	//Close Input File
    fclose(stdout);	//Close Output File
#endif
    return 0;

}
