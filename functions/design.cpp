#include<iostream>
#include<iomanip>



void menu()
{
    cout<<setw(69)<<"1.One Player"<<endl;
    cout<<setw(70)<<"2.Multiplayer"<<endl;
    cout<<setw(64)<<"3.About"<<endl;
}

int difficulty()
{
    int x;
    cout<<"Select Difficulty level(1-49): ";
    cin>>x;
    return x;
}

int finalscore(player arr[], player AI,int number,int men,int mode)
{
    player tmp(1);
    int tp;
    cout<<"Game Over!!\n"<<endl;
    if(mode==1)
    {
        for(int i=0;i<number;i++)
        {
            for(int j=0;j<number-1;j++)
            {
                if(arr[j].getscore()<arr[j+1].getscore())
                {
                    tmp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=tmp;
                }
            }
        }
        if(AI.getscore()>arr[0].getscore())
        {
            cout<<"Computer has won the game"<<endl;
            tp=1;
        }
        else if(number==1)
            cout<<arr[0].dispname()<<" has won the game"<<endl;
    
        cout<<"The final scores are\n"<<endl;
        cout<<"Rank ------>Name ------> Score"<<endl;
        if(tp==1)
        cout<<"1."<<" ------> "<<AI.dispname()<<" ------> "<<AI.getscore()<<endl;
    
        for(int i=0;i<number;i++)
            cout<<i+1<<". ------> "<<arr[i].dispname()<<" ------> "<<arr[i].getscore()<<endl;
        if(men==1 && tp!=1)
            cout<<"2."<<" ------> "<<AI.dispname()<<" ------> "<<AI.getscore()<<endl;
    }
    else
    {
        if(men==1)
        {
            if(arr[0].errors<0)
                cout<<"Computer has won the game"<<endl;
            else
                cout<<arr[0].dispname()<<" has won the game"<<endl;
        }
        else
            for(int i=0;i<number;i++)
                if(arr[i].errors>=0)
                    cout<<arr[i].dispname()<<" has won the game"<<endl;
    }
    
    int x;
    cout<<"To play again enter 1 "<<endl;
    cout<<"To quit Enter any number"<<endl;
    cin>>x;
    if(x==1)
      return 1;
   else
     return 0;
}
