#include<stdio.h>    
#include<string.h>    
#include <stdlib.h>
#include <time.h>      
#include <math.h>    
#include <malloc.h>    
#define MAX 100    
#define LEN sizeof(struct slink)    
void sub(int a[MAX], int b[MAX], int c[MAX]);
struct slink
{
    int  bignum[MAX];
    struct slink* next;
};
//大数运算库
void  print(int a[MAX])
{
    int i;
    for (i = 0; i < a[99]; i++)
        printf("%d", a[a[99] - i - 1]);
    printf("\n\n");
    return;
}
int  cmp(int a1[MAX], int a2[MAX])
{
    int l1, l2;
    int i;
    l1 = a1[99];
    l2 = a2[99];
    if (l1 > l2)
        return 1;
    if (l1 < l2)
        return -1;
    for (i = (l1 - 1); i >= 0; i--)
    {
        if (a1[i] > a2[i])
            return 1;
        if (a1[i] < a2[i])
            return -1;
    }
    return 0;
}
void mov(int a[MAX], int* b)
{
    int j;
    for (j = 0; j < MAX; j++)
        b[j] = a[j];
    return;
}
void mul(int a1[MAX], int a2[MAX], int* c)
{
    int i, j;
    int y;
    int x;
    int z;
    int w;
    int l1, l2;
    l1 = a1[MAX - 1];
    l2 = a2[MAX - 1];
    if (a1[MAX - 2] == '-' && a2[MAX - 2] == '-')
        c[MAX - 2] = 0;
    else if (a1[MAX - 2] == '-')
        c[MAX - 2] = '-';
    else if (a2[MAX - 2] == '-')
        c[MAX - 2] = '-';
    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < l2; j++)
        {
            x = a1[i] * a2[j];
            y = x / 10;
            z = x % 10;
            w = i + j;
            c[w] = c[w] + z;
            c[w + 1] = c[w + 1] + y + c[w] / 10;
            c[w] = c[w] % 10;
        }
    }
    w = l1 + l2;
    if (c[w - 1] == 0)w = w - 1;
    c[MAX - 1] = w;
    return;
}
void add(int a1[MAX], int a2[MAX], int* c)
{
    int i, l1, l2;
    int len, temp[MAX];
    int k = 0;
    l1 = a1[MAX - 1];
    l2 = a2[MAX - 1];
    if ((a1[MAX - 2] == '-') && (a2[MAX - 2] == '-'))
    {
        c[MAX - 2] = '-';
    }
    else if (a1[MAX - 2] == '-')
    {
        mov(a1, temp);
        temp[MAX - 2] = 0;
        sub(a2, temp, c);
        return;
    }
    else if (a2[MAX - 2] == '-')
    {
        mov(a2, temp);
        temp[98] = 0;
        sub(a1, temp, c);
        return;
    }
    if (l1 < l2)len = l1;
    else len = l2;
    for (i = 0; i < len; i++)
    {
        c[i] = (a1[i] + a2[i] + k) % 10;
        k = (a1[i] + a2[i] + k) / 10;
    }
    if (l1 > len)
    {
        for (i = len; i < l1; i++)
        {
            c[i] = (a1[i] + k) % 10;
            k = (a1[i] + k) / 10;
        }
        if (k != 0)
        {
            c[l1] = k;
            len = l1 + 1;
        }
        else len = l1;
    }
    else
    {
        for (i = len; i < l2; i++)
        {
            c[i] = (a2[i] + k) % 10;
            k = (a2[i] + k) / 10;
        }
        if (k != 0)
        {
            c[l2] = k;
            len = l2 + 1;
        }
        else len = l2;
    }
    c[99] = len;
    return;
}
void sub(int a1[MAX], int a2[MAX], int* c)
{
    int i, l1, l2;
    int len, t1[MAX], t2[MAX];
    int k = 0;
    l1 = a1[MAX - 1];
    l2 = a2[MAX - 1];
    if ((a1[MAX - 2] == '-') && (a2[MAX - 2] == '-'))
    {
        mov(a1, t1);
        mov(a2, t2);
        t1[MAX - 2] = 0;
        t2[MAX - 2] = 0;
        sub(t2, t1, c);
        return;
    }
    else if (a2[MAX - 2] == '-')
    {
        mov(a2, t2);
        t2[MAX - 2] = 0;
        add(a1, t2, c);
        return;
    }
    else if (a1[MAX - 2] == '-')
    {
        mov(a2, t2);
        t2[MAX - 2] = '-';
        add(a1, t2, c);
        return;
    }
    if (cmp(a1, a2) == 1)
    {
        len = l2;
        for (i = 0; i < len; i++)
        {
            if ((a1[i] - k - a2[i]) < 0)
            {
                c[i] = (a1[i] - a2[i] - k + 10) % 10;
                k = 1;
            }
            else
            {
                c[i] = (a1[i] - a2[i] - k) % 10;
                k = 0;
            }
        }
        for (i = len; i < l1; i++)
        {
            if ((a1[i] - k) < 0)
            {
                c[i] = (a1[i] - k + 10) % 10;
                k = 1;
            }
            else
            {
                c[i] = (a1[i] - k) % 10;
                k = 0;
            }
        }
        if (c[l1 - 1] == 0)
        {
            len = l1 - 1;
            i = 2;
            while (c[l1 - i] == 0)
            {
                len = l1 - i;
                i++;
            }
        }
        else
        {
            len = l1;
        }
    }
    else
        if (cmp(a1, a2) == (-1))
        {
            c[MAX - 2] = '-';
            len = l1;
            for (i = 0; i < len; i++)
            {
                if ((a2[i] - k - a1[i]) < 0)
                {
                    c[i] = (a2[i] - a1[i] - k + 10) % 10;
                    k = 1;
                }
                else
                {
                    c[i] = (a2[i] - a1[i] - k) % 10;
                    k = 0;
                }
            }
            for (i = len; i < l2; i++)
            {
                if ((a2[i] - k) < 0)
                {
                    c[i] = (a2[i] - k + 10) % 10;
                    k = 1;
                }
                else
                {
                    c[i] = (a2[i] - k) % 10;
                    k = 0;
                }
            }
            if (c[l2 - 1] == 0)
            {
                len = l2 - 1;
                i = 2;
                while (c[l1 - i] == 0)
                {
                    len = l1 - i;
                    i++;
                }

            }
            else len = l2;
        }

        else if (cmp(a1, a2) == 0)
        {
            len = 1;
            c[len - 1] = 0;
        }
    c[MAX - 1] = len;
    return;
}
void  mod(int a[MAX], int b[MAX], int* c)/*/c=a mod b//注意：经检验知道此处A和C的数组都改变了。*/
{
    int d[MAX];
    mov(a, d);
    while (cmp(d, b) != (-1))/*/c=a-b-b-b-b-b.......until(c<b)*/
    {
        sub(d, b, c);
        mov(c, d);/*/c复制给a*/
    }
    return;
}


