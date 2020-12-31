// Danh sach lien ket don vong.

#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
	Đề bài tạo 1 danh sách liên kế vòng
	cấu trúc dữ liệu
	  data 
	// int ma_ho; // Kieu int  Không trùng nhau
	// string chu_ho; // Kiểu string
	// int so_thanh_vien; // kiểu int
	// float thu_nhap; // đơn vị tính  (triệu VND)
	1.Hiển thị toàn bộ danh sách
	2.Tìm hộ theo tên chủ hộ ( nhập vào) -> Chủ hộ được trùng họ tên -> return danh sách
	3.Thêm 1 hộ vào cuối danh sách. Đảm bảo không có hộ thêm trùng.
	 - Kiểm tra trùng mã hộ -> Thêm 1 hộ vào cuối danh sách
	 -!Kiểm tra trùng mã hộ -> thông báo hoặc yêu cầu nhập lại mã hộ khác.
	4.Xóa 1 hộ ra khỏi danh sách từ mã hộ.
	 - Tìm hộ theo mã hộ -> Xóa
	 - !Tìm hộ theo mã hộ -> thông báo 
	5.Nhập số thành viên. Hiển thị danh sách có số thành viên đó
	 - Tìm hộ theo số thành viên.
	 - Thêm hộ đó vào danh sách mới -> có nhiều hộ có cùng số thành viên -> return danh sách
	6.Điếm số hộ có thu nhập trên 2 Triệu thu_nhap >2 
	7.Sắp xếp danh sách giảm dần theo số thành viên
	 - Sử dụng bubble sort
	8.Sau đó, thêm mới hộ thành viên, nhưng vẫn đảm bảo yêu cầu 7.
	 - Thêm vào.
	 - Sort.
	9.Tìm kiếm các hộ có thu nhập dưới 10 M thu_nhap<10
	10. Hủy danh sách
	 - Lưu lại data
	 - Sử dụng hàm hủy trong c++ ( đối với c free())
*/
//Cấu trúc dữ liệu hộ gia đình
/*
	Struct là gì?
	Cấu trúc dữ liệu là dữ liệu được lập trình viên tạo có cấu trúc.
	struct  là tập hợp các biến có sẵn từ trước ( biến mặc định) mà lập trình viên gôm nó lại

*/
struct Ho_gia_dinh
{
	/* data */
	int ma_ho; // Kieu int  Không trùng nhau
	string chu_ho; // Kiểu string
	int so_thanh_vien; // kiểu int
	float thu_nhap; // đơn vị tính  (triệu VND)
};

// //được học
// struc Node{
// 	int data;//data
// 	Node *next; //lưu nút tiếp theo
// }

//Cấu trúc Node
struct Node{
	Ho_gia_dinh data;// int data ->
	Node *next;// Chứa địa chỉ kế tiếp của con trỏ
};
//Danh sách liên kết vòng
/*
	 Danh sách liên kết vòng là gì?
	 Danh sách là biến thể của mảng
	 Mảng là tập hợp các biến cùng kiểu dữ liệu
	 Danh sách liên kết là danh sách cấp phát động ( sử dụng con trỏ) phần tử cuối danh sách liên kết -> next sẽ -> NULL
	 Danh sách liên kết vòng là danh sách mà phần tử cuối -> next sẽ -> phần tử đầu
*/
struct List{
	Node *head;// phần tử đầu
	Node *tail; // phần tử cuối
};

void Init(List &l){ // Kiểm tra tạo thành vòng
	l.head = l.tail = NULL;
}

Node *creatNode(Ho_gia_dinh x ){ // tạo thông tin cho node // int k
	Node *p = new Node; // tạo node mới
	if(p == NULL) exit(1);
	// p -> next
	p->next = NULL;
	//p ->data
	p->data.ma_ho=x.ma_ho;//
	p->data.chu_ho =x.chu_ho;
	p->data.so_thanh_vien=x.so_thanh_vien;
	p->data.thu_nhap = x.thu_nhap;
	return p;
}
// Kiểm tra rỗng : nếu rỗng  = 0 mà không rỗng  =1
bool isEmpty(List l ){ 
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
// tim kiem theo tên ma ho
// có thể có nhiều kết quả tìm kiếm vì tên co thể trùng nhau -> kết quả trả về là danh sách
//thêm list
Node *search(List l, int ma_ho ){
	Node *p = l.head;
	do {
		if( p->data.ma_ho == ma_ho ) return p;
		else p = p->next;
	} while( p != l.head );
	return NULL;
}
// tim kiem theo tên chủ hộ
// có thể có nhiều kết quả tìm kiếm vì tên co thể trùng nhau -> kết quả trả về là danh sách
//thêm list
bool so_sanh_string(string s1,string s2)
{
	bool flag =true;
	for(int i =0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i]) {
			flag =false;
			break;
		}
	}
   
   return flag;
}
List search_ten_chu_ho(List l, string ten_chu_ho ){
	// cout<<isEmpty(l)<<endl; //debug
	List result;
	Init(result);
	Node *p = l.head;
	//int count = 0;
	do {
		count++;
		cout << count <<endl;
		if(so_sanh_string(p->data.chu_ho,ten_chu_ho) )
		{
			addTail(result,p->data);
			//cout << count <<endl;
		} 
		p = p->next;
			

	} while( p != l.head );
	return result;
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
		cout<<"| STT |    Ma ho    |     Ten chu ho     |  So luong |     Thu nhap    |" <<endl;
		cout<<"._____._____________.____________________.___________.__________________." <<endl;
		do{
			// hiển thị
			//coppy string vào  chuỗi char - do hàm printf khó in chuỗi
			char temp[p->data.chu_ho.length()];
			for (int i = 0; i < sizeof(temp); i++) {
        			temp[i] = p->data.chu_ho[i];
			}
			//Thêm ký tự kết thúc chuỗi vào cuối chuỗi
			temp[sizeof(temp)] ='\0';
			printf("|%5d|%13d|%20s|%12d|%17f|\n",count,p->data.ma_ho,temp,p->data.so_thanh_vien,p->data.thu_nhap);
			p = p->next;
			count++;
		}while( p != l.head );
		cout<<"|_____|_____________|____________________|____________|_________________|" <<endl;

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
	//List khởi tạo để chạy
	List l;
	Init(l);
	nhap(l);
	cout<<"tim chu ho ten Le Viet Thu:"<<endl;
	List f;
	Init(f);
	f =search_ten_chu_ho(l,"Le Viet Thu");
	xuat(f);
	return 0;
}
