#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>


using namespace std;
#define len 12
#define test cout<<"bishier geschaft";
int xdif[len]={0};
int ydif[len]={0};
int monitorX =3000;
int monitorY =3000;

//it may be necessary to convert the second distances in chencking the next in step to to absolute values
//vlt. müssen die abstände imm 2ten schritt absolute sein

struct GUIControll{
    int name;
    int x;
    int y;
    int ID;
};
void prntarr(int arr[]){

        cout << " {";
        for (int i=0; i < len; ++i)
        {
            cout << arr[i] << ", ";
        }
        cout << arr[len-1] << "}\n";

}
void prntstruct(GUIControll arr[]){
    for(int i=0;i<len;++i) {
        //printf("%d\n",i);
        //printf("name:%d\n", arr[i].name);
        printf(" X:%d", arr[i].x);
        //printf("y:%d\n", arr[i].y);
        //printf("ID:%d\n", arr[i].ID);

    }
    printf("\n");
    for(int i=0;i<len;++i) {
        //printf("%d\n",i);
        //printf("name:%d\n", arr[i].name);
        //printf("X:%d\n", arr[i].x);
        printf( " y:%d", arr[i].y);
        //printf("ID:%d\n", arr[i].ID);

    }
    printf("\n");

}

void finddifference(GUIControll arr[len],int cuurr[],int xdif[len],int ydif[len]){


    for(int i=0;i<len;i++){
        xdif[i] =arr[i].x-cuurr[0];
        ydif[i] =arr[i].y-cuurr[1];
    }

}

int findmostnext(GUIControll arr[len],string dir,int cuurr[],int xdif[],int ydif[]){
    vector<int> best;
    finddifference(arr,cuurr,xdif,ydif);
    int kleinster = 0;

    if(dir =="UP") {

        int kleinster=0;
        int wertofbesty = -cuurr[1]-1; //so that it matches the check of difference and -1 so that it can detect points that life on perimeter
        for (int a=0; a < len; a++) {

            if ( ydif[a] >= wertofbesty && ydif[a] < 0) {
                kleinster = a;
                wertofbesty = ydif[a];
            }

        }

        for (int i=0; i < len; i++) {

            if (ydif[i] == wertofbesty) {
                best.push_back(i);
            }
        }
        int currentX = cuurr[0];
        kleinster = 0;
        for (int i=0; i < best.size(); i++) {
            if (xdif[best[i]] < xdif[kleinster]) {
                kleinster = i;
            }
        }
        return best[kleinster];
    }
    else if(dir =="DOWN") {
        kleinster = 0;
        int wertofbesty = monitorY;
        for (int i=0; i < len; i++) {
            if (ydif[i] <= wertofbesty && ydif[i] > 0) {
                kleinster = i;
                wertofbesty = ydif[i];
            }
        }
        for (int i=0; i < len; i++) {
            if (ydif[i] == wertofbesty) {
                best.push_back(i);
            }
        }
        int currentX = cuurr[0];
        kleinster = 0;
        for (int i=0; i < best.size(); i++) {
            if (xdif[best[i]] < xdif[kleinster]) {
                kleinster = i;
            }
        }
        return best[kleinster];
    }
    else if(dir =="RIGHT") {
        kleinster = 0;
        int wertofbestx = monitorX;
        for (int i=0; i < len; i++) {
            if (xdif[i] <= wertofbestx && xdif[i] > 0) {
                kleinster = i;
                wertofbestx = xdif[i];
            }
        }
        for (int i=0; i < len; i++) {
            if (xdif[i] == wertofbestx) {
                best.push_back(i);
            }
        }
        int currentY = cuurr[1];
        kleinster = 0;
        for (int i=0; i < best.size(); i++) {
            if (ydif[best[i]] < ydif[kleinster]) {
                kleinster = i;
            }
        }
        return best[kleinster];
    }
    else if(dir =="LEFT") {
        kleinster = 0;
        int wertofbestx = -cuurr[0]-1;
        for (int i=0; i < len; i++) {
            if (xdif[i] >= wertofbestx && xdif[i] < 0) {
                kleinster = i;
                wertofbestx = xdif[i];
            }
        }
        for (int i=0; i < len; i++) {
            if (xdif[i] == wertofbestx) {
                best.push_back(i);
            }
        }
        int currentY = cuurr[1];
        kleinster = 0;
        for (int i=0; i < best.size(); i++) {
            if (ydif[best[i]] < ydif[kleinster]) {
                kleinster = i;
            }
        }
        return best[kleinster];
    }
    else{cout<<"erroro";}//do nothing;

}
int main() {
    /*GUIControll myGUI[len] ;
    for(int i=0;i<len;i++){
        myGUI[i].name = int(rand()%6);
        myGUI[i].x = int(rand()%6);
        myGUI[i].y = int(rand()%6);
        myGUI[i].ID = int(rand()%6);


    }*/
    GUIControll myGUI[len] = { { 0,5 ,4, 10},
                               { 1,4 ,0, 0},
                               { 2,2 ,5, 0},
                               { 3,3 ,1, 0},
                               { 4,2 ,3, 0},
                               { 5,0 ,2, 0},
                               { 6,4 ,3, 0},
                               { 7,5 ,5, 0},
                               { 8,0 ,3, 0},
                               { 9,1 ,1, 0},
                               { 10,-1 ,2, 0},
                               { 11,2 ,3, 0}
    };int cuurr[2];

    cuurr[0] = 3;
    cuurr[1] = 3;


    //prntstruct(myGUI);

    int d =findmostnext(myGUI,"DOWN",cuurr,xdif,ydif);
    cout<<endl;
    cout<<"ba";
    cout<<d<<endl;cout<<"ba";

    return 0;
}

/*
for(const auto& name_of_elemt : name of source) {   // Range-for!
std::cout << text << std::endl;
}
*/