void  divt(int t[MAX], int b[MAX], int* c, int* w)/*//试商法//调用以后w为a mod b, C为a  div b;*/
{
    int a1, b1, i, j, m;/*w用于暂时保存数据*/
    int d[MAX], e[MAX], f[MAX], g[MAX], a[MAX];
    mov(t, a);
    for (i = 0; i < MAX; i++)
        e[i] = 0;
    for (i = 0; i < MAX; i++)
        d[i] = 0;
    for (i = 0; i < MAX; i++) g[i] = 0;
    a1 = a[MAX - 1];
    b1 = b[MAX - 1];
    if (cmp(a, b) == (-1))
    {
        c[0] = 0;
        c[MAX - 1] = 1;
        mov(t, w);
        return;
    }
    else if (cmp(a, b) == 0)
    {
        c[0] = 1;
        c[MAX - 1] = 1;
        w[0] = 0;
        w[MAX - 1] = 1;
        return;
    }
    m = (a1 - b1);
    for (i = m; i >= 0; i--)/*341245/3=341245-300000*1--->41245-30000*1--->11245-3000*3--->2245-300*7--->145-30*4=25--->25-3*8=1*/
    {
        for (j = 0; j < MAX; j++)
            d[j] = 0;
        d[i] = 1;
        d[MAX - 1] = i + 1;
        mov(b, g);
        mul(g, d, e);
        while (cmp(a, e) != (-1))
        {
            c[i]++;
            sub(a, e, f);
            mov(f, a);/*f复制给g*/
        }
        for (j = i; j < MAX; j++)/*高位清零*/
            e[j] = 0;
    }
    mov(a, w);
    if (c[m] == 0) c[MAX - 1] = m;
    else c[MAX - 1] = m + 1;
    return;
}
void mulmod(int a[MAX], int b[MAX], int n[MAX], int* m)/*解决 了 m=a*b mod n;*/
{
    int c[MAX], d[MAX];
    int i;
    for (i = 0; i < MAX; i++)
        d[i] = c[i] = 0;
    mul(a, b, c);
    divt(c, n, d, m);
    for (i = 0; i < m[MAX - 1]; i++)
        printf("%d", m[m[MAX - 1] - i - 1]);
    printf("\nm  length is :  %d \n", m[MAX - 1]);
}
void expmod(int a[MAX], int p[MAX], int n[MAX], int* m)
{
    int t[MAX], l[MAX], temp[MAX]; /*/t放入2，l放入1；*/
    int w[MAX], s[MAX], c[MAX], b[MAX], i;
    for (i = 0; i < MAX - 1; i++)
        b[i] = l[i] = t[i] = w[i] = 0;
    t[0] = 2; t[MAX - 1] = 1;
    l[0] = 1; l[MAX - 1] = 1;
    mov(l, temp);
    mov(a, m);
    mov(p, b);
    while (cmp(b, l) != 0)
    {
        for (i = 0; i < MAX; i++)
            w[i] = c[i] = 0;
        divt(b, t, w, c);/*// c=p mod 2  w= p /2*/
        mov(w, b);/*//p=p/2*/
        if (cmp(c, l) == 0) /*/余数c==1*/
        {
            for (i = 0; i < MAX; i++)
                w[i] = 0;
            mul(temp, m, w);
            mov(w, temp);
            for (i = 0; i < MAX; i++)
                w[i] = c[i] = 0;
            divt(temp, n, w, c);/* /c为余c=temp % n，w为商w=temp/n */
            mov(c, temp);
        }
        for (i = 0; i < MAX; i++)
            s[i] = 0;
        mul(m, m, s);//s=a*a    
        for (i = 0; i < MAX; i++)
            c[i] = 0;
        divt(s, n, w, c);/*/w=s/n;c=s mod n*/
        mov(c, m);
    }
    for (i = 0; i < MAX; i++)
        s[i] = 0;
    mul(m, temp, s);
    for (i = 0; i < MAX; i++)
        c[i] = 0;
    divt(s, n, w, c);
    mov(c, m);/*余数s给m*/
    m[MAX - 2] = a[MAX - 2];/*为后面的汉字显示需要，用第99位做为标记*/
    return;
}
int   is_prime_san(int p[MAX])
{
    int i, a[MAX], t[MAX], s[MAX], o[MAX];
    for (i = 0; i < MAX; i++)
        s[i] = o[i] = a[i] = t[i] = 0;
    t[0] = 1;
    t[MAX - 1] = 1;
    a[0] = 2;
    a[MAX - 1] = 1;
    sub(p, t, s);
    expmod(a, s, p, o);
    if (cmp(o, t) != 0)
    {
        return 0;
    }
    a[0] = 3;
    for (i = 0; i < MAX; i++)  o[i] = 0;
    expmod(a, s, p, o);
    if (cmp(o, t) != 0)
    {
        return 0;
    }
    a[0] = 5;
    for (i = 0; i < MAX; i++)  o[i] = 0;
    expmod(a, s, p, o);
    if (cmp(o, t) != 0)
    {
        return 0;
    }
    a[0] = 7;
    for (i = 0; i < MAX; i++)  o[i] = 0;
    expmod(a, s, p, o);
    if (cmp(o, t) != 0)
    {
        return 0;
    }
    return 1;
}
int coprime(int e[MAX], int s[MAX]) /*//// 求两个大数之间是否互质////*/

