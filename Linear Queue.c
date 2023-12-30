#define size 0
#define True 1
#define False 0
struct Queue
{
    char item[size];
    int rear;
    int front;
};
void EnQueue(char x)
{
    if (q.rear == size - 1)
    {
        printf("Queue over\n");
        exit(1);
    }
    else
    {
        q.rear = q.rear + 1;
        q.item[q.rear] = x;
    }
}
char DeQueue()
{
    char x;
    if (Isempty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    else
    {
        x = q.item[q.front];
        q.front = q.front + 1;
        return x;
    }
}
int main()
{
    char x;
    initialise();
    EnQueue('A');
    EnQueue('B');
    EnQueue('C');
    x = DeQueue();
    printf("%c\n", x);
    return 0;
}
