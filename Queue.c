#define size 0;
#define True=1;
#define False=0;
struct Queue
{
    int char item[size];
    int rear;
    int front;

};
struct Queue q;
initialise()
{
    Q.rear=-1;
    Q.front=0;

}
int Isempty()
{
    if(Q.rear-Q.front+1>==0)
    return False;
}
void EnQueue(char x)
if(Q.rear==size-1)
print ("Queue over");
exit(1)
else
Q.rear=Q.rear+1
Q.item EQ.rear=x
char DeQueue(charx);
{
    if(Isempty())
}
{
    print("Q  n clu")

}
exit
else
x=Q.item(Q.front)
Q.front=Qfront+1
return x;
int main()
{
    initialise()
    EnQueue('A');
      EnQueue('B');
        EnQueue('C');
        x=DeQueue();
        print("%c",x);
        return 0;
}