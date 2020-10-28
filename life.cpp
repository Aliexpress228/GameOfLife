#include <TXLib.h>
int nei(int a[],int m,int n,int col,int line){
    int res=0;
    for(int i = m-1;i<m+2;i++){
        for(int j=n-1;j<n+2;j++){
            if (i>=0 && j>=0 && j<col && i<line)
                res = res + a[i*col+j];
        }
    }
    //cout << "\nresul" << res;
    return res - a[m * col + n];
}
int main(){
    txCreateWindow(900,600);
    int m,n;
    cin >> m;
    cin >> n;
    int curm[m][n], bufm[m][n];
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            curm[i][j]=0;
        }
    }
    curm[3][3]=1;
    curm[3][4]=1;
    curm[3][5]=1;
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            bufm[i][j]=curm[i][j];
        }
    }
    (TX_BLACK);
    txClear();
    txSetColor(TX_BLUE);
    txRectangle(0,0,10*m,10*n);
    txSetFillColor(TX_GREEN);
    txSetColor(TX_BLACK);
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(curm[i][j]==1){
                    txRectangle(i*10,j*10,i*10+10,j*10+10);
                }
            }
        }
    while(true){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nei(&curm[0][0],i,j,m,n)==3){
                     bufm[i][j] = 1;
                }
                if(nei(&curm[0][0],i,j,m,n)!=2 &&
                                nei(&curm[0][0],i,j,m,n)!=3){
                     bufm[i][j] = 0;
                }
            }
        }
        if (txMouseButtons() == 2){
            txSleep(100);
            while(txMouseButtons()!=2){
                if(txMouseButtons()==1){
                    bufm[txMouseX()/10][txMouseY()/10]=1;
                }
                txSetFillColor(TX_BROWN);
                txRectangle(0,0,10*m,10*n);
                txSetColor(RGB(200, 128, 128));
                for(int j=0;j<n;j++)
                    txLine(0,j*10,m*10,j*10);
                for(int j=0;j<m;j++)
                    txLine(j*10,0,j*10,n*10);
                txSetColor(TX_BLACK);
                txSetFillColor(TX_GREEN);
                for(int i = 0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(bufm[i][j]==1){
                            txRectangle(i*10,j*10,i*10+10,j*10+10);
                        }
                    }
                }
                txSleep(50);
            }
        }

        for(int i = 0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                curm[i][j]=bufm[i][j];
            }
        }
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor(TX_BLUE);
        txRectangle(0,0,10*m,10*n);
        txSetFillColor(TX_GREEN);
        txSetColor(RGB(128, 128, 128));
        for(int j=0;j<n;j++)
            txLine(0,j*10,m*10,j*10);
        for(int j=0;j<m;j++)
            txLine(j*10,0,j*10,n*10);
        txSetColor(TX_BLACK);
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(curm[i][j]==1){
                    txRectangle(i*10,j*10,i*10+10,j*10+10);
                }
            }
        }
        if(txMouseButtons()!=1){
                    bufm[txMouseX()/10][txMouseY()/10]=1;
            txSleep(150);
        }
        txSleep(50);
    }
    return 0;
}