{
    int a[MAX], b[MAX], c[MAX], d[MAX], o[MAX], l[MAX];
    int i;
    for (i = 0; i < MAX; i++)
        l[i] = o[i] = c[i] = d[i] = 0;
    o[0] = 0; o[MAX - 1] = 1;
    l[0] = 1; l[MAX - 1] = 1;
    mov(e, b);
    mov(s, a);
    do
    {
        if (cmp(b, l) == 0)
        {
            return 1;
        }
        for (i = 0; i < MAX; i++)
            c[i] = 0;
        divt(a, b, d, c);
        mov(b, a);
        mov(c, b);
    } while (cmp(c, o) != 0);
    return 0;
}
void prime_random(int* p, int* q)
{
    int i, k;
    time_t t;
    p[0] = 1;
    q[0] = 3;
    p[MAX - 1] = 10;
    q[MAX - 1] = 11;
    do
    {
        t = time(NULL);
        srand((unsigned long)t);
        for (i = 1; i < p[MAX - 1] - 1; i++)
        {
            k = rand() % 10;
            p[i] = k;
        }
        k = rand() % 10;
        while (k == 0)
        {
            k = rand() % 10;
        }
        p[p[MAX - 1] - 1] = k;
    } while ((is_prime_san(p)) != 1);
    printf("素数 p 为  : ");
    for (i = 0; i < p[MAX - 1]; i++)
    {
        printf("%d", p[p[MAX - 1] - i - 1]);
    }
    printf("\n正在生成素数q......\n");
    do
    {
        t = time(NULL);
        srand((unsigned long)t);
        for (i = 1; i < q[MAX - 1]; i++)
        {
            k = rand() % 10;
            q[i] = k;
        }
    } while ((is_prime_san(q)) != 1);
    printf("素数 q 为 : ");
    for (i = 0; i < q[MAX - 1]; i++)
    {
        printf("%d", q[q[MAX - 1] - i - 1]);
    }
    printf("\n正在生成一个与(p-1)*(q-1)互素的e......\n");
    return;
}
void  erand(int e[MAX], int m[MAX])
{
    int i, k;
    time_t t;
    e[MAX - 1] = 5;
    printf("\ne为:");
    do
    {
        t = time(NULL);
        srand((unsigned long)t);
        for (i = 0; i < e[MAX - 1] - 1; i++)
        {
            k = rand() % 10;
            e[i] = k;
        }
        while ((k = rand() % 10) == 0)
            k = rand() % 10;
        e[e[MAX - 1] - 1] = k;
    } while (coprime(e, m) != 1);
    for (i = 0; i < e[MAX - 1]; i++)
    {
        printf("%d", e[e[MAX - 1] - i - 1]);
    }
    printf("\n");
    return;
}
void rsad(int e[MAX], int g[MAX], int* d)
{
    int   r[MAX], n1[MAX], n2[MAX], k[MAX], w[MAX];
    int     i, t[MAX], b1[MAX], b2[MAX], temp[MAX];
    mov(g, n1);
    mov(e, n2);
    for (i = 0; i < MAX; i++)
        k[i] = w[i] = r[i] = temp[i] = b1[i] = b2[i] = t[i] = 0;
    b1[MAX - 1] = 0; b1[0] = 0;/*/b1=0;*/
    b2[MAX - 1] = 1; b2[0] = 1;/*/b2=1;*/
    while (1)
    {
        for (i = 0; i < MAX; i++)
            k[i] = w[i] = 0;
        divt(n1, n2, k, w);/*/k=n1/n2;*/
        for (i = 0; i < MAX; i++)
            temp[i] = 0;
        mul(k, n2, temp);/*/temp=k*n2;*/
        for (i = 0; i < MAX; i++)
            r[i] = 0;
        sub(n1, temp, r);
        if ((r[MAX - 1] == 1) && (r[0] == 0))/*/r=0*/
        {
            break;
        }
        else
        {
            mov(n2, n1);/*/n1=n2;*/
            mov(r, n2);/*/n2=r;*/
            mov(b2, t);/*/t=b2;*/
            for (i = 0; i < MAX; i++)
                temp[i] = 0;
            mul(k, b2, temp);/*/b2=b1-k*b2;*/
            for (i = 0; i < MAX; i++)
                b2[i] = 0;
            sub(b1, temp, b2);
            mov(t, b1);
        }
    }
    for (i = 0; i < MAX; i++)
        t[i] = 0;
    add(b2, g, t);
    for (i = 0; i < MAX; i++)
        temp[i] = d[i] = 0;
    divt(t, g, temp, d);
    printf("解密密钥d为：");
    for (i = 0; i < d[MAX - 1]; i++)
        printf("%d", d[d[MAX - 1] - i - 1]);
    printf("\n");
}
unsigned long  rsa(unsigned long p, unsigned long q, unsigned long e)
{
    unsigned long g, k, r, n1, n2, t;
    unsigned long b1 = 0, b2 = 1;
    g = (p - 1) * (q - 1);
    n1 = g;
    n2 = e;
    while (1)
    {
        k = n1 / n2;
        r = n1 - k * n2;
        if (r != 0)
        {
            n1 = n2;
            n2 = r;
            t = b2;
            b2 = b1 - k * b2;
            b1 = t;
        }
        else
        {
            break;
        }
    }
    return (g + b2) % g;
}
void  printbig(struct slink* h)
{
    struct slink* p;
    int i;
    p = (struct slink*)malloc(LEN);
    p = h;
    if (h != NULL)
        do
        {
            for (i = 0; i < p->bignum[MAX - 1]; i++)
                printf("%d", p->bignum[p->bignum[MAX - 1] - i - 1]);
            p = p->next;
        }
    while (p != NULL);
        printf(" \n");
}
void  tencrypto(int e[MAX], int n[MAX])/*//对有需要的文件进行加密*/
{
    FILE* fp;
    int i, k, count, temp, c;
    char filename[25], ch;
    struct slink* p, * p1, * p2;
    struct slink* h;
    h = p = p1 = p2 = (struct slink*)malloc(LEN);
    h = NULL;
    printf("请输入要加密的文件名 : ");
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open file !\n");
        exit(0);
    }
    count = 0;
    printf("正在加密文件，请稍候......");
    while ((ch = fgetc(fp)) != EOF)
    {
        c = ch;
        k = 0;
        if (c < 0)
        {
            c = abs(c);/*/把负数取正并且做一个标记*/
            p1->bignum[MAX - 2] = '0';
        }
        else
        {
            p1->bignum[MAX - 2] = '1';
        }
        while (c / 10 != 0)
        {
            temp = c % 10;
            c = c / 10;
            p1->bignum[k] = temp;
            k++;
        }
        p1->bignum[k] = c;
        p1->bignum[MAX - 1] = k + 1;
        count = count + 1;
        if (count == 1)
            h = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct slink*)malloc(LEN);
    }
    p2->next = NULL;
    printf("\n");
    fclose(fp);
    fp = fopen("encryfile.txt", "w");
    p = p1 = (struct slink*)malloc(LEN);
    p = h;
    if (h != NULL)
        do
        {
            expmod(p->bignum, e, n, p1->bignum);
            ch = p1->bignum[MAX - 2];
            fputc(ch, fp);
            if ((p1->bignum[MAX - 1] / 10) == 0)/*/判断p1->bignum[99]的是否大于十；*/
            {
                ch = 0 + 48;
                fputc(ch, fp);
                ch = p1->bignum[MAX - 1] + 48;
                fputc(ch, fp);
            }
            else
            {
                ch = p1->bignum[MAX - 1] / 10 + 48;
                fputc(ch, fp);
                ch = p1->bignum[MAX - 1] % 10 + 48;
                fputc(ch, fp);
            }
            for (i = 0; i < p1->bignum[MAX - 1]; i++)
            {
                ch = p1->bignum[i] + 48;
                fputc(ch, fp);
            }
            p = p->next;
            p1 = (struct slink*)malloc(LEN);
        } while (p != NULL);
        printf("\n");
        fclose(fp);
        return;
}
void  tdecrypto(int d[MAX], int n[MAX])
{
    FILE* fp;
    struct slink* h, * p1, * p2;
    char ch;
    int i, j, k, c, count, temp;
    if ((fp = fopen("encryfile.txt", "r")) == NULL)
    {
        printf("此文件不存在!\n");
        exit(0);
    }
    printf("正在解密文件，请稍候......");
    i = 0;
    j = 3;
    count = 0;
    h = p1 = p2 = (struct slink*)malloc(LEN);
    while ((ch = fgetc(fp)) != EOF)
    {
        c = ch;
        if (j == 3)
        {
            p1->bignum[MAX - 2] = c;
            j--;
        }
        else if (j == 2)
        {
            temp = c - 48;
            j--;
        }
        else if (j == 1)
        {
            p1->bignum[MAX - 1] = temp * 10 + c - 48;
            j--;
        }
        else if (j == 0)
        {
            p1->bignum[i] = c - 48;
            i++;
            if (i == p1->bignum[MAX - 1])
            {
                i = 0;
                j = 3;
                count++;
                if (count == 1)
                    h = p1;
                else p2->next = p1;
                p2 = p1;
                p1 = (struct slink*)malloc(LEN);
            }
        }
    }
    p2->next = NULL;
    printf("\n");
    fclose(fp);
    fp = fopen("decryfile.txt", "w");
    p2 = (struct slink*)malloc(LEN);
    p1 = h;
    k = 0;
    if (h != NULL)/*/temp为暂存ASIIC码的int值*/
        do
        {
            for (i = 0; i < MAX; i++)
                p2->bignum[i] = 0;
            expmod(p1->bignum, d, n, p2->bignum);
            temp = p2->bignum[0] + p2->bignum[1] * 10 + p2->bignum[2] * 100;
            if ((p2->bignum[MAX - 2]) == '0')
            {
                temp = 0 - temp;
            }/*/转化为正确的ASIIC码，如-78-96形成汉字    */
            ch = temp;/*  str[k]--->ch */

            fputc(ch, fp);/*/写入文件str[k]--->ch*/
            k++;
            p1 = p1->next;
            p2 = (struct slink*)malloc(LEN);
        } while (p1 != NULL);
        printf("\n");
        fclose(fp);
        return;
}

