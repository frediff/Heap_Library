#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define lui unsigned long long int
#define lnum long long int

#define left(j) (2*(j)+1) // position of left child of a node
#define right(j) (2*(j)+2) // position of right child of a node


void addToHeap(person* p,person* heap[],lui& sz) // this simply inserts into heap and modifies it to maintian heap property
{
    lui j = sz;
    heap[sz++] = p;
    while(j)
    {
        if(compare(*heap[j],*heap[(j-1)/2]))
        {
            person* temp = heap[j];
            heap[j] = heap[(j-1)/2];
            heap[(j-1)/2] = temp;
            j = (j-1)/2;
        }
        else break;
    }
}

void delMax(person* heap[],lui &sz) // deletes max element and maintains heap property
{
    if(sz==0) return;
    heap[0] = heap[sz-1];
    --sz;
    lui j = 0;
    while(left(j)<sz)
    {
        if(right(j)<sz)
        {
            if(compare(*heap[left(j)],*heap[right(j)]))
            {
                if(compare(*heap[left(j)],*heap[j]))
                {
                    person* temp = heap[j];
                    heap[j] = heap[left(j)];
                    heap[left(j)] = temp;
                    j = left(j);
                }
                else break;
            }
            else
            {
                if(compare(*heap[right(j)],*heap[j]))
                {
                    person* temp = heap[j];
                    heap[j] = heap[right(j)];
                    heap[right(j)] = temp;
                    j = right(j);
                }
                else break;
            }
        }
        else
        {
            if(compare(*heap[left(j)],*heap[j]))
            {
                person* temp = heap[j];
                heap[j] = heap[left(j)];
                heap[left(j)] = temp;
                j = left(j);
            }
            else break;
        }
    }
}
