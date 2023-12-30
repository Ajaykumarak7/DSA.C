int main() {
    struct node *start;
    start = NULL;
    int x;
    Insbeg(&start, 100);
    Insbeg(&start, 200);
    Insbeg(&start, 300);
    Insbeg(&start, 400);
    Insbeg(&start, 500);
    Insbeg(&start, 600);
    Insbeg(&start, 700);
    Insbeg(&start, 800);
    Traverse(start);

    printf("\n");
    Insend(&start, 700);
    Traverse(start);

    Insaft(&start, 400, 350);
    printf("\n");
    Traverse(start);
    reverse(start);


     printf("\n");
    struct node *start1,*p;
    start = NULL;

    Insbeg(&start1, 100);
    Insbeg(&start1, 900);
    Insbeg(&start1, 200);
    Insbeg(&start1, 120);
    Insbeg(&start1, 150);
    Insbeg(&start1, 200);
    Insbeg(&start1, 190);


    printf("\n");
    p=merge(start,start1);
    Traverse(p);



    return 0;
P1 = START1
P2 = START2
START3 = NULL
 WHILE P1 != NULL AND P2 != NULL DO
IF P1 →Info < = P2 →Info THEN
InsEnd(START3, P1→Info)
P1 = P1→Next
ELSE 
InsEnd(START3, P2→Info)
P2 = P2→Next
WHILE P1 != NULL DO
InsEnd(START3, P1→Info)
P1 = P1→Next
WHILE P2 != NULL DO
InsEnd(START3, P2→Info)
P2 = P2→Next
RETURN START3
