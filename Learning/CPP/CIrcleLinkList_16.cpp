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
	Thành phần quản lý gồm con trỏ pList trỏ vào cuối danh sách
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

	Thành phần quản lý gồm con trỏ pList trỏ vào cuối danh sách
*/
struct List{
	Node *pList; // phần tử cuối
};
/// Khởi tạo sao cho phần tử cuối là NULL
void Init(List &l){ 
	l.pList =NULL;
}
// Kiểm tra rỗng : nếu rỗng  = 1 mà không rỗng  =0
// Nếu  pList = Null thì return rỗng 
// !Nếu  pList != NULL thì return flase
// vì là danh sách LK vòng nên cuối danh sách ->next = đầu danh sách
// Còn nếu cuối danh sách trả null thì chưa thêm phần tử nào vào
bool isEmpty(List l ){ 
	if(l.pList == NULL ) return true;
	return false;
}
// tạo thông tin cho node // int k
// Vì pList luôn nằm ở cuối danh sách nên thêm vào danh sách thì sẽ trỏ vào pList
Node *creatNode(Ho_gia_dinh x ){ 
	Node *p = new Node; 
	if(p == NULL) exit(1);
	// p -> next
	p->next = NULL;
	//p ->data
	p->data.ma_ho=x.ma_ho;//
	p->data.chu_ho =x.chu_ho;
	p->data.so_thanh_vien=x.so_thanh_vien;
	p->data.thu_nhap = x.thu_nhap;
	return p; //trả về Node
}
//hàm trà về Node trước pList
Node * back_pList(List l)
{
	if(!isEmpty(l)) // nếu danh sách rỗng -> re turn null
	{
		return NULL;
	}
	else 
	{
		Node * Node_hien_tai = new Node;// Node hiện tại
		Node * Node_truoc_do = new Node;// Node trước đó
		Node_truoc_do  = NULL; // chưa rõ node trước đó hay tiếp theo
		Node_hien_tai = l.pList;// Node hiện tại bằng pList
		// sử dụng do while cho nhanh vì có khi List có 1
		do
		{
			Node_truoc_do = Node_hien_tai;
			Node_hien_tai = Node_hien_tai ->next;
		} while (Node_hien_tai != l.pList);
		// Sau khi đi 1 vòng thì ra kết quả
		return Node_truoc_do;
	}
	return NULL;
}
//Thêm vào đầu
void  Them_vao_dau(List &l, Ho_gia_dinh data) {
    Node * p = creatNode(data);
    if (isEmpty(l)) {
        l.pList = p;
        p -> next = p;
    } else {
        p -> next = l.pList -> next;
        l.pList -> next = p;
    }
}
// chen vao cuối List:
//Trong Circular Linked List,
//để thêm vào cuối bạn có thể thêm vào đầu và trả về đầu mới là next của node mới thêm vào.
void Them_vao_cuoi(List &l, Ho_gia_dinh x ){ 
		Them_vao_dau(l,x);
		//đổi đầu mới
		// pList vẫn ở cuối danh sách
		l.pList = l.pList ->next;
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
List Tim_ho_ten_chu_ho(List l, string ten_chu_ho ){
	 //cout<<isEmpty(l)<<endl; //debug
	//  cout<<ten_chu_ho<<endl; //debug
	List result;
	Init(result);
	Node *p = l.pList;
	//int count = 0;
	do {
	//	count++;
		//cout << count <<endl;
		if(so_sanh_string(p->data.chu_ho,ten_chu_ho) )
		{
			Them_vao_cuoi(result,p->data);
			//cout << count <<endl;
		} 
		p = p->next;
			

	} while( p != l.pList );
	return result;
}

// input dữ liệu từ file
//sử dụng myfile
void nhap(List &l){
	std::fstream myfile("CIrcleLinkList_data_16.txt", std::ios_base::in);// mở file để đọc
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
			//cout<<"addpList()_ing"<<endl; debug
		 	Them_vao_dau(l,temp);
		}
		myfile.close();
		//cout<<"\nDa lay du lieu tu file: ";// dùng để debug file
  	}
	else 
	{
		cout << "Khong tim thay file : CIrcleLinkList_data_16.txt"<<endl;
		cout << "vui long tai ve qua github:"<<endl;
		cout << "https://github.com/nguyenvanauVietNam/Share_code/blob/main/Learning/CPP/CIrcleLinkList_data.txt"<<endl;
		cout << "Hoac tao file theo mau sau"<<endl;
		cout << "1. Tao mot file co ten CIrcleLinkList_data_16.txt"<<endl;
		cout << "2. Dong dau:ma chu ho  -> kieu int"<<endl;
		cout << "3. Dong 2: ten chu ho -> kieu string"<<endl;
		cout << "4. Dong 3: so thanh vien -> kieu int"<<endl;
		cout << "5. Dong 4 : thu nhap -> kieu float"<<endl;
		cout << "6. Sau luu bo vao cung thu muc voi file CIrcleLinkList.cpp da build vidu: CIrcleLinkList.exe "<<endl;
	}

}
// xuat thong tin ra man hinh
void xuat(List l ){	
	if(l.pList){
		cout<< "\n\t--------------Danh sach ho gia dinh--------------- \n";
		Node *p = l.pList;
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
		}while( p != l.pList );
		cout<<"|_____|_____________|____________________|____________|_________________|" <<endl;

	}
	else cout<< "\nDanh Sach Rong"; // dùng để debug file
	//cout<< endl;// dùng để debug file
}

