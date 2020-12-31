// Danh sach lien ket don vong.

#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//tạo cấu trúc dữ liệu
struct Ho_gia_dinh
{
	/* data */
	int ma_ho; // Kieu int  Không trùng nhau
	string chu_ho; // Kiểu string
	int so_thanh_vien; // kiểu int
	float thu_nhap; // đơn vị tính  (triệu VND)
};



struct Node{
	Ho_gia_dinh data;
	Node *next;// Chứa địa chỉ kế tiếp của con trỏ
};

struct List{
	Node *head;// phần tử đầu
	Node *tail; // phần tử cuối
};

void Init(List &l){ // Kiểm tra tạo thành vòng
	l.head = l.tail = NULL;
}

Node *creatNode(Ho_gia_dinh x ){ // tạo thông tin cho node
	Node *p = new Node; // tạo node
	if(p == NULL) exit(1);
	p->next = NULL;
	p->data.ma_ho=x.ma_ho;//
	p->data.chu_ho =x.chu_ho;
	p->data.so_thanh_vien=x.so_thanh_vien;
	p->data.thu_nhap = x.thu_nhap;
	return p;
}

bool isEmpty(List l ){ // k tr a xem lieu List co rong hay k.
	if(l.head == NULL ) return true;
	return false;
}

// chen vao dau List:
void addHead(List &l, Ho_gia_dinh x ){ 
	Node *p = creatNode(x);// truyền tham trị
	if(isEmpty(l)) l.head = l.tail = p;
	else{
		p->next = l.head; // con tro next cua p tro toi dia chi cua node head(ban dau)
		l.head = p; // cap nhat node head( luc sau )
	}
	l.tail->next = l.head; // khep vong don.
}
// hàm chèn vào đầu list
//thông tin đầu vào: Danh sách List, cấu trúc hộ gia đình
void addTail(List &l, Ho_gia_dinh x ){
	Node *p = creatNode(x);// truyền tham trị
	if(isEmpty(l)) addHead(l,x); // thêm hộ
	else{
		l.tail->next = p;
		l.tail = p;
	}
	l.tail->next = l.head; // khep vong don
}
// tim kiem theo tên chủ hộ
Node *search(List l, int ma_ho ){
	Node *p = l.head;
	do {
		if( p->data.ma_ho == ma_ho ) return p;
		else p = p->next;
	} while( p != l.head );
	return NULL;
}

void addMid(List &l, Ho_gia_dinh x, Ho_gia_dinh k ){ // chen node co data = x vao sau node co data  = k;
	Node *p = search(l,k.ma_ho);
	if(p!=NULL){
		Node *q= creatNode(x);
		Node *r = p->next;
		p->next = q;
		q->next = r;
	}
	else cout<<"\nKhong tim thay node co data = k.";
}
// input dữ liệu từ file
//sử dụng myfile
void nhap(List &l){
	std::fstream myfile("CIrcleLinkList_data.txt", std::ios_base::in);// mở file để đọc
	 if (myfile.is_open())
  	{
		//cout<<"\nDang lay du lieu tu file "<<endl;// dùng để debug file
		string ma_ho,chu_ho,so_thanh_vien,thu_nhap;
		 while ( getline(myfile,ma_ho) )
		 {
			getline(myfile,chu_ho);
			getline(myfile,so_thanh_vien);
			getline(myfile,thu_nhap);
			// string mh = ma_ho;// dùng để debug file
			// cout<<"Chu ho:"<< stoi(mh)<<endl;// dùng để debug file
			 Ho_gia_dinh temp;
			temp.ma_ho =stoi(ma_ho);
			temp.chu_ho =chu_ho;
			temp.so_thanh_vien =stoi(so_thanh_vien);
			temp.thu_nhap =stof(thu_nhap);
		 	addTail(l,temp);
		}
		myfile.close();
		//cout<<"\nDa lay du lieu tu file: ";// dùng để debug file
  	}
	else 
	{
		cout << "Khong tim thay file : CIrcleLinkList_data.txt"<<endl;
		cout << "vui long tai ve qua github:"<<endl;
		cout << "https://github.com/nguyenvanauVietNam/Share_code/blob/main/Learning/CPP/CIrcleLinkList_data.txt"<<endl;
		cout << "Hoac tao file theo mau sau"<<endl;
		cout << "1. Tao mot file co ten CIrcleLinkList_data.txt"<<endl;
		cout << "2. Dong dau:ma chu ho  -> kieu int"<<endl;
		cout << "3. Dong 2: ten chu ho -> kieu string"<<endl;
		cout << "4. Dong 3: so thanh vien -> kieu int"<<endl;
		cout << "5. Dong 4 : thu nhap -> kieu float"<<endl;
		cout << "6. Sau luu bo vao cung thu muc voi file CIrcleLinkList.cpp da build vidu: CIrcleLinkList.exe "<<endl;
	}

}
// xuat thong tin ra man hinh
void xuat(List l ){	
	if(l.head){
		cout<< "\n\t--------------Danh sach ho gia dinh--------------- \n";
		Node *p = l.head;
		int count =1;
		cout<<"._____._____________.____________________.___________.__________________." <<endl;
		cout<<"| STT |    Ma ho    |     Ten chu ho     |  So luong  |     Thu nhap    |" <<endl;
		cout<<"._____._____________.____________________.___________.__________________." <<endl;
		do{
			cout<<p->data.chu_ho;
			p = p->next;
			count++;
		}while( p != l.head );
		cout<<"\n|_____|_____________|____________________|____________|_________________|" <<endl;

	}
	//else cout<< "\nDanh Sach Rong"; // dùng để debug file
	//cout<< endl;// dùng để debug file
}

void delHead(List &l ){ // xoa node o dau List
	if(!isEmpty(l)){
		if(l.head != l.tail ){
			Node *p = l.head;
			l.head = l.head->next; // cap nhat l.head
			delete p; // xoa bo node head ban dau
			l.tail->next = l.head;
		}
		else l.head = NULL;
	}
	else return;
}

void delTail(List &l ){
	if(!isEmpty(l)){
		if(l.head != l.tail ){
			Node *p = l.head;
			Node *q = new Node;
			while(p->next != l.tail ) p = p->next; // tim node ngay truoc tail
			q = p; // gan node nay cho node q
			p = p->next; // p chinh la node tail can xoa
			l.tail = q; // cap nhat l.tail
			l.tail->next = l.head;
			delete p;
		} else l.head = NULL;
	}
	else return;
}

void delAtK(List &l, int ma_ho ){
	if( ma_ho <= 1) delHead(l);
	else if( ma_ho >= 10 ) delTail(l); // còn bug dòng này
	else{
		int dem = 0;
		if(!isEmpty(l)){
			Node *p = l.head;
			Node *q = new Node;
			while(p != NULL){ // tim node thu k.
				dem++;
				q = p;
				if(dem == ma_ho ) break; // tim thay thi break
				else p= p->next; // k thi tim tiep
			}
			Node *r = l.head;
			while(r->next != q ) r = r->next; // tim node k-1
			r->next = q->next; // cho node next cua node k-1 tro toi node k+1;
			delete q;
		}
	}
}

void menu(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
}
int main(){
	menu();	
	return 0;
}
