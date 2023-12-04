#include<stdio.h>
#include<string.h>
#include <stdbool.h>
struct Todolist{
    int id;
    char start[50];
    char end[50];
    char content[100];
    bool status;
};
typedef struct Todolist todolist;
void input(todolist *temp){
    printf("nhap ma so:");
    scanf("%d",&temp->id);
    printf("ngay bat dau:");
    getchar();
    gets(temp->start);
    printf("ngay ket thuc:");
    getchar();
    gets(temp->end);
    printf("noi dung:");
    getchar();
    gets(temp->content);
    printf("nhap trang thai:");
    scanf("%d",&temp->status);
}
void output( todolist *temp){
    printf("ma so:%d, bat dau :%s   ket thuc :%s   boi dung:%s   trang thai:%d\n",temp->id, temp->start, temp->end, temp->content, temp->status);
}
void a(todolist temp[], int index){
    for (int i=0; i<index-1; i++) {
		for (int j=0; j<index-i-1; j++) {
			if (temp[j].content > temp[j+1].content) {
				todolist t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	}
}
int main(){
    int n,i;
    todolist todo[100];
    printf("nhap vao so nguoi co trong danh sach:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    input(&todo[i]);
    int index = n;
    int choice;
    int check;
    do{
        printf("************************MENU**************************\n");
		printf("1.In toan bo danh sach todo\n");
		printf("2.Them todo moi vao vi tri cuoi cung\n");
		printf("3.Cap nhat thong tin todo \n");
		printf("4.Xoa todo mong muon\n");
		printf("5.Sap xep todo va in ra danh sach tang dan\n");
		printf("6.Tim kiem todo theo content \n");
		printf("7.Tim kiem va in ra theo status\n");
		printf("8.thoat\n");
	printf("nhap lua chon cua ban:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                for (i=0;i<index;i++){
                    printf("%d:",i+1);
                    output(&todo[i]);
                }
                break;
            case 2:
                input(&todo[index]);
                index++;
                break;
            case 3:
                check = 0;
                char update_content[50];
                printf("nhap vao content muon cap nhat thong tin:");
                getchar();
                gets(update_content);
                for (i=0;i<index;i++){
                    if ( strcmp(todo[i].content,update_content) == 0 ){
                        input(&todo[i]);
                        check = 1;
                    }
                }
                if (check == 0) 
                    printf("khong tim thay\n");
                break;
            case 4:
                check = 0;
                char delete_content[50];
                printf("nhap content muon xoa:");
                getchar();
                gets(delete_content);
                for (i=0;i<index;i++){
                    if ( strcmp(todo[i].content,delete_content) == 0 ){
                        for (int j=i;j<index-1;j++)
                            todo[j] = todo[j+1];
                            check = 1;
                    }
                }
                index--;
                if (check == 0) 
                    printf("khong tin thay");
                break;
            case 5:
                a(todo,index);
                break;
            case 6:
                printf("nhap content can tim kiem:");
                char find_content[50];
                getchar();
                gets(find_content);
                int start = 0;
                int end = index;
                int mid;
                while( start<=end ) {
                    mid = (start+end) / 2;
                    if ( strcmp(todo[mid].content,find_content) == 0 ){
                        break;
                    } else if (todo[mid].content < find_content) {
                        start = mid+1;
                    } else {
                        end = mid-1;
                    }
                }
                if ( strcmp(todo[mid].content,find_content) == 0 ) {
                    output(&todo[mid]);
                } else {
                    printf("Khong tim thay ");
                }
                break;
            case 7:
                check = 0;
                int find_status;
                printf("nhap vao gia tri status can tim:");
                scanf("%d",&find_status);
                for (i=0;i<index;i++){
                    if (find_status == todo[i].status){
                        output(&todo[i]);
                        check = 1;
                    }
                }
                if (check == 0 )
                    printf("khong tin thay");
                break;
            case 8:
                printf("thoat\n");
            default:
                printf("khong hop le\n");
        }
    } while(choice != 8);   
}