// Kiểm tra mã hộ đã thêm có trùng với mã hộ nào không?
// dùng hàm bool trả về là 1 có thể thêm, trả về 0 không thêm được
bool Kiem_tra_ma_ho_them_co_trung(List l,int data)
{
	bool result = true;
	Node *p = l.pList;
	//int count = 0; //debug
	do {
	//	count++;//debug
	//	cout << count <<endl;//debug
		if(p->data.ma_ho == data) 
		{
			
			result =false;
			break;
		} 
		p = p->next;
			

	} while( p != l.pList );
	return result;
}
void Them_ho_vao_cuoi_danh_sach(List &l,Ho_gia_dinh data)
{
	if(Kiem_tra_ma_ho_them_co_trung(l,data.ma_ho))
	{
		Them_vao_cuoi(l,data);
	}
		cout<<" da co ma ho xin vui long nhap lai"<<endl;
}
int main(){
	// Khai báo danh sách
	List l;
	// Khởi tạo danh sách
	Init(l);
	//cout<<isEmpty(l)<<endl;//debug
	nhap(l);
	//xuat(l); // Câu 1 hiển thị danh sách 
	// // Câu 2 tìm chủ họ theo tên nhập từ bàn phím
	//  cout<<"tim chu ho  theo ten:"<<endl;
	//  List f;
	//  Init(f);
	//   string s;
	//  cout<<"Vui long nhap ten chu ho:"<<endl;
	//  getline(std::cin,s); // hàm nhập cả giá trị khoảng trắng
	//  f =Tim_ho_ten_chu_ho(l,s);
	//  xuat(f);
	// //Kết thúc câu 2
	//Câu 3:
	// Ho_gia_dinh data;
	// // data.ma_ho =1;
	// // data.chu_ho ="Nguyen Van Au";
	// // data.so_thanh_vien =3;
	// // data.thu_nhap =5.6;
	// cout<<"Vui long nhap ma ho:"<<endl;
	// cin>>data.ma_ho;
	// fflush(stdin);// phân biệt \n
	// cout<<"Vui long nhap ten chu ho:"<<endl;
	// getline(std::cin,data.chu_ho); // hàm nhập cả giá trị khoảng trắng
	// cout<<"Vui long nhap so thanh vien:"<<endl;
	// cin>>data.so_thanh_vien;
	// cout<<"Vui long nhap thu nhap:"<<endl;
	// cin>>data.thu_nhap;
	// Them_ho_vao_cuoi_danh_sach(l,data);
	// xuat(l);
	// //kết thúc câu 3
	return 0;
}
