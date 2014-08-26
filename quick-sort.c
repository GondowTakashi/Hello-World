//クイックソートバブルソートを含む
#include  <stdio.h>

void QSort(int x[10], int left, int right);
void BubSort(int x[10], int n);
void Swap(int x[10], int i, int j);
void ShowData(int x[10]);
int main(void);

  /* クイックソートを行う */
void QSort(int x[10], int left, int right)
{
    int i, j;
    int pivot;

    i = left;                      /* ソートする配列の一番小さい要素の添字 */
    j = right;                     /* ソートする配列の一番大きい要素の添字 */

    pivot = x[(left + right) / 2]; /* 基準値を配列の中央付近にとる */

    while (1) {                    /* 無限ループ */

        while (x[i] < pivot)       /* pivot より大きい値が */
            i++;                   /* 出るまで i を増加させる */

        while (pivot < x[j])       /* pivot より小さい値が */
            j--;                   /*  出るまで j を減少させる */
        if (i >= j)                /* i >= j なら */
            break;                 /* 無限ループから抜ける */

        Swap(x, i, j);             /* x[i] と x[j]を交換 */
        i++;                       /* 次のデータ */
        j--;
    }
    ShowData(x);               /* 途中経過を表示 */

    if (left < i - 1)              /* 基準値の左に 2 以上要素があれば */
        QSort(x, left, i - 1);     /* 左の配列を Q ソートする */
    if (j + 1 <  right)            /* 基準値の右に 2 以上要素があれば */
        QSort(x, j + 1, right);    /* 右の配列を Q ソートする */
}
  /* バブルソートを行う */
void BubSort(int x[10], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (x[j - 1] > x[j]) {  /* 前の要素の方が大きかったら */
                temp = x[j];        /* 交換する */
                x[j] = x[j - 1];
                x[j - 1]= temp;
            }
        }   
        /* ソートの途中経過を表示 */
        ShowData(x);
    }
}

  /* 配列の要素を交換する */
void Swap(int x[10], int i, int j)
{
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}


  /* n 個のデータを表示する */
void ShowData(int x[10])
{
    int i;

    for (i = 0; i <10 ; i++)
        printf("%d  ", x[i]);
    printf("\n");
}

int main(void)
{      /* ソートする配列 */
        int x[10],y[10];
        for(int i=0;i<10;i++){
                scanf("%d",&x[i]);
                y[i]=x[i];
            }

    //クイックソート部
    printf("ソート前:\n");
    ShowData(x);
    printf("ソート中:\n");
    BubSort(x,10);
    printf("ソート後:\n");
    ShowData(x);

    //バブルソート部
    printf("ソート前:\n");
    ShowData(y);
    printf("ソート中:\n");
    QSort(y, 0,10 - 1);
    printf("ソート後:\n");
    ShowData(y);



        return 0;
}