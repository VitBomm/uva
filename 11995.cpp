#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin>>n) {
    bool isStack = true,isQueue = true, isPQueue = true;
    stack<int> ustack;
    queue<int> uqueue;
    priority_queue<int> upqueue;
        while (n--) {
            int a,b;
            cin>>a>>b;
            switch (a) {
                case 1:
                    if(isStack)
                        ustack.push(b);
                    if(isQueue)
                        uqueue.push(b);
                    if(isPQueue)
                        upqueue.push(b);
                    break;
                case 2:
                    if(isStack)
                    {  if( ustack.empty() ||ustack.top()!= b)
                        isStack = false;
                    else
                        ustack.pop();
                    }
                    if(isQueue)
                    {
                        if(uqueue.empty() || uqueue.front() !=b)
                            isQueue = false;
                        else
                            uqueue.pop();
                    }
                    if(isPQueue)
                    {
                        if(upqueue.empty() || upqueue.top() !=b)
                            isPQueue = false;
                        else
                            upqueue.pop();
                    }
                    break;
            }
        }
            if(!isStack && !isQueue && !isPQueue)
            {
                cout<<"impossible"<<endl;
            }
            else if((isStack && isPQueue) || (isStack && isQueue) ||(isPQueue && isQueue))
            {
                cout<<"not sure"<<endl;
            }
            else if (isStack)
            {
                cout<<"stack"<<endl;
            }
            else if (isQueue)
            {
                cout<<"queue"<<endl;
            }
            else
            {
                cout<<"priority queue"<<endl;
            }
    }
    return 0;
}