int main()
{
    int  i;
    char  c;
    int  p[MAX], q[MAX], n[MAX], d[MAX], e[MAX], m[MAX], p1[MAX], q1[MAX];
    for (i = 0; i < MAX; i++)
        m[i] = p[i] = q[i] = n[i] = d[i] = e[i] = 0;/*/简单初始化一下*/
    while (1)
    {
        printf("----------欢迎使用RSA文本加解密测试系统----------\n");
        printf("1.加密\n");
        printf("2.解密\n");
        printf("3.退出\n");
        printf("请选择一种操作：");
        c = getchar();
        getchar();//接受回车符    
        if (c == '1')//操作E产生密钥对    
        {
            for (i = 0; i < MAX; i++)
                m[i] = p[i] = q[i] = n[i] = d[i] = e[i] = 0;
            printf("正在生成随机密钥对，请稍候......\n");
            printf("正在生成素数p......\n");
            prime_random(p, q);/*/随机产生两个大素数*/
            mul(p, q, n); //p乘以q=n  
            printf("密钥长度(模长)n为：");
            for (i = 0; i < n[MAX - 1]; i++)
            {
                printf("%d", n[n[MAX - 1] - i - 1]);
            }
            mov(p, p1);
            p1[0]--; //p-1        
            mov(q, q1);
            q1[0]--;      /*/q-1;*/
            mul(p1, q1, m);//m=(p-1)*(q-1)    
            erand(e, m);   //随机产生个与m互素的数
            rsad(e, m, d);  /*/求解密密钥d的函数(根据Euclid算法)*/
            printf("密钥对产生完成!\n");
            tencrypto(e, n);
            printf("\n加密文件操作完成!\n");
            printf("\n按任意键回主菜单…………");
            getchar();
        }
        else if (c == '2')
        {
            tdecrypto(d, n);
            printf("\n解密文件操作完成!\n");
            printf("\n按任意键回主菜单…………\n");
            getchar();
        }
        else if (c == '3')
            break;
    }
}
