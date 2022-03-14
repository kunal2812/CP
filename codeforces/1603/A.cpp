#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int val;
    struct node* next;
};

void solve(int xx){ 
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    struct node* head = NULL, *tail = NULL;
    for(int i = n-1; i>=0; i--){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->val = a[i];
		newnode->next = NULL;
        if(i==(n-1)){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    bool ok = true;
    while(ok){
        if(head==NULL){
            break;
        }
        ok = false;
        int ind = n;
        struct node* p = head, *q = NULL;
        while(p!=NULL){
            if(p->val%(ind+1)){
                ok = true;
                if(p==head){
                    if(head->next!=NULL){
                        head=head->next;
                        p->next = NULL;
                    }
                    else{
                        head = NULL;
                    }
                }
                else{
                    if(q!=NULL && p->next==NULL){
                        q->next = NULL;
                    }
                    else{
                        if(q==NULL){
                            p->next==NULL;
                        }
                        else{
                            q->next = p->next;
                            p->next = NULL;
                        }
                    }
                }
                free(p);
                n--;
                break;
            }
            q = p;
            p=p->next;
            ind--;
        }
// 		struct node* r = head;
// 		while(r!=NULL){
// 			printf("%d",r->val);
// 			r = r->next;
// 		}printf("\n");
    }
    if(head==NULL){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int main() {
    int t, i=0; 
    scanf("%d",&t);
    while(t--)  
        solve(++i);
    return 0;
}


