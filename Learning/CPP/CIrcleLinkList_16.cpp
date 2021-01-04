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
List Tim_ten_chu_ho(List l, string ten_chu_ho ){
	 //cout<<isEmpty(l)<<endl; //debug
	//  cout<<ten_chu_ho<<endl; //debug
	List result;
	Init(result);
	Node *p = l.pList;
	//int count = 0;
	do {
	//	count++;
		//cout << count <<endl;
		if(strstr(ten_chu_ho,p->data.chu_ho)!=NULL )
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
		cout<< "\t------Bai Tap So 16---------"<<endl;
		cout<< "\n\t--------------Danh sach ho gia dinh--------------- \n";
		Node *p = l.pList->next;
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

			count++;
			p = p->next;
		}while( p != l.pList->next);
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

// xóa 1 phần tử theo mã hộ
void  Xoa_theo_ma_ho(List &l, int data) {
	//cout << data <<endl; //debug
	//cout << isEmpty(l) <<endl;//debug
	Node *p = l.pList; // p = nút l.pList  int i = 0;
	Node *pre;
	// Nếu List rỗng
	if(isEmpty(l)) 
	{
		l.pList = NULL;
		//cout << l.pList <<endl; //debug
	}
	// nếu danh sách có 1 phần tử và nếu phần tử đó == số mã hộ cần xóa
	else if(l.pList == l.pList ->next)
	{
		if(l.pList ->data.ma_ho ==data )
		{
			cout <<"line 307"<<endl;
			l.pList = NULL;
			delete p;// hủy 
			cout <<isEmpty(l)<<endl;
		}
	}
	else
	{
		// List không rỗng
		do {
			
			pre = p;// cho pre bằng p 
			p= p->next; // cho p = p->next
			// Sau 2 lệnh trên ta được 1 con trỏ trước p và p
			//cout <<"line 318" <<l.pList->data.ma_ho <<endl; //debgu
			if(p->data.ma_ho == data) 
			{
				pre -> next = p -> next; // cắt 1 đoạn p ra sao đó nói pre -> next vào
				if (p == l.pList) l.pList = pre;
				free(p);
				p = pre -> next;
			} 
			p = pre -> next;
		} while( p != l.pList );
	}
}
//5.nhập số thành viên. Hiển thị danh sách hộ có số thành viên đó.
// vì chỉ là tìm mã hộ theo số thành viên nên trả về số hộ thôi -> kiểu int
int Tim_so_ho_theo_so_thanh_vien ( List l, int so_thanh_vien)
{
	int result =0;
	Node *p = l.pList;
	//int count = 0;
	do {
	//	count++;
		//cout << count <<endl;
		if(p->data.so_thanh_vien == so_thanh_vien)
		{
			result ++;
			//cout << count <<endl;
		} 
		p = p->next;
			

	} while( p != l.pList );
	return result;
}
// câu 6  điếm số hộ có trên 2 M
// hàm nhận vào danh sách list và thu nhập của hộ gia đình
// trả về số lượng hộ có thu nhập trên >X
int Diem_thu_nhap_tren_X ( List l, float thu_nhap)
{
	int result =0;
	Node *p = l.pList;
	//int count = 0;
	do {
	//	count++;
		//cout << count <<endl;
		if(p->data.thu_nhap > thu_nhap)
		{
			result ++;
			//cout << count <<endl;
		} 
		p = p->next;
			

	} while( p != l.pList );
	return result;
}
//Câu 7:Sắp xếp danh sách giảm dần theo số thành viên. 
	//Điếm số lượng thành viên trong list
	int Length(List  l) {
		Node * current = l.pList;
		int i = 1;
		if (l.pList == NULL) {
			return 0;
		} else {
			current = current -> next;
			while (current != l.pList) {
				i++;
				current = current -> next;
			}
		}
		return i;
	}	
void Sort(List  &l) {
   //nếu list có danh sách nhỏ hơn 1 thì không cần sắp xếp
   if(Length(l) >2)
   {
	Node *tail = l.pList;
    Node * ptr1 = tail -> next, * ptr2, * min;
    Ho_gia_dinh temp;
    // selection sort implementation
    while (ptr1 -> next != tail -> next) {
        min = ptr1;
        ptr2 = ptr1 -> next;
        while (ptr2 != tail -> next) {
            if (min -> data.so_thanh_vien < ptr2 -> data.so_thanh_vien) min = ptr2;
            ptr2 = ptr2 -> next;
        }
        if (min != ptr1) {
            temp = min -> data;
            min -> data = ptr1 -> data;
            ptr1 -> data = temp;
        }
        ptr1 = ptr1 -> next;
    }
   }
}
//Tìm kiếm danh sách các hộ có mức thu nhập dưới x triệu
List Danh_sach_thu_Nhap_duoi_X(List l, float x ){
	List result;
	Init(result);
	Node *p = l.pList;
	//int count = 0;
	do {
	//	count++;
		//cout << count <<endl;
		if(p->data.thu_nhap < x )
		{
			//cout<< p->data.thu_nhap<< endl;
			Them_vao_cuoi(result,p->data);
			//cout << count <<endl;
		} 
		p = p->next;
			
	} while( p != l.pList );
	return result;
}



//Hàm hủy danh sách
void Huy_List(List &l)
{
	if(!isEmpty)
	{
		cout<<"Khong the huy"<<endl;
	} else if(l.pList =l.pList->next)
	{
		delete l.pList;
		l.pList = NULL;
      
	}
	else
	{
		Node* node = l.pList,*p;
		while (l.pList)
		{
			p = node->next;
      		delete node;
		}
		delete node;
		delete p;
		l.pList =NULL;
	}
}
 void menu()
 {
	 cout<< "Moi ban chon 1 trong cac Mod sau"<<endl;
	 cout<< "1. Hien thi danh sach"<<endl;
	 cout<< "2. Tim ho theo Ten chu ho"<<endl;
	 cout<< "3. Them ho vao cuoi danh sach "<<endl;
	 cout<< "4. Xoa ho theo Ma ho"<<endl;
	 cout<< "5. Hien thi danh sach ho co so thanh vien da nhap"<<endl;
	 cout<< "6. So ho co thu nhap tren 2 trieu"<<endl;
	 cout<< "7. Sap xep giam dan theo so thanh vien"<<endl;
	 cout<< "8. Them ho moi, sap xep"<<endl;
	 cout<< "9. Danh sach ho co muc thu nhap duoi 10 trieu"<<endl;
	 cout<< "10.Huy toan bo danh sach"<<endl;
	 cout<< "0. Thoat chuong trinh"<<endl;

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
	//Câu 4:
	//Xoa_theo_ma_ho(l,1001);
	//xuat(l);
	// câu 5:
	//cout << Tim_so_ho_theo_so_thanh_vien(l,100)<<endl;
	//Câu 6:
	//cout << " so thanh vien duoi 2 M"<< Diem_thu_nhap_tren_X(l,2)<<endl;
	// Câu 7:
	//Sort(l);
	//xuat(l);
	// câu 8:
	//thêm 1 hộ mới
	// Ho_gia_dinh data;
	// data.ma_ho =1010;
	// data.chu_ho ="Nguyen Van Au";
	// data.so_thanh_vien =3;
	// data.thu_nhap =5.6;
	// Them_ho_vao_cuoi_danh_sach(l,data);
	// //sort:
	// Sort(l);
	// xuat(l);
	// // Câu 9:
	//  List f;
	//  Init(f);
	//  f =Danh_sach_thu_Nhap_duoi_X(l,10);
	// Sort(f);
	// xuat(f);
	// //cau 10:
	// Huy_List(f);
	// xuat(f);
	int  i;
	string s;
	xuat(l);
	menu();
	cout<< "Vui long nhap mod:";
	cin >>i;
	do
	{
		switch (i)
		{
			//1.	 Hiển thị toàn bộ danh sách
			case 1:
			{	/* code */
				system("cls");
				cout<< "Mod 1. Hien thi toan bo danh sach:"<<endl;
				menu();
				cout<< "Vui long nhap mod:";
				cin >>i;
				break;
			}
			//2.	Tìm  hộ theo Tên chủ hộ (nhập vào)
			// case 2:
			// {
			// 	/* code */
			// 	cout<<"tim chu ho  theo ten:"<<endl;
			// 	List f;
			// 	Init(f);
			// 	cout<<"Vui long nhap ten chu ho:"<<endl;
			// 	//getline(std::cin,s); // hàm nhập cả giá trị khoảng trắng
			// 	cin>>s;// nhap ten
			// 	f =Tim_ten_chu_ho(l,s);
			// 	xuat(f);
			// 	menu();
			// 	cout<< "Vui long nhap mod:";
			// 	std::cin>>i;
			// 	break;
			// }
			case 3:
			{
				/* code */
				system("cls");
				menu();
				break;
			}
			default:
			{
				xuat(l);
				menu();
				cout<< "Vui long nhap mod:";
				cin >>i;
				break;
			}
		}
	} while(i!=0);
	


	return 0;
}
