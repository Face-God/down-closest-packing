//
//  main.c
//  down closest packing
//  ver: beta-0.1
//  Created by God's face on 2019/12/18.
//  Copyright © 2019 God's face. All rights reserved.
//

#include <stdio.h>
//向下最密堆积算法核心
int videobit(int* map,int longbit,int longheight);//longbit=map总长度 longheight=map一行最大显示数
int* meson(int* broken,int longbit,int widebit);//longbit=map总长度 widebit=map一行最大显示数
//int* meson1(int* broken,int p,int q);//q=map行数 p=map列数//失败的算法

int map[96] = {
    0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,
    0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int broke[96] = {
    0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,
    0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,
    1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int main(void) {
    // insert code here...
    int* n;
    printf("map!\n");
    videobit(map,95,16);
    printf("broken map!\n");
    videobit(broke, 95, 16);/*95=最大数（96）减一*/
    printf("new map!!!\n");
    n = meson(broke, 95, 16);
    videobit(n, 95, 16);
    
    return 0;
}

int videobit(int* map,int longbit,int longheight){
    int i,p,h = 0;
    for (i=0; i<=longbit; i++) {
        h++;
        p=map[i];
        if (h==longheight) {
            printf("%d",p);
            printf("\n");
            h=0;
        }

        else if (p==0) {
            printf(" ");
        }
        else{
            printf("%d",p);
        }
    }
    return 0;
}

int* meson(int* broken,int longbit,int widebit){
    
    int maplong,n;
    int* newmap;
    newmap=broken;
    for (maplong=longbit; maplong>0; maplong--) {
        if (newmap[maplong]==0) {
            
            
            for (n=maplong-widebit; n>0; n=n-widebit) {
                if (newmap[n]==1) {
                    newmap[maplong]=1;
                    newmap[n]=0;
                    break;
                }
                /*if (maplong>widebit) {
                 n=maplong-widebit;
                 break;
                 }
                 else{
                 return  newmap;
                 }*/
            }
        }
    }
    return newmap;
}

/*int* meson1(int* broken,int longbit,int widebit){
    
    int maplong,n;
    int* newmap;
    newmap=broken;
    for (maplong=longbit; maplong>0; maplong--) {
        n=freem(newmap, longbit, widebit);
        if (n!=990) {
            newmap[n]=0;
            newmap[maplong]=1;
        }
    }
    return newmap;
}

int freem(int* newmap,int maplong,int widebit){
    int n,n1;
    n=maplong;
    n1=maplong;
    if (newmap[maplong]==0) {
        if (maplong>widebit) {
            n=n-widebit;
            n1=freem(newmap, n, widebit);
            if (n1==990) {
                return  990;
            }
        }
        else{
            return 990;
        }
    }
    return n1;
}
递归实现meson，未完成
 1.我不喜欢递归
 2.递归速度极慢
 3.留着它是因为日后实现其他功能时可能会用到*/

/*—————————————————————————————————————————————————————————————————————————————————————————————*/

/*int* meson1(int* broken,int p,int q){
    int nq,np,n,fn;
    int* newmap;
    newmap=broken;
    for (nq=q; nq!=0; nq--) {
        for (np=p; nq!=0; np--) {
            n = (nq-1)*p+nq;
            if (newmap[n]!=1) {
                for (fn=n-p; n<p; fn=fn-p) {
                    if (newmap[fn]==1) {
                        newmap[fn]=0;
                        newmap[n]=1;
                    }
                }
            }
        }
        
    }
    return newmap;
}
int* meson2(int* broken,int longbit,int widebit){
    
    int maplong,n;
    int* newmap;
    newmap=broken;
    for (maplong=longbit; maplong>0; maplong--) {
        if (newmap[maplong]==0) {
            if (maplong>widebit) {
                n=maplong-widebit;
                break;
            }
            else{
                return  newmap;
            }
        }
    }
    return newmap;
}
失败的函数，日后优化算法可能会用到*/
